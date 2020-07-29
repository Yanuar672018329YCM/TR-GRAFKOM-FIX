#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void init(void);
void ukuran(int,int);
void tampil(void);
void hilang(void);
void rumah_tingkat(void);
void display(void);
void dasar(void);
void keyboard(unsigned char, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void alat_berat(void);
void cylinder(float alas,float atas,float tinggi);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void alat_berat(void)
{
	//bak depan bawah
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-50.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 19.0);
    glVertex3f(-50.0, -7.0, 19.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 19.0);
    glVertex3f(-50.0, -7.0, 19.0);
    glEnd();

    //bak miring kiri
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-50.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 33.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-50.0, -4.0, 37.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, -7.0, 33.0);
    glVertex3f(-40.0, -7.0, 33.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-50.0, -4.0, 37.0);
    glEnd();

    //bak miring kanan
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-50.0, -7.0, 19.0);
    glVertex3f(-40.0, -7.0, 19.0);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-50.0, -4.0, 15.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, -7.0, 19.0);
    glVertex3f(-40.0, -7.0, 19.0);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-50.0, -4.0, 15.0);
    glEnd();

    //bak miring kanan tegak
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-50.0, -4.0, 15.0);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-40.0, 3.0, 15.0);
    glVertex3f(-50.0, 1.0, 15.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, -4.0, 15.0);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-40.0, 3.0, 15.0);
    glVertex3f(-50.0, 1.0, 15.0);
    glEnd();

    //bak miring kiri tegak
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-50.0, -4.0, 37.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-40.0, 3.0,  37.0);
    glVertex3f(-50.0, 1.0,  37.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-50.0, -4.0, 37.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-40.0, 3.0,  37.0);
    glVertex3f(-50.0, 1.0,  37.0);
    glEnd();

    //bak tutup belkakang atas
    glBegin(GL_QUADS);
    glColor3ub(218, 165, 32);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-40.0, 3.0,  37.0);
    glVertex3f(-40.0, 3.0,  15.0);
    glEnd();

    //bak tutup belkakang bawah
    glBegin(GL_QUADS);
    glColor3ub(218, 165, 32);
    glVertex3f(-40.0, -4.0, 15.0);
    glVertex3f(-40.0, -4.0, 37.0);
    glVertex3f(-40.0, -7.0,  33.0);
    glVertex3f(-40.0, -7.0,  19.0);
    glEnd();

//bawah eskavator
    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-48.0, -7.0, 30.0);
    glVertex3f(-25.0, -7.0, 30.0);
    glVertex3f(-25.0, -10.0,  30.0);
    glVertex3f(-48.0, -10.0,  30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-48.0, -7.0, 22.0);
    glVertex3f(-25.0, -7.0, 22.0);
    glVertex3f(-25.0, -10.0,  22.0);
    glVertex3f(-48.0, -10.0,  22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-48.0, -7.0, 22.0);
    glVertex3f(-48.0, -7.0, 30.0);
    glVertex3f(-48.0, -10.0,  30.0);
    glVertex3f(-48.0, -10.0,  22.0);
    glEnd();

//mesin
	//mesin bawah kiri
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 3.0, 33.0);
    glVertex3f(-25.0, 3.0, 33.0);
    glVertex3f(-25.0, -8.0,  33.0);
    glVertex3f(-40.0, -12.0,  33.0);
    glEnd();
     //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.9, 3.0, 33.0);
    glVertex3f(-25.0, 3.0, 33.0);
    glVertex3f(-25.0, -5.0,  33.0);
    glVertex3f(-39.9, -7.0,  33.0);
    glEnd();

    //mesin bawah kanan
	glBegin(GL_QUADS);
   glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 3.0, 19.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, -5.0,19.0);
    glVertex3f(-40.0, -7.0,19.0);
    glEnd();
     //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.9, 3.0, 19.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, -8.0,19.0);
    glVertex3f(-39.9, -12.0,19.0);
    glEnd();

    //mesin bawah tutup atas
	glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-40.0, 3.0, 19.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, 3.0,33.0);
    glVertex3f(-40.0, 3.0,33.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.9, 3.0, 19.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, 3.0,33.0);
    glVertex3f(-39.9, 3.0,33.0);
    glEnd();

    //mesin bawah belakang
	glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-25.0, 3.0, 33.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, -5.0,19.0);
    glVertex3f(-25.0, -5.0,33.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-25.0, 3.0, 33.0);
    glVertex3f(-25.0, 3.0, 19.0);
    glVertex3f(-25.0, -5.0,19.0);
    glVertex3f(-25.0, -5.0,33.0);
    glEnd();

    //mesin atas kiri
	glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-39.0, 6.0, 30.0);
    glVertex3f(-35.0, 7.0, 30.0);
    glVertex3f(-35.0, 3.0, 30.0);
    glVertex3f(-39.0, 3.0, 30.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.0, 6.0, 30.0);
    glVertex3f(-35.0, 7.0, 30.0);
    glVertex3f(-35.0, 3.0, 30.0);
    glVertex3f(-39.0, 3.0, 30.0);
    glEnd();

    //mesin atas kanan
	glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-39.0, 6.0, 22.0);
    glVertex3f(-35.0, 7.0, 22.0);
    glVertex3f(-35.0, 3.0, 22.0);
    glVertex3f(-39.0, 3.0, 22.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.0, 6.0, 22.0);
    glVertex3f(-35.0, 7.0, 22.0);
    glVertex3f(-35.0, 3.0, 22.0);
    glVertex3f(-39.0, 3.0, 22.0);
    glEnd();

    //mesin atas tutup depan
	glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-39.0, 6.0, 22.0);
    glVertex3f(-39.0, 6.0, 30.0);
    glVertex3f(-39.0, 2.0, 30.0);
    glVertex3f(-39.0, 2.0, 22.0);
    glEnd();

    //mesin atas tutup belakang
	glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-35.0, 7.0, 22.0);
    glVertex3f(-35.0, 7.0, 30.0);
    glVertex3f(-35.0, 3.0, 30.0);
    glVertex3f(-35.0, 3.0, 22.0);
    glEnd();

    //tutup atas mein atas
	glBegin(GL_QUADS);
    glColor3ub(240, 230, 140);
    glVertex3f(-39.0, 6.0, 22.0);
    glVertex3f(-39.0, 6.0, 30.0);
    glVertex3f(-35.0, 7.0, 30.0);
    glVertex3f(-35.0, 7.0, 22.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-39.0, 6.0, 22.0);
    glVertex3f(-39.0, 6.0, 30.0);
    glVertex3f(-35.0, 7.0, 30.0);
    glVertex3f(-35.0, 7.0, 22.0);
    glEnd();

//atap e
	//payung
	glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-36.0, 16.0, 19.0);
    glVertex3f(-24.0, 16.0, 19.0);
    glVertex3f(-24.0, 16.0,33.0);
    glVertex3f(-36.0, 16.0,33.0);
    glEnd();

    //payung kiri
	glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-36.0, 15.0, 33.0);
    glVertex3f(-24.0, 15.0, 33.0);
    glVertex3f(-24.0, 16.0, 33.0);
    glVertex3f(-36.0, 16.0, 33.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-36.0, 15.0, 33.0);
    glVertex3f(-24.0, 15.0, 33.0);
    glVertex3f(-24.0, 16.0, 33.0);
    glVertex3f(-36.0, 16.0, 33.0);
    glEnd();

    //payung kanan
	glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-36.0, 15.0, 19.0);
    glVertex3f(-24.0, 15.0, 19.0);
    glVertex3f(-24.0, 16.0, 19.0);
    glVertex3f(-36.0, 16.0, 19.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-36.0, 15.0, 19.0);
    glVertex3f(-24.0, 15.0, 19.0);
    glVertex3f(-24.0, 16.0, 19.0);
    glVertex3f(-36.0, 16.0, 19.0);
    glEnd();

    //payung depan
	glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-36.0, 15.0, 33.0);
    glVertex3f(-36.0, 15.0, 19.0);
    glVertex3f(-36.0, 16.0, 19.0);
    glVertex3f(-36.0, 16.0, 33.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-36.0, 15.0, 33.0);
    glVertex3f(-36.0, 15.0, 19.0);
    glVertex3f(-36.0, 16.0, 19.0);
    glVertex3f(-36.0, 16.0, 33.0);
    glEnd();

    //payung belakang
	glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-24.0, 15.0, 33.0);
    glVertex3f(-24.0, 15.0, 19.0);
    glVertex3f(-24.0, 16.0, 19.0);
    glVertex3f(-24.0, 16.0, 33.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-24.0, 15.0, 33.0);
    glVertex3f(-24.0, 15.0, 19.0);
    glVertex3f(-24.0, 16.0, 19.0);
    glVertex3f(-24.0, 16.0, 33.0);
    glEnd();

