#include "BulletsAsteroidsCollision.h"
#include "Messages_defs.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"

BulletsAsteroidsCollision::BulletsAsteroidsCollision() {
	bullets_ = nullptr;
	asteroids_ = nullptr;
}

BulletsAsteroidsCollision::~BulletsAsteroidsCollision() {}

void BulletsAsteroidsCollision::update(Container* c, Uint32 time) {
	bool auxRunning = static_cast<GameManager*>(c)->getRunning();
	if (auxRunning) {
		if (asteroids_ != nullptr || bullets_ != nullptr) {
			for (Bullet* b : *bullets_) {
				for (Asteroid* a : *asteroids_) {
					if (b->isActive() && a->isActive()) {
						if (Collisions::collidesWithRotation(b, a)) {
							static_cast<GameManager*>(c)->getGame()->send(this, msg::BulletAsteroidCollision(c->getId(), msg::Broadcast, b, a));
						}
					}
				}
			}
		}
	}
}

void BulletsAsteroidsCollision::receive(Container * c, const msg::Message & m) {
	switch (m.type_) {
	case msg::ASTEROIDS_INFO: {
		const msg::AsteroidsInfo m_ = static_cast<const msg::AsteroidsInfo&>(m);
		asteroids_ = m_.asteroids_;
		break;
	}
	case msg::BULLETS_INFO: {
		const msg::BulletsInfoMsg m_ = static_cast<const msg::BulletsInfoMsg&>(m);
		bullets_ = m_.bullets_;
		break;
	}
	default:
		break;
	}
}
