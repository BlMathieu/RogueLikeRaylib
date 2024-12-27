#pragma once
#include <raylib.h>
class AbstractEntity {
protected:
  Vector2 position;

public:
  AbstractEntity();
  virtual void update() = 0;
  virtual void draw() = 0;
};