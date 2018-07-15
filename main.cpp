#include <stdlib.h>
#include <gl/glut.h>


int w = 480, h = 480, z = -30;
int x1 = 0, y1 = 0, z1 = 0, sudut = 0;



void init (void)
{
    glClearColor(0,0,1,0);
    GLfloat modelambient[] = {0, 0.2, 0.2, 0.2};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glEnable(GL_COLOR_MATERIAL);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelambient);
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w/ (GLdouble)h, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
}

void myKeyboard(unsigned char key, int x, int y) {

if(key == 'w') z += 5; //mendekat

else if (key == 's') z -= 5; //menjauh

else if (key == 'x') { //rotasi sumbu x

x1 = 1;

y1 = 0;

z1 = 0;

sudut += 5;

} else if (key == 'y') { //rotasi sumbu y

x1 = 0;

y1 = 1;

z1 = 0;

sudut += 5;

} else if (key == 'z') { //rotasi sumbu z

x1 = 0;

y1 = 0;

z1 = 1;

sudut += 5;

}
}

GLfloat angle = 0.0f;
GLfloat direction = 1.0f;
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.70f,0.77f,0.9f,0.0f);
    glLoadIdentity();
    glTranslatef(0,0,z);
    glRotatef(sudut, x1,y1,z1);
    
    //objek
    //kepala
    glPushMatrix();
    glTranslatef(0,4,0);
    glColor3f(0.5, 0.24, 1.0);
    glScalef(1.0,0.8,0.8);
    glutSolidSphere(4.6,100,100);
    glPopMatrix();
    
    //mata
    glPushMatrix();
    glColor3f(-0.9,-0.9,-0.9);
    glScalef(0.6,0.6,0.6);
    glTranslatef(2.75,7,5.0);
    glutSolidSphere(1,100,10);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(-0.9,-0.9,-0.9);
    glScalef(0.6,0.6,0.6);
    glTranslatef(-2.75,7,5.0);
    glutSolidSphere(1,100,10);
    glPopMatrix();
    
    //mulut
    glPushMatrix();
    glColor3f(1.0,0.25,0);
    glRotatef(90,7,0,0);
    glTranslatef(0,3.5,-4);
    glScalef(1, 1.0, 0.5);
    glutSolidSphere(1,5,100);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,0.25,0);
    glRotatef(90,7,0,0);    
    glTranslatef(0, 3.5, -3.5);
    glScalef(1.0, 1.0, 0.5);
    glutSolidSphere(0.7, 5, 500);
    glPopMatrix();
    
    //sayap
    glPushMatrix();
    glColor3f(0.5,0.24,1.0);
    glRotatef(angle,0,0,1);    
    glTranslatef(6.0,3.2,-0.1);
    glScalef(0.8,0.3,0.0);
    glutSolidSphere(3,100,100);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.5,0.24,1.0);
    glRotatef(-angle,0,0,1);    
    glTranslatef(-6.0,3.2,-0.1);
    glScalef(0.8,0.3,0.0);
    glutSolidSphere(3,100,100);
    glPopMatrix();


  angle += direction;
  if (angle >= 5 || angle <= -5) {
    direction = -direction;
  }

  glutSwapBuffers();
}

void timer(int value) {

glutPostRedisplay();

glutTimerFunc(50,timer,0);

}

int main (int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Bird 3D");
    glutDisplayFunc(renderScene);
    glutTimerFunc(50, timer, 0);
    glutKeyboardFunc(myKeyboard);

    init();
    glutMainLoop();
}


