#include "BulletsHoleCollision.h"
#include "Messages_defs.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Messages_defs.h"


BulletsHoleCollision::BulletsHoleCollision()
{
	bullets_ = nullptr;
	holes_ = nullptr;
}


BulletsHoleCollision::~BulletsHoleCollision() {}

void BulletsHoleCollision::update(Container * c, Uint32 time)
{
	bool auxRunning = static_cast<GameManager*>(c)->getRunning();
	if (auxRunning) {
		if (holes_ != nullptr || bullets_ != nullptr) {
			for (Bullet* b : *bullets_) {
				for (VeryDarkHole* a : *holes_) {
					if (b->isActive() && a->isActive()) {
						if (Collisions::collidesWithRotation(b, a)) {
							static_cast<GameManager*>(c)->getGame()->send(this, msg::BulletHoleCollision(c->getId(), msg::Broadcast, b, a));
						}
					}
				}
			}
		}
	}
}

void BulletsHoleCollision::receive(Container * c, const msg::Message & m)
{
	switch (m.type_) {
	case msg::DARKHOLES_INFO: {
		const msg::DarkHoleInfo m_ = static_cast<const msg::DarkHoleInfo&>(m);
		holes_ = m_.holes_;
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
