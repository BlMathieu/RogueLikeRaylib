#include "AbstractGun.hpp"
#include <raylib.h>

AbstractGun::AbstractGun(char *url, double damage, int bulletNumber, double reloadTime, float velocity){
    this->damage = damage;
    this->bulletNumber = bulletNumber;
    this->reloadTime = reloadTime;
    this->velocity = velocity;
    this->url = url;
    this->position = {0,0};
}

void AbstractGun::loadTexture(){
    Image image = LoadImage(this->url);
    this->texture = LoadTextureFromImage(image);
}

Bullet AbstractGun::shoot(){
    Vector2 bulletPosition = {this->position.x + this->texture.width - 20, this->position.y + 8};
    Bullet bullet = Bullet(bulletPosition, GetMousePosition());
    return bullet;
}

void AbstractGun::update(Vector2& playerPosition){
    this->position = {playerPosition.x + 2, playerPosition.y};
}

void AbstractGun::draw(){
    DrawTexture(this->texture, this->position.x, this->position.y, WHITE);
}