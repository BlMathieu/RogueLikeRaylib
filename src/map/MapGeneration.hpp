#include <raylib.h>
#include "data/Terrain.hpp"
class MapGeneration {
private: 
Terrain terrain;
public: 
MapGeneration();
void loadTexture();
void draw();
};