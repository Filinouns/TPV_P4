#include "RotationIC.h"

RotationIC::RotationIC(SDL_Keycode ctrlKey0, SDL_Keycode ctrlKey1, float angle) :
	ctrlKey0_(ctrlKey0), ctrlKey1_(ctrlKey1), ang_(angle) 
{
}

RotationIC::~RotationIC() {}

void RotationIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey0_) {
			c->setRotation(c->getRotation() + ang_);
		}
		else if (event.key.keysym.sym == ctrlKey1_) {
			c->setRotation(c->getRotation() - ang_);
		}
	}
}