#include "FighterAsteroidCollision.h"
#include "Messages_defs.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"

FighterAsteroidCollision::FighterAsteroidCollision() {
	fighter_ = nullptr;
	asteroids_ = nullptr;
}

FighterAsteroidCollision::~FighterAsteroidCollision() {}

void FighterAsteroidCollision::update(Container* c, Uint32 time) {
	bool auxRunning = static_cast<GameManager*>(c)->getRunning();
	if (auxRunning) {
		if (fighter_ != nullptr || asteroids_ != nullptr) {
			for (Asteroid* a : *asteroids_) {
				if (fighter_->isActive() && a->isActive()) {
					if (Collisions::collidesWithRotation(fighter_, a)) {
						//Mensaje de colision
						static_cast<GameManager*>(c)->getGame()->send(this, msg::FighterAsteroidCollisionMsg(c->getId(), msg::Broadcast, fighter_, a));
					}
				}
			}
		}
	}

}

void FighterAsteroidCollision::receive(Container * c, const msg::Message & m) {
	switch (m.type_) {
	case msg::ASTEROIDS_INFO: {
		const msg::AsteroidsInfo m_ = static_cast<const msg::AsteroidsInfo&>(m);
		asteroids_ = m_.asteroids_;
		break;
	}
	case msg::FIGHTER_INFO: {
		const msg::FighterInfo m_ = static_cast<const msg::FighterInfo&>(m);
		fighter_ = m_.fighter_;
		break;
	}
	default:
		break;
	}
}

