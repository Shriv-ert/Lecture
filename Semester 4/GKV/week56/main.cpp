#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535898

float angle = 0.0f, deltaAngle = 0.0f;
float x = 0.0f, y = 3.0f, z = 12.0f;
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0;
int w, h;
float ratio;

const GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 5.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 80.0f };

void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) {
    x += i * lx * 0.1f;
    z += i * lz * 0.1f;
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void Reshape(int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1; h = h1;
    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void Grid() {
    double i;
    const float Z_MIN = -30, Z_MAX = 30;
    const float X_MIN = -30, X_MAX = 30;
    const float gap = 1.5f;

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f((float)i, 0, Z_MIN);
        glVertex3f((float)i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, (float)i);
        glVertex3f(X_MAX, 0, (float)i);
    }
    glEnd();
}

// Fungsi helper untuk menggambar bidang dan menghitung normal secara otomatis
void drawQuad(float z1, float y1, float x1, 
              float z2, float y2, float x2, 
              float z3, float y3, float x3, 
              float z4, float y4, float x4) {
    float u[3] = {x2-x1, y2-y1, z2-z1};
    float v[3] = {x3-x1, y3-y1, z3-z1};
    float nx = u[1]*v[2] - u[2]*v[1];
    float ny = u[2]*v[0] - u[0]*v[2];
    float nz = u[0]*v[1] - u[1]*v[0];
    float len = sqrt(nx*nx + ny*ny + nz*nz);
    if(len > 1e-5f) { nx/=len; ny/=len; nz/=len; }
    glNormal3f(nx, ny, nz);
    
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
}

float getW(float y, float y_top, float w_top, float y_bot, float w_bot) {
    if (fabs(y_top - y_bot) < 1e-5f) return w_bot;
    float t = (y - y_bot) / (y_top - y_bot);
    return w_bot + t * (w_top - w_bot);
}

void drawCarBody() {
    int num_points = 9;
    // Profil bodi lambo dari depan (Z positif) ke belakang (Z negatif)
    float prof_Z[9] = { 2.4f,  2.4f,  2.0f,  0.5f, -0.1f, -0.8f, -1.6f, -2.3f, -2.3f};
    float prof_Y[9] = { 0.25f, 0.5f,  0.6f,  0.8f,  1.25f, 1.25f, 0.85f, 0.8f,  0.25f};
    float prof_W[9] = { 0.8f,  0.8f,  0.9f,  1.0f,  0.75f, 0.75f, 1.0f,  1.05f, 1.0f}; 
    float bot_W[9]  = { 0.8f,  0.8f,  0.9f,  1.0f,  1.05f, 1.05f, 1.1f,  1.05f, 1.0f}; 
    float bot_Y = 0.25f;
    float sill_Y[9] = { 0.25f, 0.5f, 0.6f, 0.8f, 0.85f, 0.85f, 0.85f, 0.8f, 0.25f };

    float sill_W[9];
    for(int i=0; i<9; i++) {
        sill_W[i] = getW(sill_Y[i], prof_Y[i], prof_W[i], bot_Y, bot_W[i]);
    }

    float colors[8][3] = {
        {0.1f, 0.1f, 0.1f},   // 0: Bumper depan bawah (Hitam/Air intake)
        {1.0f, 0.8f, 0.0f},   // 1: Moncong depan (Kuning Lambo)
        {1.0f, 0.8f, 0.0f},   // 2: Kap mesin
        {0.15f, 0.15f, 0.2f}, // 3: Kaca depan
        {1.0f, 0.8f, 0.0f},   // 4: Atap
        {0.15f, 0.15f, 0.2f}, // 5: Kaca belakang
        {1.0f, 0.8f, 0.0f},   // 6: Dek belakang
        {0.1f, 0.1f, 0.1f}    // 7: Bumper belakang bawah
    };
    
    // Draw Top Panels
    for(int i=0; i<num_points-1; i++) {
        glColor3fv(colors[i]);
        drawQuad(prof_Z[i], prof_Y[i], -prof_W[i],     
                 prof_Z[i], prof_Y[i], prof_W[i],      
                 prof_Z[i+1], prof_Y[i+1], prof_W[i+1],
                 prof_Z[i+1], prof_Y[i+1], -prof_W[i+1]);
    }
    
    // Draw Bottom Panel
    glColor3f(0.1f, 0.1f, 0.1f);
    drawQuad(prof_Z[num_points-1], bot_Y, -bot_W[num_points-1], 
             prof_Z[num_points-1], bot_Y, bot_W[num_points-1],  
             prof_Z[0], bot_Y, bot_W[0],                        
             prof_Z[0], bot_Y, -bot_W[0]);                      
             
    // Draw Right Side Panels
    for(int i=0; i<num_points-1; i++) {
        if (i == 3 || i == 4 || i == 5) {
            glColor3f(0.15f, 0.15f, 0.2f); // Kaca samping
        } else {
            glColor3f(1.0f, 0.8f, 0.0f); // Bodi samping
        }
        drawQuad(prof_Z[i], prof_Y[i], prof_W[i],         
                 prof_Z[i], sill_Y[i], sill_W[i],              
                 prof_Z[i+1], sill_Y[i+1], sill_W[i+1],          
                 prof_Z[i+1], prof_Y[i+1], prof_W[i+1]);  
                 
        glColor3f(1.0f, 0.8f, 0.0f); 
        drawQuad(prof_Z[i], sill_Y[i], sill_W[i],         
                 prof_Z[i], bot_Y, bot_W[i],              
                 prof_Z[i+1], bot_Y, bot_W[i+1],          
                 prof_Z[i+1], sill_Y[i+1], sill_W[i+1]);  
    }
    
    // Draw Left Side Panels
    for(int i=0; i<num_points-1; i++) {
        if (i == 3 || i == 4 || i == 5) {
            glColor3f(0.15f, 0.15f, 0.2f);
        } else {
            glColor3f(1.0f, 0.8f, 0.0f);
        }
        drawQuad(prof_Z[i], prof_Y[i], -prof_W[i],        
                 prof_Z[i+1], prof_Y[i+1], -prof_W[i+1],  
                 prof_Z[i+1], sill_Y[i+1], -sill_W[i+1],         
                 prof_Z[i], sill_Y[i], -sill_W[i]);            
                 
        glColor3f(1.0f, 0.8f, 0.0f); 
        drawQuad(prof_Z[i], sill_Y[i], -sill_W[i],        
                 prof_Z[i+1], sill_Y[i+1], -sill_W[i+1],  
                 prof_Z[i+1], bot_Y, -bot_W[i+1],         
                 prof_Z[i], bot_Y, -bot_W[i]);            
    }
}

void sisiQuad(float pW, float pH) {
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(-pW, -pH, 0);
        glVertex3f( pW, -pH, 0);
        glVertex3f( pW,  pH, 0);
        glVertex3f(-pW,  pH, 0);
    glEnd();
}

void gambarKotak(float px, float py, float pz) {
    float hx = px / 2.0f;
    float hy = py / 2.0f;
    float hz = pz / 2.0f;
    glPushMatrix(); glTranslatef(0, 0, hz); sisiQuad(hx, hy); glPopMatrix();
    glPushMatrix(); glTranslatef(0, 0, -hz); glRotatef(180, 0, 1, 0); sisiQuad(hx, hy); glPopMatrix();
    glPushMatrix(); glTranslatef(0, hy, 0); glRotatef(-90, 1, 0, 0); sisiQuad(hx, hz); glPopMatrix();
    glPushMatrix(); glTranslatef(0, -hy, 0); glRotatef(90, 1, 0, 0); sisiQuad(hx, hz); glPopMatrix();
    glPushMatrix(); glTranslatef(hx, 0, 0); glRotatef(90, 0, 1, 0); sisiQuad(hz, hy); glPopMatrix();
    glPushMatrix(); glTranslatef(-hx, 0, 0); glRotatef(-90, 0, 1, 0); sisiQuad(hz, hy); glPopMatrix();
}

void gambarSilinder(float radius, float tebal, int slices) {
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, 1);
    glVertex3f(0, 0, tebal / 2.0f);
    for (int i = 0; i <= slices; i++) {
        float a = 2.0f * PI * i / slices;
        glNormal3f(0, 0, 1);
        glVertex3f(cos(a) * radius, sin(a) * radius, tebal / 2.0f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, -1);
    glVertex3f(0, 0, -tebal / 2.0f);
    for (int i = slices; i >= 0; i--) {
        float a = 2.0f * PI * i / slices;
        glNormal3f(0, 0, -1);
        glVertex3f(cos(a) * radius, sin(a) * radius, -tebal / 2.0f);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float a = 2.0f * PI * i / slices;
        float nx = cos(a), ny = sin(a);
        glNormal3f(nx, ny, 0);
        glVertex3f(nx * radius, ny * radius,  tebal / 2.0f);
        glVertex3f(nx * radius, ny * radius, -tebal / 2.0f);
    }
    glEnd();
}

void gambarRoda() {
    // Ban
    glColor3f(0.05f, 0.05f, 0.05f);
    gambarSilinder(0.35f, 0.3f, 32);

    // Velg
    glColor3f(0.7f, 0.7f, 0.7f);
    gambarSilinder(0.2f, 0.32f, 16);
}

void gambarMobil() {
    // Gambar bodi utama
    drawCarBody();
    
    // Spoiler Support Kiri
    glColor3f(0.1f, 0.1f, 0.1f);
    glPushMatrix();
    glTranslatef(-0.6f, 0.95f, -2.15f);
    glRotatef(-20, 1, 0, 0);
    gambarKotak(0.05f, 0.3f, 0.2f);
    glPopMatrix();
    
    // Spoiler Support Kanan
    glPushMatrix();
    glTranslatef(0.6f, 0.95f, -2.15f);
    glRotatef(-20, 1, 0, 0);
    gambarKotak(0.05f, 0.3f, 0.2f);
    glPopMatrix();

    // Spoiler Wing
    glColor3f(1.0f, 0.8f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 1.1f, -2.25f);
    glRotatef(-10, 1, 0, 0);
    gambarKotak(2.4f, 0.05f, 0.5f);
    glPopMatrix();
    
    // Lampu Depan
    glColor3f(1.0f, 1.0f, 0.8f); 
    glPushMatrix();
    glTranslatef(0.7f, 0.6f, 1.9f);
    glRotatef(15, 1, 0, 0);
    glRotatef(10, 0, 1, 0);
    gambarKotak(0.3f, 0.05f, 0.4f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.7f, 0.6f, 1.9f);
    glRotatef(15, 1, 0, 0);
    glRotatef(-10, 0, 1, 0);
    gambarKotak(0.3f, 0.05f, 0.4f);
    glPopMatrix();
    
    // Lampu Belakang
    glColor3f(1.0f, 0.1f, 0.1f);
    glPushMatrix();
    glTranslatef(0.7f, 0.7f, -2.31f);
    gambarKotak(0.5f, 0.1f, 0.05f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.7f, 0.7f, -2.31f);
    gambarKotak(0.5f, 0.1f, 0.05f);
    glPopMatrix();
    
    // Roda
    float rodaX[]  = { 1.0f,  1.0f, -1.0f, -1.0f };
    float rodaZ[]  = { 1.4f, -1.4f, 1.4f, -1.4f };

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(rodaX[i], 0.35f, rodaZ[i]);
        glRotatef(90, 0, 1, 0);
        gambarRoda();
        glPopMatrix();
    }
}

void display() {
    if (deltaMove) moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Grid();
    gambarMobil();
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x2, int y2) {
    switch (key) {
        case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT : deltaAngle =  0.01f; break;
        case GLUT_KEY_UP : deltaMove  =  1; break;
        case GLUT_KEY_DOWN : deltaMove  = -1; break;
    }
}

void releaseKey(int key, int x2, int y2) {
    switch (key) {
        case GLUT_KEY_LEFT : if (deltaAngle < 0) deltaAngle = 0; break;
        case GLUT_KEY_RIGHT : if (deltaAngle > 0) deltaAngle = 0; break;
        case GLUT_KEY_UP : if (deltaMove  > 0) deltaMove  = 0; break;
        case GLUT_KEY_DOWN : if (deltaMove  < 0) deltaMove  = 0; break;
    }
}

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void initGL() {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Lambo 3D");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    lighting(); 
    initGL();
    glutMainLoop();
    return 0;
}
