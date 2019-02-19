#include "TempGunIC.h"

#include "Bullets.h"

TempGunIC::TempGunIC(SDL_Keycode ctrlKey) : ctrlKey_(ctrlKey)
{
}


TempGunIC::~TempGunIC()
{
}

void TempGunIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey_) {
			//static_cast<DemoContainer*>(c)->reset();
			Vector2D p = Vector2D(300, 300);
			Vector2D v = Vector2D(0, -1);
			static_cast<Bullets*>(c)->createBullet(p, v);
		}
	}
}
