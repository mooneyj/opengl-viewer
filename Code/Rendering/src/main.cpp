
#include <Vector3.h>
#include <Point3D.h>
#include <Triangle.h>
#include <vector>
#include <Line.h>
#include <Face1n.h>
#include <ListFace1n.h>
#include <STLObject.h>
#include <FileReader.h>
#include <Mat4x4.h>
#include <glut.h>
void drawAxes();
Point3D	eye(0., 0., 300.);
Point3D object(0., 0., 0.);
Point3D	upDir(0., 1., 0.);
int nMainWnd = -1;

double col[3] = {.1,0.5,0.};
Mat3x1 m1(col);
FileReader file1("D:\\Programs\\OpenGL\\google_repo\\data\\aa.stl");
STLObject stlObj1(m1);
void LoadSTL(STLObject &iObj)
{
	file1.GetSTLObject(iObj);
}

void changeSize(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(75,ratio,100,1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;
float dist = 10.;
Vector3 viewTranslate(1.,0,1);
void renderScene(void) 
{
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	eye.GetX(), eye.GetY(),eye.GetZ(),
			object.GetX(), object.GetY(),object.GetZ(),
			upDir.GetX(), upDir.GetY(),  upDir.GetZ());

	eye.Translate(viewTranslate,dist);
	
	//glRotatef(angle, 1.0f, 4.0f, 1.0f);
	//glTranslatef(dist, dist, 0);

	stlObj1.Draw();

	drawAxes();

	//angle+=0.5f;
	dist+=1;

	glutSwapBuffers();
}

void drawAxes()
{
	double color1[3] = {.3, 0.0, 0.0};
	double color2[3] = {.0, 0.3, 0.0};
	double color3[3] = {.0, 0.0, 0.3};
	Mat3x1 m1(color1), m2(color2), m3(color3);


	Point3D p1(-100, 0, 0);
	Point3D p2(100, 0, 0);
	LineR l1(&p1, &p2, m1);
	l1.Draw();	
	Point3D p3(0, -100, 0);
	Point3D p4(	0, 100, 0	);
	LineR l2(&p3, &p4, m2);
	l2.Draw();
	Point3D p5(0, 0, -100);
	Point3D p6(0, 0, 100);
	LineR l3(&p5, &p6, m2);
	l3.Draw();
}

void glutMouseFunc(int button, int state, int x, int y)
{
}
void processNormalKeys(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		glutDestroyWindow(nMainWnd);
		exit(0);
		break;
	}
}

void processSpecialKeys(int key, int x, int y)
{
}

int main(int argc, char **argv) 
{
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1024,860);
	nMainWnd = glutCreateWindow("Main Window");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMouseFunc(glutMouseFunc);

	LoadSTL(stlObj1);

	double d1[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	double d2[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	Mat4x4 m1(&d1[0][0]);Mat4x4 m2(&d2[0][0]);
	Mat4x4 m3 = m1*m2;

	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}
