#pragma once
#include "PhysicsComponent.h"
class ReduceSpeedPC : public PhysicsComponent {
public:
	ReduceSpeedPC(float factor);
	virtual ~ReduceSpeedPC();
	virtual void update(Container* c, Uint32 time);

private:
	float factor_;
};