//cagak atap
	//kiri depan
	glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-34.0, 3.0, 31.0);
    glVertex3f(-34.0, 3.0, 30.5);
    glVertex3f(-34.0, 16.0, 30.5);
    glVertex3f(-34.0, 16.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 31.0);
    glVertex3f(-33.5, 3.0, 30.5);
    glVertex3f(-33.5, 16.0, 30.5);
    glVertex3f(-33.5, 16.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 30.5);
    glVertex3f(-34.0, 3.0, 30.5);
    glVertex3f(-34.0, 16.0, 30.5);
    glVertex3f(-33.5, 16.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 31.0);
    glVertex3f(-34.0, 3.0, 31.0);
    glVertex3f(-34.0, 16.0, 31.0);
    glVertex3f(-33.5, 16.0, 31.0);
    glEnd();


    //kiri belakang
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 31.0);
    glVertex3f(-26.5, 3.0, 30.5);
    glVertex3f(-26.5, 16.0, 30.5);
    glVertex3f(-26.5, 16.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.0, 3.0, 31.0);
    glVertex3f(-26.0, 3.0, 30.5);
    glVertex3f(-26.0, 16.0, 30.5);
    glVertex3f(-26.0, 16.0, 31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 30.5);
    glVertex3f(-26.0, 3.0, 30.5);
    glVertex3f(-26.0, 16.0, 30.5);
    glVertex3f(-26.5, 16.0, 30.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 31.0);
    glVertex3f(-26.0, 3.0, 31.0);
    glVertex3f(-26.0, 16.0, 31.0);
    glVertex3f(-26.5, 16.0, 31.0);
    glEnd();

    //kanan depan
	glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-34.0, 3.0, 21.0);
    glVertex3f(-34.0, 3.0, 21.5);
    glVertex3f(-34.0, 16.0, 21.5);
    glVertex3f(-34.0, 16.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 21.0);
    glVertex3f(-33.5, 3.0, 21.5);
    glVertex3f(-33.5, 16.0, 21.5);
    glVertex3f(-33.5, 16.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 21.5);
    glVertex3f(-34.0, 3.0, 21.5);
    glVertex3f(-34.0, 16.0, 21.5);
    glVertex3f(-33.5, 16.0, 21.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-33.5, 3.0, 21.0);
    glVertex3f(-34.0, 3.0, 21.10);
    glVertex3f(-34.0, 16.0, 21.0);
    glVertex3f(-33.5, 16.0, 21.0);
    glEnd();

    //kanan belakang
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 21.0);
    glVertex3f(-26.5, 3.0, 21.5);
    glVertex3f(-26.5, 16.0, 21.5);
    glVertex3f(-26.5, 16.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.0, 3.0, 21.0);
    glVertex3f(-26.0, 3.0, 21.5);
    glVertex3f(-26.0, 16.0, 21.5);
    glVertex3f(-26.0, 16.0, 21.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 21.5);
    glVertex3f(-26.0, 3.0, 21.5);
    glVertex3f(-26.0, 16.0, 21.5);
    glVertex3f(-26.5, 16.0, 21.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(-26.5, 3.0, 21.0);
    glVertex3f(-26.0, 3.0, 21.0);
    glVertex3f(-26.0, 16.0, 21.0);
    glVertex3f(-26.5, 16.0, 21.0);
    glEnd();

//alat belakang ekor
	//samping depan nempel bawah
	glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-25.0, -7.0, 12.0);
    glVertex3f(-25.0, -7.0, 40.0);
    glVertex3f(-25.0, -10.96, 40.0);
    glVertex3f(-25.0, -10.96, 12.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-25.0, -7.0, 12.0);
    glVertex3f(-25.0, -7.0, 40.0);
    glVertex3f(-25.0, -10.96, 40.0);
    glVertex3f(-25.0, -10.96, 12.0);
    glEnd();

    //alas
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex3f(-25.0, -10.86, 12.0);
    glVertex3f(-25.0, -10.86, 40.0);
    glVertex3f(-19.0, -10.86, 40.0);
    glVertex3f(-19.0, -10.86, 12.0);
    glEnd();


    //pertengahan alas
    glBegin(GL_QUADS);
    glColor3ub(75, 0, 130);
    glVertex3f(-25.0, -9.86, 12.0);
    glVertex3f(-25.0, -9.86, 17.0);
    glVertex3f(-22.0, -9.86, 17.0);
    glVertex3f(-22.0, -9.86, 12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 0, 130);
    glVertex3f(-25.0, -9.86, 18.0);
    glVertex3f(-25.0, -9.86, 23.0);
    glVertex3f(-22.0, -9.86, 23.0);
    glVertex3f(-22.0, -9.86, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 0, 130);
    glVertex3f(-25.0, -9.86, 24.0);
    glVertex3f(-25.0, -9.86, 29.0);
    glVertex3f(-22.0, -9.86, 29.0);
    glVertex3f(-22.0, -9.86, 24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 0, 130);
    glVertex3f(-25.0, -9.86, 30.0);
    glVertex3f(-25.0, -9.86, 35.0);
    glVertex3f(-22.0, -9.86, 35.0);
    glVertex3f(-22.0, -9.86, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 0, 130);
    glVertex3f(-25.0, -9.86, 36.0);
    glVertex3f(-25.0, -9.86, 40.0);
    glVertex3f(-22.0, -9.86, 40.0);
    glVertex3f(-22.0, -9.86, 36.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-25.0, -7.0, 40);
    glVertex3f(-22.0, -7.0, 40.0);
    glVertex3f(-19.0, -10.96, 40.0);
    glVertex3f(-25.0, -10.96, 40.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-25.0, -7.0, 40);
    glVertex3f(-22.0, -7.0, 40.0);
    glVertex3f(-19.0, -10.96, 40.0);
    glVertex3f(-25.0, -10.96, 40.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3ub(184, 134, 11);
    glVertex3f(-25.0, -7.0, 12.0);
    glVertex3f(-22.0, -7.0, 12.0);
    glVertex3f(-19.0, -10.96, 12.0);
    glVertex3f(-25.0, -10.96, 12.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(-25.0, -7.0, 12.0);
    glVertex3f(-22.0, -7.0, 12.0);
    glVertex3f(-19.0, -10.96, 12.0);
    glVertex3f(-25.0, -10.96, 12.0);
    glEnd();

//kursi alat berat
	//bantalan
	glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-31.0, 6.0, 24.0);
    glVertex3f(-28.0, 6.0, 24.0);
    glVertex3f(-28.0, 6.0,28.0);
    glVertex3f(-31.0, 6.0,28.0);
    glEnd();

	glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-31.0, 5.5, 24.0);
    glVertex3f(-28.0, 5.5, 24.0);
    glVertex3f(-28.0, 5.5,28.0);
    glVertex3f(-31.0, 5.5,28.0);
    glEnd();
    //tutup bantalan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-31.0, 6.0, 24.0);
    glVertex3f(-28.0, 6.0, 24.0);
    glVertex3f(-28.0, 5.5, 24.0);
    glVertex3f(-31.0, 5.5, 24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-31.0, 6.0, 28.0);
    glVertex3f(-28.0, 6.0, 28.0);
    glVertex3f(-28.0, 5.5, 28.0);
    glVertex3f(-31.0, 5.5, 28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-31.0, 6.0, 24.0);
    glVertex3f(-31.0, 5.5, 24.0);
    glVertex3f(-31.0, 5.5,28.0);
    glVertex3f(-31.0, 6.0,28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.0, 6.0, 24.0);
    glVertex3f(-28.0, 5.5, 24.0);
    glVertex3f(-28.0, 5.5,28.0);
    glVertex3f(-28.0, 6.0,28.0);
    glEnd();

    //kaki kiri kursi
    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-30.0, 5.5, 27.5);
    glVertex3f(-29.0, 5.5, 27.5);
    glVertex3f(-29.0, 3.0 ,27.5);
    glVertex3f(-30.0, 3.0 ,27.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-30.0, 5.5, 24.5);
    glVertex3f(-29.0, 5.5, 24.5);
    glVertex3f(-29.0, 3.0 ,24.5);
    glVertex3f(-30.0, 3.0 ,24.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-30.0, 5.5, 24.5);
    glVertex3f(-30.0, 5.5, 27.5);
    glVertex3f(-30.0, 3.0 ,27.5);
    glVertex3f(-30.0, 3.0 ,24.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(-29.0, 5.5, 24.5);
    glVertex3f(-29.0, 5.5, 27.5);
    glVertex3f(-29.0, 3.0 ,27.5);
    glVertex3f(-29.0, 3.0 ,24.5);
    glEnd();

    //senderan
    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-28.0, 6.0, 24.0);
    glVertex3f(-28.0, 10.0, 24.0);
    glVertex3f(-28.0, 10.0,28.0);
    glVertex3f(-28.0, 6.0,28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(253, 215, 3);
    glVertex3f(-28.3, 6.0, 24.0);
    glVertex3f(-28.3, 10.0, 24.0);
    glVertex3f(-28.3, 10.0,28.0);
    glVertex3f(-28.3, 6.0,28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.3, 10.0, 24.0);
    glVertex3f(-28.0, 10.0, 24.0);
    glVertex3f(-28.0, 10.0,28.0);
    glVertex3f(-28.3, 10.0,28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.3, 10.0, 28.0);
    glVertex3f(-28.0, 10.0, 28.0);
    glVertex3f(-28.0, 6.0,28.0);
    glVertex3f(-28.3, 6.0,28.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-28.3, 10.0, 24.0);
    glVertex3f(-28.0, 10.0, 24.0);
    glVertex3f(-28.0, 6.0,  24.0);
    glVertex3f(-28.3, 6.0,  24.0);
    glEnd();
}
void dasar(void)
{
	//dasar
    glBegin(GL_QUADS);
    glColor3ub(189, 183, 107);
    glVertex3f(-60.0, -12.0, 52.0);
    glVertex3f(60.0, -12.0, 52.0);
    glVertex3f(60.0, -12.0, -60.0);
    glVertex3f(-60.0, -12.0, -60.0);
    glEnd();

//Jalan
	//trotoar depan
	glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, -11.0, 45.0);
    glVertex3f(60.0,-11.0, 45.0);
    glVertex3f(60.0, -11.0, 40.0);
    glVertex3f(-60.0, -11.0, 40.0);
    glEnd();
    //==//
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-60.0, -11.0, 45.0);
    glVertex3f(60.0,-11.0, 45.0);
    glVertex3f(60.0, -11.0, 40.0);
    glVertex3f(-60.0, -11.0, 40.0);
    glEnd();

    //trotoar belakang
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0,-11.0, 12.0);
    glVertex3f(60.0, -11.0, 12.0);
    glVertex3f(60.0, -11.0, 7.0);
    glVertex3f(-60.0, -11.0, 7.0);
    glEnd();
    //==//
    glBegin(GL_LINE_LOOP);
    glColor3ub(69, 43, 16);
    glVertex3f(-60.0,-11.0, 12.0);
    glVertex3f(60.0, -11.0, 12.0);
    glVertex3f(60.0, -11.0, 7.0);
    glVertex3f(-60.0, -11.0, 7.0);
    glEnd();

    //jalan raya
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-60.0, -11.98, 40.0);
    glVertex3f(60.0, -11.98, 40.0);
    glVertex3f(60.0, -11.98, 12.0);
    glVertex3f(-60.0, -11.98, 12.0);
    glEnd();

    //Garis tngah jalan raya
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(45.0, -11.88, 26.0);
    glVertex3f(60.0, -11.88, 26.0);
    glVertex3f(60.0, -11.88, 24.0);
    glVertex3f(45.0, -11.88, 24.0);
    glEnd();
    //Garis tngah jalan raya
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(20.0, -11.88, 26.0);
    glVertex3f(35.0, -11.88, 26.0);
    glVertex3f(35.0, -11.88, 24.0);
    glVertex3f(20.0, -11.88, 24.0);
    glEnd();
     //Garis tngah jalan raya
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(-5.0, -11.88, 26.0);
    glVertex3f(10.0, -11.88, 26.0);
    glVertex3f(10.0, -11.88, 24.0);
    glVertex3f(-5.0, -11.88, 24.0);
    glEnd();
    //Garis tngah jalan raya
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(-30.0, -11.88, 26.0);
    glVertex3f(-15.0, -11.88, 26.0);
    glVertex3f(-15.0, -11.88, 24.0);
    glVertex3f(-30.0, -11.88, 24.0);
    glEnd();

    //Garis tngah jalan raya
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(-55.0, -11.88, 26.0);
    glVertex3f(-40.0, -11.88, 26.0);
    glVertex3f(-40.0, -11.88, 24.0);
    glVertex3f(-55.0, -11.88, 24.0);
    glEnd();

    //depan trotoar
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, -11.0, 40.0);
    glVertex3f(60.0,-11.0, 40.0);
    glVertex3f(60.0, -12.0, 40.0);
    glVertex3f(-60.0, -12.0, 40.0);
    glEnd();

    //depan trotoar belakang
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, -11.0, 12.0);
    glVertex3f(60.0,-11.0, 12.0);
    glVertex3f(60.0, -12.0, 12.0);
    glVertex3f(-60.0, -12.0, 12.0);
    glEnd();

    //belakang trotoar depan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, -11.0, 45.0);
    glVertex3f(60.0,-11.0, 45.0);
    glVertex3f(60.0, -12.0, 45.0);
    glVertex3f(-60.0, -12.0, 45.0);
    glEnd();

    //belakang trotoar belakang
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, -11.0, 7.0);
    glVertex3f(60.0,-11.0, 7.0);
    glVertex3f(60.0, -12.0, 7.0);
    glVertex3f(-60.0, -12.0, 7.0);
    glEnd();


