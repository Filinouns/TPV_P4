#include "Fighter.h"
#include "Messages_defs.h"

Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation_(SDLK_RIGHT, SDLK_LEFT, 5), thrust_(SDLK_UP, 0.5, 2), reduceSpeed_(0.995), normalGun_(SDLK_SPACE)
{
	width_ = 50;
	height_ = 50;
	position_ = Vector2D(200, 200);

	//setId();

	addC(&fighterImage_);
	addC(&fighterMove_);
	addC(&oppositeSide_);
	addC(&rotation_);
	addC(&thrust_);
	addC(&reduceSpeed_);
	addC(&normalGun_);

	setId(msg::Fighter);

	setActive(false);
}

Fighter::~Fighter() {}

void Fighter::initFighter() {
	position_ = Vector2D(this->game_->getWindowWidth() / 2, this->game_->getWindowHeight() / 2);
	velocity_ = Vector2D(0, 0);

	setActive(true);
}

void Fighter::receive(const void * senderObj, const msg::Message & m) {

	Container::receive(senderObj, m);
	
	switch (m.type_) {
	case msg::GAME_START:
		this->getGame()->send(this, msg::FighterInfo(getId(), msg::Broadcast, this));
		break;
	case msg::ROUND_START:
		initFighter();
		break;
	case msg::ROUND_OVER:
		setActive(false);
		break;
	default:
		break;
	}
}
