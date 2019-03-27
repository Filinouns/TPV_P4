#include "RotationIC.h"

#include "Fighter.h"

RotationIC::RotationIC(SDL_Keycode ctrlKey0, SDL_Keycode ctrlKey1, float angle) :
	ctrlKey0_(ctrlKey0), ctrlKey1_(ctrlKey1), ang_(angle) 
{
}

RotationIC::~RotationIC() {}

void RotationIC::handleInput(Container* c, Uint32 time) {
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(ctrlKey0_)) {
			//Activar rotacion der
			static_cast<Fighter*>(c)->setRotating(true);
			static_cast<Fighter*>(c)->setRot(ang_);
			//c->setRotation(c->getRotation() + ang_);
		}
		else if (InputHandler::getInstance()->isKeyDown(ctrlKey1_)) {
			//Activar rot izq
			static_cast<Fighter*>(c)->setRotating(true);
			static_cast<Fighter*>(c)->setRot(-ang_);
			//c->setRotation(c->getRotation() - ang_);
		}
	}
	/*if (InputHandler::getInstance()->isAnyKeyUp()) {
		if (InputHandler::getInstance()->isKeyUp(ctrlKey0_)) {
			//Desactivar rot der
			static_cast<Fighter*>(c)->setRotating(false);
			static_cast<Fighter*>(c)->setRot(0);
			//c->setRotation(c->getRotation() + ang_);
		}
		else if (InputHandler::getInstance()->isKeyUp(ctrlKey1_)) {
			//Desactivar rot izq
			static_cast<Fighter*>(c)->setRotating(false);
			static_cast<Fighter*>(c)->setRot(0);
			//c->setRotation(c->getRotation() - ang_);
		}
	}*/
}