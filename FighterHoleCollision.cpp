#include "FighterHoleCollision.h"
#include "Messages_defs.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


FighterHoleCollision::FighterHoleCollision()
{
	fighter_ = nullptr;
	holes_ = nullptr;
}


FighterHoleCollision::~FighterHoleCollision() {}

void FighterHoleCollision::update(Container * c, Uint32 time)
{
	bool auxRunning = static_cast<GameManager*>(c)->getRunning();
	if (auxRunning) {
		if (fighter_ != nullptr || holes_ != nullptr) {
			for (VeryDarkHole* a : *holes_) {
				if (fighter_->isActive() && a->isActive()) {
					if (Collisions::collidesWithRotation(fighter_, a)) {
						//Mensaje de colision
						static_cast<GameManager*>(c)->getGame()->send(this, msg::FighterHoleCollisionMsg(c->getId(), msg::Broadcast, fighter_, a));
					}
				}
			}
		}
	}

}

void FighterHoleCollision::receive(Container * c, const msg::Message & m)
{
	switch (m.type_) {
	case msg::DARKHOLES_INFO: {
		const msg::DarkHoleInfo m_ = static_cast<const msg::DarkHoleInfo&>(m);
		holes_ = m_.holes_;
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
