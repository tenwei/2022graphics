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
/*void mouse(int button, int state, int mouseX, int mouseY){ ///按下mouse  放開mouse
    if(state == GLUT_DOWN){    /// if 按下mouse
        N++;                   /// 多個新頂點
        x[N-1] = mouseX;       /// 最後一個新增的頂點的X座標
        y[N-1] = mouseY;       /// 最後一個新增的頂點的Y座標
        printf("現在按下滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1]);
    }
    display();
}*/
void motion(int mouseX, int mouseY){ ///按下mouse  放開mouse
    N++;                   /// 多個新頂點
    x[N-1] = mouseX;       /// 最後一個新增的頂點的X座標
    y[N-1] = mouseY;       /// 最後一個新增的頂點的Y座標
    printf("現在按下滑鼠,得到新座標 %d %d\n", x[N-1], y[N-1]);
    display();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 複習 mouse");

    glutDisplayFunc(display);
    //glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
