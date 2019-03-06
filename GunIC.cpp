#include "GunIC.h"
#include "Fighter.h"
#include "Messages_defs.h"

GunIC::GunIC(SDL_Keycode ctrlKey) :
	ctrlKey_(ctrlKey)
{
}

GunIC::~GunIC() {}

void GunIC::handleInput(Container * c, Uint32 time, const SDL_Event & event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey_) {
			Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + 
				Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
			Vector2D d = Vector2D(0, -1).rotate(c->getRotation());

			int bT = 0;

			//Mensaje con p, d y bT (pos, dir, bulletType)
			static_cast<Fighter*>(c)->getGame()->send(c, msg::Shoot(c->getId(), msg::Broadcast, p, d, bT));
			//cout << "PIUM!" << endl;
		}
	}
}
