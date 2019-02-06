#pragma once

#include "ObjectPool.h"
#include "EggInt.h"
#include "Egg.h"

/*
 *
 */
class EggsShooter: public ObjectPool<Egg, 20>, public EggInt{
public:
	EggsShooter(SDLGame* game);

protected:
	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc);
};