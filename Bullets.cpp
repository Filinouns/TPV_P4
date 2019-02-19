#include "Bullets.h"

Bullets::Bullets(SDLGame* game) : 
	GameObjectPool(game), 
	bulletImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect)),
	tempGun_(SDLK_q)
{

	for (auto o : getAllObjects()) {
		o->addC(&bulletImage_);
		o->addC(&naturalMove_);
		o->addC(&deactivate_);
	}

	addC(&tempGun_);
}

Bullets::~Bullets() {}

void Bullets::createBullet(Vector2D p, Vector2D d) {
	Bullet *b = getUnusedObject();
	if (b != nullptr) {
		b->setActive(true);
		b->setPosition(p);
		b->setVelocity(d);
	}
}