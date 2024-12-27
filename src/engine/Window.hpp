#include "../entity/character/Player.hpp"
#include "../map/MapGeneration.hpp"
class Window {
private:
  Player player;
  MapGeneration mapGeneration;
public:
  Window(float screenWidth, float screenHeight, int framerate);
  void update();
  void draw();
};