#include "GunIC.h"
#include "Fighter.h"
#include "Messages_defs.h"

#include "Logger.h"
#include <sstream>

GunIC::GunIC(SDL_Keycode ctrlKey) :
	ctrlKey_(ctrlKey)
{
}

GunIC::~GunIC() {}

void GunIC::handleInput(Container * c, Uint32 time) {
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(ctrlKey_)) {
			Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) + 
				Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
			Vector2D d = Vector2D(0, -1).rotate(c->getRotation());

			int bT = 0;

			//Mensaje con p, d y bT (pos, dir, bulletType)
			static_cast<Fighter*>(c)->getGame()->send(c, msg::Shoot(c->getId(), msg::Broadcast, p, d, bT));

			/*Logger::instance()->log([p, d]() {
				stringstream s;
				s << "Shooting: " << p << " " << d;
				return s.str();
			});*/
		}
	}
}
