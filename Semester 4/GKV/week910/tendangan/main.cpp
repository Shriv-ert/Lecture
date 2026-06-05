#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.14159265

// Kamera Global
float angle = 0.0f, deltaAngle = 0.0f, ratio;
float x = -5.0f, y = 12.0f, z = 40.0f; // posisi awal kamera
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;

// Rotasi World / Grid
static int rotAngleX = 0, rotAngleY = 0, rotAngleZ = 0;

// Variabel Posisi Objek Interaksi
float posXKaki = 10.0f, posXBola = -10.0f;
float posYKaki = 6.0f, posYBola = -5.0f;
float rotKaki = 0.0f;

// Variabel State Interaksi
int kick = 0, roll = 0, touch = 0;
float jarak = 1.0f;

GLUquadricObj *IDquadric;

// Variabel Pencahayaan & Material
const GLfloat light_ambient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    IDquadric = gluNewQuadric();
    gluQuadricNormals(IDquadric, GL_SMOOTH);
    gluQuadricTexture(IDquadric, GL_TRUE);
}

void Reshape(int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0, ratio, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    lx = sin(ang / 10.0f);
    lz = -cos(ang / 10.0f);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) {
    x = x + i * lx * 0.1f;
    z = z + i * lz * 0.1f;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': rotAngleX += 2; break;
        case 's': rotAngleX -= 2; break;
        case 'a': rotAngleY += 2; break;
        case 'd': rotAngleY -= 2; break;
        case 'q': rotAngleZ += 2; break;
        case 'e': rotAngleZ -= 2; break;
        case 'o': 
            posXKaki -= 1.0f;
            if (posXBola < -2.9f) {
                posXBola += 1.0f;
            }
            break;
        case 'p': 
            posXKaki += 1.0f;
            posXBola -= 1.0f;
            break;
        case 'k': 
            kick = 1; 
            break;
        case 32: // Spasi untuk reset
            rotAngleX = rotAngleY = rotAngleZ = 0;
            posXKaki = 10.0f; posXBola = -10.0f; 
            posYKaki = 6.0f; posYBola = -5.0f;
            rotKaki = 0.0f; kick = roll = touch = 0;
            jarak = 1.0f;
            break;
        case 27: // ESC
            exit(0);
            break;
        default: break;
    }
    glutPostRedisplay();
}

void pressKey(int k, int x, int y) {
    switch (k) {
        case GLUT_KEY_UP:    deltaMove = 1;   break;
        case GLUT_KEY_DOWN:  deltaMove = -1;  break;
        case GLUT_KEY_LEFT:  deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.01f;  break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    if (deltaMove > 0)  deltaMove = 0; break;
        case GLUT_KEY_DOWN:  if (deltaMove < 0)  deltaMove = 0; break;
        case GLUT_KEY_LEFT:  if (deltaAngle < 0.0f) deltaAngle = 0.0f; break;
        case GLUT_KEY_RIGHT: if (deltaAngle > 0.0f) deltaAngle = 0.0f; break;
    }
}

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 2;
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    for(i = Z_MIN; i <= Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for(i = X_MIN; i <= X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Balok(float panjang, float lebar, float tinggi) {
    glPushMatrix();
    float p = panjang / 2.0f;
    float l = lebar / 2.0f;
    float t = tinggi / 2.0f;
    
    // Depan
    glBegin(GL_QUADS);
    glVertex3f(-p, 0, l);
    glVertex3f(p, 0, l);
    glVertex3f(p, -t * 2, l);
    glVertex3f(-p, -t * 2, l);
    glEnd();
    
    // Belakang
    glBegin(GL_QUADS);
    glVertex3f(-p, 0, -l);
    glVertex3f(p, 0, -l);
    glVertex3f(p, -t * 2, -l);
    glVertex3f(-p, -t * 2, -l);
    glEnd();
    
    // Atas
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-p, 0, -l);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(p, 0, -l);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(p, 0, l);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-p, 0, l);
    glEnd();
    
    // Bawah
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-p, -t * 2, -l);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(p, -t * 2, -l);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(p, -t * 2, l);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-p, -t * 2, l);
    glEnd();
    
    // Kanan
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(p, -t * 2, -l);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(p, -t * 2, l);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(p, 0, l);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(p, 0, -l);
    glEnd();
    
    // Kiri
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-p, -t * 2, -l);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-p, -t * 2, l);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-p, 0, l);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-p, 0, -l);
    glEnd();
    
    glPopMatrix();
}

void pergerakanKaki() {
    // Kondisi menarik kaki ke belakang bersiap menendang
    if (kick == 1) {
        if (rotKaki <= 45.0f) {
            rotKaki += 0.5f; 
        }
        if (rotKaki > 44.9f) {
            kick = 2;
        }
    }
    
    // Deteksi apakah bola menempel/berada di area jangkauan tendang
    if (posXBola > -2.9f) {
        touch = 1;
    } else if (posXBola < -12.0f) {
        touch = 0;
    }
    
    // Kondisi mengayunkan kaki menendang ke depan
    if (kick == 2) {
        if (rotKaki >= -90.0f) {
            rotKaki -= 0.8f;
            if (rotKaki < 1.0f && touch == 1) {
                roll = 1; // Bola mulai bergulir jika terkena
            }
        }
        if (rotKaki < -90.0f) {
            kick = 3;
        }
    }
    
    // Kondisi mengembalikan posisi kaki ke semula
    if (kick == 3) {
        if (rotKaki <= 0.0f) {
            rotKaki += 0.5f;
        }
        if (rotKaki > -1.0f) {
            kick = 0;
        }
    }
}

void pergerakanBola() {
    // Kondisi jika bola menggelinding setelah ditendang
    if (roll == 1) {
        if (jarak > 0.0f) {
            posXBola -= 0.3f; // Mengatur kecepatan laju bola
            jarak -= 0.01f;   // Mengurangi batas durasi perulangan gelinding
        }
        if (jarak <= 0.0f) {
            roll = 0;
            jarak = 1.0f; // Reset batas jarak
        }
    }
}

void Object() {
    glPushMatrix();
    // Gambar Kaki (Balok Putih)
    glPushMatrix();
    glTranslatef(posXKaki, posYKaki, 0.0f);
    pergerakanKaki();
    glRotatef(rotKaki, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Balok(2.0f, 3.0f, 6.0f);
    glPopMatrix();
    
    // Gambar Bola (Sphere Jingga)
    glPushMatrix();
    pergerakanBola();
    glColor3f(0.8f, 0.4f, 0.0f);
    glTranslatef(posXBola, posYBola, 0.0f);
    glutSolidSphere(1.0f, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (deltaMove) moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    
    glPushMatrix();
    glRotatef(rotAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotAngleZ, 0.0f, 0.0f, 1.0f);
    
    Grid();
    Object();
    
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Simulation: Tendangan");
    
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    
    lighting();
    init();
    glutMainLoop();
    return 0;
}