#pragma once
#include "BulletsShooter.h"
class BulletInt : public BulletsShooter
{
public:
	BulletInt(SDLGame* game);
	virtual ~BulletInt();

	void add(Vector2D pos, Vector2D vel);
};

