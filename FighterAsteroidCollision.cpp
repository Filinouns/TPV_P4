#include "FighterAsteroidCollision.h"

#include "GameManager.h"
#include "Collisions.h"

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
						//Mandar msg::FighterAsteroidCollision con valores correspondientes

						cout << "Me golpiaron guey" << endl;
					}
				}
			}
		}
	}

}