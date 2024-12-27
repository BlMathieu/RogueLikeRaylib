#include "AbstractData.hpp"
#include <raylib.h>
#include <vector>

AbstractData::AbstractData(char *url, float tileSize) {
  this->tiles = std::vector<Rectangle>();
  this->tileSize = tileSize;
  this->map = std::vector<std::vector<int>>();
  this->url = url;
}

void AbstractData::loadTexture() {
  Image image = LoadImage(this->url);
  int height = image.height / tileSize;
  int width = image.width / tileSize;

  for (int i = 0; i < height; i++) {
    for (int x = 0; x < width; x++) {
      Rectangle tile = Rectangle({x * this->tileSize, i * this->tileSize,this->tileSize, this->tileSize});
      this->tiles.push_back(tile);
    }
  }
  this->texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

void AbstractData::drawDebugTiles() {
  int index = 0;
  float y = 0;
  for (int i = 0; i < tiles.size(); i++) {
    float x = index * this->tileSize;
    if (x >= GetScreenWidth()) {
      index = 0;
      y = y + 50;
    }
    DrawTextureRec(this->texture, tiles.at(i), {x, y}, WHITE);
    DrawText(TextFormat("%i", i), x, y + 30, 10, WHITE);
    index++;
  }
}

void AbstractData::draw() {
  int rows = this->map.size();
  int columns = this->map[0].size();
  for (int i = 0; i < rows; i++) {
    for (int x = 0; x < columns; x++) {
      DrawTextureRec(this->texture, tiles.at(this->map.at(i).at(x)),{x * this->tileSize, i * this->tileSize}, WHITE);
    }
  }
}