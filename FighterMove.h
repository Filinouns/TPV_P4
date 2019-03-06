#pragma once
#include "PhysicsComponent.h"
class FighterMove :	public PhysicsComponent {
public:
	FighterMove();
	virtual ~FighterMove();
	void update(Container* c, Uint32 time);
};

