#include "./engine/Window.hpp"
#include <raylib.h>

int main(void) {

  const double screenWidth = 800;
  const double screenHeight = 450;
  const int framerate = 60;

  Window gameWindow = Window(screenWidth, screenHeight, framerate);
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    gameWindow.update();
    gameWindow.draw();
  }
  CloseWindow();
  return 0;
}
