#include <stdio.h>
#include <GL/glut.h>
int N = 0;
int x[1000], y[1000];
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++)
        glVertex2f((x[i]-150)/150.0, -(y[i]-150)/150.0);
    glEnd();
    glutSwapBuffers();
}
/*void mouse(int button, int state, int mouseX, int mouseY){ ///���Umouse  ��}mouse
    if(state == GLUT_DOWN){    /// if ���Umouse
        N++;                   /// �h�ӷs���I
        x[N-1] = mouseX;       /// �̫�@�ӷs�W�����I��X�y��
        y[N-1] = mouseY;       /// �̫�@�ӷs�W�����I��Y�y��
        printf("�{�b���U�ƹ�,�o��s�y�� %d %d\n", x[N-1], y[N-1]);
    }
    display();
}*/
void motion(int mouseX, int mouseY){ ///���Umouse  ��}mouse
    N++;                   /// �h�ӷs���I
    x[N-1] = mouseX;       /// �̫�@�ӷs�W�����I��X�y��
    y[N-1] = mouseY;       /// �̫�@�ӷs�W�����I��Y�y��
    printf("�{�b���U�ƹ�,�o��s�y�� %d %d\n", x[N-1], y[N-1]);
    display();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 �Ʋ� mouse");

    glutDisplayFunc(display);
    //glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