//halte pertama depan rumah
	//alas halte
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(18.0, -11.0, 52.0);
    glVertex3f(18.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(18.0, -11.0, 52.0);
    glVertex3f(18.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(18.0, -12.0, 52.0);
    glVertex3f(18.0, -12.0, 45.0);
    glVertex3f(18.0, -11.0, 45.0);
    glVertex3f(18.0, -11.0, 52.0);
    glEnd();
     //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glColor3ub(128, 128, 128);
    glVertex3f(18.0, -12.0, 52.0);
    glVertex3f(18.0, -12.0, 45.0);
    glVertex3f(18.0, -11.0, 45.0);
    glVertex3f(18.0, -11.0, 52.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(53.0, -12.0, 52.0);
    glVertex3f(53.0, -12.0, 45.0);
    glVertex3f(53.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glColor3ub(128, 128, 128);
    glColor3ub(128, 128, 128);
    glVertex3f(53.0, -12.0, 52.0);
    glVertex3f(53.0, -12.0, 45.0);
    glVertex3f(53.0, -11.0, 45.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(18.0, -11.0, 52.0);
    glVertex3f(18.0, -12.0, 52.0);
    glVertex3f(53.0, -12.0, 52.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(18.0, -11.0, 52.0);
    glVertex3f(18.0, -12.0, 52.0);
    glVertex3f(53.0, -12.0, 52.0);
    glVertex3f(53.0, -11.0, 52.0);
    glEnd();



    //atap
    glBegin(GL_QUADS);
    glColor3ub(248, 28, 25);
    glVertex3f(18.0, 10.0, 52.0);
    glVertex3f(18.0, 12.0, 43.0);
    glVertex3f(53.0, 12.0, 43.0);
    glVertex3f(53.0, 10.0, 52.0);
    glEnd();

    //atap bawah
    glBegin(GL_QUADS);
    glColor3ub(248, 28, 25);
    glVertex3f(18.0, 9.0,  52.0);
    glVertex3f(18.0, 11.0, 43.0);
    glVertex3f(53.0, 11.0, 43.0);
    glVertex3f(53.0, 9.0,  52.0);
    glEnd();
    //atap tutup depan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(18.0, 11.0,  43.0);
    glVertex3f(18.0, 12.0,  43.0);
    glVertex3f(53.0, 12.0,  43.0);
    glVertex3f(53.0, 11.0,  43.0);
    glEnd();
    //atap tutup belakang
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(18.0, 9.0,  52.0);
    glVertex3f(18.0, 10.0, 52.0);
    glVertex3f(53.0, 10.0, 52.0);
    glVertex3f(53.0, 9.0,  52.0);
    glEnd();
    //atap tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(53.0, 9.0,  52.0);
    glVertex3f(53.0, 10.0, 52.0);
    glVertex3f(53.0, 12.0, 43.0);
    glVertex3f(53.0, 11.0, 43.0);
    glEnd();
    //atap tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(18.0, 9.0,  52.0);
    glVertex3f(18.0, 10.0, 52.0);
    glVertex3f(18.0, 12.0, 43.0);
    glVertex3f(18.0, 11.0, 43.0);
    glEnd();

    //kursi bawah
    glBegin(GL_QUADS);
    glColor3ub(248, 28, 25);
    glVertex3f(20.0, -5.0, 50.0);
    glVertex3f(20.0, -5.0, 45.0);
    glVertex3f(51.0, -5.0, 45.0);
    glVertex3f(51.0, -5.0, 50.0);
    glEnd();
    //kursi atas
    glBegin(GL_QUADS);
    glColor3ub(248, 28, 25);
    glVertex3f(20.0, -4.0, 50.0);
    glVertex3f(20.0, -4.0, 45.0);
    glVertex3f(51.0, -4.0, 45.0);
    glVertex3f(51.0, -4.0, 50.0);
    glEnd();
    //tutup kursi depan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, -5.0, 45.0);
    glVertex3f(20.0, -4.0, 45.0);
    glVertex3f(51.0, -4.0, 45.0);
    glVertex3f(51.0, -5.0, 45.0);
    glEnd();
    //tutup kursi belakang
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, -5.0, 50.0);
    glVertex3f(20.0, -4.0, 50.0);
    glVertex3f(51.0, -4.0, 50.0);
    glVertex3f(51.0, -5.0, 50.0);
    glEnd();

    //tutup kursi kiri
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, -5.0, 50.0);
    glVertex3f(20.0, -4.0, 50.0);
    glVertex3f(20.0, -4.0, 45.0);
    glVertex3f(20.0, -5.0, 45.0);
    glEnd();
    //tutup kursi kanan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(51.0, -5.0, 50.0);
    glVertex3f(51.0, -4.0, 50.0);
    glVertex3f(51.0, -4.0, 45.0);
    glVertex3f(51.0, -5.0, 45.0);
    glEnd();

    //tiang pondasi belakang kanan halte
    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 50.1);
    glVertex3f(51.1, 9.0, 50.1);
    glVertex3f(51.1, 9.0, 49.5);
    glVertex3f(51.1, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(50.5, -12.0, 50.1);
    glVertex3f(50.5, 9.0, 50.1);
    glVertex3f(50.5, 9.0, 49.5);
    glVertex3f(50.5, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 49.5);
    glVertex3f(51.1, 9.0, 49.5);
    glVertex3f(50.5, 9.0, 49.5);
    glVertex3f(50.5, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 50.1);
    glVertex3f(51.1, 9.0, 50.1);
    glVertex3f(50.5, 9.0, 50.1);
    glVertex3f(50.5, -12.0, 50.1);
    glEnd();

    //tiang pondasi depan kanan halte
     glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 45.4);
    glVertex3f(51.1, 11.0, 45.4);
    glVertex3f(51.1, 11.0, 44.9);
    glVertex3f(51.1, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(50.5, -12.0, 45.4);
    glVertex3f(50.5, 11.0, 45.4);
    glVertex3f(50.5, 11.0, 44.9);
    glVertex3f(50.5, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 44.9);
    glVertex3f(51.1, 11.0, 44.9);
    glVertex3f(50.5, 11.0, 44.9);
    glVertex3f(50.5, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(51.1, -12.0, 45.4);
    glVertex3f(51.1, 11.0, 45.4);
    glVertex3f(50.5, 11.0, 45.4);
    glVertex3f(50.5, -12.0, 45.4);
    glEnd();

    //tiang pondasi belakang kiri halte
    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 50.1);
    glVertex3f(20.4, 9.0, 50.1);
    glVertex3f(20.4, 9.0, 49.5);
    glVertex3f(20.4, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(19.9, -12.0, 50.1);
    glVertex3f(19.9, 9.0, 50.1);
    glVertex3f(19.9, 9.0, 49.5);
    glVertex3f(19.9, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 49.5);
    glVertex3f(20.4, 9.0, 49.5);
    glVertex3f(19.9, 9.0, 49.5);
    glVertex3f(19.9, -12.0, 49.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 50.1);
    glVertex3f(20.4, 9.0, 50.1);
    glVertex3f(19.9, 9.0, 50.1);
    glVertex3f(19.9, -12.0, 50.1);
    glEnd();

    //tiang pondasi depan kiri halte
     glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 45.4);
    glVertex3f(20.4, 11.0, 45.4);
    glVertex3f(20.4, 11.0, 44.9);
    glVertex3f(20.4, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(19.9, -12.0, 45.4);
    glVertex3f(19.9, 11.0, 45.4);
    glVertex3f(19.9, 11.0, 44.9);
    glVertex3f(19.9, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 44.9);
    glVertex3f(20.4, 11.0, 44.9);
    glVertex3f(19.9, 11.0, 44.9);
    glVertex3f(19.9, -12.0, 44.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 165, 3);
    glVertex3f(20.4, -12.0, 45.4);
    glVertex3f(20.4, 11.0, 45.4);
    glVertex3f(19.9, 11.0, 45.4);
    glVertex3f(19.9, -12.0, 45.4);
    glEnd();

	//tutup senderan belakang
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(19.8, -2.0, 50.2);
    glVertex3f(19.8, 3.0, 50.2);
    glVertex3f(51.2, 3.0, 50.2);
    glVertex3f(51.2, -2.0, 50.2);
    glEnd();
     //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(19.8, -2.0, 50.2);
    glVertex3f(19.8, 3.0, 50.2);
    glVertex3f(51.2, 3.0, 50.2);
    glVertex3f(51.2, -2.0, 50.2);
    glEnd();

    //tutup senderan kanan
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(51.2, -2.0, 50.2);
    glVertex3f(51.2, 3.0, 50.2);
    glVertex3f(51.2, 3.0, 44.8);
    glVertex3f(51.2, -2.0, 44.8);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(51.2, -2.0, 50.2);
    glVertex3f(51.2, 3.0, 50.2);
    glVertex3f(51.2, 3.0, 44.8);
    glVertex3f(51.2, -2.0, 44.8);
    glEnd();

    //tutup senderan kiri
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(19.8, -2.0, 50.2);
    glVertex3f(19.8, 3.0, 50.2);
    glVertex3f(19.8, 3.0, 44.8);
    glVertex3f(19.8, -2.0, 44.8);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(19.8, -2.0, 50.2);
    glVertex3f(19.8, 3.0, 50.2);
    glVertex3f(19.8, 3.0, 44.8);
    glVertex3f(19.8, -2.0, 44.8);
    glEnd();



//Tiang Listrik depan rumah
	//tiang kanan
	glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 7.0);
    glVertex3f(56.0,25.0, 7.0);
    glVertex3f(56.0, -12.0, 7.0);
    glVertex3f(55.0, -12.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 6.0);
    glVertex3f(56.0, 25.0, 6.0);
    glVertex3f(56.0, -12.0, 6.0);
    glVertex3f(55.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(56.0, 25.0, 6.0);
    glVertex3f(56.0, 25.0, 7.0);
    glVertex3f(56.0, -12.0, 7.0);
    glVertex3f(56.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 6.0);
    glVertex3f(55.0, 25.0, 7.0);
    glVertex3f(55.0, -12.0, 7.0);
    glVertex3f(55.0, -12.0, 6.0);
    glEnd();

	//tiang 2 dari kanan
	glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 7.0);
    glVertex3f(16.0,25.0, 7.0);
    glVertex3f(16.0, -12.0, 7.0);
    glVertex3f(15.0, -12.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 6.0);
    glVertex3f(16.0, 25.0, 6.0);
    glVertex3f(16.0, -12.0, 6.0);
    glVertex3f(15.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(16.0, 25.0, 6.0);
    glVertex3f(16.0, 25.0, 7.0);
    glVertex3f(16.0, -12.0, 7.0);
    glVertex3f(16.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 6.0);
    glVertex3f(15.0, 25.0, 7.0);
    glVertex3f(15.0, -12.0, 7.0);
    glVertex3f(15.0, -12.0, 6.0);
    glEnd();

    // 3 dari kanan
    glBegin(GL_QUADS);
  	glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 7.0);
    glVertex3f(-26.0,25.0, 7.0);
    glVertex3f(-26.0, -12.0, 7.0);
    glVertex3f(-25.0, -12.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 6.0);
    glVertex3f(-26.0, 25.0, 6.0);
    glVertex3f(-26.0, -12.0, 6.0);
    glVertex3f(-25.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-26.0, 25.0, 6.0);
    glVertex3f(-26.0, 25.0, 7.0);
    glVertex3f(-26.0, -12.0, 7.0);
    glVertex3f(-26.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 6.0);
    glVertex3f(-25.0, 25.0, 7.0);
    glVertex3f(-25.0, -12.0, 7.0);
    glVertex3f(-25.0, -12.0, 6.0);
    glEnd();

    //Tiang 4 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 7.0);
    glVertex3f(-60.0,25.0, 7.0);
    glVertex3f(-60.0, -12.0, 7.0);
    glVertex3f(-59.0, -12.0, 7.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 6.0);
    glVertex3f(-59.0, 25.0, 6.0);
    glVertex3f(-59.0, -12.0, 6.0);
    glVertex3f(-59.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-60.0, 25.0, 6.0);
    glVertex3f(-60.0, 25.0, 7.0);
    glVertex3f(-60.0, -12.0, 7.0);
    glVertex3f(-60.0, -12.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 6.0);
    glVertex3f(-59.0, 25.0, 7.0);
    glVertex3f(-59.0, -12.0, 7.0);
    glVertex3f(-59.0, -12.0, 6.0);
    glEnd();

    //tiang melintang kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 23.0, 1.0);
    glVertex3f(-59.0, 23.0, 12.0);
    glVertex3f(-59.0, 24.0, 12.0);
    glVertex3f(-59.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, 23.0, 1.0);
    glVertex3f(-60.0, 23.0, 12.0);
    glVertex3f(-60.0, 24.0, 12.0);
    glVertex3f(-60.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 23.0, 1.0);
    glVertex3f(-59.0, 23.0, 12.0);
    glVertex3f(-60.0, 23.0, 12.0);
    glVertex3f(-60.0, 23.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 24.0, 1.0);
    glVertex3f(-59.0, 24.0, 12.0);
    glVertex3f(-60.0, 24.0, 12.0);
    glVertex3f(-60.0, 24.0, 1.0);
    glEnd();

    //tiang 2 melintang kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 20.0, 1.0);
    glVertex3f(-59.0, 20.0, 12.0);
    glVertex3f(-59.0, 21.0, 12.0);
    glVertex3f(-59.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, 20.0, 1.0);
    glVertex3f(-60.0, 20.0, 12.0);
    glVertex3f(-60.0, 21.0, 12.0);
    glVertex3f(-60.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 21.0, 1.0);
    glVertex3f(-59.0, 21.0, 12.0);
    glVertex3f(-60.0, 21.0, 12.0);
    glVertex3f(-60.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 20.0, 1.0);
    glVertex3f(-59.0, 20.0, 12.0);
    glVertex3f(-60.0, 20.0, 12.0);
    glVertex3f(-60.0, 20.0, 1.0);
    glEnd();

    //tiang melintang kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 23.0, 1.0);
    glVertex3f(55.0, 23.0, 12.0);
    glVertex3f(55.0, 24.0, 12.0);
    glVertex3f(55.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 23.0, 1.0);
    glVertex3f(56.0, 23.0, 12.0);
    glVertex3f(56.0, 24.0, 12.0);
    glVertex3f(56.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 23.0, 1.0);
    glVertex3f(55.0, 23.0, 12.0);
    glVertex3f(56.0, 23.0, 12.0);
    glVertex3f(56.0, 23.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 24.0, 1.0);
    glVertex3f(55.0, 24.0, 12.0);
    glVertex3f(56.0, 24.0, 12.0);
    glVertex3f(56.0, 24.0, 1.0);
    glEnd();

	//tiang 2 melintang kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 20.0, 1.0);
    glVertex3f(55.0, 20.0, 12.0);
    glVertex3f(55.0, 21.0, 12.0);
    glVertex3f(55.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 20.0, 1.0);
    glVertex3f(56.0, 20.0, 12.0);
    glVertex3f(56.0, 21.0, 12.0);
    glVertex3f(56.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 21.0, 1.0);
    glVertex3f(55.0, 21.0, 12.0);
    glVertex3f(56.0, 21.0, 12.0);
    glVertex3f(56.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 20.0, 1.0);
    glVertex3f(55.0, 20.0, 12.0);
    glVertex3f(56.0, 20.0, 12.0);
    glVertex3f(56.0, 20.0, 1.0);
    glEnd();

    //tiang 2 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 23.0, 1.0);
    glVertex3f(15.0, 23.0, 12.0);
    glVertex3f(15.0, 24.0, 12.0);
    glVertex3f(15.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(16.0, 23.0, 1.0);
    glVertex3f(16.0, 23.0, 12.0);
    glVertex3f(16.0, 24.0, 12.0);
    glVertex3f(16.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 23.0, 1.0);
    glVertex3f(15.0, 23.0, 12.0);
    glVertex3f(16.0, 23.0, 12.0);
    glVertex3f(16.0, 23.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 24.0, 1.0);
    glVertex3f(15.0, 24.0, 12.0);
    glVertex3f(16.0, 24.0, 12.0);
    glVertex3f(16.0, 24.0, 1.0);
    glEnd();

	//tiang 2 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 20.0, 1.0);
    glVertex3f(15.0, 20.0, 12.0);
    glVertex3f(15.0, 21.0, 12.0);
    glVertex3f(15.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(16.0, 20.0, 1.0);
    glVertex3f(16.0, 20.0, 12.0);
    glVertex3f(16.0, 21.0, 12.0);
    glVertex3f(16.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 21.0, 1.0);
    glVertex3f(15.0, 21.0, 12.0);
    glVertex3f(16.0, 21.0, 12.0);
    glVertex3f(16.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 20.0, 1.0);
    glVertex3f(15.0, 20.0, 12.0);
    glVertex3f(16.0, 20.0, 12.0);
    glVertex3f(16.0, 20.0, 1.0);
    glEnd();

    //tiang 3 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 23.0, 1.0);
    glVertex3f(-25.0, 23.0, 12.0);
    glVertex3f(-25.0, 24.0, 12.0);
    glVertex3f(-25.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-26.0, 23.0, 1.0);
    glVertex3f(-26.0, 23.0, 12.0);
    glVertex3f(-26.0, 24.0, 12.0);
    glVertex3f(-26.0, 24.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 23.0, 1.0);
    glVertex3f(-25.0, 23.0, 12.0);
    glVertex3f(-26.0, 23.0, 12.0);
    glVertex3f(-26.0, 23.0, 1.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 24.0, 1.0);
    glVertex3f(-25.0, 24.0, 12.0);
    glVertex3f(-26.0, 24.0, 12.0);
    glVertex3f(-26.0, 24.0, 1.0);
    glEnd();

	//tiang 3 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 20.0, 1.0);
    glVertex3f(-25.0, 20.0, 12.0);
    glVertex3f(-25.0, 21.0, 12.0);
    glVertex3f(-25.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-26.0, 20.0, 1.0);
    glVertex3f(-26.0, 20.0, 12.0);
    glVertex3f(-26.0, 21.0, 12.0);
    glVertex3f(-26.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 21.0, 1.0);
    glVertex3f(-25.0, 21.0, 12.0);
    glVertex3f(-26.0, 21.0, 12.0);
    glVertex3f(-26.0, 21.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 20.0, 1.0);
    glVertex3f(-25.0, 20.0, 12.0);
    glVertex3f(-26.0, 20.0, 12.0);
    glVertex3f(-26.0, 20.0, 1.0);
    glEnd();


//Tiang Listrik sebrang rumah
	//tiang kanan
	glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 46.0);
    glVertex3f(56.0,25.0, 46.0);
    glVertex3f(56.0, -12.0, 46.0);
    glVertex3f(55.0, -12.0, 46.0);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 45.0);
    glVertex3f(56.0, 25.0, 45.0);
    glVertex3f(56.0, -12.0, 45.0);
    glVertex3f(55.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(56.0, 25.0, 45.0);
    glVertex3f(56.0, 25.0, 46.0);
    glVertex3f(56.0, -12.0, 46.0);
    glVertex3f(56.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(55.0, 25.0, 45.0);
    glVertex3f(55.0, 25.0, 46.0);
    glVertex3f(55.0, -12.0, 46.0);
    glVertex3f(55.0, -12.0, 45.0);
    glEnd();

	//tiang 2 dari kanan
	glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 46.0);
    glVertex3f(16.0,25.0, 46.0);
    glVertex3f(16.0, -12.0, 46.0);
    glVertex3f(15.0, -12.0, 46.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 45.0);
    glVertex3f(16.0, 25.0, 45.0);
    glVertex3f(16.0, -12.0, 45.0);
    glVertex3f(15.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(16.0, 25.0, 45.0);
    glVertex3f(16.0, 25.0, 46.0);
    glVertex3f(16.0, -12.0, 46.0);
    glVertex3f(16.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(15.0, 25.0, 45.0);
    glVertex3f(15.0, 25.0, 46.0);
    glVertex3f(15.0, -12.0, 46.0);
    glVertex3f(15.0, -12.0, 45.0);
    glEnd();

    // 3 dari kanan
    glBegin(GL_QUADS);
  	glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 46.0);
    glVertex3f(-26.0,25.0, 46.0);
    glVertex3f(-26.0, -12.0, 46.0);
    glVertex3f(-25.0, -12.0, 46.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 45.0);
    glVertex3f(-26.0, 25.0, 45.0);
    glVertex3f(-26.0, -12.0, 45.0);
    glVertex3f(-25.0, -12.0,45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-26.0, 25.0, 45.0);
    glVertex3f(-26.0, 25.0, 46.0);
    glVertex3f(-26.0, -12.0, 46.0);
    glVertex3f(-26.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-25.0, 25.0, 45.0);
    glVertex3f(-25.0, 25.0, 46.0);
    glVertex3f(-25.0, -12.0, 46.0);
    glVertex3f(-25.0, -12.0, 45.0);
    glEnd();

    //Tiang 4 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 46.0);
    glVertex3f(-60.0,25.0, 46.0);
    glVertex3f(-60.0, -12.0, 46.0);
    glVertex3f(-59.0, -12.0, 46.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 45.0);
    glVertex3f(-59.0, 25.0, 45.0);
    glVertex3f(-59.0, -12.0, 45.0);
    glVertex3f(-59.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-60.0, 25.0, 45.0);
    glVertex3f(-60.0, 25.0, 46.0);
    glVertex3f(-60.0, -12.0, 46.0);
    glVertex3f(-60.0, -12.0, 45.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex3f(-59.0, 25.0, 45.0);
    glVertex3f(-59.0, 25.0, 46.0);
    glVertex3f(-59.0, -12.0, 46.0);
    glVertex3f(-59.0, -12.0, 45.0);
    glEnd();

    //tiang melintang kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 23.0, 40.0);
    glVertex3f(-59.0, 23.0, 50.0);
    glVertex3f(-59.0, 24.0, 50.0);
    glVertex3f(-59.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, 23.0, 40.0);
    glVertex3f(-60.0, 23.0, 50.0);
    glVertex3f(-60.0, 24.0, 50.0);
    glVertex3f(-60.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 23.0, 40.0);
    glVertex3f(-59.0, 23.0, 50.0);
    glVertex3f(-60.0, 23.0, 50.0);
    glVertex3f(-60.0, 23.0, 40.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 24.0, 40.0);
    glVertex3f(-59.0, 24.0, 50.0);
    glVertex3f(-60.0, 24.0, 50.0);
    glVertex3f(-60.0, 24.0, 40.0);
    glEnd();

    //tiang 2 melintang kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 20.0, 40.0);
    glVertex3f(-59.0, 20.0, 50.0);
    glVertex3f(-59.0, 21.0, 50.0);
    glVertex3f(-59.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-60.0, 20.0, 40.0);
    glVertex3f(-60.0, 20.0, 50.0);
    glVertex3f(-60.0, 21.0, 50.0);
    glVertex3f(-60.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 21.0, 40.0);
    glVertex3f(-59.0, 21.0, 50.0);
    glVertex3f(-60.0, 21.0, 50.0);
    glVertex3f(-60.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-59.0, 20.0, 40.0);
    glVertex3f(-59.0, 20.0, 50.0);
    glVertex3f(-60.0, 20.0, 50.0);
    glVertex3f(-60.0, 20.0, 40.0);
    glEnd();

    //tiang melintang kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 23.0, 40.0);
    glVertex3f(55.0, 23.0, 50.0);
    glVertex3f(55.0, 24.0, 50.0);
    glVertex3f(55.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 23.0, 40.0);
    glVertex3f(56.0, 23.0, 50.0);
    glVertex3f(56.0, 24.0, 50.0);
    glVertex3f(56.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 23.0, 40.0);
    glVertex3f(55.0, 23.0, 50.0);
    glVertex3f(56.0, 23.0, 50.0);
    glVertex3f(56.0, 23.0, 40.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 24.0, 40.0);
    glVertex3f(55.0, 24.0, 50.0);
    glVertex3f(56.0, 24.0, 50.0);
    glVertex3f(56.0, 24.0, 40.0);
    glEnd();

	//tiang 2 melintang kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 20.0, 40.0);
    glVertex3f(55.0, 20.0, 50.0);
    glVertex3f(55.0, 21.0, 50.0);
    glVertex3f(55.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 20.0, 40.0);
    glVertex3f(56.0, 20.0, 50.0);
    glVertex3f(56.0, 21.0, 50.0);
    glVertex3f(56.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 21.0, 40.0);
    glVertex3f(55.0, 21.0, 50.0);
    glVertex3f(56.0, 21.0, 50.0);
    glVertex3f(56.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 20.0, 40.0);
    glVertex3f(55.0, 20.0, 50.0);
    glVertex3f(56.0, 20.0, 50.0);
    glVertex3f(56.0, 20.0, 40.0);
    glEnd();

    //tiang 2 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 23.0, 40.0);
    glVertex3f(15.0, 23.0, 50.0);
    glVertex3f(15.0, 24.0, 50.0);
    glVertex3f(15.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(16.0, 23.0, 40.0);
    glVertex3f(16.0, 23.0, 50.0);
    glVertex3f(16.0, 24.0, 50.0);
    glVertex3f(16.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 23.0, 40.0);
    glVertex3f(15.0, 23.0, 50.0);
    glVertex3f(16.0, 23.0, 50.0);
    glVertex3f(16.0, 23.0, 40.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 24.0, 40.0);
    glVertex3f(15.0, 24.0, 50.0);
    glVertex3f(16.0, 24.0, 50.0);
    glVertex3f(16.0, 24.0, 40.0);
    glEnd();

	//tiang 2 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 20.0, 40.0);
    glVertex3f(15.0, 20.0, 50.0);
    glVertex3f(15.0, 21.0, 50.0);
    glVertex3f(15.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(16.0, 20.0, 40.0);
    glVertex3f(16.0, 20.0, 50.0);
    glVertex3f(16.0, 21.0, 50.0);
    glVertex3f(16.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 21.0, 40.0);
    glVertex3f(15.0, 21.0, 50.0);
    glVertex3f(16.0, 21.0, 50.0);
    glVertex3f(16.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(15.0, 20.0, 40.0);
    glVertex3f(15.0, 20.0, 50.0);
    glVertex3f(16.0, 20.0, 50.0);
    glVertex3f(16.0, 20.0, 40.0);
    glEnd();

    //tiang 3 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 23.0, 40.0);
    glVertex3f(-25.0, 23.0, 50.0);
    glVertex3f(-25.0, 24.0, 50.0);
    glVertex3f(-25.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-26.0, 23.0, 40.0);
    glVertex3f(-26.0, 23.0, 50.0);
    glVertex3f(-26.0, 24.0, 50.0);
    glVertex3f(-26.0, 24.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 23.0, 40.0);
    glVertex3f(-25.0, 23.0, 50.0);
    glVertex3f(-26.0, 23.0, 50.0);
    glVertex3f(-26.0, 23.0, 40.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 24.0, 40.0);
    glVertex3f(-25.0, 24.0, 50.0);
    glVertex3f(-26.0, 24.0, 50.0);
    glVertex3f(-26.0, 24.0, 40.0);
    glEnd();

	//tiang 3 melintang nomer 2 dari kanan
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 20.0, 40.0);
    glVertex3f(-25.0, 20.0, 50.0);
    glVertex3f(-25.0, 21.0, 50.0);
    glVertex3f(-25.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-26.0, 20.0, 40.0);
    glVertex3f(-26.0, 20.0, 50.0);
    glVertex3f(-26.0, 21.0, 50.0);
    glVertex3f(-26.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 21.0, 40.0);
    glVertex3f(-25.0, 21.0, 50.0);
    glVertex3f(-26.0, 21.0, 50.0);
    glVertex3f(-26.0, 21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-25.0, 20.0, 40.0);
    glVertex3f(-25.0, 20.0, 50.0);
    glVertex3f(-26.0, 20.0, 50.0);
    glVertex3f(-26.0, 20.0, 40.0);
    glEnd();

//Kabel listrik depan rumah
	//kabel belakang bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 2.0);
    glVertex3f(55.0, 21.3, 2.0);
    glVertex3f(55.0, 21.3, 1.7);
    glVertex3f(-60.0, 21.3, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 2.0);
    glVertex3f(55.0, 21.0, 2.0);
    glVertex3f(55.0, 21.0, 1.7);
    glVertex3f(-60.0, 21.0, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 2.0);
    glVertex3f(55.0, 21.0, 2.0);
    glVertex3f(55.0, 21.3, 1.7);
    glVertex3f(-60.0, 21.3, 1.7);
    glEnd();

    //kabel belakang atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 2.0);
    glVertex3f(55.0, 24.3, 2.0);
    glVertex3f(55.0, 24.3, 1.7);
    glVertex3f(-60.0, 24.3, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 2.0);
    glVertex3f(55.0, 24.0, 2.0);
    glVertex3f(55.0, 24.0, 1.7);
    glVertex3f(-60.0, 24.0, 1.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 2.0);
    glVertex3f(55.0, 24.0, 2.0);
    glVertex3f(55.0, 24.3, 1.7);
    glVertex3f(-60.0, 24.3, 1.7);
    glEnd();

	//kabel depan bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 11.3);
    glVertex3f(55.0, 21.3, 11.3);
    glVertex3f(55.0, 21.3, 11.0);
    glVertex3f(-60.0, 21.3, 11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 11.3);
    glVertex3f(55.0, 21.0, 11.3);
    glVertex3f(55.0, 21.0, 11.0);
    glVertex3f(-60.0, 21.0, 11.);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 11.3);
    glVertex3f(55.0, 21.0, 11.3);
    glVertex3f(55.0, 21.3, 11.0);
    glVertex3f(-60.0, 21.3, 11.0);
    glEnd();

    //kabel depan atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 11.3);
    glVertex3f(55.0, 24.3, 11.3);
    glVertex3f(55.0, 24.3, 11.0);
    glVertex3f(-60.0, 24.3, 11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 11.3);
    glVertex3f(55.0, 24.0, 11.3);
    glVertex3f(55.0, 24.0, 11.0);
    glVertex3f(-60.0, 24.0, 11.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 11.3);
    glVertex3f(55.0, 24.0, 11.3);
    glVertex3f(55.0, 24.3, 11.0);
    glVertex3f(-60.0, 24.3, 11.0);
    glEnd();

	//kabel tengah bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 5.8);
    glVertex3f(55.0, 21.3, 5.8);
    glVertex3f(55.0, 21.3, 5.5);
    glVertex3f(-60.0, 21.3, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 5.8);
    glVertex3f(55.0, 21.0, 5.8);
    glVertex3f(55.0, 21.0, 5.5);
    glVertex3f(-60.0, 21.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 5.8);
    glVertex3f(55.0, 21.0, 5.8);
    glVertex3f(55.0, 21.3, 5.5);
    glVertex3f(-60.0, 21.3, 5.5);
    glEnd();

    //kabel tengah atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 5.8);
    glVertex3f(55.0, 24.3, 5.8);
    glVertex3f(55.0, 24.3, 5.5);
    glVertex3f(-60.0, 24.3, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 5.8);
    glVertex3f(55.0, 24.0, 5.8);
    glVertex3f(55.0, 24.0, 5.5);
    glVertex3f(-60.0, 24.0, 5.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 5.8);
    glVertex3f(55.0, 24.0, 5.8);
    glVertex3f(55.0, 24.3, 5.5);
    glVertex3f(-60.0, 24.3, 5.5);
    glEnd();

//Kabel listrik sebrang rumah
	//kabel belakang bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 41.0);
    glVertex3f(55.0, 21.3, 41.0);
    glVertex3f(55.0, 21.3, 40.7);
    glVertex3f(-60.0, 21.3, 40.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 41.0);
    glVertex3f(55.0, 21.0, 41.0);
    glVertex3f(55.0, 21.0, 40.7);
    glVertex3f(-60.0, 21.0, 40.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 41.0);
    glVertex3f(55.0, 21.0, 41.0);
    glVertex3f(55.0, 21.3, 40.7);
    glVertex3f(-60.0, 21.3, 40.7);
    glEnd();

    //kabel belakang atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 41.0);
    glVertex3f(55.0, 24.3, 41.0);
    glVertex3f(55.0, 24.3, 40.7);
    glVertex3f(-60.0, 24.3, 40.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 41.0);
    glVertex3f(55.0, 24.0, 41.0);
    glVertex3f(55.0, 24.0, 40.7);
    glVertex3f(-60.0, 24.0, 40.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 41.0);
    glVertex3f(55.0, 24.0, 41.0);
    glVertex3f(55.0, 24.3, 40.7);
    glVertex3f(-60.0, 24.3, 40.7);
    glEnd();

	//kabel depan bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 50.3);
    glVertex3f(55.0, 21.3, 50.3);
    glVertex3f(55.0, 21.3, 50.0);
    glVertex3f(-60.0, 21.3, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 50.3);
    glVertex3f(55.0, 21.0, 50.3);
    glVertex3f(55.0, 21.0, 50.0);
    glVertex3f(-60.0, 21.0, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 50.3);
    glVertex3f(55.0, 21.0, 50.3);
    glVertex3f(55.0, 21.3, 50.0);
    glVertex3f(-60.0, 21.3, 50.0);
    glEnd();

    //kabel depan atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 50.3);
    glVertex3f(55.0, 24.3, 50.3);
    glVertex3f(55.0, 24.3, 50.0);
    glVertex3f(-60.0, 24.3, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 50.3);
    glVertex3f(55.0, 24.0, 50.3);
    glVertex3f(55.0, 24.0, 50.0);
    glVertex3f(-60.0, 24.0, 50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 50.3);
    glVertex3f(55.0, 24.0, 50.3);
    glVertex3f(55.0, 24.3, 50.0);
    glVertex3f(-60.0, 24.3, 50.0);
    glEnd();

	//kabel tengah bawah
	glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.3, 44.5);
    glVertex3f(55.0, 21.3, 44.5);
    glVertex3f(55.0, 21.3, 44.3);
    glVertex3f(-60.0, 21.3, 44.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 44.5);
    glVertex3f(55.0, 21.0, 44.5);
    glVertex3f(55.0, 21.0, 44.3);
    glVertex3f(-60.0, 21.0,44.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 21.0, 44.5);
    glVertex3f(55.0, 21.0, 44.5);
    glVertex3f(55.0, 21.3, 44.3);
    glVertex3f(-60.0, 21.3, 44.3);
    glEnd();

    //kabel tengah atas
    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.3, 44.5);
    glVertex3f(55.0, 24.3, 44.5);
    glVertex3f(55.0, 24.3, 44.3);
    glVertex3f(-60.0, 24.3, 44.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 44.5);
    glVertex3f(55.0, 24.0, 44.5);
    glVertex3f(55.0, 24.0, 44.3);
    glVertex3f(-60.0, 24.0, 44.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 25, 112);
    glVertex3f(-60.0, 24.0, 44.5);
    glVertex3f(55.0, 24.0, 44.5);
    glVertex3f(55.0, 24.3, 44.3);
    glVertex3f(-60.0, 24.3, 44.3);
    glEnd();


}

void rumah_tingkat(void)
{
	//dinding kanan
	glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 35.0, -15.0);
    glVertex3f(55.0, 35.0, -43.0);
    glVertex3f(55.0, -12.0, -43.0);
    glVertex3f(55.0, -12.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 35.0, -15.0);
    glVertex3f(56.0, 35.0, -44.0);
    glVertex3f(56.0, -12.0, -44.0);
    glVertex3f(56.0, -12.0, -15.0);
    glEnd();
	//liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.0, 34.9, -15.0);
    glVertex3f(56.0, 34.9, -44.0);
    glVertex3f(56.0, -11.8, -44.0);
    glVertex3f(56.0, -11.8, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(55.0, 35.0, -15.0);
    glVertex3f(56.0, 35.0, -15.0);
    glVertex3f(56.0, -12.0, -15.0);
    glVertex3f(55.0, -12.0, -15.0);
    glEnd();

    //dinding kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(20.0, 35.0, -15.0);
    glVertex3f(20.0, 35.0, -43.0);
    glVertex3f(20.0, -12.0, -43.0);
    glVertex3f(20.0, -12.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(19.0, 35.0, -15.0);
    glVertex3f(19.0, 35.0, -44.0);
    glVertex3f(19.0, -12.0, -44.0);
    glVertex3f(19.0, -12.0, -15.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(19.0, 34.9, -15.0);
    glVertex3f(19.0, 34.9, -44.0);
    glVertex3f(19.0, -11.8, -44.0);
    glVertex3f(19.0, -11.8, -15.0);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(19.0, 35.0, -15.0);
    glVertex3f(20.0, 35.0, -15.0);
    glVertex3f(20.0, -12.0, -15.0);
    glVertex3f(19.0, -12.0, -15.0);
    glEnd();

    //dinding belakang
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(55.0, 35.0, -43.0);
    glVertex3f(20.0, 35.0, -43.0);
    glVertex3f(20.0, -12.0, -43.0);
    glVertex3f(55.0, -12.0, -43.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 35.0, -44.0);
    glVertex3f(19.0, 35.0, -44.0);
    glVertex3f(19.0, -12.0, -44.0);
    glVertex3f(56.0, -12.0, -44.0);
    glEnd();

    //lantai 2 bawah
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex3f(55.0, 11.0, -43.0);
    glVertex3f(55.0, 11.0, -15.0);
    glVertex3f(20.0, 11.0, -15.0);
    glVertex3f(20.0, 11.0, -43.0);
    glEnd();

    //lantai 2 atas
    glBegin(GL_QUADS);
    glColor3ub(135, 206, 250);
    glVertex3f(55.0, 12.0, -43.0);
    glVertex3f(55.0, 12.0, -15.0);
    glVertex3f(20.0, 12.0, -15.0);
    glVertex3f(20.0, 12.0, -43.0);
    glEnd();

    //tutup atas kanan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(55.0, 35.0, -15.0);
    glVertex3f(56.0, 35.0, -15.0);
    glVertex3f(56.0, 35.0, -44.0);
    glVertex3f(55.0, 35.0, -44.0);
    glEnd();

    //tutup atas kiri
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(19.0, 35.0, -15.0);
    glVertex3f(20.0, 35.0, -15.0);
    glVertex3f(20.0, 35.0, -44.0);
    glVertex3f(19.0, 35.0, -44.0);
    glEnd();

    //tutup atas belakang
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(20.0, 35.0, -43.0);
    glVertex3f(56.0, 35.0, -43.0);
    glVertex3f(56.0, 35.0, -44.0);
    glVertex3f(20.0, 35.0, -44.0);
    glEnd();

     //tutup lantai 2
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(55.0, 12.0, -15.0);
    glVertex3f(55.0, 11.0, -15.0);
    glVertex3f(20.0, 11.0, -15.0);
    glVertex3f(20.0, 12.0, -15.0);
    glEnd();

    //cendela kiri 1 lantai 2 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(56.2, 24.0, -24.0);
    glVertex3f(56.2, 24.0, -20.0);
    glVertex3f(56.2, 17.0, -20.0);
    glVertex3f(56.2, 17.0, -24.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 24.0, -24.0);
    glVertex3f(56.2, 24.0, -20.0);
    glVertex3f(56.2, 17.0, -20.0);
    glVertex3f(56.2, 17.0, -24.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 24.0, -22.0);
    glVertex3f(56.2, 17.0, -22.0);
    glEnd();

    //cendela kiri 2 lantai 2 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(56.2, 24.0, -40.0);
    glVertex3f(56.2, 24.0, -36.0);
    glVertex3f(56.2, 17.0, -36.0);
    glVertex3f(56.2, 17.0, -40.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 24.0, -40.0);
    glVertex3f(56.2, 24.0, -36.0);
    glVertex3f(56.2, 17.0, -36.0);
    glVertex3f(56.2, 17.0, -40.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 24.0, -38.0);
    glVertex3f(56.2, 17.0, -38.0);
    glEnd();

    //cendela kiri 1 lantai 1 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(56.2, 4.0, -32.0);
    glVertex3f(56.2, 4.0, -28.0);
    glVertex3f(56.2, -2.0, -28.0);
    glVertex3f(56.2, -2.0, -32.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 4.0, -32.0);
    glVertex3f(56.2, 4.0, -28.0);
    glVertex3f(56.2, -2.0, -28.0);
    glVertex3f(56.2, -2.0, -32.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(56.2, 4.0, -30.0);
    glVertex3f(56.2, -2.0, -30.0);
    glEnd();

    //cendela kiri 1 lantai 2 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(18.9, 24.0, -24.0);
    glVertex3f(18.9, 24.0, -20.0);
    glVertex3f(18.9, 17.0, -20.0);
    glVertex3f(18.9, 17.0, -24.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(18.9, 24.0, -24.0);
    glVertex3f(18.9, 24.0, -20.0);
    glVertex3f(18.9, 17.0, -20.0);
    glVertex3f(18.9, 17.0, -24.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(18.9, 24.0, -22.0);
    glVertex3f(18.9, 17.0, -22.0);
    glEnd();

    //cendela kiri 2 lantai 2 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(18.9, 24.0, -40.0);
    glVertex3f(18.9, 24.0, -36.0);
    glVertex3f(18.9, 17.0, -36.0);
    glVertex3f(18.9, 17.0, -40.0);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(18.9, 24.0, -40.0);
    glVertex3f(18.9, 24.0, -36.0);
    glVertex3f(18.9, 17.0, -36.0);
    glVertex3f(18.9, 17.0, -40.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(18.9, 24.0, -38.0);
    glVertex3f(18.9, 17.0, -38.0);
    glEnd();

    //genteng Garasi bawah
    glBegin(GL_QUADS);
    glColor3ub(248, 248, 255);
    glVertex3f(-10.0, 11.0, -43.0);
    glVertex3f(-10.0, 11.0, -25.0);
    glVertex3f(20.0, 11.0, -25.0);
    glVertex3f(20.0, 11.0, -43.0);
    glEnd();

    //genteng Garasi atas
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3f(-10.0, 13.0, -43.0);
    glVertex3f(-10.0, 13.0, -25.0);
    glVertex3f(20.0, 13.0, -25.0);
    glVertex3f(20.0, 13.0, -43.0);
    glEnd();

    //tutup garasi depan
    glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(-10.0, 11.0, -25.0);
    glVertex3f(-10.0, 13.0, -25.0);
    glVertex3f(20.0, 13.0, -25.0);
    glVertex3f(20.0, 11.0, -25.0);
    glEnd();

    //tutup garasi kiri
    glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(-10.0, 13.0, -43.0);
    glVertex3f(-10.0, 13.0, -25.0);
    glVertex3f(-10.0, 11.0, -25.0);
    glVertex3f(-10.0, 11.0, -43.0);
    glEnd();

    //tutup garasi belakang
    glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(-10.0, 11.0, -43.0);
    glVertex3f(-10.0, 13.0, -43.0);
    glVertex3f(20.0, 13.0, -43.0);
    glVertex3f(20.0, 11.0, -43.0);
    glEnd();

    //tiang depan garasi kiri kiri
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -28.0);
    glVertex3f(-7.0, 13.0, -27.0);
    glVertex3f(-7.0, -12.0, -27.0);
    glVertex3f(-7.0, -12.0, -28.0);
    glEnd();

    //tiang depan garasi kiri kanan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-6.0, 13.0, -28.0);
    glVertex3f(-6.0, 13.0, -27.0);
    glVertex3f(-6.0, -12.0, -27.0);
    glVertex3f(-6.0, -12.0, -28.0);
    glEnd();

    //tiang depan garasi kiri depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -27.0);
    glVertex3f(-6.0, 13.0, -27.0);
    glVertex3f(-6.0, -12.0, -27.0);
    glVertex3f(-7.0, -12.0, -27.0);
    glEnd();

    //tiang depan garasi kiri depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -28.0);
    glVertex3f(-6.0, 13.0, -28.0);
    glVertex3f(-6.0, -12.0, -28.0);
    glVertex3f(-7.0, -12.0, -28.0);
    glEnd();

     //tiang belakang garasi kiri kiri
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -40.0);
    glVertex3f(-7.0, 13.0, -39.0);
    glVertex3f(-7.0, -12.0, -39.0);
    glVertex3f(-7.0, -12.0, -40.0);
    glEnd();

    //tiang belakakng garasi kiri kanan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-6.0, 13.0, -40.0);
    glVertex3f(-6.0, 13.0, -39.0);
    glVertex3f(-6.0, -12.0, -39.0);
    glVertex3f(-6.0, -12.0, -40.0);
    glEnd();

    //tiang belakang garasi kiri depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -39.0);
    glVertex3f(-6.0, 13.0, -39.0);
    glVertex3f(-6.0, -12.0, -39.0);
    glVertex3f(-7.0, -12.0, -39.0);
    glEnd();

    //tiang belakang garasi kiri depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(-7.0, 13.0, -40.0);
    glVertex3f(-6.0, 13.0, -40.0);
    glVertex3f(-6.0, -12.0, -40.0);
    glVertex3f(-7.0, -12.0, -40.0);
    glEnd();

    //alas garasi
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 240);
    glVertex3f(-7.0, -11.0, -40.0);
    glVertex3f(-7.0, -11.0, -28.0);
    glVertex3f(20.0, -11.0, -28.0);
    glVertex3f(20.0, -11.0, -40.0);
    glEnd();

    //alas garasi turunan
    glBegin(GL_QUADS);
    glColor3ub(225, 248, 220);
    glVertex3f(-6.0, -12.0, -24.5);
    glVertex3f(-6.0, -11.0, -28.0);
    glVertex3f(20.0, -11.0, -28.0);
    glVertex3f(20.0, -12.0, -24.5);
    glEnd();

    //S3 tutup alas garasi turunan
    glBegin(GL_POLYGON);
    glColor3ub(225, 248, 220);
    glVertex3f(-6.0, -12.0, -28.0);
    glColor3ub(225, 248, 220);
    glVertex3f(-6.0, -11.0, -28.0);
    glColor3ub(225, 248, 220);
    glVertex3f(-6.0, -12, -24.5);
    glEnd();

    //tutup alas garasi kiri
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-7.0, -5.0, -39.0);
    glVertex3f(-7.0, -5.0, -28.0);
    glVertex3f(-7.0, -12.0, -28.0);
    glVertex3f(-7.0, -12.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-6.0, -5.0, -40.0);
    glVertex3f(-6.0, -5.0, -28.0);
    glVertex3f(-6.0, -12.0, -28.0);
    glVertex3f(-6.0, -12.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-7.0, -5.0, -28.0);
    glVertex3f(-7.0, -5.0, -39.0);
    glVertex3f(-6.0, -5.0, -39.0);
    glVertex3f(-6.0, -5.0, -28.0);
    glEnd();

    //tutup alas garasi belakang
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-6.0, -12.0, -40.0);
    glVertex3f(-6.0, -5.0, -40.0);
    glVertex3f(20.0, -5.0, -40.0);
    glVertex3f(20.0, -12.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(-6.0, -12.0, -39.0);
    glVertex3f(-6.0, -5.0, -39.0);
    glVertex3f(20.0, -5.0, -39.0);
    glVertex3f(20.0, -12.0, -39.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3f(-7.0, -5.0, -40.0);
    glVertex3f(-7.0, -5.0, -39.0);
    glVertex3f(20.0, -5.0, -39.0);
    glVertex3f(20.0, -5.0, -40.0);
    glEnd();

}


void rumah(void)
{
 	//atap kanan
	glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3f(38.0, 50.0, -11.0);
    glVertex3f(38.0, 50.0, -48.0);
    glVertex3f(60.0, 31.8, -48.0);
    glVertex3f(60.0, 31.8, -11.0);
    glEnd();

    //atap kiri
	glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3f(38.0, 50.0, -11.0);
    glVertex3f(38.0, 50.0, -48.0);
    glVertex3f(15.0, 32.0, -48.0);
    glVertex3f(15.0, 32.0, -11.0);
    glEnd();

    //segitiga belakang
    glBegin(GL_POLYGON);
    glColor3ub(128, 128, 128);
    glVertex3f(19.0, 35.0, -44.0);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 35.0, -44.0);
    glColor3ub(128, 128, 128);
    glVertex3f(38.0, 50.0, -44.0);
    glEnd();

    //segitiga depan
    glBegin(GL_POLYGON);
    glColor3ub(128, 128, 128);
    glVertex3f(19.0, 35.0, -15.0);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 35.0, -15.0);
    glColor3ub(128, 128, 128);
    glVertex3f(38.0, 50.0, -15.0);
    glEnd();

    //dinding depan
	glBegin(GL_QUADS);
    glColor3ub(128, 128, 128);
    glVertex3f(56.0, 35.0, -14.999);
    glVertex3f(19.0, 35.0, -14.999);
    glVertex3f(19.0, -12.0, -14.999);
    glVertex3f(56.0, -12.0, -14.999);
    glEnd();

//balkon depan
	//alas depan atas
	glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(30.0, -11.0, -15.0);
    glVertex3f(46.0, -11.0, -15.0);
    glVertex3f(46.0, -11.0, -5.0);
    glVertex3f(30.0, -11.0, -5.0);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(30.0, -11.0, -15.0);
    glVertex3f(46.0, -11.0, -15.0);
    glVertex3f(46.0, -11.0, -5.0);
    glVertex3f(30.0, -11.0, -5.0);
    glEnd();

    //alas depan tutup kiri
	glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(30.0, -12.0, -15.0);
    glVertex3f(30.0, -11.0, -15.0);
    glVertex3f(30.0, -11.0, -5.0);
    glVertex3f(30.0, -12.0, -5.0);
    glEnd();

    //alas depan tutup kanan
	glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(46.0, -12.0, -15.0);
    glVertex3f(46.0, -11.0, -15.0);
    glVertex3f(46.0, -11.0, -5.0);
    glVertex3f(46.0, -12.0, -5.0);
    glEnd();

    //alas depan tutup depan
	glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(46.0, -12.0, -5.0);
    glVertex3f(46.0, -11.0, -5.0);
    glVertex3f(30.0, -11.0, -5.0);
    glVertex3f(30.0, -12.0, -5.0);
    glEnd();

    //tiang kanan depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(46.1, -12.0, -4.9);
    glVertex3f(46.1, 30.0, -4.9);
    glVertex3f(45.0, 30.0, -4.9);
    glVertex3f(45.0, -12.0, -4.9);
    glEnd();

     //tiang kanan kanan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(46.1, -12.0, -5.9);
    glVertex3f(46.1, 30.0, -5.9);
    glVertex3f(46.1, 30.0, -4.9);
    glVertex3f(46.1, -12.0, -4.9);
    glEnd();

    //tiang kanan kiri
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(45.0, -12.0, -5.9);
    glVertex3f(45.0, 30.0, -5.9);
    glVertex3f(45.0, 30.0, -4.9);
    glVertex3f(45.0, -12.0, -4.9);
    glEnd();

    //tiang kanan belakang
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(46.1, -12.0, -5.9);
    glVertex3f(46.1, 30.0, -5.9);
    glVertex3f(45.1, 30.0, -5.9);
    glVertex3f(45.1, -12.0, -5.9);
    glEnd();

    //tiang kiri belakang
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(30.0, -12.0, -5.9);
    glVertex3f(30.0, 30.0, -5.9);
    glVertex3f(31.0, 30.0, -5.9);
    glVertex3f(31.0, -12.0, -5.9);
    glEnd();

    //tiang kiri depan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(30.0, -12.0, -4.9);
    glVertex3f(30.0, 30.0, -4.9);
    glVertex3f(31.0, 30.0, -4.9);
    glVertex3f(31.0, -12.0, -4.9);
    glEnd();

    //tiang kiri kiri
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(30.0, -12.0, -5.9);
    glVertex3f(30.0, 30.0, -5.9);
    glVertex3f(30.0, 30.0, -4.9);
    glVertex3f(30.0, -12.0, -4.9);
    glEnd();

    //tiang kiri kanan
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 153);
    glVertex3f(31.0, -12.0, -5.9);
    glVertex3f(31.0, 30.0, -5.9);
    glVertex3f(31.0, 30.0, -4.9);
    glVertex3f(31.0, -12.0, -4.9);
    glEnd();

    //genteng balkon kanan
    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex3f(39.0, 38.0, -2.9);
    glVertex3f(39.0, 38.0, -15.0);
    glVertex3f(48.0, 28.0, -15.0);
    glVertex3f(48.0, 28.0, -2.9);
    glEnd();

    //genteng balkon kiri
    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex3f(39.0, 38.0, -2.9);
    glVertex3f(39.0, 38.0, -15.0);
    glVertex3f(29.0, 29.1, -15.0);
    glVertex3f(29.0, 29.1, -2.9);
    glEnd();

    //segitiga depan
    glBegin(GL_POLYGON);
    glColor3ub(125, 105, 66);
    glVertex3f(30.0, 30.0, -4.9);
    glColor3ub(105, 88, 55);
    glVertex3f(46.1, 30.0, -4.9);
    glColor3ub(125, 105, 66);
    glVertex3f(39.0, 38.0, -4.9);
    glEnd();

    //plafon depan
    glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(30.0, 30.0, -15.0);
    glVertex3f(46.0, 30.0, -15.0);
    glVertex3f(46.0, 30.0, -5.0);
    glVertex3f(30.0, 30.0, -5.0);
    glEnd();

    //lantai 2 balkon
	glBegin(GL_QUADS);
    glColor3ub(245, 255, 250);
    glVertex3f(30.0, 11.0, -15.0);
    glVertex3f(46.0, 11.0, -15.0);
    glVertex3f(46.0, 11.0, -5.0);
    glVertex3f(30.0, 11.0, -5.0);
    glEnd();

    //lantai 2 balkon atas
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(30.0, 12.0, -15.0);
    glVertex3f(46.0, 12.0, -15.0);
    glVertex3f(46.0, 12.0, -5.0);
    glVertex3f(30.0, 12.0, -5.0);
    glEnd();

    //tutup lantai 2 balkon atas depan
	glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(29.9, 17.0, -4.8);
    glVertex3f(46.2, 17.0, -4.8);
    glVertex3f(46.2, 10.0, -4.8);
    glVertex3f(29.9, 10.0, -4.8);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(29.9, 17.0, -4.8);
    glVertex3f(46.2, 17.0, -4.8);
    glVertex3f(46.2, 10.0, -4.8);
    glVertex3f(29.9, 10.0, -4.8);
    glEnd();

    //tutup lantai 2 balkon atas kanan
    glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(46.2, 17.0, -4.8);
    glVertex3f(46.2, 17.0, -15.0);
    glVertex3f(46.2, 10.0, -15.0);
    glVertex3f(46.2, 10.0, -4.8);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(46.2, 17.0, -4.8);
    glVertex3f(46.2, 17.0, -15.0);
    glVertex3f(46.2, 10.0, -15.0);
    glVertex3f(46.2, 10.0, -4.8);
    glEnd();

    //tutup lantai 2 balkon atas kanan
    glBegin(GL_QUADS);
    glColor3ub(125, 105, 66);
    glVertex3f(29.9, 17.0, -4.8);
    glVertex3f(29.9, 17.0, -15.0);
    glVertex3f(29.9, 10.0, -15.0);
    glVertex3f(29.9, 10.0, -4.8);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex3f(29.9, 17.0, -4.8);
    glVertex3f(29.9, 17.0, -15.0);
    glVertex3f(29.9, 10.0, -15.0);
    glVertex3f(29.9, 10.0, -4.8);
    glEnd();

    //pintu lantai 1
	glBegin(GL_QUADS);
    glColor3ub(210, 105, 30);
    glVertex3f(35.0, 5.0, -14.8);
    glVertex3f(41.0, 5.0, -14.8);
    glVertex3f(41.0, -12.0, -14.8);
    glVertex3f(35.0, -12.0, -14.8);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(35.0, 5.0, -14.8);
    glVertex3f(41.0, 5.0, -14.8);
    glVertex3f(41.0, -11.0, -14.8);
    glVertex3f(35.0, -11.0, -14.8);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(38.0, 5.0, -14.8);
    glVertex3f(38.0, -12.0, -14.8);
    glEnd();

    //cendela balkon lt1 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(43.5, 3.0, -14.8);
    glVertex3f(42.0, 3.0, -14.8);
    glVertex3f(42.0, -9.0, -14.8);
    glVertex3f(43.5, -9.0, -14.8);
    glEnd();
     //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(43.5, 3.0, -14.8);
    glVertex3f(42.0, 3.0, -14.8);
    glVertex3f(42.0, -9.0, -14.8);
    glVertex3f(43.5, -9.0, -14.8);
    glEnd();

    //cendela lt 1 balkon kiri
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(32.0, 3.0, -14.8);
    glVertex3f(33.5, 3.0, -14.8);
    glVertex3f(33.5, -9.0, -14.8);
    glVertex3f(32.0, -9.0, -14.8);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(32.0, 3.0, -14.8);
    glVertex3f(33.5, 3.0, -14.8);
    glVertex3f(33.5, -9.0, -14.8);
    glVertex3f(32.0, -9.0, -14.8);
    glEnd();

    //pintu lantai 2
	glBegin(GL_QUADS);
    glColor3ub(210, 105, 30);
    glVertex3f(35.5, 27.0, -14.8);
    glVertex3f(40.5, 27.0, -14.8);
    glVertex3f(40.5, 12.0, -14.8);
    glVertex3f(35.5, 12.0, -14.8);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(35.5, 27.0, -14.8);
    glVertex3f(40.5, 27.0, -14.8);
    glVertex3f(40.5, 12.0, -14.8);
    glVertex3f(35.5, 12.0, -14.8);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(38.0, 12.0, -14.8);
    glVertex3f(38.0, 27.0, -14.8);
    glEnd();


    //cendela lantai 2 kanan
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(49.0, 24.0, -14.8);
    glVertex3f(53.0, 24.0, -14.8);
    glVertex3f(53.0, 17.0, -14.8);
    glVertex3f(49.0, 17.0, -14.8);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(49.0, 24.0, -14.8);
    glVertex3f(53.0, 24.0, -14.8);
    glVertex3f(53.0, 17.0, -14.8);
    glVertex3f(49.0, 17.0, -14.8);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(51.0, 24.0, -14.8);
    glVertex3f(51.0, 17.0, -14.8);
    glEnd();

    //cendela lantai 2 kiri
	glBegin(GL_QUADS);
    glColor3ub(135, 206, 235);
    glVertex3f(22.5, 24.0, -14.8);
    glVertex3f(27.0, 24.0, -14.8);
    glVertex3f(27.0, 17.0, -14.8);
    glVertex3f(22.5, 17.0, -14.8);
    glEnd();
    //liss
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(22.5, 24.0, -14.8);
    glVertex3f(27.0, 24.0, -14.8);
    glVertex3f(27.0, 17.0, -14.8);
    glVertex3f(22.5, 17.0, -14.8);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(24.5, 24.0, -14.8);
    glVertex3f(24.5, 17.0, -14.8);
    glEnd();
}


void ban(int jari2, int lebar_ban, int x_tengah, int y_tengah, int z_tengah) {
	float PI = 3.14;
	glBegin(GL_POLYGON);
	float z = z_tengah+18;
		for (int i = 0; i <= 360; i++) {
			float sudut = i * (2 * PI / 360);
			float x = x_tengah + jari2 * cos(sudut);
			float y = y_tengah + jari2 * sin(sudut);
            glVertex3f(x, y, z);
			glVertex3f(x, y, z + lebar_ban +20);

		}
	glEnd();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rumah();
    dasar();
    alat_berat();
    ban(6,6,-33,-6,-6);
    rumah_tingkat();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void display(void)
{
    if (is_depth)
        tampil();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case'w':
        case'W' :
            glTranslatef(0.0, 0.0, 3.0);
            break;
        case'd':
        case'D':
            glTranslatef(-3.0, 0.0, 0.0);
            break;
        case's':
        case'S':
            glTranslatef(0.0, 0.0, -3.0);
            break;
        case'a':
        case'A':
            glTranslatef(3.0, 0.0, 0.0);
            break;
        case'7':
            glTranslatef(0.0, 3.0, 0.0);
            break;
        case'9':
            glTranslatef(0.0, -3.0, 0.0);
            break;
        case'2':
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case'8':
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case'6':
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case'4':
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        case'1':
            glRotatef(2.0, 0.0, 0.0, 1.0);
            break;
        case'3':
            glRotatef(-2.0, 0.0, 0.0, 1.0);
            break;
    }
    display();
}

void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void ok()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    ok();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.5, -30.0, -135.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1900,1100);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TR Grafkom");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
