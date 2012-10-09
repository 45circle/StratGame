#include "core.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

UniqueKeyTree Core::tree;
void config()
{
}

void idle_func()
{
  glutSwapBuffers();
}

void display_func()
{
  glutSwapBuffers();
}

void Core::init(int counter, char **args)
{
  glutInit(&counter, args);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("StratGame");
  glutIdleFunc(idle_func);
  glutDisplayFunc(display_func);
  config();
  glutMainLoop();
}

int main(int argc, char **argv)
{
  Core game;
  game.init(argc, argv);
}
