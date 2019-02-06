#pragma once

//#include "EggsShooter.h"
#include "Vector2D.h"

class EggInt {
public:
	EggInt();
	virtual ~EggInt();

	virtual void addEgg(Vector2D pos, Vector2D vel, Vector2D acc) = 0;
};