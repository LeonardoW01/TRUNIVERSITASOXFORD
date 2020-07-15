#include <windows.h>
#include <GL/glut.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);
void mouse(int button, int state, int x, int y);
void idle();
GLUquadricObj *obj = gluNewQuadric();

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR UNIVERSITY OFXORD");
    init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
	glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void puncak (){

	//-------------------------------------
	//PINTU
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-2,-13.0,-9.5);
	glVertex3f(-2,-2.5,-9.5);
	glVertex3f(2,-2.5,-9.5);
	glVertex3f(2,-13.0,-9.5);
	glEnd();
	//TANAH
	glBegin(GL_QUADS);
	glColor3ub(36, 176, 28);
	glVertex3f(-80,-13,30);
	glVertex3f(80,-13,30);
	glVertex3f(80,-13,-100); //belakang tanah z nya u gedein kalau mau luas
	glVertex3f(-80,-13,-100); //belakang tanah z nya u gedein kalau mau luas
	glEnd();

	//JALAN tengah bawah
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-2,-12.8,25);
	glVertex3f(2,-12.8,25);
	glVertex3f(2,-12.8,-9.5);
	glVertex3f(-2,-12.8,-9.5);
	glEnd();

	//JALAN tengah depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-24.5,-12.8,25);
	glVertex3f(19.5,-12.8,25);
	glVertex3f(19.5,-12.8,30);
	glVertex3f(-24.5,-12.8,30);
	glEnd();

    //JALAN tengah belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-24.5,-12.8,-95);
	glVertex3f(19.5,-12.8,-95);
	glVertex3f(19.5,-12.8,-100);
	glVertex3f(-24.5,-12.8,-100);
	glEnd();

	//jalan kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(19.5,-12.8,25);
	glVertex3f(15.5,-12.8,25);
	glVertex3f(15.5,-12.8,-95);
	glVertex3f(19.5,-12.8,-95);
	glEnd();

    //jalan kanan gedung dalem
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(74.5,-12.8,25);
	glVertex3f(30.5,-12.8,25);
	glVertex3f(30.5,-12.8,-95);
	glVertex3f(74.5,-12.8,-95);
	glEnd();

    //jalan kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-24.5,-12.8,25);
	glVertex3f(-20.5,-12.8,25);
	glVertex3f(-20.5,-12.8,-95);
	glVertex3f(-24.5,-12.8,-95);
	glEnd();

    //jalan kiri gedung dalem
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-75,-12.8,-30);
	glVertex3f(-35,-12.8,-30);
	glVertex3f(-35,-12.8,-80);
	glVertex3f(-75,-12.8,-80);
	glEnd();

    //badan
