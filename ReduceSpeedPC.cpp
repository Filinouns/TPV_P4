#include "ReduceSpeedPC.h"

ReduceSpeedPC::ReduceSpeedPC(float factor) :
	factor_(factor)
{

}

ReduceSpeedPC::~ReduceSpeedPC() {}

void ReduceSpeedPC::update(Container* c, Uint32 time) {
	c->setVelocity(c->getVelocity()*factor_);
	c->setPosition(c->getPosition() + c->getVelocity());
}