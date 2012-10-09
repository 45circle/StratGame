#ifndef CORE_H
#define CORE_H
#include "utils/uniquekeytree.h"
#include "corevisual.h"

class Core
{
private:
  static UniqueKeyTree tree;
public:
  void static init(int counter, char **args);
  void touch(int key_event);
};

#endif
