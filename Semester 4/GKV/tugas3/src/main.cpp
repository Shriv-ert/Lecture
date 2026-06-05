#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, fingerJoint1 = 0, fingerJoint2 = 0;
float angle = 0.0f; // Sudut rotasi kamera
float radius = 7.0f; // Jarak kamera dari objek

void init(void) {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST); // Penting agar objek 3D tidak tumpang tindih secara visual
}

void drawJari(float length, float width) {
    glPushMatrix();
    glScalef(length, width, width);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawIbuJari(float length, float width) {
    glPushMatrix();
    glScalef(width, width, length);
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // HITUNG POSISI KAMERA OTOMATIS (ORBIT)
    float camX = radius * cos(angle);
    float camZ = radius * sin(angle);
    float camY = 2.0f; // Kamera sedikit lebih tinggi agar terlihat dari atas

    gluLookAt(camX, camY, camZ,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);

    glPushMatrix();
        // lengan atas
        glTranslatef(-1.5, 0.0, 0.0);
        glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.2, 0.6);
            glutWireCube(1.0);
        glPopMatrix();

        // lengan bawah
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.2, 0.6);
            glutWireCube(1.0);
        glPopMatrix();

        // telapak tangan
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.6, 0.2, 0.8);
            glutWireCube(1.0);
        glPopMatrix();

        // Menggambar 4 Jari
        float offsets[4] = {0.3, 0.1, -0.1, -0.3}; // Posisi jari relatif terhadap telapak tangan
        for (int i = 0; i < 4; i++) {
            glPushMatrix();
                glTranslatef(0.3, 0.0, offsets[i]);
                glRotatef((GLfloat)fingerJoint1, 0.0, 0.0, 1.0);
                glTranslatef(0.15, 0.0, 0.0);
                drawJari(0.3, 0.1);
                glTranslatef(0.15, 0.0, 0.0);
                glRotatef((GLfloat)fingerJoint2, 0.0, 0.0, 1.0);
                glTranslatef(0.15, 0.0, 0.0);
                drawJari(0.3, 0.1);
            glPopMatrix();
        }
        // buat ibu jari
        glPushMatrix();
            glTranslatef(0.0, 0.02, 0.5);
            glRotatef(-(GLfloat)fingerJoint1, 1.0, 0.0, 0.0);
            drawIbuJari(0.3, 0.1);
            glTranslatef(0.0, 0.0, 0.15);
            glRotatef(-(GLfloat)fingerJoint2, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 0.0, 0.15);
            drawIbuJari(0.3, 0.1);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

// FUNGSI ANIMASI (Idle Function)
void update(int value) {
    angle += 0.02f; // Kecepatan putaran kamera
    if (angle > 360) angle -= 360;

    glutPostRedisplay(); // Meminta layar digambar ulang
    glutTimerFunc(16, update, 0); // Refresh sekitar 60 FPS
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q': fingerJoint1 = (fingerJoint1 + 5) % 90; break;
        case 'w': fingerJoint2 = (fingerJoint2 + 5) % 90; break;
        case 'e': shoulder = (shoulder + 5) % 360; break;
        case 'r': elbow = (elbow + 5) % 360; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Animasi Tangan 3D");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0); // Memulai loop animasi
    glutMainLoop();
    return 0;
}