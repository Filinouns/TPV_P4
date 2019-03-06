#include "RotationIC.h"

#include "Fighter.h"

RotationIC::RotationIC(SDL_Keycode ctrlKey0, SDL_Keycode ctrlKey1, float angle) :
	ctrlKey0_(ctrlKey0), ctrlKey1_(ctrlKey1), ang_(angle) 
{
}

RotationIC::~RotationIC() {}

void RotationIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey0_) {
			//Activar rotacion der
			static_cast<Fighter*>(c)->setRotating(true);
			static_cast<Fighter*>(c)->setRot(ang_);
			//c->setRotation(c->getRotation() + ang_);
		}
		else if (event.key.keysym.sym == ctrlKey1_) {
			//Activar rot izq
			static_cast<Fighter*>(c)->setRotating(true);
			static_cast<Fighter*>(c)->setRot(-ang_);
			//c->setRotation(c->getRotation() - ang_);
		}
	}
	if (event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == ctrlKey0_) {
			//Desactivar rot der
			static_cast<Fighter*>(c)->setRotating(false);
			static_cast<Fighter*>(c)->setRot(0);
			//c->setRotation(c->getRotation() + ang_);
		}
		else if (event.key.keysym.sym == ctrlKey1_) {
			//Desactivar rot izq
			static_cast<Fighter*>(c)->setRotating(false);
			static_cast<Fighter*>(c)->setRot(0);
			//c->setRotation(c->getRotation() - ang_);
		}
	}
}