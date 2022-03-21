#include <GL/glut.h>
float angle = 0, oldx = 0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); ///轉動
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y){ ///按下mouse  放開mouse
    oldx = x;
}
void motion(int x, int y){ ///拖者動
    angle += (x - oldx);
    oldx = x;
    display();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
