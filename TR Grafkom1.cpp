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
	glVertex3f(-40,-13,30);
	glVertex3f(40,-13,30);
	glVertex3f(40,-13,-70); //belakang tanah z nya u gedein kalau mau luas
	glVertex3f(-40,-13,-70); //belakang tanah z nya u gedein kalau mau luas
	glEnd();
	//JALAN
	glBegin(GL_QUADS);
	glColor3ub(255, 196, 140);
	glVertex3f(-2,-12.8,30);
	glVertex3f(2,-12.8,30);
	glVertex3f(2,-12.8,-9.5);
	glVertex3f(-2,-12.8,-9.5);
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
