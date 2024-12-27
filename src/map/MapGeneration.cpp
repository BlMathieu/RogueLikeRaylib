#include "MapGeneration.hpp"
#include <raylib.h>

MapGeneration::MapGeneration(){
  this->terrain = Terrain();
}
void MapGeneration::loadTexture(){
  this->terrain.loadTexture();
}
void MapGeneration::draw() {
  terrain.draw();
  //terrain.drawDebugTiles();
}