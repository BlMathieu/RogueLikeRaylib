#include "../AbstractEntity.hpp"
#include "../projectile/Bullet.hpp"
#include <vector>
class Player:public AbstractEntity {
private:
  float width;
  float height;

  bool up;
  bool down;
  bool left;
  bool right;
  bool isRunning;

  Vector2 moveSpeed;

  double currentMoveSpeed;
  double walkSpeed;
  double runSpeed;
  int shootCooldown;
  std::vector<Bullet> bullets;
  void checkMovement();
  void move();
  void shoot();

public:
  Player();
  void draw() override;
  void update() override;
};