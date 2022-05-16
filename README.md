# 2022graphics

Week03
```c++
#include <GL/glut.h>

void display(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);
    glutSolidTeapot( 0.3 );

    glutSwapBuffers();
}

int main(int argc, char**argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03的視窗");

    glutDisplayFunc( display );

    glutMainLoop();
    return 0;
}

```

```c++
#include <GL/glut.h>

void display(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);
    //glutSolidTeapot( 0.3 );

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);    glVertex2f(0.0f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);    glVertex2f(0.87f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);    glVertex2f(-0.87f, -0.5f);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char**argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03的視窗");

    glutDisplayFunc( display );

    glutMainLoop();
    return 0;
}

```
week08
```c++
#include <GL/glut.h>

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1, 1, 0);
    glutSolidTeapot( 0.3 );

    glutSwapBuffers();
}

int main(int argc, char**argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 300);
    glutCreateWindow("light week08");

    glutDisplayFunc( display );

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}

```


week12

```c++
#include <GL/glut.h>
float angle = 0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);
    glPushMatrix();
        glTranslatef(0.3,0,0);
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.5;
}
int main(int argc,char **argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week12");
    glutIdleFunc(display);
    glutDisplayFunc( display );
    glutMainLoop();
}

```

week13
```c++
#include <GL/glut.h>
float angle[20], oldx = 0;
int angleID = 0;
void keyboard(unsigned char key, int x, int y){
    if(key=='1')    angleID = 1;
    if(key=='2')    angleID = 2;
    if(key=='3')    angleID = 3;
    if(key=='4')    angleID = 4;
}///案鍵決定哪個關節
void mouse(int button, int state, int x, int y){
    oldx = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldx);
    oldx = x;
    glutPostRedisplay();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);///白色身體
    glRectf(0.3, 0.5, -0.3, -0.2);

    glPushMatrix();///右半邊
        glTranslatef(0.3, 0.5, 0);///要掛的位子
        glRotatef(angle[0], 0, 0, 1);///旋轉
        glTranslatef(-0.3, -0.4, 0);///旋轉中心
        glColor3f(1, 0, 0);///紅色手臂
        glRectf(0.3, 0.5, 0.8, 0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);///(2)旋轉
            glTranslatef(-0.8, -0.4, 0);///(1)把下手肘的旋轉中心放在正中心
            glColor3f(0, 1, 0);///綠色
            glRectf(0.8, 0.5, 1.1, 0.3);///下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3, 0.5, 0);///要掛的位子
        glRotatef(angle[2], 0, 0, 1);///旋轉
        glTranslatef(0.3, -0.4, 0);///旋轉中心
        glColor3f(1, 0, 0);///紅色手臂
        glRectf(-0.3, 0.5, -0.8, 0.3);///上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);///(2)旋轉
            glTranslatef(0.8, -0.4, 0);///(1)把下手肘的旋轉中心放在正中心
            glColor3f(0, 1, 0);///綠色
            glRectf(-0.8, 0.5, -1.1, 0.3);///下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char **argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week13 rect TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc( display );
    glutMainLoop();
}

```
