#include "BulletInt.h"

BulletInt::BulletInt(SDLGame* game) : BulletsShooter(game) {}

BulletInt::~BulletInt() {}

void BulletInt::add(Vector2D pos, Vector2D vel) {
	addBullet(pos, vel);
}
