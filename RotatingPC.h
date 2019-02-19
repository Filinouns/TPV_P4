#pragma once

#include "PhysicsComponent.h"

class RotatingPC : public PhysicsComponent {
public:
	RotatingPC(int r);
	virtual ~RotatingPC();
	virtual void update(Container* c, Uint32 time);

private:
	int rotation_;
};

