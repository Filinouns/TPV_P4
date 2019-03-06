#include "ThrustIC.h"
#include "Fighter.h"

ThrustIC::ThrustIC(SDL_Keycode ctrlKey, float thrust, float speedLimit) : 
	ctrlKey_(ctrlKey), thrust_(thrust), speedLimit_(speedLimit) 
{
}

ThrustIC::~ThrustIC() {}

void ThrustIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey_) {
			Vector2D v ;
			v = c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())* thrust_);
			if (v.magnitude() > speedLimit_) {
				v = v.normalize() * speedLimit_;
			}

			c->setVelocity(v);

			static_cast<Fighter*>(c)->setMoving(true);
		}
	}
	if (event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == ctrlKey_) {
			static_cast<Fighter*>(c)->setMoving(false);
		}
	}
}