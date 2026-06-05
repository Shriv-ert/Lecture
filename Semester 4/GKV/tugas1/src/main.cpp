#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. GL_LINE_STRIP (Warna Merah) - Membentuk huruf 'S' terbalik kaku memanjang ekor
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8, 0.8);
        glVertex2f(-0.6, 0.8);
        glVertex2f(-0.6, 0.6);
        glVertex2f(-0.8, 0.6);
        glVertex2f(-0.8, 0.4);
        glVertex2f(1.0, 0.4);
    glEnd();

    // 2. GL_LINE_LOOP (Warna Hijau) - Membentuk Segitiga Tertutup
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.4, 0.8);
        glVertex2f(-0.2, 0.8);
        glVertex2f(-0.3, 0.5);
    glEnd();

    // 3. GL_TRIANGLE_STRIP (Warna Biru) - Bentuk kotak biru
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(0.2, 0.8);
        glVertex2f(0.2, 0.6);
        glVertex2f(0.5, 0.8);
        glVertex2f(0.5, 0.6);
    glEnd();

    // 4. GL_TRIANGLE_FAN (Warna Kuning) - Menyerupai Kipas
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.7, -0.2); // Titik Pusat
        glVertex2f(-0.8, -0.5);
        glVertex2f(-0.7, -0.6);
        glVertex2f(-0.6, -0.5);
    glEnd();

    // 5. GL_QUADS (Warna Magenta) - Dua Kotak Terpisah
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        // Quad 1
        glVertex2f(-0.3, -0.2); glVertex2f(-0.1, -0.2);
        glVertex2f(-0.1, -0.4); glVertex2f(-0.3, -0.4);
        // Quad 2
        glVertex2f(0.0, -0.2); glVertex2f(0.2, -0.2);
        glVertex2f(0.2, -0.4); glVertex2f(0.0, -0.4);
    glEnd();

    // 6. GL_QUAD_STRIP (Warna Cyan) - Pita memanjang
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.4, -0.2); glVertex2f(0.4, -0.5);
        glVertex2f(0.6, -0.2); glVertex2f(0.6, -0.5);
        glVertex2f(0.8, -0.1); glVertex2f(0.8, -0.4);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Demo Primitif OpenGL");
    glutDisplayFunc(display);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}