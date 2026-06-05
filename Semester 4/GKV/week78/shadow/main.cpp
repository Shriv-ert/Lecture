#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

double rx = 0.0;
double ry = 0.0;

// Koordinat sumber cahaya
float l[] = { 0.0,  80.0, 0.0 };

// Titik bidang (plane)
float n[] = { 0.0, -40.0, 0.0 };
float e[] = { 0.0, -60.0, 0.0 };

void help();

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawStar() {
    float outerR = 30.0f;
    float innerR = 12.0f;
    float thickness = 10.0f;
    float starVertices[10][2];

    for (int i = 0; i < 10; ++i) {
        float angle = (i * 36.0f + 90.0f) * M_PI / 180.0f;
        float r = (i % 2 == 0) ? outerR : innerR;
        starVertices[i][0] = r * cos(angle);
        starVertices[i][1] = r * sin(angle);
    }

    // Wajah depan
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, thickness / 2.0f);
    for (int i = 0; i <= 10; ++i) {
        int idx = i % 10;
        glVertex3f(starVertices[idx][0], starVertices[idx][1], thickness / 2.0f);
    }
    glEnd();

    // Wajah belakang
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, -thickness / 2.0f);
    for (int i = 10; i >= 0; --i) {
        int idx = i % 10;
        glVertex3f(starVertices[idx][0], starVertices[idx][1], -thickness / 2.0f);
    }
    glEnd();

    // Sisi samping
    glBegin(GL_QUADS);
    for (int i = 0; i < 10; ++i) {
        int next = (i + 1) % 10;
        float dx = starVertices[next][0] - starVertices[i][0];
        float dy = starVertices[next][1] - starVertices[i][1];
        float len = sqrt(dx*dx + dy*dy);
        float nx = dy / len;
        float ny = -dx / len;

        glNormal3f(nx, ny, 0.0f);
        glVertex3f(starVertices[i][0], starVertices[i][1], thickness / 2.0f);
        glVertex3f(starVertices[next][0], starVertices[next][1], thickness / 2.0f);
        glVertex3f(starVertices[next][0], starVertices[next][1], -thickness / 2.0f);
        glVertex3f(starVertices[i][0], starVertices[i][1], -thickness / 2.0f);
    }
    glEnd();
}

// Objek yang akan digambar
void draw() {
    drawStar();
}

// Membuat proyeksi bayangan
void glShadowProjection(float *l, float *e, float *n) {
    float d, c;
    float mat[16];

    d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
    c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;

    // Matriks (OpenGL pakai column-major)
    mat[0]  = l[0]*n[0] + c;
    mat[4]  = n[1]*l[0];
    mat[8]  = n[2]*l[0];
    mat[12] = -l[0]*c - l[0]*d;

    mat[1]  = n[0]*l[1];
    mat[5]  = l[1]*n[1] + c;
    mat[9]  = n[2]*l[1];
    mat[13] = -l[1]*c - l[1]*d;

    mat[2]  = n[0]*l[2];
    mat[6]  = n[1]*l[2];
    mat[10] = l[2]*n[2] + c;
    mat[14] = -l[2]*c - l[2]*d;

    mat[3]  = n[0];
    mat[7]  = n[1];
    mat[11] = n[2];
    mat[15] = -d;

    glMultMatrixf(mat);
}

void render() {
    glClearColor(0.0, 0.6, 0.9, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, l);

    // Gambar titik sumber cahaya
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
        glVertex3f(l[0], l[1], l[2]);
    glEnd();

    // Gambar lantai
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3f(-1300.0, e[1] - 0.1,  1300.0);
        glVertex3f( 1300.0, e[1] - 0.1,  1300.0);
        glVertex3f( 1300.0, e[1] - 0.1, -1300.0);
        glVertex3f(-1300.0, e[1] - 0.1, -1300.0);
    glEnd();

    // Gambar objek asli
    glPushMatrix();
        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);

        glEnable(GL_LIGHTING);
        glColor3f(1.0, 0.84, 0.0); // Emas
        draw();
    glPopMatrix();

    // Gambar bayangan
    glPushMatrix();
        glShadowProjection(l, e, n);

        glRotatef(ry, 0, 1, 0);
        glRotatef(rx, 1, 0, 0);

        glDisable(GL_LIGHTING);
        glColor3f(0.4, 0.4, 0.4);
        glDepthMask(GL_FALSE); // Mencegah Z-fighting antar poligon bayangan
        draw();
        glDepthMask(GL_TRUE);
    glPopMatrix();

    glutSwapBuffers();
}

void keypress(unsigned char c, int a, int b) {
    if (c == 27) exit(0);
    else if (c == 's') l[1] -= 5.0;
    else if (c == 'w') l[1] += 5.0;
    else if (c == 'a') l[0] -= 5.0;
    else if (c == 'd') l[0] += 5.0;
    else if (c == 'q') l[2] -= 5.0;
    else if (c == 'e') l[2] += 5.0;
    else if (c == 'h') help();
}

void help() {
    printf("Contoh proyeksi bayangan sebuah objek\n");
}

void idle() {
    rx += 0.1;
    ry += 0.1;
    render();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(300, 30);
    glutCreateWindow("Proyeksi Bayangan");

    glutReshapeFunc(resize);
    glutReshapeWindow(400, 400);
    glutKeyboardFunc(keypress);
    glutDisplayFunc(render);
    glutIdleFunc(idle);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);

    // Setup proyeksi
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1.0, 1.0, 400.0);

    // Setup kamera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -150.0);

    glutMainLoop();
    return 0;
}