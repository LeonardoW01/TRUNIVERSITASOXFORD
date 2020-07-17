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
	glVertex3f(-80,-13,35);
	glVertex3f(80,-13,35);
	glVertex3f(80,-13,-110); //belakang tanah z nya u gedein kalau mau luas
	glVertex3f(-80,-13,-110); //belakang tanah z nya u gedein kalau mau luas
	glEnd();

	//JALAN tengah bawah
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(-2,-12.8,30);
	glVertex3f(2,-12.8,30);
	glVertex3f(2,-12.8,-9.5);
	glVertex3f(-2,-12.8,-9.5);
	glEnd();

	//JALAN tengah depan
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(-24.5,-12.8,30);
	glVertex3f(19.5,-12.8,30);
	glVertex3f(19.5,-12.8,35);
	glVertex3f(-24.5,-12.8,35);
	glEnd();

    //JALAN tengah belakang
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(-24.5,-12.8,-105);
	glVertex3f(19.5,-12.8,-105);
	glVertex3f(19.5,-12.8,-110);
	glVertex3f(-24.5,-12.8,-110);
	glEnd();

	//jalan kanan
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(19.5,-12.8,30);
	glVertex3f(15.5,-12.8,30);
	glVertex3f(15.5,-12.8,-105);
	glVertex3f(19.5,-12.8,-105);
	glEnd();

    //jalan kanan gedung dalem
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(74.5,-12.8,25);
	glVertex3f(30.5,-12.8,25);
	glVertex3f(30.5,-12.8,-105);
	glVertex3f(74.5,-12.8,-105);
	glEnd();

    //jalan kiri
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
	glVertex3f(-24.5,-12.8,30);
	glVertex3f(-20.5,-12.8,30);
	glVertex3f(-20.5,-12.8,-105);
	glVertex3f(-24.5,-12.8,-105);
	glEnd();

    //jalan kiri gedung dalem
	glBegin(GL_QUADS);
	glColor3ub(47,79,79);
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
	glBegin(GL_TRIANGLES);// genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,25.0);
	glVertex3f(20,13,35.0);
	glVertex3f(20,23,30.0);
	glEnd();
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
	glColor3ub(105 ,105 ,105);
	glVertex3f(-3.0,-13,-7);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-3.0,18,-5);
	glVertex3f(-3.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(-3.0,18,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glVertex3f(-3.0,18,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-3.0,-13,-7);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(-3.0,-13,-5);
	glVertex3f(-5.0,-13,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-3.0,18,-5);
	glEnd();

	//object bendera tiang
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(-3.0,-13,-7);
	glVertex3f(-5.0,-13,-7);
	glVertex3f(-5.0,18,-7);
	glVertex3f(-3.0,18,-7);
	glEnd();

    //object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255 ,0 ,0);
	glVertex3f(-5.0,14,-7);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,18,-5);
	glVertex3f(-12.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0,18,-5);
	glVertex3f(-12.0,18,-5);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

	//object bendera warna paling atas
	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0,14,-7);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-12.0,18,-7);
	glVertex3f(-5.0,18,-7);
	glEnd();

    //object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
	glVertex3f(-5.0,10,-7);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
	glVertex3f(-12.0,10,-7);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
	glVertex3f(-5.0,14,-5);
	glVertex3f(-12.0,14,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,10,-7);
	glVertex3f(-5.0,10,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
	glVertex3f(-5.0,10,-5);
	glVertex3f(-12.0,10,-5);
	glVertex3f(-12.0,14,-7);
	glVertex3f(-5.0,14,-7);
	glEnd();

	//object bendera warna paling bawah
	glBegin(GL_QUADS);
	glColor3ub(255 ,255 ,255);
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
	glColor3ub(139 ,69 ,19);
	glVertex3f(-10.0,-9,0);
	glVertex3f(-10.0,-9,20);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-10.0,-11,0);
	glEnd();

	//dudukan kanan
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-11,0);
	glEnd();

	//dudukan kursi bawah
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-11,0);
	glVertex3f(-10.0,-11,0);
	glEnd();

	//dudukan depan
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(-10.0,-11,20);
	glVertex3f(-3.0,-11,20);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-10.0,-9,20);
	glEnd();

	//dudukan belakang
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(-10.0,-11,0);
	glVertex3f(-3.0,-11,0);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-10.0,-9,0);
	glEnd();

	//dudukan kursi atas
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(-10.0,-9,20);
	glVertex3f(-3.0,-9,20);
	glVertex3f(-3.0,-9,0);
	glVertex3f(-10.0,-9,0);
	glEnd();

	//dudukan kursi atas kiri
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
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
	glColor3ub(139 ,69 ,19);
	glVertex3f(10.0,-9,0);
	glVertex3f(10.0,-9,20);
	glVertex3f(10.0,-11,20);
	glVertex3f(10.0,-11,0);
	glEnd();

	//dudukan kanan
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(3.0,-9,0);
	glVertex3f(3.0,-9,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-11,0);
	glEnd();

	//dudukan kursi bawah
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(10.0,-11,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-11,0);
	glVertex3f(10.0,-11,0);
	glEnd();

	//dudukan depan
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(10.0,-11,20);
	glVertex3f(3.0,-11,20);
	glVertex3f(3.0,-9,20);
	glVertex3f(10.0,-9,20);
	glEnd();

	//dudukan belakang
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(10.0,-11,0);
	glVertex3f(3.0,-11,0);
	glVertex3f(3.0,-9,0);
	glVertex3f(10.0,-9,0);
	glEnd();

	//dudukan kursi atas
	glBegin(GL_QUADS);
	glColor3ub(139 ,69 ,19);
	glVertex3f(10.0,-9,20);
	glVertex3f(3.0,-9,20);
	glVertex3f(3.0,-9,0);
	glVertex3f(10.0,-9,0);
	glEnd();

	//dudukan kursi atas kanan
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
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
	glColor3ub(107, 25, 0);
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

	//PINTU GEDUNG KIRI DEPAN 3
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-24.5,0,-48);
	glVertex3f(-24.5,0,-58);
	glVertex3f(-24.5,-13,-58);
	glVertex3f(-24.5,-13,-48);
	glEnd();

	//PINTU GEDUNG KIRI BELAKANG 3
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-35.1,0,-48);
	glVertex3f(-35.1,0,-58);
	glVertex3f(-35.1,-13,-58);
	glVertex3f(-35.1,-13,-48);
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

	//PINTU GEDUNG TEMBOK KANAN DEPAN
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(19.9,0,-30);
	glVertex3f(19.5,0,-40);
	glVertex3f(19.5,-13,-40);
	glVertex3f(19.5,-13,-30);
	glEnd();

	//PINTU GEDUNG TEMBOK KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(30.1,0,-30);
	glVertex3f(30.1,0,-40);
	glVertex3f(30.1,-13,-40);
	glVertex3f(30.1,-13,-30);
	glEnd();

    //GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,10);
	glVertex3f(80.0,-13,25);
	glVertex3f(80.0,13,25);
	glVertex3f(80.0,13,10);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(20.0,-13,10);
	glVertex3f(20.0,-13,25);
	glVertex3f(20.0,13,25);
	glVertex3f(20.0,13,10);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,25);
	glVertex3f(20.0,13,25);
	glVertex3f(20.0,13,10);
	glVertex3f(80.0,13,10);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,25);
	glVertex3f(20.0,13,25);
	glVertex3f(20.0,-13,25);
	glVertex3f(80.0,-13,25);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,10);
	glVertex3f(20.0,13,10);
	glVertex3f(20.0,-13,10);
	glVertex3f(80.0,-13,10);
	glEnd();

	//GEDUNG KANAN 1
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,25);
	glVertex3f(20.0,-13,25);
	glVertex3f(20.0,-13,10);
	glVertex3f(80.0,-13,10);
	glEnd();

    //GEDUNG KANAN 1 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,25);
	glVertex3f(40.0,-13,35);
	glVertex3f(40.0,13,35);
	glVertex3f(40.0,13,25);
	glEnd();

	//GEDUNG KANAN 1 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(20.0,-13,25);
	glVertex3f(20.0,-13,35);
	glVertex3f(20.0,13,35);
	glVertex3f(20.0,13,25);
	glEnd();

	//GEDUNG KANAN 1 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,35);
	glVertex3f(20.0,13,35);
	glVertex3f(20.0,13,25);
	glVertex3f(40.0,13,25);
	glEnd();

	//GEDUNG KANAN 1 kannanya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,35);
	glVertex3f(20.0,13,35);
	glVertex3f(20.0,-13,35);
	glVertex3f(40.0,-13,35);
	glEnd();

	//GEDUNG KANAN 1 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,25);
	glVertex3f(20.0,13,25);
	glVertex3f(20.0,-13,25);
	glVertex3f(40.0,-13,25);
	glEnd();

	//GEDUNG KANAN 1 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,35);
	glVertex3f(20.0,-13,35);
	glVertex3f(20.0,-13,25);
	glVertex3f(40.0,-13,25);
	glEnd();


    //GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,0);
	glVertex3f(40.0,-13,10);
	glVertex3f(40.0,13,10);
	glVertex3f(40.0,13,0);
	glEnd();

	//GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(20.0,-13,0);
	glVertex3f(20.0,-13,10);
	glVertex3f(20.0,13,10);
	glVertex3f(20.0,13,0);
	glEnd();

	//GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,10);
	glVertex3f(20.0,13,10);
	glVertex3f(20.0,13,0);
	glVertex3f(40.0,13,0);
	glEnd();

	//GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,10);
	glVertex3f(20.0,13,10);
	glVertex3f(20.0,-13,10);
	glVertex3f(40.0,-13,10);
	glEnd();

	//GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,0);
	glVertex3f(20.0,13,0);
	glVertex3f(20.0,-13,0);
	glVertex3f(40.0,-13,0);
	glEnd();

	//GEDUNG KANAN 1 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,10);
	glVertex3f(20.0,-13,10);
	glVertex3f(20.0,-13,0);
	glVertex3f(40.0,-13,0);
	glEnd();

    //JENDELA BESAR KIRI
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-6,2.5);
	glVertex3f(19.9,-6,7.5);
	glVertex3f(19.9,8,7.5);
	glVertex3f(19.9,8,2.5);
	glEnd();

	//JENDELA BESAR KANAN
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-6,27);
	glVertex3f(19.9,-6,32);
	glVertex3f(19.9,8,32);
	glVertex3f(19.9,8,27);
	glEnd();

	//JENDELA BESAR TENGAH
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-10,12);
	glVertex3f(19.9,-10,22);
	glVertex3f(19.9,10,22);
	glVertex3f(19.9,10,12);
	glEnd();

    //GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,-13,-80);
	glVertex3f(80.0,-13,-95);
	glVertex3f(80.0,13,3-80);
	glVertex3f(80.0,13,-95);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(20.0,-13,-80);
	glVertex3f(20.0,-13,-95);
	glVertex3f(20.0,13,-95);
	glVertex3f(20.0,13,-80);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-95);
	glVertex3f(20.0,13,-95);
	glVertex3f(20.0,13,-80);
	glVertex3f(80.0,13,-80);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-95);
	glVertex3f(20.0,13,-95);
	glVertex3f(20.0,-13,-95);
	glVertex3f(80.0,-13,-95);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(80.0,13,-80);
	glVertex3f(20.0,13,-80);
	glVertex3f(20.0,-13,-80);
	glVertex3f(80.0,-13,-80);
	glEnd();

	//GEDUNG KANAN 2
	glBegin(GL_QUADS);
	glColor3ub(199, 91, 2);
	glVertex3f(70.0,-13,-95);
	glVertex3f(80.0,-13,-95);
	glVertex3f(20.0,-13,-80);
	glVertex3f(80.0,-13,-80);
	glEnd();

    //GEDUNG KANAN 2 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,-70);
	glVertex3f(40.0,-13,-80);
	glVertex3f(40.0,13,-80);
	glVertex3f(40.0,13,-70);
	glEnd();

	//GEDUNG KANAN 2 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(20.0,-13,-70);
	glVertex3f(20.0,-13,-80);
	glVertex3f(20.0,13,-80);
	glVertex3f(20.0,13,-70);
	glEnd();

	//GEDUNG KANAN 2 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-80);
	glVertex3f(20.0,13,-80);
	glVertex3f(20.0,13,-70);
	glVertex3f(40.0,13,-70);
	glEnd();

	//GEDUNG KANAN 2 kannanya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-80);
	glVertex3f(20.0,13,-80);
	glVertex3f(20.0,-13,-80);
	glVertex3f(40.0,-13,-80);
	glEnd();

	//GEDUNG KANAN 2 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-70);
	glVertex3f(20.0,13,-70);
	glVertex3f(20.0,-13,-70);
	glVertex3f(40.0,-13,-70);
	glEnd();

	//GEDUNG KANAN 2 kanannya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,-70);
	glVertex3f(20.0,-13,-70);
	glVertex3f(20.0,-13,-80);
	glVertex3f(40.0,-13,-80);
	glEnd();

    //GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,-95);
	glVertex3f(40.0,-13,-105);
	glVertex3f(40.0,13,-105);
	glVertex3f(40.0,13,-95);
	glEnd();

	//GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(20.0,-13,-95);
	glVertex3f(20.0,-13,-105);
	glVertex3f(20.0,13,-105);
	glVertex3f(20.0,13,-95);
	glEnd();

	//GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-105);
	glVertex3f(20.0,13,-105);
	glVertex3f(20.0,13,-95);
	glVertex3f(40.0,13,-95);
	glEnd();

	//GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-105);
	glVertex3f(20.0,13,-105);
	glVertex3f(20.0,-13,-105);
	glVertex3f(40.0,-13,-105);
	glEnd();

	//GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,13,-95);
	glVertex3f(20.0,13,-95);
	glVertex3f(20.0,-13,-95);
	glVertex3f(40.0,-13,-95);
	glEnd();

	//GEDUNG KANAN 2 kirinya
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(40.0,-13,-95);
	glVertex3f(20.0,-13,-95);
	glVertex3f(20.0,-13,-105);
	glVertex3f(40.0,-13,-105);
	glEnd();

    //JENDELA BESAR KIRI
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-6,-98);
	glVertex3f(19.9,-6,-103);
	glVertex3f(19.9,8,-103);
	glVertex3f(19.9,8,-98);
	glEnd();

	//JENDELA BESAR KANAN
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-6,-72);
	glVertex3f(19.9,-6,-77);
	glVertex3f(19.9,8,-77);
	glVertex3f(19.9,8,-72);
	glEnd();

	//JENDELA BESAR TENGAH
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(19.9,-10,-83);
	glVertex3f(19.9,-10,-93);
	glVertex3f(19.9,10,-93);
	glVertex3f(19.9,10,-83);


    //GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,-13,-80);
	glVertex3f(80.0,-13,10);
	glVertex3f(80.0,13,10);
	glVertex3f(80.0,13,-80);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(70.0,-13,-80);
	glVertex3f(70.0,-13,10);
	glVertex3f(70.0,13,10);
	glVertex3f(70.0,13,-80);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,13,10);
	glVertex3f(70.0,13,10);
	glVertex3f(70.0,13,-80);
	glVertex3f(80.0,13,-80);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(80.0,13,10);
	glVertex3f(70.0,13,10);
	glVertex3f(70.0,-13,10);
	glVertex3f(80.0,-13,10);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(74, 122, 255);
	glVertex3f(80.0,13,-80);
	glVertex3f(70.0,13,-80);
	glVertex3f(70.0,-13,-80);
	glVertex3f(80.0,-13,-80);
	glEnd();

	//GEDUNG KANAN BELAKANG
	glBegin(GL_QUADS);
	glColor3ub(51, 0, 115);
	glVertex3f(80.0,-13,10);
	glVertex3f(70.0,-13,10);
	glVertex3f(70.0,-13,-80);
	glVertex3f(80.0,-13,-80);
	glEnd();


    //GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(80.0,13,-45);
	glVertex3f(80.0,13,-25);
	glVertex3f(80.0,30,-25);
	glVertex3f(80.0,30,-45);
	glEnd();

	//GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(70.0,13,-45);
	glVertex3f(70.0,13,-25);
	glVertex3f(70.0,30,-25);
	glVertex3f(70.0,30,-45);
	glEnd();

	//GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(80.0,30,-25);
	glVertex3f(70.0,30,-25);
	glVertex3f(70.0,30,-45);
	glVertex3f(80.0,30,-45);
	glEnd();

	//GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(80.0,30,-25);
	glVertex3f(70.0,30,-25);
	glVertex3f(70.0,13,-25);
	glVertex3f(80.0,13,-25);
	glEnd();

	//GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(80.0,30,-45);
	glVertex3f(70.0,30,-45);
	glVertex3f(70.0,13,-45);
	glVertex3f(80.0,13,-45);
	glEnd();

	//GEDUNG KANAN BELAKANG batang tengah
	glBegin(GL_QUADS);
	glColor3ub(115, 115, 115);
	glVertex3f(80.0,13,-25);
	glVertex3f(70.0,13,-25);
	glVertex3f(70.0,13,-45);
	glVertex3f(80.0,13,-45);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,13,-60);
	glVertex3f(80.0,13,-45);
	glVertex3f(80.0,40,-45);
	glVertex3f(80.0,40,-60);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,13,-60);
	glVertex3f(70.0,13,-45);
	glVertex3f(70.0,40,-45);
	glVertex3f(70.0,40,-60);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-45);
	glVertex3f(70.0,40,-45);
	glVertex3f(70.0,40,-60);
	glVertex3f(80.0,40,-60);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-45);
	glVertex3f(70.0,40,-45);
	glVertex3f(70.0,13,-45);
	glVertex3f(80.0,13,-45);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-60);
	glVertex3f(70.0,40,-60);
	glVertex3f(70.0,13,-60);
	glVertex3f(80.0,13,-60);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,13,-45);
	glVertex3f(70.0,13,-45);
	glVertex3f(70.0,13,-60);
	glVertex3f(80.0,13,-60);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,13,-10);
	glVertex3f(80.0,13,-25);
	glVertex3f(80.0,40,-25);
	glVertex3f(80.0,40,-10);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,13,-25);
	glVertex3f(70.0,13,-10);
	glVertex3f(70.0,40,-10);
	glVertex3f(70.0,40,-25);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-10);
	glVertex3f(70.0,40,-10);
	glVertex3f(70.0,40,-25);
	glVertex3f(80.0,40,-25);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,35,-10);
	glVertex3f(70.0,35,-10);
	glVertex3f(70.0,13,-10);
	glVertex3f(80.0,13,-10);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,35,-25);
	glVertex3f(70.0,35,-25);
	glVertex3f(70.0,13,-25);
	glVertex3f(80.0,13,-25);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,13,-10);
	glVertex3f(70.0,13,-10);
	glVertex3f(70.0,13,-25);
	glVertex3f(80.0,13,-25);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-58);
	glVertex3f(80.0,40,-47);
	glVertex3f(80.0,50,-47);
	glVertex3f(80.0,50,-58);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,40,-58);
	glVertex3f(70.0,40,-47);
	glVertex3f(70.0,50,-47);
	glVertex3f(70.0,50,-58);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-47);
	glVertex3f(70.0,50,-47);
	glVertex3f(70.0,50,-58);
	glVertex3f(80.0,50,-58);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-47);
	glVertex3f(70.0,50,-47);
	glVertex3f(70.0,40,-47);
	glVertex3f(80.0,40,-47);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-58);
	glVertex3f(70.0,50,-58);
	glVertex3f(70.0,40,-58);
	glVertex3f(80.0,40,-58);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-47);
	glVertex3f(70.0,40,-47);
	glVertex3f(70.0,40,-58);
	glVertex3f(80.0,40,-58);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-55);
	glVertex3f(80.0,50,-50);
	glVertex3f(80.0,55,-50);
	glVertex3f(80.0,55,-55);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,50,-55);
	glVertex3f(70.0,50,-50);
	glVertex3f(70.0,55,-50);
	glVertex3f(70.0,55,-55);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-50);
	glVertex3f(70.0,55,-50);
	glVertex3f(70.0,55,-55);
	glVertex3f(80.0,55,-55);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-50);
	glVertex3f(70.0,55,-50);
	glVertex3f(70.0,50,-50);
	glVertex3f(80.0,50,-50);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-55);
	glVertex3f(70.0,55,-55);
	glVertex3f(70.0,50,-55);
	glVertex3f(80.0,50,-55);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-50);
	glVertex3f(70.0,50,-50);
	glVertex3f(70.0,50,-55);
	glVertex3f(80.0,50,-55);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-12);
	glVertex3f(80.0,40,-23);
	glVertex3f(80.0,50,-23);
	glVertex3f(80.0,50,-12);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,40,-23);
	glVertex3f(70.0,40,-12);
	glVertex3f(70.0,50,-12);
	glVertex3f(70.0,50,-23);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-12);
	glVertex3f(70.0,50,-12);
	glVertex3f(70.0,50,-23);
	glVertex3f(80.0,50,-23);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-12);
	glVertex3f(70.0,50,-12);
	glVertex3f(70.0,40,-12);
	glVertex3f(80.0,40,-12);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-23);
	glVertex3f(70.0,50,-23);
	glVertex3f(70.0,40,-23);
	glVertex3f(80.0,40,-23);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,40,-12);
	glVertex3f(70.0,40,-12);
	glVertex3f(70.0,40,-23);
	glVertex3f(80.0,40,-23);
	glEnd();

    //GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-15);
	glVertex3f(80.0,50,-20);
	glVertex3f(80.0,55,-20);
	glVertex3f(80.0,55,-15);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(70.0,50,-20);
	glVertex3f(70.0,50,-15);
	glVertex3f(70.0,55,-15);
	glVertex3f(70.0,55,-20);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-15);
	glVertex3f(70.0,55,-15);
	glVertex3f(70.0,55,-20);
	glVertex3f(80.0,55,-20);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-15);
	glVertex3f(70.0,55,-15);
	glVertex3f(70.0,50,-15);
	glVertex3f(80.0,50,-15);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,55,-20);
	glVertex3f(70.0,55,-20);
	glVertex3f(70.0,50,-20);
	glVertex3f(80.0,50,-20);
	glEnd();

	//GEDUNG KANAN BELAKANG batang kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(80.0,50,-15);
	glVertex3f(70.0,50,-15);
	glVertex3f(70.0,50,-20);
	glVertex3f(80.0,50,-20);
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
	glColor3ub(255,64,64);
	glVertex3f(79.0,-13,-95);
	glVertex3f(79.0,-13,-80);
	glVertex3f(79.0,5,-80);
	glVertex3f(79.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(69.0,-13,-95);
	glVertex3f(69.0,-13,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,5,-95);
	glVertex3f(79.0,5,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,-80);
	glVertex3f(69.0,5,-80);
	glVertex3f(69.0,-13,-80);
	glVertex3f(79.0,-13,-80);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,-95);
	glVertex3f(69.0,5,-95);
	glVertex3f(69.0,-13,-95);
	glVertex3f(79.0,-13,-95);
	glEnd();

	//lemari kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
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
	glColor3ub(255,64,64);
	glVertex3f(79.0,-13,25);
	glVertex3f(79.0,-13,10);
	glVertex3f(79.0,5,10);
	glVertex3f(79.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(69.0,-13,25);
	glVertex3f(69.0,-13,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,5,25);
	glVertex3f(79.0,5,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,10);
	glVertex3f(69.0,5,10);
	glVertex3f(69.0,-13,10);
	glVertex3f(79.0,-13,10);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
	glVertex3f(79.0,5,25);
	glVertex3f(69.0,5,25);
	glVertex3f(69.0,-13,25);
	glVertex3f(79.0,-13,25);
	glEnd();

	//lemari kanan depan
	glBegin(GL_QUADS);
	glColor3ub(255,64,64);
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

    // BINGKAI KIRI
	glBegin(GL_POLYGON);
	glColor3ub(184, 184, 184);
	glVertex3f(-78.0,3,-45.0);
	glVertex3f(-78.0,-8,-45.0);
	glVertex3f(-78.0,-8,-65.0);
	glVertex3f(-78.0,3,-65.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(255, 184, 69);
	glVertex3f(-78.0,3,-45.0);
	glVertex3f(-78.0,-8,-45.0);
	glVertex3f(-78.0,-8,-65.0);
	glVertex3f(-78.0,3,-65.0);
	glEnd();

	// OBJEK BINGKAI KIRI
	glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(-79.0,1,-57.0);
	glVertex3f(-75.0,-5,-57.0);
	glVertex3f(-76.0,1,-63.0);
	glEnd();

	// OBJEK BINGKAI KIRI
	glBegin(GL_POLYGON);
	glColor3ub(255, 226, 79);
	glVertex3f(-79.0,1,-47.0);
	glVertex3f(-75.0,-5,-47.0);
	glVertex3f(-76.0,1,-53.0);
	glEnd();

    // BINGKAI KANAN 1
	glBegin(GL_POLYGON);
	glColor3ub(184, 184, 184);
	glVertex3f(78.0,6,-40.0);
	glVertex3f(78.0,-11,-40.0);
	glVertex3f(78.0,-11,-65.0);
	glVertex3f(78.0,6,-65.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(255, 184, 69);
	glVertex3f(78.0,6,-40.0);
	glVertex3f(78.0,-11,-40.0);
	glVertex3f(78.0,-11,-65.0);
	glVertex3f(78.0,6,-65.0);
	glEnd();

	// OBJEK BINGKAI KANAN BELAKANG 1
	glBegin(GL_POLYGON);
	glColor3ub(36, 0, 112);
	glVertex3f(79.0,0,-57.0);
	glVertex3f(75.0,-5,-57.0);
	glVertex3f(76.0,0,-63.0);
	glEnd();

	// OBJEK BINGKAI KANAN BELAKANG 2
	glBegin(GL_POLYGON);
	glColor3ub(255, 226, 79);
	glVertex3f(79.0,3,-55.0);
	glVertex3f(75.0,-5,-55.0);
	glVertex3f(76.0,3,-49.0);
	glEnd();

	// OBJEK BINGKAI KANAN BELAKANG 3
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(79.0,3,-48.0);
	glVertex3f(75.0,-8,-47.0);
	glVertex3f(76.0,3,-43.0);
	glEnd();

    // BINGKAI KANAN 2
	glBegin(GL_POLYGON);
	glColor3ub(184, 184, 184);
	glVertex3f(78.0,6,-5.0);
	glVertex3f(78.0,-11,-5.0);
	glVertex3f(78.0,-11,-30.0);
	glVertex3f(78.0,6,-30.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3ub(255, 184, 69);
	glVertex3f(78.0,6,-5.0);
	glVertex3f(78.0,-11,-5.0);
	glVertex3f(78.0,-11,-30.0);
	glVertex3f(78.0,6,-30.0);
	glEnd();

	// OBJEK BINGKAI KANAN DEPAN 1
	glBegin(GL_POLYGON);
	glColor3ub(255, 226, 79);
	glVertex3f(79.0,0,-22.0);
	glVertex3f(75.0,-5,-22.0);
	glVertex3f(76.0,0,-27.0);
	glEnd();

	// OBJEK BINGKAI KANAN DEPAN 2
	glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(79.0,3,-16.0);
	glVertex3f(75.0,-5,-16.0);
	glVertex3f(76.0,3,-21.0);
	glEnd();

    // OBJEK BINGKAI KANAN DEPAN 3
	glBegin(GL_POLYGON);
	glColor3ub(255, 184, 69);
	glVertex3f(79.0,1,-8.0);
	glVertex3f(75.0,-5,-8.0);
	glVertex3f(76.0,-2,-14.0);
	glEnd();


    //PINTU kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(52,-13.0,-79.9);
	glVertex3f(52,-2.5,-79.9);
	glVertex3f(56,-2.5,-79.9);
	glVertex3f(56,-13.0,-79.9);
	glEnd();

	//PINTU kanan belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(44,-13.0,-79.9);
	glVertex3f(44,-2.5,-79.9);
	glVertex3f(48,-2.5,-79.9);
	glVertex3f(48,-13.0,-79.9);
	glEnd();

	//PINTU kanan belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(60,-13.0,-79.9);
	glVertex3f(60,-2.5,-79.9);
	glVertex3f(64,-2.5,-79.9);
	glVertex3f(64,-13.0,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(40,12,-79.9);
	glVertex3f(40,0,-79.9);
	glVertex3f(44,0,-79.9);
	glVertex3f(44,12,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(45,12,-79.9);
	glVertex3f(45,0,-79.9);
	glVertex3f(49,0,-79.9);
	glVertex3f(49,12,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(50,12,-79.9);
	glVertex3f(50,0,-79.9);
	glVertex3f(54,0,-79.9);
	glVertex3f(54,12,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(55,12,-79.9);
	glVertex3f(55,0,-79.9);
	glVertex3f(59,0,-79.9);
	glVertex3f(59,12,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(60,12,-79.9);
	glVertex3f(60,0,-79.9);
	glVertex3f(64,0,-79.9);
	glVertex3f(64,12,-79.9);
	glEnd();

	//kaca kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(65,12,-79.9);
	glVertex3f(65,0,-79.9);
	glVertex3f(69,0,-79.9);
	glVertex3f(69,12,-79.9);
	glEnd();

    //PINTU kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(52,-13.0,9.9);
	glVertex3f(52,-2.5,9.9);
	glVertex3f(56,-2.5,9.9);
	glVertex3f(56,-13.0,9.9);
	glEnd();

	//PINTU kanan belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(44,-13.0,9.9);
	glVertex3f(44,-2.5,9.9);
	glVertex3f(48,-2.5,9.9);
	glVertex3f(48,-13.0,9.9);
	glEnd();

	//PINTU kanan belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(60,-13.0,9.9);
	glVertex3f(60,-2.5,9.9);
	glVertex3f(64,-2.5,9.9);
	glVertex3f(64,-13.0,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(40,12,9.9);
	glVertex3f(40,0,9.9);
	glVertex3f(44,0,9.9);
	glVertex3f(44,12,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(45,12,9.9);
	glVertex3f(45,0,9.9);
	glVertex3f(49,0,9.9);
	glVertex3f(49,12,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(50,12,9.9);
	glVertex3f(50,0,9.9);
	glVertex3f(54,0,9.9);
	glVertex3f(54,12,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(55,12,9.9);
	glVertex3f(55,0,9.9);
	glVertex3f(59,0,9.9);
	glVertex3f(59,12,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(60,12,9.9);
	glVertex3f(60,0,9.9);
	glVertex3f(64,0,9.9);
	glVertex3f(64,12,9.9);
	glEnd();

	//kaca kanan depan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(65,12,9.9);
	glVertex3f(65,0,9.9);
	glVertex3f(69,0,9.9);
	glVertex3f(69,12,9.9);
	glEnd();

    //PINTU kiri belakang tengah
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-54,-13.0,-74.9);
	glVertex3f(-54,-2.5,-74.9);
	glVertex3f(-50,-2.5,-74.9);
	glVertex3f(-50,-13.0,-74.9);
	glEnd();

	 //PINTU kiri belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-62,-13.0,-74.9);
	glVertex3f(-62,-2.5,-74.9);
	glVertex3f(-58,-2.5,-74.9);
	glVertex3f(-58,-13.0,-74.9);
	glEnd();

	//PINTU kiri belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-46,-13.0,-74.9);
	glVertex3f(-46,-2.5,-74.9);
	glVertex3f(-42,-2.5,-74.9);
	glVertex3f(-42,-13.0,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-40,4,-74.9);
	glVertex3f(-40,0,-74.9);
	glVertex3f(-36,0,-74.9);
	glVertex3f(-36,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-45,4,-74.9);
	glVertex3f(-45,0,-74.9);
	glVertex3f(-41,0,-74.9);
	glVertex3f(-41,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-50,4,-74.9);
	glVertex3f(-50,0,-74.9);
	glVertex3f(-46,0,-74.9);
	glVertex3f(-46,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-55,4,-74.9);
	glVertex3f(-55,0,-74.9);
	glVertex3f(-51,0,-74.9);
	glVertex3f(-51,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-60,4,-74.9);
	glVertex3f(-60,0,-74.9);
	glVertex3f(-56,0,-74.9);
	glVertex3f(-56,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-65,4,-74.9);
	glVertex3f(-65,0,-74.9);
	glVertex3f(-61,0,-74.9);
	glVertex3f(-61,4,-74.9);
	glEnd();

	//kaca kiri belakang 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-70,4,-74.9);
	glVertex3f(-70,0,-74.9);
	glVertex3f(-66,0,-74.9);
	glVertex3f(-66,4,-74.9);
	glEnd();

    //kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-40,9,-74.9);
	glVertex3f(-40,5,-74.9);
	glVertex3f(-36,5,-74.9);
	glVertex3f(-36,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-45,9,-74.9);
	glVertex3f(-45,5,-74.9);
	glVertex3f(-41,5,-74.9);
	glVertex3f(-41,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-50,9,-74.9);
	glVertex3f(-50,5,-74.9);
	glVertex3f(-46,5,-74.9);
	glVertex3f(-46,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-55,9,-74.9);
	glVertex3f(-55,5,-74.9);
	glVertex3f(-51,5,-74.9);
	glVertex3f(-51,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-60,9,-74.9);
	glVertex3f(-60,5,-74.9);
	glVertex3f(-56,5,-74.9);
	glVertex3f(-56,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-65,9,-74.9);
	glVertex3f(-65,5,-74.9);
	glVertex3f(-61,5,-74.9);
	glVertex3f(-61,9,-74.9);
	glEnd();

	//kaca kiri belakang 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-70,9,-74.9);
	glVertex3f(-70,5,-74.9);
	glVertex3f(-66,5,-74.9);
	glVertex3f(-66,9,-74.9);
	glEnd();

    //PINTU kiri depan tengah
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-54,-13.0,-35.1);
	glVertex3f(-54,-2.5,-35.1);
	glVertex3f(-50,-2.5,-35.1);
	glVertex3f(-50,-13.0,-35.1);
	glEnd();

	//PINTU kiri depan kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-62,-13.0,-35.1);
	glVertex3f(-62,-2.5,-35.1);
	glVertex3f(-58,-2.5,-35.1);
	glVertex3f(-58,-13.0,-35.1);
	glEnd();

	//PINTU kiri depan kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-46,-13.0,-35.1);
	glVertex3f(-46,-2.5,-35.1);
	glVertex3f(-42,-2.5,-35.1);
	glVertex3f(-42,-13.0,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-40,4,-35.1);
	glVertex3f(-40,0,-35.1);
	glVertex3f(-36,0,-35.1);
	glVertex3f(-36,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-45,4,-35.1);
	glVertex3f(-45,0,-35.1);
	glVertex3f(-41,0,-35.1);
	glVertex3f(-41,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-50,4,-35.1);
	glVertex3f(-50,0,-35.1);
	glVertex3f(-46,0,-35.1);
	glVertex3f(-46,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-55,4,-35.1);
	glVertex3f(-55,0,-35.1);
	glVertex3f(-51,0,-35.1);
	glVertex3f(-51,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-60,4,-35.1);
	glVertex3f(-60,0,-35.1);
	glVertex3f(-56,0,-35.1);
	glVertex3f(-56,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-65,4,-35.1);
	glVertex3f(-65,0,-35.1);
	glVertex3f(-61,0,-35.1);
	glVertex3f(-61,4,-35.1);
	glEnd();

	//kaca kiri depan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-70,4,-35.1);
	glVertex3f(-70,0,-35.1);
	glVertex3f(-66,0,-35.1);
	glVertex3f(-66,4,-35.1);
	glEnd();

    //kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-40,9,-35.1);
	glVertex3f(-40,5,-35.1);
	glVertex3f(-36,5,-35.1);
	glVertex3f(-36,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-45,9,-35.1);
	glVertex3f(-45,5,-35.1);
	glVertex3f(-41,5,-35.1);
	glVertex3f(-41,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-50,9,-35.1);
	glVertex3f(-50,5,-35.1);
	glVertex3f(-46,5,-35.1);
	glVertex3f(-46,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-55,9,-35.1);
	glVertex3f(-55,5,-35.1);
	glVertex3f(-51,5,-35.1);
	glVertex3f(-51,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-60,9,-35.1);
	glVertex3f(-60,5,-35.1);
	glVertex3f(-56,5,-35.1);
	glVertex3f(-56,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-65,9,-35.1);
	glVertex3f(-65,5,-35.1);
	glVertex3f(-61,5,-35.1);
	glVertex3f(-61,9,-35.1);
	glEnd();

	//kaca kiri depan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-70,9,-35.1);
	glVertex3f(-70,5,-35.1);
	glVertex3f(-66,5,-35.1);
	glVertex3f(-66,9,-35.1);
	glEnd();


    //PINTU GEDUNG KIRI BELAKANG 1
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-69.9,-2.5,-48);
	glVertex3f(-69.9,-2.5,-52);
	glVertex3f(-69.9,-13,-52);
	glVertex3f(-69.9,-13,-48);
	glEnd();

	 //PINTU GEDUNG KIRI BELAKANG 2
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-69.9,-2.5,-60);
	glVertex3f(-69.9,-2.5,-64);
	glVertex3f(-69.9,-13,-64);
	glVertex3f(-69.9,-13,-60);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-70);
	glVertex3f(-69.9,9,-74);
	glVertex3f(-69.9,5,-74);
	glVertex3f(-69.9,5,-70);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-65);
	glVertex3f(-69.9,9,-69);
	glVertex3f(-69.9,5,-69);
	glVertex3f(-69.9,5,-65);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-60);
	glVertex3f(-69.9,9,-64);
	glVertex3f(-69.9,5,-64);
	glVertex3f(-69.9,5,-60);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-55);
	glVertex3f(-69.9,9,-59);
	glVertex3f(-69.9,5,-59);
	glVertex3f(-69.9,5,-55);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-50);
	glVertex3f(-69.9,9,-54);
	glVertex3f(-69.9,5,-54);
	glVertex3f(-69.9,5,-50);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-45);
	glVertex3f(-69.9,9,-49);
	glVertex3f(-69.9,5,-49);
	glVertex3f(-69.9,5,-45);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-40);
	glVertex3f(-69.9,9,-44);
	glVertex3f(-69.9,5,-44);
	glVertex3f(-69.9,5,-40);
	glEnd();

	//kaca atas
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,9,-35.5);
	glVertex3f(-69.9,9,-39.5);
	glVertex3f(-69.9,5,-39.5);
	glVertex3f(-69.9,5,-35.5);
	glEnd();

    //kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-70);
	glVertex3f(-69.9,4,-74);
	glVertex3f(-69.9,0,-74);
	glVertex3f(-69.9,0,-70);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-65);
	glVertex3f(-69.9,4,-69);
	glVertex3f(-69.9,0,-69);
	glVertex3f(-69.9,0,-65);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-60);
	glVertex3f(-69.9,4,-64);
	glVertex3f(-69.9,0,-64);
	glVertex3f(-69.9,0,-60);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-55);
	glVertex3f(-69.9,4,-59);
	glVertex3f(-69.9,0,-59);
	glVertex3f(-69.9,0,-55);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-50);
	glVertex3f(-69.9,4,-54);
	glVertex3f(-69.9,0,-54);
	glVertex3f(-69.9,0,-50);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-45);
	glVertex3f(-69.9,4,-49);
	glVertex3f(-69.9,0,-49);
	glVertex3f(-69.9,0,-45);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-40);
	glVertex3f(-69.9,4,-44);
	glVertex3f(-69.9,0,-44);
	glVertex3f(-69.9,0,-40);
	glEnd();

	//kaca bawah
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(-69.9,4,-35.5);
	glVertex3f(-69.9,4,-39.5);
	glVertex3f(-69.9,0,-39.5);
	glVertex3f(-69.9,0,-35.5);
	glEnd();

    //PINTU GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,-3,-39);
	glVertex3f(69.9,-3,-44);
	glVertex3f(69.9,-10,-44);
	glVertex3f(69.9,-10,-39);
	glEnd();

    //PINTU GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(69.9,0,-33);
	glVertex3f(69.9,0,-38);
	glVertex3f(69.9,-13,-38);
	glVertex3f(69.9,-13,-33);
	glEnd();

	//PINTU GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,-3,-27);
	glVertex3f(69.9,-3,-32);
	glVertex3f(69.9,-10,-32);
	glVertex3f(69.9,-10,-27);
	glEnd();

    //kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,14,-39);
	glVertex3f(69.9,14,-44);
	glVertex3f(69.9,2,-44);
	glVertex3f(69.9,2,-39);
	glEnd();

	//kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,14,-33);
	glVertex3f(69.9,14,-38);
	glVertex3f(69.9,2,-38);
	glVertex3f(69.9,2,-33);
	glEnd();

	//kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,14,-27);
	glVertex3f(69.9,14,-32);
	glVertex3f(69.9,2,-32);
	glVertex3f(69.9,2,-27);
	glEnd();

    //kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,27,-39);
	glVertex3f(69.9,27,-44);
	glVertex3f(69.9,15,-44);
	glVertex3f(69.9,15,-39);
	glEnd();

	//kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 18, 18);
	glVertex3f(69.9,27,-33);
	glVertex3f(69.9,27,-38);
	glVertex3f(69.9,15,-38);
	glVertex3f(69.9,15,-33);
	glEnd();

	//kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,27,-27);
	glVertex3f(69.9,27,-32);
	glVertex3f(69.9,15,-32);
	glVertex3f(69.9,15,-27);
	glEnd();

    //kaca GEDUNG kanan paling kanan tiang pancar 1
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,2,-16);
	glVertex3f(69.9,2,-21);
	glVertex3f(69.9,-11,-21);
	glVertex3f(69.9,-11,-16);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 1
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,15,-16);
	glVertex3f(69.9,15,-21);
	glVertex3f(69.9,3,-21);
	glVertex3f(69.9,3,-16);
	glEnd();

    //kaca GEDUNG kanan paling kanan tiang pancar 1 double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,29,-19);
	glVertex3f(69.9,29,-24);
	glVertex3f(69.9,16,-24);
	glVertex3f(69.9,16,-19);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 1 double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,29,-12);
	glVertex3f(69.9,29,-17);
	glVertex3f(69.9,16,-17);
	glVertex3f(69.9,16,-12);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 1 atas double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,38.5,-19);
	glVertex3f(69.9,38.5,-24);
	glVertex3f(69.9,32,-24);
	glVertex3f(69.9,32,-19);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 1 atas double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,38.5,-12);
	glVertex3f(69.9,38.5,-17);
	glVertex3f(69.9,32,-17);
	glVertex3f(69.9,32,-12);
	glEnd();

    //kaca GEDUNG kanan paling kanan tiang pancar 2
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,2,-51);
	glVertex3f(69.9,2,-56);
	glVertex3f(69.9,-11,-56);
	glVertex3f(69.9,-11,-51);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 2
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,15,-51);
	glVertex3f(69.9,15,-56);
	glVertex3f(69.9,3,-56);
	glVertex3f(69.9,3,-51);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 2 double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,29,-54);
	glVertex3f(69.9,29,-59);
	glVertex3f(69.9,16,-59);
	glVertex3f(69.9,16,-54);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 2 double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,29,-47);
	glVertex3f(69.9,29,-52);
	glVertex3f(69.9,16,-52);
	glVertex3f(69.9,16,-47);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 2 atas double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,38.5,-54);
	glVertex3f(69.9,38.5,-59);
	glVertex3f(69.9,32,-59);
	glVertex3f(69.9,32,-54);
	glEnd();

	//kaca GEDUNG kanan paling kanan tiang pancar 2 atas double
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,38.5,-47);
	glVertex3f(69.9,38.5,-52);
	glVertex3f(69.9,32,-52);
	glVertex3f(69.9,32,-47);
	glEnd();

    //kaca GEDUNG kanan paling kanan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,4);
	glVertex3f(69.9,0,9);
	glVertex3f(69.9,-10,9);
	glVertex3f(69.9,-10,4);
	glEnd();

	//kaca GEDUNG kanan paling kanan 1
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,4);
	glVertex3f(69.9,11,9);
	glVertex3f(69.9,1,9);
	glVertex3f(69.9,1,4);
	glEnd();

    //kaca GEDUNG kanan paling kanan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,-2);
	glVertex3f(69.9,0,3);
	glVertex3f(69.9,-10,3);
	glVertex3f(69.9,-10,-2);
	glEnd();

	//kaca GEDUNG kanan paling kanan 2
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,-2);
	glVertex3f(69.9,11,3);
	glVertex3f(69.9,1,3);
	glVertex3f(69.9,1,-2);
	glEnd();

	//kaca GEDUNG kanan paling kanan 3
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,-8);
	glVertex3f(69.9,0,-3);
	glVertex3f(69.9,-10,-3);
	glVertex3f(69.9,-10,-8);
	glEnd();

	//kaca GEDUNG kanan paling kanan 3
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,-8);
	glVertex3f(69.9,11,-3);
	glVertex3f(69.9,1,-3);
	glVertex3f(69.9,1,-8);
	glEnd();

    //kaca GEDUNG kanan paling kanan 4
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,-67);
	glVertex3f(69.9,0,-62);
	glVertex3f(69.9,-10,-62);
	glVertex3f(69.9,-10,-67);
	glEnd();

	//kaca GEDUNG kanan paling kanan 4
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,-67);
	glVertex3f(69.9,11,-62);
	glVertex3f(69.9,1,-62);
	glVertex3f(69.9,1,-67);
	glEnd();

    //kaca GEDUNG kanan paling kanan 5
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,-73);
	glVertex3f(69.9,0,-68);
	glVertex3f(69.9,-10,-68);
	glVertex3f(69.9,-10,-73);
	glEnd();

	//kaca GEDUNG kanan paling kanan 5
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,-73);
	glVertex3f(69.9,11,-68);
	glVertex3f(69.9,1,-68);
	glVertex3f(69.9,1,-73);
	glEnd();

    //kaca GEDUNG kanan paling kanan 6
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,0,-79);
	glVertex3f(69.9,0,-74);
	glVertex3f(69.9,-10,-74);
	glVertex3f(69.9,-10,-79);
	glEnd();

	//kaca GEDUNG kanan paling kanan 6
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,11,-79);
	glVertex3f(69.9,11,-74);
	glVertex3f(69.9,1,-74);
	glVertex3f(69.9,1,-79);
	glEnd();

    //genteng depan kiri bagian kiri 1
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-35.5,10,-45);
	glVertex3f(-29.5,16,-45);
	glVertex3f(-29.5,16,28);
	glVertex3f(-35.5,10,28);
	glEnd();

	//genteng depan kanan bagian kiri 1
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-24.5,10,-45);
	glVertex3f(-30.5,16,-45);
	glVertex3f(-30.5,16,28);
	glVertex3f(-24.5,10,28);
	glEnd();

    //tutup
    glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(-36.0,10,28.1);
	glVertex3f(-24.5,10,28.1);
	glVertex3f(-30.5,16,28.1);
	glEnd();

    //genteng depan kiri bagian kiri 2
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-35.5,10,-95);
	glVertex3f(-29.5,16,-95);
	glVertex3f(-29.5,16,-60);
	glVertex3f(-35.5,10,-60);
	glEnd();

	//genteng depan kanan bagian kiri 2
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-24.5,10,-95);
	glVertex3f(-30.5,16,-95);
	glVertex3f(-30.5,16,-60);
	glVertex3f(-24.5,10,-60);
	glEnd();

    //tutup
	glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(-36.0,10,-95.1);
	glVertex3f(-24.5,10,-95.1);
	glVertex3f(-30.5,16,-95.1);
	glEnd();

    //genteng belakang kiri
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-80.5,10,-85);
	glVertex3f(-74.5,15.5,-85);
	glVertex3f(-74.5,15.5,-25);
	glVertex3f(-80.5,10,-25);
	glEnd();

	//genteng belakang kanan
	glBegin(GL_QUADS);
	glColor3ub(0 ,100 ,0);
	glVertex3f(-69.5,10,-85);
	glVertex3f(-75.5,15.5,-85);
	glVertex3f(-75.5,15.5,-25);
	glVertex3f(-69.5,10,-25);
	glEnd();

	//tutup
    glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(-81.0,10,-85.1);
	glVertex3f(-69.5,10,-85.1);
	glVertex3f(-75.5,16,-85.1);
	glEnd();

	//tutup
	glBegin(GL_POLYGON);
	glColor3ub(163, 0, 0);
	glVertex3f(-81.0,10,-25.1);
	glVertex3f(-69.5,10,-25.1);
	glVertex3f(-75.5,16,-25.1);
	glEnd();

    //genteng belakang sisi kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-75,10,-35);
	glVertex3f(-75,15,-30);
	glVertex3f(-30,15,-30);
	glVertex3f(-30,10,-35);
	glEnd();

	//genteng belakang sisi kiri
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-30,10,-25);
	glVertex3f(-30,15,-30);
	glVertex3f(-75,15,-30);
	glVertex3f(-75,10,-25);
	glEnd();

    //genteng belakang sisi kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-75,10,-85);
	glVertex3f(-75,15,-80);
	glVertex3f(-30,15,-80);
	glVertex3f(-30,10,-85);
	glEnd();

	//genteng belakang sisi kanan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(-30,10,-75);
	glVertex3f(-30,15,-80);
	glVertex3f(-75,15,-80);
	glVertex3f(-75,10,-75);
	glEnd();

    //genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(80,13,-95);
	glVertex3f(80,22,-87);
	glVertex3f(20,22,-87);
	glVertex3f(20,13,-95);
	glEnd();

	//genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(80,13,-80);
	glVertex3f(80,22,-88);
	glVertex3f(20,22,-88);
	glVertex3f(20,13,-80);
	glEnd();

    //genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,-95);
	glVertex3f(40,22,-100);
	glVertex3f(20,22,-100);
	glVertex3f(20,13,-95);
	glEnd();

	//genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,-105);
	glVertex3f(40,22,-100);
	glVertex3f(20,22,-100);
	glVertex3f(20,13,-105);
	glEnd();

	//genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,-70);
	glVertex3f(40,22,-75);
	glVertex3f(20,22,-75);
	glVertex3f(20,13,-70);
	glEnd();

	//genteng kanan belakang
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,-80);
	glVertex3f(40,22,-75);
	glVertex3f(20,22,-75);
	glVertex3f(20,13,-85);
	glEnd();

    //genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(80,13,25);
	glVertex3f(80,22,17);
	glVertex3f(20,22,17);
	glVertex3f(20,13,25);
	glEnd();

	//genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(80,13,10);
	glVertex3f(80,22,18);
	glVertex3f(20,22,18);
	glVertex3f(20,13,10);
	glEnd();

    //genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,35);
	glVertex3f(40,22,30);
	glVertex3f(20,22,30);
	glVertex3f(20,13,35);
	glEnd();

	//genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,25);
	glVertex3f(40,22,30);
	glVertex3f(20,22,30);
	glVertex3f(20,13,25);
	glEnd();

	//genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,10);
	glVertex3f(40,22,5);
	glVertex3f(20,22,5);
	glVertex3f(20,13,10);
	glEnd();

	//genteng kanan depan
	glBegin(GL_QUADS);
	glColor3ub(107, 25, 0);
	glVertex3f(40,13,0);
	glVertex3f(40,22,5);
	glVertex3f(20,22,5);
	glVertex3f(20,13,0);
	glEnd();

    // genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,25.0);
	glVertex3f(20,13,35.0);
	glVertex3f(20,23,30.0);
	glEnd();

	// genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(40,13,25.0);
	glVertex3f(40,13,35.0);
	glVertex3f(40,23,30.0);
	glEnd();

    // genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,0);
	glVertex3f(20,13,10);
	glVertex3f(20,23,5);
	glEnd();

	// genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(40,13,0);
	glVertex3f(40,13,10);
	glVertex3f(40,23,5);
	glEnd();

    // genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,-80);
	glVertex3f(20,13,-70);
	glVertex3f(20,23,-75);
	glEnd();

	 // genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(40,13,-80);
	glVertex3f(40,13,-70);
	glVertex3f(40,23,-75);
	glEnd();

    // genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,-105);
	glVertex3f(20,13,-95);
	glVertex3f(20,23,-100);
	glEnd();

	// genteng kecil
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(40,13,-105);
	glVertex3f(40,13,-95);
	glVertex3f(40,23,-100);
	glEnd();

    // genteng besar
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,10.0);
	glVertex3f(20,13,25.0);
	glVertex3f(20,23.5,18.0);
	glEnd();

	// genteng besar
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(80,13,10.0);
	glVertex3f(80,13,25.0);
	glVertex3f(80,23.5,18.0);
	glEnd();

    // genteng besar
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(20,13,-80.0);
	glVertex3f(20,13,-95.0);
	glVertex3f(20,23.5,-88.0);
	glEnd();

	// genteng besar
	glBegin(GL_POLYGON);
	glColor3ub(74, 225, 255);
	glVertex3f(80,13,-80.0);
	glVertex3f(80,13,-95.0);
	glVertex3f(80,23.5,-88.0);
	glEnd();

    //object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-30);
	glVertex3f(19.5,-13,-28);
	glVertex3f(19.5,18,-28);
	glVertex3f(19.5,18,-30);
	glEnd();

	//object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(21.5,-13,-30);
	glVertex3f(21.5,-13,-28);
	glVertex3f(21.5,18,-28);
	glVertex3f(21.5,18,-30);
	glEnd();

	//object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,18,-28);
	glVertex3f(21.5,18,-28);
	glVertex3f(21.5,18,-30);
	glVertex3f(19.5,18,-30);
	glEnd();

	//object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-28);
	glVertex3f(21.5,-13,-28);
	glVertex3f(21.5,-13,-30);
	glVertex3f(19.5,-13,-30);
	glEnd();

	//object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-28);
	glVertex3f(21.5,-13,-28);
	glVertex3f(21.5,18,-28);
	glVertex3f(19.5,18,-28);
	glEnd();

	//object tiang kanan 1
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-30);
	glVertex3f(21.5,-13,-30);
	glVertex3f(21.5,18,-30);
	glVertex3f(19.5,18,-30);
	glEnd();

	//belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(22,18.0,-30);
	glVertex3f(20,18.0,-30);
	glVertex3f(21,22.0,-29);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(22,18.0,-30);
	glVertex3f(21,22.0,-29);
	glVertex3f(21,18.0,-28);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(20,18.0,-30);
	glVertex3f(21,18.0,-28);
	glVertex3f(21,22.0,-29);
	glEnd();

    //object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-30);
	glVertex3f(29,-13,-28);
	glVertex3f(29,18,-28);
	glVertex3f(29,18,-30);
	glEnd();

	//object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(31,-13,-30);
	glVertex3f(31,-13,-28);
	glVertex3f(31,18,-28);
	glVertex3f(31,18,-30);
	glEnd();

	//object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,18,-28);
	glVertex3f(31,18,-28);
	glVertex3f(31,18,-30);
	glVertex3f(29,18,-30);
	glEnd();

	//object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-28);
	glVertex3f(31,-13,-28);
	glVertex3f(31,-13,-30);
	glVertex3f(29,-13,-30);
	glEnd();

	//object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-28);
	glVertex3f(31,-13,-28);
	glVertex3f(31,18,-28);
	glVertex3f(29,18,-28);
	glEnd();

	//object tiang kanan 2
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-30);
	glVertex3f(31,-13,-30);
	glVertex3f(31,18,-30);
	glVertex3f(29,18,-30);
	glEnd();

	//belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(31,18.0,-30);
	glVertex3f(29,18.0,-30);
	glVertex3f(30,22.0,-29);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(31,18.0,-30);
	glVertex3f(30,22.0,-29);
	glVertex3f(30,18.0,-28);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(29,18.0,-30);
	glVertex3f(30,18.0,-28);
	glVertex3f(30,22.0,-29);
	glEnd();

    //object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-42);
	glVertex3f(29,-13,-40);
	glVertex3f(29,18,-40);
	glVertex3f(29,18,-42);
	glEnd();

	//object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(31,-13,-42);
	glVertex3f(31,-13,-40);
	glVertex3f(31,18,-40);
	glVertex3f(31,18,-42);
	glEnd();

	//object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,18,-40);
	glVertex3f(31,18,-40);
	glVertex3f(31,18,-42);
	glVertex3f(29,18,-42);
	glEnd();

	//object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-40);
	glVertex3f(31,-13,-40);
	glVertex3f(31,-13,-42);
	glVertex3f(29,-13,-42);
	glEnd();

	//object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-40);
	glVertex3f(31,-13,-40);
	glVertex3f(31,18,-40);
	glVertex3f(29,18,-40);
	glEnd();

	//object tiang kanan 3
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(29,-13,-42);
	glVertex3f(31,-13,-42);
	glVertex3f(31,18,-42);
	glVertex3f(29,18,-42);
	glEnd();

	//belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(31,18.0,-42);
	glVertex3f(29,18.0,-42);
	glVertex3f(30,22.0,-41);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(31,18.0,-42);
	glVertex3f(30,22.0,-41);
	glVertex3f(30,18.0,-40);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(29,18.0,-42);
	glVertex3f(30,18.0,-40);
	glVertex3f(30,22.0,-41);
	glEnd();

    //object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-42);
	glVertex3f(19.5,-13,-40);
	glVertex3f(19.5,18,-40);
	glVertex3f(19.5,18,-42);
	glEnd();

	//object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(21.5,-13,-42);
	glVertex3f(21.5,-13,-40);
	glVertex3f(21.5,18,-40);
	glVertex3f(21.5,18,-42);
	glEnd();

	//object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,18,-40);
	glVertex3f(21.5,18,-40);
	glVertex3f(21.5,18,-42);
	glVertex3f(19.5,18,-42);
	glEnd();

	//object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-40);
	glVertex3f(21.5,-13,-40);
	glVertex3f(21.5,-13,-42);
	glVertex3f(19.5,-13,-42);
	glEnd();

	//object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-40);
	glVertex3f(21.5,-13,-40);
	glVertex3f(21.5,18,-40);
	glVertex3f(19.5,18,-40);
	glEnd();

	//object tiang kanan 4
	glBegin(GL_QUADS);
	glColor3ub(105 ,105 ,105);
	glVertex3f(19.5,-13,-42);
	glVertex3f(21.5,-13,-42);
	glVertex3f(21.5,18,-42);
	glVertex3f(19.5,18,-42);
	glEnd();

	//belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(21.5,18.0,-42);
	glVertex3f(19.5,18.0,-42);
	glVertex3f(20.5,22.0,-41);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(21.5,18.0,-42);
	glVertex3f(20.5,22.0,-41);
	glVertex3f(20.5,18.0,-40);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(19.5,18.0,-42);
	glVertex3f(20.5,18.0,-40);
	glVertex3f(20.5,22.0,-41);
	glEnd();

    //buletan atas tembok
	glPushMatrix();
	glTranslatef(25,11,-35);
	glColor3ub(255, 203, 130);
	glRotatef(90,90,0,0);
	//glScalef(1.0,1.0,0.0);
	glutSolidSphere(7,12,14);
	glPopMatrix();

	//badan buletan tembok
	glPushMatrix();
	glTranslatef(25,9,-35);
	glRotatef(90, 90,0,0);
	glColor3ub(92, 92, 92);
	gluCylinder(obj,6,6,8,30,30);
	glPopMatrix();

    //belakang segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(26,18.0,-36);
	glVertex3f(24,18.0,-36);
	glVertex3f(25,22.0,-35);
	glEnd();

	//kanan segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(26,18.0,-36);
	glVertex3f(25,22.0,-35);
	glVertex3f(25,18.0,-34);
	glEnd();

	//kiri segitiga lancip
	glBegin(GL_TRIANGLES);
	glColor3ub(168, 168, 168);
	glVertex3f(24,18.0,-36);
	glVertex3f(25,18.0,-34);
	glVertex3f(25,22.0,-35);
	glEnd();

    //batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-25);
	glVertex3f(30.1,5,-28);
	glVertex3f(30.1,2,-28);
	glVertex3f(30.1,2,-25);
    glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-25);
	glVertex3f(19.9,5,-28);
	glVertex3f(19.9,2,-28);
	glVertex3f(19.9,2,-25);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-19);
	glVertex3f(30.1,5,-22);
	glVertex3f(30.1,2,-22);
	glVertex3f(30.1,2,-19);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-19);
	glVertex3f(19.9,5,-22);
	glVertex3f(19.9,2,-22);
	glVertex3f(19.9,2,-19);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-13);
	glVertex3f(30.1,5,-16);
	glVertex3f(30.1,2,-16);
	glVertex3f(30.1,2,-13);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-13);
	glVertex3f(19.9,5,-16);
	glVertex3f(19.9,2,-16);
	glVertex3f(19.9,2,-13);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-7);
	glVertex3f(30.1,5,-10);
	glVertex3f(30.1,2,-10);
	glVertex3f(30.1,2,-7);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-7);
	glVertex3f(19.9,5,-10);
	glVertex3f(19.9,2,-10);
	glVertex3f(19.9,2,-7);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-1);
	glVertex3f(30.1,5,-4);
	glVertex3f(30.1,2,-4);
	glVertex3f(30.1,2,-1);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-1);
	glVertex3f(19.9,5,-4);
	glVertex3f(19.9,2,-4);
	glVertex3f(19.9,2,-1);
	glEnd();

    //batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-42);
	glVertex3f(30.1,5,-45);
	glVertex3f(30.1,2,-45);
	glVertex3f(30.1,2,-42);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-42);
	glVertex3f(19.9,5,-45);
	glVertex3f(19.9,2,-45);
	glVertex3f(19.9,2,-42);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-48);
	glVertex3f(30.1,5,-51);
	glVertex3f(30.1,2,-51);
	glVertex3f(30.1,2,-48);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-48);
	glVertex3f(19.9,5,-51);
	glVertex3f(19.9,2,-51);
	glVertex3f(19.9,2,-48);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-54);
	glVertex3f(30.1,5,-57);
	glVertex3f(30.1,2,-57);
	glVertex3f(30.1,2,-54);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-54);
	glVertex3f(19.9,5,-57);
	glVertex3f(19.9,2,-57);
	glVertex3f(19.9,2,-54);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-60);
	glVertex3f(30.1,5,-63);
	glVertex3f(30.1,2,-63);
	glVertex3f(30.1,2,-60);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-60);
	glVertex3f(19.9,5,-63);
	glVertex3f(19.9,2,-63);
	glVertex3f(19.9,2,-60);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(30.1,5,-66);
	glVertex3f(30.1,5,-69);
	glVertex3f(30.1,2,-69);
	glVertex3f(30.1,2,-66);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(19.9,5,-66);
	glVertex3f(19.9,5,-69);
	glVertex3f(19.9,2,-69);
	glVertex3f(19.9,2,-66);
	glEnd();

    //kaca GEDUNG kanan paling kanan
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,49,-16);
	glVertex3f(69.9,49,-21);
	glVertex3f(69.9,41,-21);
	glVertex3f(69.9,41,-16);
	glEnd();

	//kaca GEDUNG kanan paling kiri
	glBegin(GL_QUADS);
	glColor3ub(18, 27, 18);
	glVertex3f(69.9,49,-50);
	glVertex3f(69.9,49,-55);
	glVertex3f(69.9,41,-55);
	glVertex3f(69.9,41,-50);
	glEnd();













	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-24.9,28,-58);
	glVertex3f(-24.9,28,-60);
	glVertex3f(-24.9,25,-60);
	glVertex3f(-24.9,25,-58);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-34.9,28,-58);
	glVertex3f(-34.9,28,-60);
	glVertex3f(-34.9,25,-60);
	glVertex3f(-34.9,25,-58);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-24.9,28,-52);
	glVertex3f(-24.9,28,-54);
	glVertex3f(-24.9,25,-54);
	glVertex3f(-24.9,25,-52);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-34.9,28,-52);
	glVertex3f(-34.9,28,-54);
	glVertex3f(-34.9,25,-54);
	glVertex3f(-34.9,25,-52);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-24.9,28,-46);
	glVertex3f(-24.9,28,-48);
	glVertex3f(-24.9,25,-48);
	glVertex3f(-24.9,25,-46);
	glEnd();

	//batako
	glBegin(GL_QUADS);
	glColor3ub(139 ,90 ,43);
	glVertex3f(-34.9,28,-46);
	glVertex3f(-34.9,28,-48);
	glVertex3f(-34.9,25,-48);
	glVertex3f(-34.9,25,-46);
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
