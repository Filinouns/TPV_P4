#include "GameManager.h"
#include "Messages_defs.h"
#include "Asteroids.h"
#include "SDLAudioManager.h"

#include "Logger.h"

GameManager::GameManager(SDLGame* game) :
	Container(game),
	gameCtrl_(SDLK_RETURN), 
	livesViewer_(game->getServiceLocator()->getTextures()->getTexture(Resources::Badges), { 400, 376, 200, 188 })
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
	addC(&fighterHoleCollision_);
	addC(&bulletsHoleCollision_);
	addC(&asteroidHoleCollision_);
}

GameManager::~GameManager() {}

void GameManager::receive(const void * senderObj, const msg::Message & m)
{
	Container::receive(senderObj, m);

	switch (m.type_) {
	case msg::GAME_START:
		setGameOver(false);
		setWinner(0);
		setLives(maxLives_);
		setScore(0);
		cout << "Game Start" << endl;
		break;

	case msg::ROUND_START:
		Logger::instance()->log("Round Start");
		setRunning(true);
		setWinner(0);
		
		this->getGame()->getServiceLocator()->getAudios()->playMusic(Resources::ImperialMarch, -1); //Reproducir backgorund music (ImperialMarch)
		break;

	case msg::ASTEROID_DESTROYED: {
		const msg::AsteroidDestroyed m_ = static_cast<const msg::AsteroidDestroyed&>(m);
		int auxScore = getScore();
		setScore(auxScore + m_.points_);
		break;
	}

	case msg::NO_MORE_ASTEROIDS:
		setRunning(false);
		setGameOver(true);
		setWinner(1);

		//Stop music
		this->getGame()->getServiceLocator()->getAudios()->haltMusic();	//para la musica de fondo

		this->getGame()->send(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));
		Logger::instance()->log("Round Over"); 
		this->getGame()->send(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));
		break;

	case msg::FIGHTER_ASTEROID_COLLISION: {
		
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);	//Sonido Explosion
		
		setRunning(false);
		int myHp = getLives();
		myHp--;
		setLives(myHp);

		this->getGame()->send(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));
		Logger::instance()->log("Round Over");

		this->getGame()->getServiceLocator()->getAudios()->haltMusic();  //Para la musica de fondo

		if (getLives() == 0) {
			setGameOver(true);
			setWinner(2);
			this->getGame()->send(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));

			//sonido abucheo al perder
			this->getGame()->getServiceLocator()->getAudios()->playMusic(Resources::Boooo, 1);	
		}
		break;
	}
	case msg::FIGHTER_HOLE_COLLISION: {
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0);	//Sonido Explosion

		setRunning(false);
		int myHp = getLives();
		myHp--;
		setLives(myHp);

		this->getGame()->send(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));
		Logger::instance()->log("Round Over");

		this->getGame()->getServiceLocator()->getAudios()->haltMusic();  //Para la musica de fondo

		if (getLives() == 0) {
			setGameOver(true);
			setWinner(2);
			this->getGame()->send(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));

			//sonido abucheo al perder
			this->getGame()->getServiceLocator()->getAudios()->playMusic(Resources::Boooo, 1);
		}
		break;
	}

	default:
		break;
	}
}