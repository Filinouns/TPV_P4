#include "GameStatusViewGC.h"
#include "GameManager.h"


GameStatusViewGC::GameStatusViewGC()
{
}


GameStatusViewGC::~GameStatusViewGC()
{
}

void GameStatusViewGC::render(Container* c, Uint32 time) {

	int auxScore = static_cast<GameManager*>(c)->getScore();
	int auxWinner = static_cast<GameManager*>(c)->getWinner();
	int auxLives = static_cast<GameManager*>(c)->getLives();

	//Todos los mensajes
	Texture msgGameOver(c->getGame()->getRenderer(),
		"Game Over! The winner is " + auxWinner,
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });

	Texture msgContinue(c->getGame()->getRenderer(),
		"“Press ENTER to Continue",
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });

	Texture msgNewGame(c->getGame()->getRenderer(),
		"“Press ENTER to Start a New Game",
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });

	if (auxLives <= 0) {
		msgGameOver.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 2 - msgGameOver.getWidth() / 2, c->getGame()->getWindowHeight() - 150);

		/*if (condicion para que sea nueva partida o nueva ronda¿ ? )
		{
			msgContinue.render(c->getGame()->getRenderer(),
				c->getGame()->getWindowWidth() / 2 - msgContinue.getWidth() / 2, c->getGame()->getWindowHeight() - 50);
		}
		else
		{
			msgNewGame.render(c->getGame()->getRenderer(),
				c->getGame()->getWindowWidth() / 2 - msgNewGame.getWidth() / 2, c->getGame()->getWindowHeight() - 50);

		}*/

	}
}