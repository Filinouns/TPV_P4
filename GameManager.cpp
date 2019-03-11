#include "GameManager.h"
#include "Messages_defs.h"
#include "Asteroids.h"
#include "SDLAudioManager.h"


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
		setRunning(true);
		
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
		this->getGame()->send(this, msg::Message(msg::GAME_OVER, getId(), msg::Broadcast));
		break;

	case msg::FIGHTER_ASTEROID_COLLISION: {
		
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 1);	//Sonido Explosion
		
		setRunning(false);
		int myHp = getLives();
		myHp--;
		setLives(myHp);

		this->getGame()->send(this, msg::Message(msg::ROUND_OVER, getId(), msg::Broadcast));
		
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


