#pragma once

#include "Bullet.h"
#include "ObjectPool.h"

/*
 *
 */
class BulletsShooter: public ObjectPool<Bullet, 100> {
public:
	BulletsShooter(SDLGame* game);

protected:
	virtual void addBullet(Vector2D pos, Vector2D vel);
};