#include "Player.hpp"
#include <algorithm>
#include <cmath>
#include <iterator>
#include <raylib.h>
#include <vector>

Player::Player() {
  this->bullets = std::vector<Bullet>();
  this->height = 20;
  this->width = 20;
  this->position = {GetScreenWidth() / 2 - this->width / 2, GetScreenHeight() / 2 - this->height / 2};
  
  this->up = false;
  this->down = false;
  this->left = false;
  this->right = false;

  this->isRunning = false;

  this->moveSpeed = {0,0};

  this->walkSpeed = 5;
  this->runSpeed = this->walkSpeed * 2;
}

void Player::checkMovement() {
  if (IsKeyDown('W')) {
    this->up = true;
  }
  if (IsKeyUp('W')) {
    this->up = false;
  }
  if (IsKeyDown('A')) {
    this->left = true;
  }
  if (IsKeyUp('A')) {
    this->left = false;
  }
  if (IsKeyDown('S')) {
    this->down = true;
  }
  if (IsKeyUp('S')) {
    this->down = false;
  }
  if (IsKeyDown('D')) {
    this->right = true;
  }
  if (IsKeyUp('D')) {
    this->right = false;
  }
  if (IsKeyDown(KEY_LEFT_SHIFT)) {
    this->isRunning = true;
  } else {
    if (IsKeyUp(KEY_LEFT_SHIFT)) {
      this->isRunning = false;
    }
  }
}

void Player::move() {
  this->moveSpeed = {0 ,0 };
  this->checkMovement();
  if (this->up) {
    this->moveSpeed.y = -1;
  }
  if (this->down) {
    this->moveSpeed.y = 1;
  }
  if (this->left) {
    this->moveSpeed.x = -1;
  }
  if (this->right) {
    this->moveSpeed.x = 1;
  }

  this->currentMoveSpeed = (this->isRunning) ? this->runSpeed : this->walkSpeed;

  if (this->moveSpeed.x != 0 && this->moveSpeed.y != 0) {
    int normalizedSpeed = std::sqrt(this->moveSpeed.x * this->moveSpeed.x + this->moveSpeed.y * this->moveSpeed.y);
    this->moveSpeed.x /= normalizedSpeed;
    this->moveSpeed.y /= normalizedSpeed;
    this->position.x += this->moveSpeed.x * this->currentMoveSpeed;
    this->position.y += this->moveSpeed.y * this->currentMoveSpeed;
  } else {
    this->position.x += this->moveSpeed.x * this->currentMoveSpeed;
    this->position.y += this->moveSpeed.y * this->currentMoveSpeed;
  }
}

void Player::shoot() {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 mousePos = GetMousePosition();
    Bullet bullet = Bullet(this->position, mousePos);
    this->bullets.push_back(bullet);
  }
}

void Player::update() {
  this->move();
  this->shoot();
  for (Bullet &bullet : bullets) {
    bullet.update();
  }
  std::vector<Bullet> activeBullets;
  std::copy_if(bullets.begin(), bullets.end(), std::back_inserter(activeBullets), [](Bullet &bullet) { return !bullet.isExpired(); });
  this->bullets = activeBullets;
}
void Player::draw() {
 // DrawText(TextFormat("PosX : %f", this->position.x), 0, 0, 25, WHITE);
 // DrawText(TextFormat("PosY : %f", this->position.y), 0, 20, 25, WHITE);
 // DrawText(TextFormat("nb : %i", this->bullets.size()), 0, 40, 25, WHITE);
 // DrawText(TextFormat("time : %d", clock() / 100000), 0, 60, 25, WHITE);
  DrawRectangle(this->position.x, this->position.y, this->width, this->height, RED);
  for (Bullet &bullet : bullets) {
    bullet.draw();
  }
}
