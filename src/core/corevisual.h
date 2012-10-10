#ifndef COREVISUAL_H
#define COREVISUAL_H
#include <GL/glut.h>

<<<<<<< HEAD
#define  KEV_MOUSE_LEFT  GLUT_LEFT_BUTTON
#define  KEV_MOUSE_RIGHT GLUT_RIGHT_BUTTON
=======
#define GE_MOUSE_LEFT GLUT_LEFT_BUTTON
#define GE_MOUSE_RIGHT GLUT_RIGHT_BUTTON
>>>>>>> 65d16911d9d1f0545a047daf7f514baa1b13dae7

class CoreVisual {
 private:
  int key;
 public:
  int getKey();
  virtual void touch(int key_event, int down) = 0;
  virtual ~CoreVisual() {}
};
#endif
