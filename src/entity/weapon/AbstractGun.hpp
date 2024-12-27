#include <raylib.h>
#include "../AbstractEntity.hpp"
#include "../projectile/Bullet.hpp"
class AbstractGun : AbstractEntity{
private:
  double damage;
  float velocity;
  double reloadTime;
  int bulletNumber;
  char* url;
  Texture2D texture;

public:
  bool isReloading();
  void loadTexture();
  void update(Vector2& playerPosition);
  void draw() override;
  Bullet shoot();
  AbstractGun(char *url, double damage, int bulletNumber, double reloadTime, float velocity);
};