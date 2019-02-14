#include "Fighter.h"



Fighter::Fighter(SDLGame* game) :
	Container(game),
	fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), { 47, 90, 207, 250 }),
	rotation_(SDLK_RIGHT, SDLK_LEFT, 5), thrust_(SDLK_UP, 0.5, 2), reduceSpeed_(0.995)
{
	width_ = 50;
	height_ = 50;
	position_ = Vector2D(200, 200);
	//velocity_ = Vector2D(2, 5);

	//setId();

	addC(&fighterImage_);
	addC(&naturalMove_);
	addC(&oppositeSide_);
	addC(&rotation_);
	addC(&thrust_);
	addC(&reduceSpeed_);
}


Fighter::~Fighter() {}
