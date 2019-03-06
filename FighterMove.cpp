#include "FighterMove.h"

#include "Fighter.h"

FighterMove::FighterMove() {}


FighterMove::~FighterMove() {}

void FighterMove::update(Container* c, Uint32 time) {
	if (static_cast<Fighter*>(c)->getMoving()) {
		c->setPosition(c->getPosition() + c->getVelocity());
	}
	if (static_cast<Fighter*>(c)->getRotating()) {
		c->setRotation(c->getRotation() + static_cast<Fighter*>(c)->getRot());
	}
}