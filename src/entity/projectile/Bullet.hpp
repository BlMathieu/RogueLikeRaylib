#include "../AbstractEntity.hpp"
#include <raylib.h>
class Bullet : public AbstractEntity {
private:
  Vector2 mousePos;
  double maxVelocity;
  Vector2 movement;
  int lifeTime;
  int maxLifeTime;

  void move();
  void getMoveSpeed();

public:
  Bullet(Vector2 position, Vector2 mousePos);
  void draw() override;
  void update();
  bool isExpired();
};