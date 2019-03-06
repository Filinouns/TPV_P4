#include "Bullets.h"
#include "Messages_defs.h"

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

	setId(msg::BulletsShooter);

	setActive(false);
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

void Bullets::receive(const void * senderObj, const msg::Message & msg) {
	switch (msg.type_) {

	case msg::GAME_START:
		this->getGame()->send(this, msg::BulletsInfoMsg(getId(), msg::Broadcast, &getAllObjects()));
		break;

	case msg::ROUND_START:
		setActive(true);
		break;

	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;

	case msg::BULLET_ASTEROID_COLLISION:
		const msg::BulletAsteroidCollision m_ = static_cast<const msg::BulletAsteroidCollision&>(msg);
		m_.bullet_->setActive(false);
		break;

		//Crear bala
	case msg::FIGHTER_SHOOT:

		break;

	default:
		break;
	}
}
