#ifndef COREVISUAL_H
#define COREVISUAL_H

//#define KEV_LEFT_MOUSE_DOWN
//#define KEV_LEFT_MOUSE_UP
//#define KEV_RIGHT_MOUSE_DOWN
//#define KEV_RIGHT_MOUSE_UP
//#define KEV_NONE

class CoreVisual {
 private:
  int key;
 public:
  enum {KEV_LEFT_MOUSE_DOWN, KEV_LEFT_MOUSE_UP, KEV_RIGHT_MOUSE_DOWN, KEV_RIGHT_MOUSE_UP, KEV_NONE};

  int getKey();
  virtual void touch(int key_event) = 0;
  ~CoreVisual() {}
};
#endif