//	GLUquadricObj *obj = gluNewQuadric();
	glPushMatrix();
	glTranslatef(0,20,-20);
	glRotatef(90, 90,0,0);
	glColor3ub(255, 153, 69);
	gluCylinder(obj,9,9,20,45,45);
	glPopMatrix();

	//badan bawah
	glPushMatrix();
	glTranslatef(0,7,-20);
	glRotatef(90, 90,0,0);
	glColor3ub(199, 91, 2);
	gluCylinder(obj,10.5,10.5,20,45,45);
	glPopMatrix();

	//----------------------------------------------------
	//badan jendela bawah SAMPE SETERUSNYA
	glPushMatrix();
	glTranslatef(-5,5,-12);
	glRotatef(90, 90,0,0);
	glColor3ub(18, 18, 18);
	gluCylinder(obj,1.5,1.5,5,45,45);
	glPopMatrix();
		glPushMatrix();
		glTranslatef(-8,5,-15);
		glRotatef(90, 90,0,0);
		glColor3ub(18, 18, 18);
		gluCylinder(obj,1.5,1.5,5,45,45);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(-9.5,5,-19);
			glRotatef(90, 90,0,0);
			glColor3ub(18, 18, 18);
			gluCylinder(obj,1.5,1.5,5,45,45);
			glPopMatrix();
				glPushMatrix();
				glTranslatef(-8,5,-25);
				glRotatef(90, 90,0,0);
				glColor3ub(18, 18, 18);
				gluCylinder(obj,1.5,1.5,5,45,45);
				glPopMatrix();
					glPushMatrix();
					glTranslatef(-4.5,5,-29);
					glRotatef(90, 90,0,0);
					glColor3ub(18, 18, 18);
					gluCylinder(obj,1.5,1.5,5,45,45);
					glPopMatrix();
						glPushMatrix();
						glTranslatef(0.5,5,-30);
						glRotatef(90, 90,0,0);
						glColor3ub(18, 18, 18);
						gluCylinder(obj,1.5,1.5,5,45,45);
						glPopMatrix();
							glPushMatrix();
							glTranslatef(4.5,5,-29);
							glRotatef(90, 90,0,0);
							glColor3ub(18, 18, 18);
							gluCylinder(obj,1.5,1.5,5,45,45);
							glPopMatrix();
								glPushMatrix();
								glTranslatef(8,5,-25);
								glRotatef(90, 90,0,0);
								glColor3ub(18, 18, 18);
								gluCylinder(obj,1.5,1.5,5,45,45);
								glPopMatrix();
									glPushMatrix();
									glTranslatef(9.5,5,-22);
									glRotatef(90, 90,0,0);
									glColor3ub(18, 18, 18);
									gluCylinder(obj,1.5,1.5,5,45,45);
									glPopMatrix();
										glPushMatrix();
										glTranslatef(9.5,5,-18);
										glRotatef(90, 90,0,0);
										glColor3ub(18, 18, 18);
										gluCylinder(obj,1.5,1.5,5,45,45);
										glPopMatrix();
											glPushMatrix();
											glTranslatef(8,5,-15);
											glRotatef(90, 90,0,0);
											glColor3ub(18, 18, 18);
											gluCylinder(obj,1.5,1.5,5,45,45);
											glPopMatrix();
												glPushMatrix();
												glTranslatef(6,5,-12);
												glRotatef(90, 90,0,0);
												glColor3ub(18, 18, 18);
												gluCylinder(obj,1.5,1.5,5,45,45);
												glPopMatrix();
													glPushMatrix();
													glTranslatef(2.5,5,-10.5);
													glRotatef(90, 90,0,0);
													glColor3ub(18, 18, 18);
													gluCylinder(obj,1.5,1.5,5,45,45);
													glPopMatrix();
														glPushMatrix();
														glTranslatef(-2,5,-10);
														glRotatef(90, 90,0,0);
														glColor3ub(18, 18, 18);
														gluCylinder(obj,1.5,1.5,5,45,45);
														glPopMatrix();
		//----------------------------------------------------
	//badan jendela bawah 2 sampe seterusnya
	glPushMatrix();
	glTranslatef(-5,-5,-12);
	glRotatef(90, 90,0,0);
	glColor3ub(18, 18, 18);
	gluCylinder(obj,1.5,1.5,5,45,45);
	glPopMatrix();
		glPushMatrix();
		glTranslatef(-8,-5,-15);
		glRotatef(90, 90,0,0);
		glColor3ub(18, 18, 18);
		gluCylinder(obj,1.5,1.5,5,45,45);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(-9.5,-5,-19);
			glRotatef(90, 90,0,0);
			glColor3ub(18, 18, 18);
			gluCylinder(obj,1.5,1.5,5,45,45);
			glPopMatrix();
				glPushMatrix();
				glTranslatef(-8,-5,-25);
				glRotatef(90, 90,0,0);
				glColor3ub(18, 18, 18);
				gluCylinder(obj,1.5,1.5,5,45,45);
				glPopMatrix();
					glPushMatrix();
					glTranslatef(-4.5,-5,-29);
					glRotatef(90, 90,0,0);
					glColor3ub(18, 18, 18);
					gluCylinder(obj,1.5,1.5,5,45,45);
					glPopMatrix();
						glPushMatrix();
						glTranslatef(0.5,-5,-30);
						glRotatef(90, 90,0,0);
						glColor3ub(18, 18, 18);
						gluCylinder(obj,1.5,1.5,5,45,45);
						glPopMatrix();
							glPushMatrix();
							glTranslatef(4.5,-5,-29);
							glRotatef(90, 90,0,0);
							glColor3ub(18, 18, 18);
							gluCylinder(obj,1.5,1.5,5,45,45);
							glPopMatrix();
								glPushMatrix();
								glTranslatef(8,-5,-25);
								glRotatef(90, 90,0,0);
								glColor3ub(18, 18, 18);
								gluCylinder(obj,1.5,1.5,5,45,45);
								glPopMatrix();
									glPushMatrix();
									glTranslatef(9.5,-5,-22);
									glRotatef(90, 90,0,0);
									glColor3ub(18, 18, 18);
									gluCylinder(obj,1.5,1.5,5,45,45);
									glPopMatrix();
										glPushMatrix();
										glTranslatef(9.5,-5,-18);
										glRotatef(90, 90,0,0);
										glColor3ub(18, 18, 18);
										gluCylinder(obj,1.5,1.5,5,45,45);
										glPopMatrix();
											glPushMatrix();
											glTranslatef(8,-5,-15);
											glRotatef(90, 90,0,0);
											glColor3ub(18, 18, 18);
											gluCylinder(obj,1.5,1.5,5,45,45);
											glPopMatrix();
												glPushMatrix();
												glTranslatef(6,-5,-12);
												glRotatef(90, 90,0,0);
												glColor3ub(18, 18, 18);
												gluCylinder(obj,1.5,1.5,5,45,45);
												glPopMatrix();

	//----------------------------------------------------
	//badan jendela tengah sampe seterusnya s
	glPushMatrix();
	glTranslatef(-4,18,-13);
	glRotatef(90, 90,0,0);
	glColor3ub(26, 26, 26);
	gluCylinder(obj,1.5,1.5,5,45,45);
	glPopMatrix();
		glPushMatrix();
		glTranslatef(-7,18,-16);
		glRotatef(90, 90,0,0);
		glColor3ub(26, 26, 26);
		gluCylinder(obj,1.5,1.5,5,45,45);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(-8,18,-20);
			glRotatef(90, 90,0,0);
			glColor3ub(26, 26, 26);
			gluCylinder(obj,1.5,1.5,5,45,45);
			glPopMatrix();
				glPushMatrix();
				glTranslatef(-7.5,18,-23.5);
				glRotatef(90, 90,0,0);
				glColor3ub(26, 26, 26);
				gluCylinder(obj,1.5,1.5,5,45,45);
				glPopMatrix();
					glPushMatrix();
					glTranslatef(-4,18,-27.2);
					glRotatef(90, 90,0,0);
					glColor3ub(26, 26, 26);
					gluCylinder(obj,1.5,1.5,5,45,45);
					glPopMatrix();
						glPushMatrix();
						glTranslatef(0.5,18,-28);
						glRotatef(90, 90,0,0);
						glColor3ub(26, 26, 26);
						gluCylinder(obj,1.5,1.5,5,45,45);
						glPopMatrix();
							glPushMatrix();
							glTranslatef(5.5,18,-26.5);
							glRotatef(90, 90,0,0);
							glColor3ub(26, 26, 26);
							gluCylinder(obj,1.5,1.5,5,45,45);
							glPopMatrix();
								glPushMatrix();
								glTranslatef(8,18,-23);
								glRotatef(90, 90,0,0);
								glColor3ub(26, 26, 26);
								gluCylinder(obj,1.5,1.5,5,45,45);
								glPopMatrix();
									glPushMatrix();
									glTranslatef(8,18,-17.5);
									glRotatef(90, 90,0,0);
									glColor3ub(26, 26, 26);
									gluCylinder(obj,1.5,1.5,5,45,45);
									glPopMatrix();
										glPushMatrix();
										glTranslatef(5.5,18,-13.8);
										glRotatef(90, 90,0,0);
										glColor3ub(26, 26, 26);
										gluCylinder(obj,1.5,1.5,5,45,45);
										glPopMatrix();
											glPushMatrix();
											glTranslatef(1,18,-12);
											glRotatef(90, 90,0,0);
											glColor3ub(26, 26, 26);
											gluCylinder(obj,1.5,1.5,5,45,45);
											glPopMatrix();



	//buletan atas
	glPushMatrix();
	glTranslatef(0,22,-20);
	glColor3ub(255, 203, 130);
	glRotatef(90,90,0,0);
	//glScalef(1.0,1.0,0.0);
	glutSolidSphere(8,8,10);
	glPopMatrix();

	//badan buletan1
	glPushMatrix();
	glTranslatef(0,35,-20);
	glRotatef(90, 90,0,0);
	glColor3ub(92, 92, 92);
	gluCylinder(obj,3,3,20,45,45);
	glPopMatrix();
	//badan buletan 2

	glPushMatrix();
	glTranslatef(0,37,-20);
	glRotatef(90, 90,0,0);
	glColor3ub(74, 74, 74);
	gluCylinder(obj,2,2,20,45,45);
	glPopMatrix();

	//bawah segitiga
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 255);
	glVertex3f(1,37.0,-21.0);
	glVertex3f(-1,37.0,-21.0);
	glVertex3f(0,37.0,-19);
	glEnd();

	//belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(1,37.0,-21.0);
	glVertex3f(-1,37.0,-21.0);
	glVertex3f(0,41.0,-20.0);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(1,37.0,-21.0);
	glVertex3f(0,41.0,-20.0);
	glVertex3f(0,37.0,-19.0);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(-1,37.0,-21.0);
	glVertex3f(0,37.0,-19.0);
	glVertex3f(0,41.0,-20.0);
	glEnd();

    //objek bendera
    //object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,-7);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-3.0,18,-5);
	glVertex3f(-3.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,18,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glVertex3f(-3.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-3.0,-13,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-3.0,18,-5);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,-7);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-5.0,18,-7);
	glVertex3f(-3.0,18,-7);
	glEnd();

    //object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-5.0,14,-7);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,18,-5);
	glVertex3f(-12.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-12.0,18,-5);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-5.0,14,-7);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

    //object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-5.0,10,-7);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-12.0,10,-7);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 1159);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,10,-7);
	glVertex3f(-5.0,10,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-5.0,10,-7);
	glVertex3f(-12.0,10,-7);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();


    //object KURSI TAMAN 1
    //kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,2);
	glVertex3f(-3.0,-13,4);
	glVertex3f(-3.0,-10,4);
	glVertex3f(-3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-5.0,-13,2);
	glVertex3f(-5.0,-13,4);
	glVertex3f(-5.0,-10,4);
	glVertex3f(-5.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-10,4);
	glVertex3f(-5.0,-10,4);
	glVertex3f(-5.0,-10,2);
	glVertex3f(-3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,4);
	glVertex3f(-5.0,-13,4);
	glVertex3f(-5.0,-13,2);
	glVertex3f(-3.0,-13,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,4);
	glVertex3f(-5.0,-13,4);
	glVertex3f(-5.0,-10,2);
	glVertex3f(-3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,2);
	glVertex3f(-5.0,-13,2);
	glVertex3f(-5.0,-10,2);
	glVertex3f(-3.0,-10,2);
	glEnd();

    //kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-13,2);
	glVertex3f(-8.0,-13,4);
	glVertex3f(-8.0,-10,4);
	glVertex3f(-8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-10.0,-13,2);
	glVertex3f(-10.0,-13,4);
	glVertex3f(-10.0,-10,4);
	glVertex3f(-10.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-10,4);
	glVertex3f(-10.0,-10,4);
	glVertex3f(-10.0,-10,2);
	glVertex3f(-8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-13,4);
	glVertex3f(-10.0,-13,4);
	glVertex3f(-10.0,-13,2);
	glVertex3f(-8.0,-13,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-8.0,-13,4);
	glVertex3f(-10.0,-13,4);
	glVertex3f(-10.0,-10,2);
	glVertex3f(-8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-8.0,-13,2);
	glVertex3f(-10.0,-13,2);
	glVertex3f(-10.0,-10,2);
	glVertex3f(-8.0,-10,2);
	glEnd();

    //kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,17);
	glVertex3f(-3.0,-13,19);
	glVertex3f(-3.0,-10,19);
	glVertex3f(-3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-5.0,-13,17);
	glVertex3f(-5.0,-13,19);
	glVertex3f(-5.0,-10,19);
	glVertex3f(-5.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-10,19);
	glVertex3f(-5.0,-10,19);
	glVertex3f(-5.0,-10,17);
	glVertex3f(-3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-3.0,-13,19);
	glVertex3f(-5.0,-13,19);
	glVertex3f(-5.0,-13,17);
	glVertex3f(-3.0,-13,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,19);
	glVertex3f(-5.0,-13,19);
	glVertex3f(-5.0,-10,17);
	glVertex3f(-3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-3.0,-13,17);
	glVertex3f(-5.0,-13,17);
	glVertex3f(-5.0,-10,17);
	glVertex3f(-3.0,-10,17);
	glEnd();

    //kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-13,17);
	glVertex3f(-8.0,-13,19);
	glVertex3f(-8.0,-10,19);
	glVertex3f(-8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-10.0,-13,17);
	glVertex3f(-10.0,-13,19);
	glVertex3f(-10.0,-10,19);
	glVertex3f(-10.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-10,19);
	glVertex3f(-10.0,-10,19);
	glVertex3f(-10.0,-10,17);
	glVertex3f(-8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(-8.0,-13,19);
	glVertex3f(-10.0,-13,19);
	glVertex3f(-10.0,-13,17);
	glVertex3f(-8.0,-13,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-8.0,-13,19);
	glVertex3f(-10.0,-13,19);
	glVertex3f(-10.0,-10,17);
	glVertex3f(-8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(-8.0,-13,17);
	glVertex3f(-10.0,-13,17);
	glVertex3f(-10.0,-10,17);
	glVertex3f(-8.0,-10,17);
	glEnd();

	//dudukan kiri
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-10.0,-9,0);
	glVertex3f(-10.0,-9,20);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-10.0,-11,0);
	glEnd();

	//dudukan kanan
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-11,0);
	glEnd();

	//dudukan kursi bawah
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-11,0);
	glVertex3f(-10.0,-11,0);
	glEnd();

	//dudukan depan
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-10.0,-9,20);
	glEnd();

	//dudukan belakang
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-10.0,-11,0);
	glVertex3f(-3.0,-11,0);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-10.0,-9,0);
	glEnd();

	//dudukan kursi atas
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-10.0,-9,20);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-10.0,-9,0);
	glEnd();

	//dudukan kursi atas kiri
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-11.5,-3,20);
	glVertex3f(-10.0,-9,20);
	glVertex3f(-10.0,-9,0);
	glVertex3f(-11.5,-3,0);
	glEnd();

    //object KURSI TAMAN 2
    //kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-13,2);
	glVertex3f(3.0,-13,4);
	glVertex3f(3.0,-10,4);
	glVertex3f(3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(5.0,-13,2);
	glVertex3f(5.0,-13,4);
	glVertex3f(5.0,-10,4);
	glVertex3f(5.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-10,4);
	glVertex3f(5.0,-10,4);
	glVertex3f(5.0,-10,2);
	glVertex3f(3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-13,4);
	glVertex3f(5.0,-13,4);
	glVertex3f(5.0,-13,2);
	glVertex3f(3.0,-13,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(3.0,-13,4);
	glVertex3f(5.0,-13,4);
	glVertex3f(5.0,-10,2);
	glVertex3f(3.0,-10,2);
	glEnd();

	//kaki kiri depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(3.0,-13,2);
	glVertex3f(5.0,-13,2);
	glVertex3f(5.0,-10,2);
	glVertex3f(3.0,-10,2);
	glEnd();

    //kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-13,2);
	glVertex3f(8.0,-13,4);
	glVertex3f(8.0,-10,4);
	glVertex3f(8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(10.0,-13,2);
	glVertex3f(10.0,-13,4);
	glVertex3f(10.0,-10,4);
	glVertex3f(10.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-10,4);
	glVertex3f(10.0,-10,4);
	glVertex3f(10.0,-10,2);
	glVertex3f(8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-13,4);
	glVertex3f(10.0,-13,4);
	glVertex3f(10.0,-13,2);
	glVertex3f(8.0,-13,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(8.0,-13,4);
	glVertex3f(10.0,-13,4);
	glVertex3f(10.0,-10,2);
	glVertex3f(8.0,-10,2);
	glEnd();

	//kaki kiri belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(8.0,-13,2);
	glVertex3f(10.0,-13,2);
	glVertex3f(10.0,-10,2);
	glVertex3f(8.0,-10,2);
	glEnd();

    //kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-13,17);
	glVertex3f(3.0,-13,19);
	glVertex3f(3.0,-10,19);
	glVertex3f(3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(5.0,-13,17);
	glVertex3f(5.0,-13,19);
	glVertex3f(5.0,-10,19);
	glVertex3f(5.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-10,19);
	glVertex3f(5.0,-10,19);
	glVertex3f(5.0,-10,17);
	glVertex3f(3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(3.0,-13,19);
	glVertex3f(5.0,-13,19);
	glVertex3f(5.0,-13,17);
	glVertex3f(3.0,-13,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(3.0,-13,19);
	glVertex3f(5.0,-13,19);
	glVertex3f(5.0,-10,17);
	glVertex3f(3.0,-10,17);
	glEnd();

	//kaki kanan depan
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(3.0,-13,17);
	glVertex3f(5.0,-13,17);
	glVertex3f(5.0,-10,17);
	glVertex3f(3.0,-10,17);
	glEnd();

    //kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-13,17);
	glVertex3f(8.0,-13,19);
	glVertex3f(8.0,-10,19);
	glVertex3f(8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(10.0,-13,17);
	glVertex3f(10.0,-13,19);
	glVertex3f(10.0,-10,19);
	glVertex3f(10.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-10,19);
	glVertex3f(10.0,-10,19);
	glVertex3f(10.0,-10,17);
	glVertex3f(8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(79, 79, 79);
	glVertex3f(8.0,-13,19);
	glVertex3f(10.0,-13,19);
	glVertex3f(10.0,-13,17);
	glVertex3f(8.0,-13,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(8.0,-13,19);
	glVertex3f(10.0,-13,19);
	glVertex3f(10.0,-10,17);
	glVertex3f(8.0,-10,17);
	glEnd();

	//kaki kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(3, 3, 3);
	glVertex3f(8.0,-13,17);
	glVertex3f(10.0,-13,17);
	glVertex3f(10.0,-10,17);
	glVertex3f(8.0,-10,17);
	glEnd();

    //dudukan kiri
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(10.0,-9,0);
	glVertex3f(10.0,-9,20);
	glVertex3f(10.0,-11,20);
	glVertex3f(10.0,-11,0);
	glEnd();

	//dudukan kanan
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(3.0,-9,0);
	glVertex3f(3.0,-9,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-11,0);
	glEnd();

	//dudukan kursi bawah
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(10.0,-11,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-11,0);
	glVertex3f(10.0,-11,0);
	glEnd();

	//dudukan depan
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(10.0,-11,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-9,20);
	glVertex3f(10.0,-9,20);
	glEnd();

	//dudukan belakang
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(10.0,-11,0);
	glVertex3f(3.0,-11,0);
	glVertex3f(3.0,-9,0);
	glVertex3f(10.0,-9,0);
	glEnd();

	//dudukan kursi atas
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(10.0,-9,20);
	glVertex3f(3.0,-9,20);
	glVertex3f(3.0,-9,0);
	glVertex3f(10.0,-9,0);
	glEnd();

	//dudukan kursi atas kanan
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(11.5,-3,20);
	glVertex3f(10.0,-9,20);
	glVertex3f(10.0,-9,0);
	glVertex3f(11.5,-3,0);
	glEnd();

    //GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-35.0,-13,-10);
	glVertex3f(-35.0,-13,28);
	glVertex3f(-35.0,10,28);
	glVertex3f(-35.0,10,-10);
	glEnd();

	//GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-25.0,-13,-10);
	glVertex3f(-25.0,-13,28);
	glVertex3f(-25.0,10,28);
	glVertex3f(-25.0,10,-10);
	glEnd();

	//GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-35.0,10,28);
	glVertex3f(-25.0,10,28);
	glVertex3f(-25.0,10,-10);
	glVertex3f(-35.0,10,-10);
	glEnd();

	//GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,10,28);
	glVertex3f(-25.0,10,28);
	glVertex3f(-25.0,-13,28);
	glVertex3f(-35.0,-13,28);
	glEnd();

	//GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,10,-10);
	glVertex3f(-25.0,10,-10);
	glVertex3f(-25.0,-13,-10);
	glVertex3f(-35.0,-13,-10);
	glEnd();

	//GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-35.0,-13,28);
	glVertex3f(-25.0,-13,28);
	glVertex3f(-25.0,-13,-10);
	glVertex3f(-35.0,-13,-10);
	glEnd();


    //KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-5);
	glVertex3f(-24.5,-1,-9);
	glVertex3f(-24.5,6,-9);
	glVertex3f(-24.5,6,-5);
	glEnd();

	//KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,0);
	glVertex3f(-24.5,-1,-4);
	glVertex3f(-24.5,6,-4);
	glVertex3f(-24.5,6,0);
	glEnd();

	//KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,5);
	glVertex3f(-24.5,-1,1);
	glVertex3f(-24.5,6,1);
	glVertex3f(-24.5,6,5);
	glEnd();

	//KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,10);
	glVertex3f(-24.5,-1,6);
	glVertex3f(-24.5,6,6);
	glVertex3f(-24.5,6,10);
	glEnd();

	//KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,15);
	glVertex3f(-24.5,-1,11);
	glVertex3f(-24.5,6,11);
	glVertex3f(-24.5,6,15);
	glEnd();

	//KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,20);
	glVertex3f(-24.5,-1,16);
	glVertex3f(-24.5,6,16);
	glVertex3f(-24.5,6,20);
	glEnd();

    //KACA GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,25);
	glVertex3f(-24.5,-1,21);
	glVertex3f(-24.5,6,21);
	glVertex3f(-24.5,6,25);
	glEnd();

    //KACA GEDUNG KIRI BAWAH 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,20);
	glVertex3f(-24.5,-8,16);
	glVertex3f(-24.5,-4,16);
	glVertex3f(-24.5,-4,20);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,10);
	glVertex3f(-24.5,-8,6);
	glVertex3f(-24.5,-4,6);
	glVertex3f(-24.5,-4,10);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,0);
	glVertex3f(-24.5,-8,-4);
	glVertex3f(-24.5,-4,-4);
	glVertex3f(-24.5,-4,0);
	glEnd();

    //PINTU GEDUNG KIRI 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-13,-5);
	glVertex3f(-24.5,-13,-9);
	glVertex3f(-24.5,-3,-9);
	glVertex3f(-24.5,-3,-5);
	glEnd();

    //GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,-13,-45);
	glVertex3f(-35.0,-13,-5);
	glVertex3f(-35.0,10,-5);
	glVertex3f(-35.0,10,-45);
	glEnd();

	//GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-25.0,-13,-5);
	glVertex3f(-25.0,10,-5);
	glVertex3f(-25.0,10,-45);
	glEnd();

	//GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-5);
	glVertex3f(-25.0,10,-5);
	glVertex3f(-25.0,10,-45);
	glVertex3f(-35.0,10,-45);
	glEnd();

	//GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-5);
	glVertex3f(-25.0,10,-5);
	glVertex3f(-25.0,-13,-5);
	glVertex3f(-35.0,-13,-5);
	glEnd();

	//GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-45);
	glVertex3f(-25.0,10,-45);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-35.0,-13,-45);
	glEnd();

	//GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,-13,-5);
	glVertex3f(-25.0,-13,-5);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-35.0,-13,-45);
	glEnd();

	 //KACA GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-11);
	glVertex3f(-24.5,-1,-15);
	glVertex3f(-24.5,6,-15);
	glVertex3f(-24.5,6,-11);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-15);
	glVertex3f(-24.5,-8,-19);
	glVertex3f(-24.5,-4,-19);
	glVertex3f(-24.5,-4,-15);
	glEnd();

	//KACA GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-19);
	glVertex3f(-24.5,-1,-23);
	glVertex3f(-24.5,6,-23);
	glVertex3f(-24.5,6,-19);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-23);
	glVertex3f(-24.5,-8,-27);
	glVertex3f(-24.5,-4,-27);
	glVertex3f(-24.5,-4,-23);
	glEnd();

	//KACA GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-27);
	glVertex3f(-24.5,-1,-31);
	glVertex3f(-24.5,6,-31);
	glVertex3f(-24.5,6,-27);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-31);
	glVertex3f(-24.5,-8,-35);
	glVertex3f(-24.5,-4,-35);
	glVertex3f(-24.5,-4,-31);
	glEnd();

	//KACA GEDUNG KIRI 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-35);
	glVertex3f(-24.5,-1,-39);
	glVertex3f(-24.5,6,-39);
	glVertex3f(-24.5,6,-35);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-39);
	glVertex3f(-24.5,-8,-43);
	glVertex3f(-24.5,-4,-43);
	glVertex3f(-24.5,-4,-39);
	glEnd();

    //GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,-13,-45);
	glVertex3f(-35.0,-13,-60);
	glVertex3f(-35.0,25,-60);
	glVertex3f(-35.0,25,-45);
	glEnd();

	//GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-25.0,25,-60);
	glVertex3f(-25.0,25,-45);
	glEnd();

	//GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,25,-60);
	glVertex3f(-25.0,25,-60);
	glVertex3f(-25.0,25,-45);
	glVertex3f(-35.0,25,-45);
	glEnd();

	//GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,25,-60);
	glVertex3f(-25.0,25,-60);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-35.0,-13,-60);
	glEnd();

	//GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,25,-45);
	glVertex3f(-25.0,25,-45);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-35.0,-13,-45);
	glEnd();

	//GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-35.0,-13,-60);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-25.0,-13,-45);
	glVertex3f(-35.0,-13,-45);
	glEnd();

	//PINTU GEDUNG KIRI 3
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,0,-48);
	glVertex3f(-24.5,0,-58);
	glVertex3f(-24.5,-13,-58);
	glVertex3f(-24.5,-13,-48);
	glEnd();

    //KACA GEDUNG KIRI BWH 3
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,1,-47);
	glVertex3f(-24.5,1,-51);
	glVertex3f(-24.5,10,-51);
	glVertex3f(-24.5,10,-47);
	glEnd();

	//KACA GEDUNG KIRI BWH 3
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,1,-55);
	glVertex3f(-24.5,1,-59);
	glVertex3f(-24.5,10,-59);
	glVertex3f(-24.5,10,-55);
	glEnd();

	//KACA GEDUNG KIRI ATS 3
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,11,-47);
	glVertex3f(-24.5,11,-51);
	glVertex3f(-24.5,20,-51);
	glVertex3f(-24.5,20,-47);
	glEnd();

	//KACA GEDUNG KIRI ATS 3
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,11,-55);
	glVertex3f(-24.5,11,-59);
	glVertex3f(-24.5,20,-59);
	glVertex3f(-24.5,20,-55);
	glEnd();

    //GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,-13,-60);
	glVertex3f(-35.0,-13,-95);
	glVertex3f(-35.0,10,-95);
	glVertex3f(-35.0,10,-60);
	glEnd();

	//GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-25.0,-13,-95);
	glVertex3f(-25.0,10,-95);
	glVertex3f(-25.0,10,-60);
	glEnd();

	//GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-95);
	glVertex3f(-25.0,10,-95);
	glVertex3f(-25.0,10,-60);
	glVertex3f(-35.0,10,-60);
	glEnd();

	//GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-95);
	glVertex3f(-25.0,10,-95);
	glVertex3f(-25.0,-13,-95);
	glVertex3f(-35.0,-13,-95);
	glEnd();

	//GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,10,-60);
	glVertex3f(-25.0,10,-60);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-35.0,-13,-60);
	glEnd();

	//GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(-35.0,-13,-95);
	glVertex3f(-25.0,-13,-95);
	glVertex3f(-25.0,-13,-60);
	glVertex3f(-35.0,-13,-60);
	glEnd();

	//KACA GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-61);
	glVertex3f(-24.5,-1,-65);
	glVertex3f(-24.5,6,-65);
	glVertex3f(-24.5,6,-61);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-65);
	glVertex3f(-24.5,-8,-69);
	glVertex3f(-24.5,-4,-69);
	glVertex3f(-24.5,-4,-65);
	glEnd();

	//KACA GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-69);
	glVertex3f(-24.5,-1,-73);
	glVertex3f(-24.5,6,-73);
	glVertex3f(-24.5,6,-69);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-73);
	glVertex3f(-24.5,-8,-77);
	glVertex3f(-24.5,-4,-77);
	glVertex3f(-24.5,-4,-73);
	glEnd();

	//KACA GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-77);
	glVertex3f(-24.5,-1,-81);
	glVertex3f(-24.5,6,-81);
	glVertex3f(-24.5,6,-77);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-81);
	glVertex3f(-24.5,-8,-85);
	glVertex3f(-24.5,-4,-85);
	glVertex3f(-24.5,-4,-81);
	glEnd();

	//KACA GEDUNG KIRI 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-1,-85);
	glVertex3f(-24.5,-1,-89);
	glVertex3f(-24.5,6,-89);
	glVertex3f(-24.5,6,-85);
	glEnd();

	//KACA GEDUNG KIRI BAWAH 4
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-24.5,-8,-89);
	glVertex3f(-24.5,-8,-93);
	glVertex3f(-24.5,-4,-93);
	glVertex3f(-24.5,-4,-89);
	glEnd();

	 //GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,-13,-35);
	glVertex3f(-80.0,-13,-25);
	glVertex3f(-80.0,10,-25);
	glVertex3f(-80.0,10,-35);
	glEnd();

	//GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-35.0,-13,-35);
	glVertex3f(-35.0,-13,-25);
	glVertex3f(-35.0,10,-25);
	glVertex3f(-35.0,10,-35);
	glEnd();

	//GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-25);
	glVertex3f(-35.0,10,-25);
	glVertex3f(-35.0,10,-35);
	glVertex3f(-80.0,10,-35);
	glEnd();

	//GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-25);
	glVertex3f(-35.0,10,-25);
	glVertex3f(-35.0,-13,-25);
	glVertex3f(-80.0,-13,-25);
	glEnd();

	//GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-35);
	glVertex3f(-35.0,10,-35);
	glVertex3f(-35.0,-13,-35);
	glVertex3f(-80.0,-13,-35);
	glEnd();

	//GEDUNG KIRI PANJANG 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,-13,-25);
	glVertex3f(-35.0,-13,-25);
	glVertex3f(-35.0,-13,-35);
	glVertex3f(-80.0,-13,-35);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,-13,-85);
	glVertex3f(-80.0,-13,-75);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-80.0,10,-85);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-35.0,-13,-85);
	glVertex3f(-35.0,-13,-75);
	glVertex3f(-35.0,10,-75);
	glVertex3f(-35.0,10,-85);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-35.0,10,-75);
	glVertex3f(-35.0,10,-85);
	glVertex3f(-80.0,10,-85);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-35.0,10,-75);
	glVertex3f(-35.0,-13,-75);
	glVertex3f(-80.0,-13,-75);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,10,-85);
	glVertex3f(-35.0,10,-85);
	glVertex3f(-35.0,-13,-85);
	glVertex3f(-80.0,-13,-85);
	glEnd();

	//GEDUNG KIRI PANJANG 2
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(-80.0,-13,-75);
	glVertex3f(-35.0,-13,-75);
	glVertex3f(-35.0,-13,-85);
	glVertex3f(-80.0,-13,-85);
	glEnd();


    //GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-80.0,-13,-35);
	glVertex3f(-80.0,-13,-75);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-80.0,10,-35);
	glEnd();

	//GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-70.0,-13,-35);
	glVertex3f(-70.0,-13,-75);
	glVertex3f(-70.0,10,-75);
	glVertex3f(-70.0,10,-35);
	glEnd();

	//GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-70.0,10,-75);
	glVertex3f(-70.0,10,-35);
	glVertex3f(-80.0,10,-35);
	glEnd();

	//GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-80.0,10,-75);
	glVertex3f(-70.0,10,-75);
	glVertex3f(-70.0,-13,-75);
	glVertex3f(-80.0,-13,-75);
	glEnd();

	//GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-80.0,10,-35);
	glVertex3f(-70.0,10,-35);
	glVertex3f(-70.0,-13,-35);
	glVertex3f(-80.0,-13,-35);
	glEnd();

	//GEDUNG KIRI BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(-80.0,-13,-75);
	glVertex3f(-70.0,-13,-75);
	glVertex3f(-70.0,-13,-35);
	glVertex3f(-80.0,-13,-35);
	glEnd();

    //GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(30.0,-13,-70);
	glVertex3f(30.0,-13,0);
	glVertex3f(30.0,2,0);
	glVertex3f(30.0,2,-70);
	glEnd();

	//GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(20.0,-13,-70);
	glVertex3f(20.0,-13,0);
	glVertex3f(20.0,2,0);
	glVertex3f(20.0,2,-70);
	glEnd();

	//GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(30.0,2,0);
	glVertex3f(20.0,2,0);
	glVertex3f(20.0,2,-70);
	glVertex3f(30.0,2,-70);
	glEnd();

	//GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(30.0,2,0);
	glVertex3f(20.0,2,0);
	glVertex3f(20.0,-13,0);
	glVertex3f(30.0,-13,0);
	glEnd();

	//GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(30.0,2,-70);
	glVertex3f(20.0,2,-70);
	glVertex3f(20.0,-13,-70);
	glVertex3f(30.0,-13,-70);
	glEnd();

	//GEDUNG TEMBOK KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(30.0,-13,0);
	glVertex3f(20.0,-13,0);
	glVertex3f(20.0,-13,-70);
	glVertex3f(30.0,-13,-70);
	glEnd();


    //GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,0);
	glVertex3f(80.0,-13,30);
	glVertex3f(80.0,13,30);
	glVertex3f(80.0,13,0);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(20.0,-13,0);
	glVertex3f(20.0,-13,30);
	glVertex3f(20.0,13,30);
	glVertex3f(20.0,13,0);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,30);
	glVertex3f(20.0,13,30);
	glVertex3f(20.0,13,0);
	glVertex3f(80.0,13,0);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,30);
	glVertex3f(20.0,13,30);
	glVertex3f(20.0,-13,30);
	glVertex3f(80.0,-13,30);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,0);
	glVertex3f(20.0,13,0);
	glVertex3f(20.0,-13,0);
	glVertex3f(80.0,-13,0);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,30);
	glVertex3f(20.0,-13,30);
	glVertex3f(20.0,-13,0);
	glVertex3f(80.0,-13,0);
	glEnd();

    //GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,-70);
	glVertex3f(80.0,-13,-100);
	glVertex3f(80.0,13,3-70);
	glVertex3f(80.0,13,-100);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(20.0,-13,-70);
	glVertex3f(20.0,-13,-100);
	glVertex3f(20.0,13,-100);
	glVertex3f(20.0,13,-70);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-100);
	glVertex3f(20.0,13,-100);
	glVertex3f(20.0,13,-70);
	glVertex3f(80.0,13,-70);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-100);
	glVertex3f(20.0,13,-100);
	glVertex3f(20.0,-13,-100);
	glVertex3f(80.0,-13,-100);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-70);
	glVertex3f(20.0,13,-70);
	glVertex3f(20.0,-13,-70);
	glVertex3f(80.0,-13,-70);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(70.0,-13,-100);
	glVertex3f(80.0,-13,-100);
	glVertex3f(20.0,-13,-70);
	glVertex3f(80.0,-13,-70);
	glEnd();

    //GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,-13,-70);
	glVertex3f(80.0,-13,0);
	glVertex3f(80.0,13,0);
	glVertex3f(80.0,13,-70);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(70.0,-13,-70);
	glVertex3f(70.0,-13,0);
	glVertex3f(70.0,13,0);
	glVertex3f(70.0,13,-70);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,13,0);
	glVertex3f(70.0,13,0);
	glVertex3f(70.0,13,-70);
	glVertex3f(80.0,13,-70);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(80.0,13,0);
	glVertex3f(70.0,13,0);
	glVertex3f(70.0,-13,0);
	glVertex3f(80.0,-13,0);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(80.0,13,-70);
	glVertex3f(70.0,13,-70);
	glVertex3f(70.0,-13,-70);
	glVertex3f(80.0,-13,-70);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,-13,0);
	glVertex3f(70.0,-13,0);
	glVertex3f(70.0,-13,-70);
	glVertex3f(80.0,-13,-70);
	glEnd();

    //object papan tulis kiri 1
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-34.9,-10,5);
	glVertex3f(-34.9,2,5);
	glVertex3f(-34.9,2,20);
	glVertex3f(-34.9,-10,20);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(10, 10, 10);
	glVertex3f(-34.9,-10,5);
	glVertex3f(-34.9,2,5);
	glVertex3f(-34.9,2,20);
	glVertex3f(-34.9,-10,20);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex3f(-34.9,-10,5);
	glVertex3f(-34.9,-10,5);
	glVertex3f(-34.9,2,20);
	glVertex3f(-34.9,2,20);
	glEnd();

    //object papan tulis kiri 2
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-34.9,-10,-15);
	glVertex3f(-34.9,2,-15);
	glVertex3f(-34.9,2,-30);
	glVertex3f(-34.9,-10,-30);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(10, 10, 10);
	glVertex3f(-34.9,-10,-15);
	glVertex3f(-34.9,2,-15);
	glVertex3f(-34.9,2,-30);
	glVertex3f(-34.9,-10,-30);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex3f(-34.9,-10,-15);
	glVertex3f(-34.9,-10,-15);
	glVertex3f(-34.9,2,-30);
	glVertex3f(-34.9,2,-30);
	glEnd();

    //object papan tulis kiri 3
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(-34.9,-10,-70);
	glVertex3f(-34.9,2,-70);
	glVertex3f(-34.9,2,-85);
	glVertex3f(-34.9,-10,-85);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(10, 10, 10);
	glVertex3f(-34.9,-10,-70);
	glVertex3f(-34.9,2,-70);
	glVertex3f(-34.9,2,-85);
	glVertex3f(-34.9,-10,-85);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230, 230, 230);
	glVertex3f(-34.9,-10,-70);
	glVertex3f(-34.9,-10,-70);
	glVertex3f(-34.9,2,-85);
	glVertex3f(-34.9,2,-85);
	glEnd();

    //lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,-13,-95);
	glVertex3f(79.0,-13,-80);
	glVertex3f(79.0,5,-80);
	glVertex3f(79.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(69.0,-13,-95);
	glVertex3f(69.0,-13,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,5,-95);
	glVertex3f(79.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,-13,-80);
	glVertex3f(79.0,-13,-80);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,-95);
	glVertex3f(69.0,5,-95);
	glVertex3f(69.0,-13,-95);
	glVertex3f(79.0,-13,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,-13,-80);
	glVertex3f(69.0,-13,-80);
	glVertex3f(69.0,-13,-95);
	glVertex3f(79.0,-13,-95);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(59, 59, 59);
	glVertex3f(69,-13,-88);
	glVertex3f(69,5,-88);
	glEnd();

    glBegin(GL_POINTS);
	glColor3ub(59, 59, 59);
	glVertex3f(69,-4,-87);
	glVertex3f(69,-4,-89);
	glEnd();

    //lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,-13,25);
	glVertex3f(79.0,-13,10);
	glVertex3f(79.0,5,10);
	glVertex3f(79.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(69.0,-13,25);
	glVertex3f(69.0,-13,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,5,25);
	glVertex3f(79.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,-13,10);
	glVertex3f(79.0,-13,10);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,5,25);
	glVertex3f(69.0,5,25);
	glVertex3f(69.0,-13,25);
	glVertex3f(79.0,-13,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(79.0,-13,10);
	glVertex3f(69.0,-13,10);
	glVertex3f(69.0,-13,25);
	glVertex3f(79.0,-13,25);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(59, 59, 59);
	glVertex3f(69,-13,18);
	glVertex3f(69,5,18);
	glEnd();

    glBegin(GL_POINTS);
	glColor3ub(59, 59, 59);
	glVertex3f(69,-4,17);
	glVertex3f(69,-4,19);
	glEnd();
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);
	puncak();
    glutSwapBuffers();

}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
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

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
 		glLoadIdentity();
		glutPostRedisplay();
	}
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
	case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 400.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
