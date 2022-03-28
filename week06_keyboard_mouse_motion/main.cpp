#include <GL/glut.h>
#include <stdio.h>
float x = 250, y = 250, z = 0, scale = 1.0, angle = 0.0, oldx, oldy;
int now = 1; /// 1:���� 2:���� 3:�Y��
void display(){
    glClearColor(0.5, 0.5, 0.5, 1);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glTranslatef((x-250)/250.0, -(y-250)/250.0, z); ///Maya w
        glRotatef(angle, 0, 0, 1); ///Maya e
        glScalef(scale, scale, scale); ///Maya: r
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY){
    //printf("�{�b���U:%c �y�Цb:%d %d\n", key, x, y);
    if(key == 'w' || key == 'W')  now = 1; ///���� (��J�k�Хέ^��)
    if(key == 'e' || key == 'E')  now = 2; ///����
    if(key == 'r' || key == 'R')  now = 3; ///�Y��
}
void mouse(int boutton, int state, int mouseX, int mouseY){
    oldx = mouseX;  oldy = mouseY;
}
void motion(int mouseX, int mouseY){
    if(now == 1){  ///����
        x += (mouseX-oldx);
        y += (mouseY-oldy);
    }
    else if(now == 2){  ///����
        angle += (mouseX-oldx);
    }
    else if(now == 3){  ///�Y��
        if(mouseX > oldx)   scale = scale * 1.01;
        if(mouseX < oldx)   scale = scale * 0.99;
    }
    oldx = mouseX;  oldy = mouseY;
    display();
}

int main(int argc, char**argv){
    glutInit( &argc , argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(500, 500);
    glutCreateWindow("week06 keyboard mouse motion");

    glutDisplayFunc( display );
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}
