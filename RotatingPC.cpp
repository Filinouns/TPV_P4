#include "RotatingPC.h"

RotatingPC::RotatingPC(int r) {
	rotation_ = r;
}

RotatingPC::~RotatingPC() {}

void RotatingPC::update(Container* c, Uint32 time) {
	c->setRotation(c->getRotation() + rotation_);
}
