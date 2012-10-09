#ifndef COREVISUAL_H
#define COREVISUAL_H

#define GE_MOUSE_LEFT GLUT_LEFT_BUTTON
#define GE_MOUSE_RIGHT GLUT_RIGHT_BUTTON

class CoreVisual {
 private:
  int key;
 public:
  int getKey();
  virtual void touch(int key_event) = 0;
  ~CoreVisual() {}
};
#endif
