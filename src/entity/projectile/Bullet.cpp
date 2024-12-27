#include "Bullet.hpp"
#include <cmath>
#include <ctime>
#include <raylib.h>

Bullet::Bullet(Vector2 position, Vector2 mousePos) {
  this->maxVelocity = 5;
  this->mousePos = mousePos;
  this->position = position;
  this->lifeTime = clock() / 10000;
  this->maxLifeTime = 5;

  this->getMoveSpeed();
}

void Bullet::getMoveSpeed(){
  float directionX = mousePos.x - this->position.x;
  float directionY = mousePos.y - this->position.y;
  float norme = std::sqrt(directionX * directionX + directionY * directionY);
  this->movement.x = directionX / norme;
  this->movement.y = directionY / norme; 
}

bool Bullet::isExpired(){
  int time = clock() / 10000;
  return time - this->lifeTime == this->maxLifeTime;
}

void Bullet::move() {
  this->position.x += this->movement.x * this->maxVelocity;
  this->position.y += this->movement.y * this->maxVelocity;
}

void Bullet::draw() { DrawRectangle(this->position.x, this->position.y, 10, 5, WHITE); }
void Bullet::update() {
  this->move();
}