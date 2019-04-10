#include "AsteroidHoleCollision.h"
#include "Messages_defs.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


AsteroidHoleCollision::AsteroidHoleCollision()
{
	asteroids_ = nullptr;
	holes_ = nullptr;
}


AsteroidHoleCollision::~AsteroidHoleCollision() {}

void AsteroidHoleCollision::update(Container * c, Uint32 time)
{
	bool auxRunning = static_cast<GameManager*>(c)->getRunning();
	if (auxRunning) {
		if (asteroids_ != nullptr || holes_ != nullptr) {
			for (VeryDarkHole* h : *holes_) {
				for (Asteroid* a : *asteroids_) {
					if (h->isActive() && a->isActive()) {
						if (Collisions::collidesWithRotation(a, h)) {
							static_cast<GameManager*>(c)->getGame()->send(this, msg::AsteroidHoleCollision(c->getId(), msg::Broadcast, a, h));
						}
					}
				}
			}
		}
	}
}

void AsteroidHoleCollision::receive(Container * c, const msg::Message & m)
{
	switch (m.type_) {
	case msg::ASTEROIDS_INFO: {
		const msg::AsteroidsInfo m_ = static_cast<const msg::AsteroidsInfo&>(m);
		asteroids_ = m_.asteroids_;
		break;
	}
	case msg::DARKHOLES_INFO: {
		const msg::DarkHoleInfo m_ = static_cast<const msg::DarkHoleInfo&>(m);
		holes_ = m_.holes_;
		break;
	}
	default:
		break;
	}
}
