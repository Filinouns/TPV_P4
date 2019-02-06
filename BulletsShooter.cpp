#include "BulletsShooter.h"

BulletsShooter::BulletsShooter(SDLGame* game) : ObjectPool (game) {}

void BulletsShooter::addBullet(Vector2D pos, Vector2D vel) {
	Bullet* e = getUnusedObj();
	if (e != nullptr) {
		e->setVelocity(vel);
		e->setPosition(pos);
		e->setActive(true);
		getGame()->getServiceLocator()->getAudios()->playChannel(Resources::GunShot, 0);
	}
}