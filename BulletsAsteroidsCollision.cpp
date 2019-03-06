#include "BulletsAsteroidsCollision.h"

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
							//Mandar msg::BulletAsteroidCollision con valores correspondientes

							cout << "Te golpie guey kak" << endl;
						}
					}
				}
			}
		}
	}
}

void BulletsAsteroidsCollision::receive(Container * c, const msg::Message & msg) {
	switch (msg.type_) {
	default:
		break;
	}
}
