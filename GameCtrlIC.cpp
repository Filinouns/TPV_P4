#include "GameCtrlIC.h"
#include "GameManager.h"
#include "Messages_defs.h"


GameCtrlIC::GameCtrlIC(SDL_Keycode ctrlKey) :
	ctrlKey_(ctrlKey) {
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container* c, Uint32 time) {
	if (InputHandler::getInstance()->isAnyKeyDown()) {
		if (InputHandler::getInstance()->isKeyDown(ctrlKey_))
		{
			if (!static_cast<GameManager*>(c)->getRunning()) {
				if (static_cast<GameManager*>(c)->getGameOver()) {
					//msg::Message tipo GAME_START
					//send(this, msg::Message(msg::NO_MORE_ASTEROIDS, getId(), msg::Broadcast));
					static_cast<GameManager*>(c)->getGame()->send(this, msg::Message(msg::GAME_START, c->getId(), msg::Broadcast));
				}
				//msg::Message tipo ROUND_START
				static_cast<GameManager*>(c)->getGame()->send(this, msg::Message(msg::ROUND_START, c->getId(), msg::Broadcast));
			}
			
		}
	}
}