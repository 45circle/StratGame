#ifndef CORE_H
#define CORE_H
#include "utils/uniquekeytree.h"
#include "corevisual.h"

class Core
{
private:
  static UniqueKeyTree tree;
  static int width, height, view_angle;
public:
  void static init(int counter, char **args);
  int getSelectId(int x, int y);
  void select(int x, int y, int key_event, int down);
};

#endif
