#ifndef COREVISUAL_H
#define COREVISUAL_H
#include <GL/glut.h>

#define  KEV_MOUSE_LEFT  GLUT_LEFT_BUTTON
#define  KEV_MOUSE_RIGHT GLUT_RIGHT_BUTTON

class CoreVisual {
 private:
  int key;
 public:
  int getKey();
  virtual void touch(int key_event, int down) = 0;
  virtual ~CoreVisual() {}
};
#endif
