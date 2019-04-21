#include "DarkHoles.h"
#include "Messages_defs.h"
#include "ServiceLocator.h"

#include "Logger.h"
#include <sstream>

DarkHoles::DarkHoles(SDLGame* game) : GameObjectPool(game), rotating_(5),
blackHoleImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::DarkHole)) {
	
	numHoles_ = initHoles_;

	for (auto o : getAllObjects()) {
		o->addC(&rotating_);
		o->addC(&blackHoleImage_);
	}

	setId(msg::DarkHoles);
}

DarkHoles::~DarkHoles() {}

void DarkHoles::InitHoles() {
	for (int i = 0; i < numHoles_; i++) {
		if (getUnusedObject() != nullptr) {
			VeryDarkHole *a = getUnusedObject();
			a->setActive(true);
			a->setPosition(randPos());

			a->setHeight(50);
			a->setWidth(50);

			//Logger
			callLogger(a->getPosition());
		}
	}

	setId(msg::DarkHoles);

	setActive(false);
}

void DarkHoles::DuplicateHoles() {
	numHoles_ *= 2;
	if (numHoles_ > 8) numHoles_ = initHoles_;
}

void DarkHoles::receive(const void * senderObj, const msg::Message & m) {
	Container::receive(senderObj, m);

	switch (m.type_) {

	case msg::GAME_START:
		this->getGame()->send(this, msg::DarkHoleInfo(getId(), msg::Broadcast, &getAllObjects()));
		break;

	case msg::ROUND_START:
		InitHoles();
		setActive(true);
		break;

	case msg::ROUND_OVER:
		this->deactiveAllObjects();
		DuplicateHoles();
		setActive(false);
		break;
	default: 
		break;
	}
}

//Info del Logger
void DarkHoles::callLogger(Vector2D p) {
	Logger::instance()->log([p]() {
		stringstream s;
		s << "New Hole: " << p;
		return s.str();
	});
}

//Arreglar las posiciones
Vector2D DarkHoles::randPos() {
	Vector2D p = Vector2D(0, 0);
	int aux = rand() % 4;

	switch (aux) {
		//Arriba
	case 0:
		p = Vector2D(rand() % this->getGame()->getWindowWidth(), rand() % 50);
		break;
		//Abajo
	case 1:
		p = Vector2D(rand() % this->getGame()->getWindowWidth(), rand() % 50 + (this->getGame()->getWindowHeight() - 150));
		break;
		//Izq
	case 2:
		p = Vector2D(rand() % 50, rand() % this->getGame()->getWindowHeight());
		break;
		//Der
	case 3:
		p = Vector2D(rand() % 50 + (this->getGame()->getWindowWidth() - 150), rand() % this->getGame()->getWindowHeight());
		break;
	default:
		break;
	}
	return p;
}