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
week09
```c++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}

void display(){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}

int main(int argc, char**argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week09 texture");

    glutDisplayFunc( display );
    myTexture("earth.jpg");

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
week14
```cpp
#include <GL/glut.h>
#include <stdio.h>///printf, fprintf, fopen, fclose
float angle[20], oldx = 0;
int angleID = 0;
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout == NULL)
            fout = fopen("file.txt", "w+");
    for(int i = 0; i < 20; i++){
        printf("%.2f", angle[i]);
        fprintf(fout, "%.2f", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void myRead(){
    if(fout != NULL){
            fclose(fout);///關閉還在讀取的檔案
            fout = NULL;
    }
    if(fin == NULL)
            fin = fopen("file.txt", "r");
    for(int i = 0; i < 20; i++){
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key, int x, int y){
    if(key=='r'){
        myRead();
    }
    if(key=='0')    angleID = 0;
    if(key=='1')    angleID = 1;
    if(key=='2')    angleID = 2;
    if(key=='3')    angleID = 3;
}
void mouse(int button, int state, int x, int y){
    oldx = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldx);
    myWrite();
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
    glutCreateWindow("week14 TRT angle write");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc( display );
    glutMainLoop();
}

```
```cpp
#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t){///t的單位是ms
                  ///1000代表1秒,1500代表1.5秒
    printf("鬧鐘%d,我起床了\n",t);
    PlaySound("do.wav", NULL, SND_ASYNC);
    printf("設定下個鬧鐘\n");
    glutTimerFunc(1000, timer, t+1);
    printf("設好鬧鐘,再回去睡\n");
}
void display(){

}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000, timer, 0);
    glutDisplayFunc( display );
    glutMainLoop();
}

```
week16
```cpp
#include <GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glutSolidTeapot(2);///大茶壼
glutSwapBuffers();
}
void motion(int x, int y)
{
glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
glLoadIdentity();
gluLookAt( (x-150)/15.0, (y-150)/15.0, 3, ///eye
0, 0, 0, ///center
0, 1, 0);///up
glutPostRedisplay();
}
void reshape(int w, int h)
{ const float ar = (float) w / (float) h;
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);///投影,把3D投射到2D畫面
glLoadIdentity();
gluPerspective(60, ar, 0.1, 100);

 glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
glLoadIdentity() ;
gluLookAt( 0, 0, 3, 0, 0, 0, 0, 1, 0);
}
int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("week16 camera lookat");

 glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutMotionFunc(motion);

 glutMainLoop();
}
```
