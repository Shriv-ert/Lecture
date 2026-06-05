#include <GL/glut.h>
#include <math.h>
void gambarRoda(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}
float radius = 30.0f; // Jari-jari roda
float gap = 5.0f; // Jarak antara roda dan rangka
float centerX = 320.0f; // Posisi tengah mobil di sumbu X
float range = 100.0f; // Jarak antara roda dengan posisi tengah mobil
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    // Gambar roda belakang
        glColor3f(0.2, 0.2, 0.2); // Warna abu abu untuk roda
        glLineWidth(7.0); // Ketebalan garis roda
        glTranslatef(-range, 0, 0); // Pindahkan ke posisi roda
        gambarRoda(centerX, 100, radius);
    glPopMatrix();
    glPushMatrix();
    // Gambar roda depan
        glColor3f(0.2, 0.2, 0.2); // Warna abu abu untuk roda
        glLineWidth(7.0); // Ketebalan garis roda
        glTranslatef(range, 0, 0); // Pindahkan ke posisi roda
        gambarRoda(centerX, 100, radius);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.9,0.4,0.0);
        //body tengah
        glBegin(GL_POLYGON);
            glVertex2f(centerX + range + 120, 100 + radius + gap);
            glVertex2f(centerX - range - 120 , 100 + radius + gap);
            glVertex2f(centerX - range - 120 , 100 + radius + gap + 10);
            glVertex2f(centerX + range + 120, 100 + radius + gap + 10);
        glEnd();
        //body atas
        glBegin(GL_POLYGON);
            glVertex2f(centerX - range - 120 , 100 + radius + gap + 10);
            glVertex2f(centerX + range + 120, 100 + radius + gap + 10);
            glVertex2f(centerX + range , 100 + radius + gap + 40);
            glVertex2f(centerX - range , 100 + radius + gap + 40);
        glEnd();
        //bodi bawah antara roda
        glBegin(GL_POLYGON);
            glVertex2f(centerX - range + radius + gap, 100);
            glVertex2f(centerX + range - radius - gap, 100);
            glVertex2f(centerX + range - radius - gap, 100 + radius + gap);
            glVertex2f(centerX - range + radius + gap, 100 + radius + gap);
        glEnd();
        //bodi bawah roda belakang   
        glBegin(GL_POLYGON);
            glVertex2f(centerX - range - 120 ,100);
            glVertex2f(centerX - range - radius - gap ,100);
            glVertex2f(centerX - range - radius - gap ,100 + radius + gap);
            glVertex2f(centerX - range - 120 ,100 + radius + gap);
        glEnd();
        //bodi bawah roda depan
        glBegin(GL_POLYGON);
            glVertex2f(centerX + range + 120 ,100);
            glVertex2f(centerX + range + radius + 2*gap,100);
            glVertex2f(centerX + range + radius + 2*gap,100 + radius + gap);
            glVertex2f(centerX + range + 120,100 + radius + gap);
        glEnd();
        //kaca kecil atas mobil bentuk segitiga
        glBegin(GL_POLYGON);
            glVertex2f(centerX + range , 100 + radius + gap + 40);
            glVertex2f(centerX + range - 20, 100 + radius + gap + 40);
            glVertex2f(centerX + range - 25, 100 + radius + gap + 80);
        glEnd();


    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Mobil sederhana");

    glClearColor(0.2, 0.5, 0.9, 1); //warna langit
    glutDisplayFunc(display);
    gluOrtho2D(0, 640, 0, 480);
    glutMainLoop();
    return 0;
}