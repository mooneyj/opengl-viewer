
#include <Vector3.h>
#include <Point3D.h>
#include <Triangle.h>
#include <vector>
#include <Line.h>
#include <Face1n.h>
#include <ListFace1n.h>
#include <STLObject.h>
#include <glut.h>
void drawAxes();
Vector3	eye(0., 0., 10.);
Vector3	object(0., 0., 0.);
Vector3	upDir(0., 1., 0.);
int nMainWnd = -1;


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
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

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

	glRotatef(angle, 1.0f, 4.0f, 1.0f);

	Point3D pts[3];
	Point3D p11(2,0,0);
	Point3D p12(0,2,0);
	Point3D p13(0,0,2);
	Point3D p21(2,0,0);
	Point3D p22(0,0,0);
	Point3D p23(0,0,2);
	Point3D p31(2,0,0);
	Point3D p32(0,2,0);
	Point3D p33(0,0,0);
	Point3D p41(0,0,0);
	Point3D p42(0,2,0);
	Point3D p43(0,0,2);
	double col[3] = {1.,0.,0.};
	Mat3x1 m1(col);
	Vector3 norm(1,0,0);
	TriangleR tri1(&p11,&p12,&p13, m1);
	TriangleR tri2(&p21,&p22,&p23, m1);
	TriangleR tri3(&p31,&p32,&p33, m1);
	TriangleR tri4(&p41,&p42,&p43, m1);
	Face1n f1(tri1,norm,m1);
	Face1n f2(tri2,norm,m1);
	Face1n f3(tri3,norm,m1);
	Face1n f4(tri4,norm,m1);
	double color1[3] = {.3, 0.0, 0.0};
	double color2[3] = {.0, 0.3, 0.0};
	double color3[3] = {.0, 0.0, 0.3};
	double color4[3] = {.3, 0.0, 0.3};
	Mat3x1 ma1(color1), ma2(color2), ma3(color3), ma4(color4);
	f1.SetColor(ma1);
	f2.SetColor(ma2);
	f3.SetColor(ma3);
	f4.SetColor(ma4);
	f1.Draw();
	f2.Draw();
	f3.Draw();
	f4.Draw();
	STLObject stlObj(ma1);
	stlObj.AddFace(&f1);
	stlObj.AddFace(&f2);
	stlObj.AddFace(&f3);
	stlObj.AddFace(&f4);
	
	stlObj.Draw();

	double dColVal = 0.5;
	m1.SetAt(0, & dColVal);
	m1.SetAt(1, & dColVal);
	m1.SetAt(2, & dColVal);
	LineR l1(&p11,&p12,m1);
	LineR l2(&p11,&p13,m1);
	LineR l3(&p13,&p12,m1);
	l1.Draw();
	l2.Draw();
	l3.Draw();

	drawAxes();

	angle+=0.5f;

	glutSwapBuffers();
}

void drawAxes()
{
	double color1[3] = {.3, 0.0, 0.0};
	double color2[3] = {.0, 0.3, 0.0};
	double color3[3] = {.0, 0.0, 0.3};
	Mat3x1 m1(color1), m2(color2), m3(color3);


	Point3D p1(-10, 0, 0);
	Point3D p2(10, 0, 0);
	LineR l1(&p1, &p2, m1);
	l1.Draw();
	Point3D p3(0, -10, 0);
	Point3D p4(	0, 10, 0	);
	LineR l2(&p3, &p4, m2);
	l2.Draw();
	Point3D p5(0, 0, -10);
	Point3D p6(0, 0, 10);
	LineR l3(&p5, &p6, m3);
	l3.Draw();
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


	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}
