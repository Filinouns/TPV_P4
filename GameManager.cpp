#include "GameManager.h"



GameManager::GameManager(SDLGame* game) :
	Container(game),
	gameCtrl_(SDLK_RETURN)
{
	running_ = false;
	gameOver_ = true;
	score_ = 0;
	lives_ = maxLives_;
	winner_ = 0;

	addC(&gameCtrl_);
	addC(&scoreView_);
	addC(&gameStatusView_);
	addC(&livesViewer_);
	addC(&fighterAsteroidCollision_);
	addC(&bulletsAsteroidsCollision_);
}


GameManager::~GameManager() {}
