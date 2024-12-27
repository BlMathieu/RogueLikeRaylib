#include "Window.hpp"
#include <raylib.h>

Window::Window(float screenWidth, float screenHeight, int framerate){
  InitWindow(screenWidth, screenHeight, "Projet roguelike");
  SetTargetFPS(framerate);
  this->player = Player();
  this->mapGeneration = MapGeneration();
  this->player.loadTexture();
  this->mapGeneration.loadTexture();
}

void Window::update() { 
  this->player.update();
}

void Window::draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  this->mapGeneration.draw();
  this->player.draw();
  EndDrawing();
}