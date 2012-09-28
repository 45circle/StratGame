#ifndef GEVISUAL_H
#define GEVISUAL_H

struct vector_t {
  float x;
  float y;
  float z;
};

struct rect_t {
  vector_t start;
  vector_t end;
};

struct cell_vector_t {
  int x;
  int y;
  int z;
};

struct cell_rect_t {
  cell_vector_t start;
  cell_vector_t end;
};

rect_t cell_point_rect(cell_vector_t c);
rect_t cell_point_rect(int x, int y, int z); 

typedef int GEColor;
class GEVisual {
 public:
  GEVisual();
  virtual ~GEVisual();
  virtual void draw(vector_t point, vector_t cell_size)=0;
  virtual GEVisual *clone()=0;
};

class GEVisualComponent : public GEVisual{
 public:
  virtual ~GEVisualComponent();
  virtual void draw(vector_t point, vector_t cell_size)=0;
  virtual GEVisual *clone()=0;
};

class GESphere : public GEVisualComponent {
 private:
  int radius;
 public:
  GESphere(int radius);
  virtual ~GESphere();
  int get_radius();
  virtual ~GEVisualComponent();
  virtual void draw(vector_t point, vector_t cell_size);
  virtual GEVisual *clone();
};

class GEQuad : public GEVisualComponent {
 private:
  cell_vector_t dimensions;
 public:
  GEQuad(cell_vector_t dimensions);
  virtual ~GEQuad();
  cell_vector_t get_dinensions();
  virtual ~GEVisualComponent();
  virtual void draw(vector_t point, vector_t cell_size);
  virtual GEVisual *clone();
};

class GEComposite : public GEVisualComponent{
 private:
  GEVisualComponent *components;
 public:
  GEComposite();
  virtual ~GEComposite();
  void addComponent(GEVisual *component);
  GEVisual *getComponent(int i);
  virtual void draw(vector_t point, vector_t cell_size);
  virtual GEVisual *clone();
};

class GEMapCell;
class GEMapGrid;

struct gemap_event_data_t {
  GEColor bg_color;
  GEVisual *visual;
  cell_vector_t cell;
  GEMapGrid *map;
  void *opaque;
  int delete_visual;
};

typedef void (*on_map_event_f) (gemap_event_data_t &event_data);

class GEMapGrid : public GEVisual {
 private:
  cell_rect_t selection;
  cell_vector_t cursor;
  GEMapCell *cells;
  void touch(GEMapCell *cell, int key_event);
 public:
  GEMapGrid();
  virtual ~GEMapGrid();
  on_map_event_f onOver;
  on_map_event_f onSelect;
  on_map_event_f onDraw;
  void moveCursorTo(cell_vector_t cell);
  cell_vector_t getCellUnderCursor();
  void select(cell_rect_t area);
  void selectUnderCursor();
  cell_rect_t getSelection();
  virtual void draw(vector_t point, vector_t cell_size);
  virtual GEVisual *clone();
  friend class GEMapCell;
};

class GEMapCell : public GEVisual {
 private :
  GEColor bg_color;
  GEMapGrid *parent;
  GEMapCell();
  virtual ~GEMapCell();
  virtual void draw(vector_t point, vector_t cell_size);
  virtual GEVisual *clone();
  friend class GEMapGrid;
};
#endif
