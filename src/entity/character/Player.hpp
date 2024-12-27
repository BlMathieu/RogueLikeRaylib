#include "../AbstractEntity.hpp"
#include "../weapon/Glock.hpp"
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

  AbstractGun gun = Glock();
  std::vector<Bullet> bullets;
  void checkMovement();
  void move();
  void shoot();

public:
  Player();
  void loadTexture();
  void setGun(AbstractGun gun);
  void draw() override;
  void update();
};