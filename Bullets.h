#pragma once

#include "GameObjectPool.h"
#include "Bullet.h"

#include "TempGunIC.h"

#include "NaturalMovePC.h"
#include "DeactivateOnBorderExit.h"
#include "ImageGC.h"

class Bullets :	public GameObjectPool<Bullet, 10> {
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();

	void createBullet(Vector2D p, Vector2D d);

	void receive(const void* senderObj, const msg::Message& msg);

private:

	TempGunIC tempGun_;

	// components for Bullet 
	NaturalMovePC naturalMove_; 
	DeactivateOnBorderExit deactivate_; 
	ImageGC bulletImage_; 
};

