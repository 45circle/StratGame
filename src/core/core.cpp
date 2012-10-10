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

void mouse_func(int button, int state, int x, int y)
{

  Core::select(x, y, button, state ==  GLUT_DOWN);
}

int Core::getSelectId(int x, int y)
{
  GLuint buff[64] = {0};
  GLint hits, view[4];
  int id;
  
  //This chooses the buffer where to store the values for the selection data
  glSelectBuffer(64, buff);
  
  //This retrieves info about the viewport
  glGetIntegerv(GL_VIEWPORT, view);
	
  //Switching in selecton mode
  glRenderMode(GL_SELECT);
  
  // Clearing the names' stack
  // This stack contains all the info about the objects
  glInitNames();
  
  // Now fill the stack with one element (or glLoadName will generate an error)
  glPushName(0);
  
  // Now modify the viewing volume, restricting selection area around the cursor
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  
  // Restrict the draw to an area around the cursor
  gluPickMatrix(x, y, 1, 1, view);
  gluPerspective(view_angle, (float)width/height, .1, 100 );
  
  
  // Draw the objects onto the screen
  glMatrixMode(GL_MODELVIEW);
  
  // Draw only the names in the stack, and fill the array
  draw();
  
  // Do you remeber? We do pushMatrix in PROJECTION mode
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  
  
  // Get number of objects drawed in that area
  // and return to render mode
  hits = glRenderMode(GL_RENDER);
  
  /*
		Print a list of the objects
  */
  //list_hits(hits, buff);
  
  /*
    uncomment this to show the whole buffer
    * /
    gl_selall(hits, buff);
  */
  
  glMatrixMode(GL_MODELVIEW);
  
  if(hits > 0)
    return buff[3];
  else
    return -1;
}

void Core::select(int x, int y, int key_event, int down)
{
  int id;
  CoreVisual *visual;
  id = getSelectedId(x, y);
  visual = Core::tree.search(id);
  if (visual != NULL)
    visual.touch(key_event, down);
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
  game.init(argc, argv);
}
