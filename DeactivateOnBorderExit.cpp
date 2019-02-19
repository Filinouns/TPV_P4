#include "DeactivateOnBorderExit.h"



DeactivateOnBorderExit::DeactivateOnBorderExit() {
}


DeactivateOnBorderExit::~DeactivateOnBorderExit()
{
}

void DeactivateOnBorderExit::update(Container* c, Uint32 time) {
	Vector2D p = c->getPosition();
	Vector2D v = c->getVelocity();

	if (p.getY() <= 0) {
		c->setActive(false);
	}

	if (p.getY() + c->getHeight() >= c->getGame()->getWindowHeight()) {
		c->setActive(false);
	}
	
	if (p.getX() <= 0) {
		c->setActive(false);
	}

	
	if (p.getX() + c->getWidth() >= c->getGame()->getWindowWidth()) {
		c->setActive(false);
	}
}