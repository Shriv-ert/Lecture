#include <GL/glut.h>
#include <math.h>

// Variabel Global untuk animasi
float posX = -5.0f;       // Posisi awal sepeda di sumbu X
float angle = 0.0f;       // Sudut rotasi roda
float radius = 1.0f;      // Jari-jari roda
float speed = 0.02f;      // Kecepatan pergerakan (translasi)
const float PI = 3.1415926535f;

// Fungsi untuk menggambar roda (Lingkaran + ruji untuk melihat rotasi)
void drawWheel() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float theta = i * PI / 180.0f;
        glVertex2f(radius * cos(theta), radius * sin(theta));
    }
    glEnd();

    // Gambar ruji-ruji roda agar rotasi terlihat jelas
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f); glVertex2f(radius, 0.0f);
    glVertex2f(0.0f, 0.0f); glVertex2f(-radius, 0.0f);
    glVertex2f(0.0f, 0.0f); glVertex2f(0.0f, radius);
    glVertex2f(0.0f, 0.0f); glVertex2f(0.0f, -radius);
    glEnd();
}

// Fungsi Display (Render Frame)
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. Gambar Rangka Sepeda (Translasi saja)
    glPushMatrix();
    
    glTranslatef(posX, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f); // Sambungan dari poros belakang
    glVertex2f(1.0f, 0.0f);  // Ke poros depan
    glVertex2f(-1.0f, 0.0f); // Dari poros belakang
    glVertex2f(0.0f, 1.0f);  // Ke sadel
    glVertex2f(1.0f, 0.0f);  // Dari poros depan
    glVertex2f(0.0f, 1.0f);  // Ke setang/sadel
    glEnd();
    glPopMatrix();

    // 2. Gambar Roda Belakang (Translasi + Rotasi)
    glPushMatrix();
    // Translasi posisi sepeda ditambah posisi relatif poros belakang (X = -1.0)
    glTranslatef(posX - 1.0f, 0.0f, 0.0f);
    // Rotasi roda pada porosnya
    glRotatef(angle, 0.0f, 0.0f, 1.0f); 
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    drawWheel();
    glPopMatrix();

    // 3. Gambar Roda Depan (Translasi + Rotasi)
    glPushMatrix();
    // Translasi posisi sepeda ditambah posisi relatif poros depan (X = 1.0)
    glTranslatef(posX + 1.0f, 0.0f, 0.0f);
    // Rotasi roda pada porosnya
    glRotatef(angle, 0.0f, 0.0f, 1.0f); 
    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau
    drawWheel();
    glPopMatrix();

    glutSwapBuffers();
}

// Fungsi Animasi (Dipanggil terus-menerus saat idle)
void update() {
    // Translasi bergerak ke kanan
    posX += speed; 
    
    // Jika sepeda keluar layar, reset posisinya ke kiri
    if (posX > 6.0f) posX = -6.0f;

    // Hitung perubahan sudut berdasarkan jarak tempuh (Translasi)
    // Sudut = (Jarak / Jari-jari) * (180/PI). Negatif agar putaran searah jarum jam (maju)
    float deltaAngle = (speed / radius) * (180.0f / PI);
    angle -= deltaAngle; 

    // Minta GLUT me-render ulang layar
    glutPostRedisplay();
}

// Setup kamera sederhana
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Area pandang ortografi dari X(-6 s/d 6) dan Y(-3 s/d 3)
    gluOrtho2D(-6.0, 6.0, -3.0, 3.0); 
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Animasi Translasi dan Rotasi Sepeda");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Background gelap

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(update); // Jadikan fungsi update sebagai game loop

    glutMainLoop();
    return 0;
}