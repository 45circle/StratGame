#ifndef GEVISUAL_H
#define GEVISUAL_H

struct point_t {
  float x;
  float y;
  float z;
};

struct rect_t {
  point_t start;
  point_t end;
};

struct cell_point_t {
  int x;
  int y;
  int z;
};

struct cell_rect_t {
  cell_point_t start;
  cell_point_t end;
};

rect_t cell_point_rect(cell_point_t c);
rect_t cell_point_rect(int x, int y, int z); 

typedef int GEColor;
class GEVisual {
 public:
  virtual void draw(point_t point)=0;
  virtual GEVisual *clone()=0;
};

class GEComposite {
 private:
  GEVisual *components;
 public:
  GEComposite();
  ~GEComposite();
  void addComponent(GEVisual *component);
  GEVisual *getComponent(int i);
  virtual void draw(point_t point)=0;
  virtual GEVisual *clone()=0;
};

class GEMapCell;
class GEMapGrid;

struct ge_event_data_t {
  GEColor bg_color;
  GEVisual *visual;
  cell_point_t cell;
  GEMapGrid *map;
  void *opaque;
  int delete_visual;
};

typedef void (*on_event_f) (ge_event_data_t &event_data);

class GEMapGrid : public GEVisual {
 private:
  cell_rect_t selection;
  cell_point_t cursor;
  GEMapCell *cells;
 public:
  GEMapGrid();
  ~GEMapGrid();
  on_event_f onOver;
  on_event_f onSelect;
  on_event_f onDraw;
  void moveCursorTo(cell_point_t cell);
  cell_point_t getCellUnderCursor();
  void select(cell_rect_t area);
  void selectUnderCursor();
  cell_rect_t getSelection();
  virtual void draw(point_t cell);
  virtual GEVisual *clone();
};

class GEMapCell : public GEVisual {
 private :
  GEColor bg_color;
  GEMapGrid *parent;
  GEMapCell();
  ~GEMapCell();
  virtual void draw(point_t cell);
  virtual GEVisual *clone();
  friend GEMapGrid;
};
#endif
