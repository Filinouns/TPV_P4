#include "ShowUpAtOppositeSidePC.h"

ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC() :
	ShowUpAtOppositeSidePC(true, true, true, true) {
}

ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC(bool left, bool right, bool top, bool bot) :
	left_(left), right_(right), top_(top), bot_(bot) {
}

ShowUpAtOppositeSidePC::~ShowUpAtOppositeSidePC(){}

void ShowUpAtOppositeSidePC::update(Container* c, Uint32 time) {
	Vector2D p = c->getPosition();

	if (top_) {
		if (p.getY() < 0) {
			p.setY(c->getGame()->getWindowHeight() - c->getHeight());
		}
	}

	if (bot_) {
		if (p.getY() + c->getHeight() > c->getGame()->getWindowHeight()) {
			p.setY(0);
		}
	}

	if (left_) {
		if (p.getX() < 0) {
			p.setX(c->getGame()->getWindowWidth() - c->getWidth());
		}
	}

	if (right_) {
		if (p.getX() + c->getWidth() > c->getGame()->getWindowWidth()) {
			p.setX(0);
		}
	}
	c->setPosition(p);
}