#ifdef COREVISUAL_H
#define COREVISUAL_H

#define KEV_LEFT_MOUSE_DOWN
#define KEV_LEFT_MOUSE_UP
#define KEV_RIGHT_MOUSE_DOWN
#define KEV_RIGHT_MOUSE_UP
#define KEV_NONE

class CoreVisual {
 private:
  int key;
 public:
  int getKey();
  virtual touch(int key_event) = 0;
}
#endif
