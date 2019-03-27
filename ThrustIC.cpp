#include "ThrustIC.h"
#include "Fighter.h"
//#include "InputHandler.h"

ThrustIC::ThrustIC(SDL_Keycode ctrlKey, float thrust, float speedLimit) : 
	ctrlKey_(ctrlKey), thrust_(thrust), speedLimit_(speedLimit) 
{
}

ThrustIC::~ThrustIC() {}

void ThrustIC::handleInput(Container* c, Uint32 time) { 
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(ctrlKey_)) {
			Vector2D v ;
			v = c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())* thrust_);
			if (v.magnitude() > speedLimit_) {
				v = v.normalize() * speedLimit_;
			}

			c->setVelocity(v);

			static_cast<Fighter*>(c)->setMoving(true);
		}
	}
	/*if (InputHandler::getInstance()->isAnyKeyUp()) {
		if (InputHandler::getInstance()->isKeyUp(ctrlKey_)) {
			static_cast<Fighter*>(c)->setMoving(false);
		}
	}*/
}