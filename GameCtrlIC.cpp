#include "GameCtrlIC.h"
#include "GameManager.h"


GameCtrlIC::GameCtrlIC(SDL_Keycode ctrlKey) :
	ctrlKey_(ctrlKey) {
}


GameCtrlIC::~GameCtrlIC()
{
}

void GameCtrlIC::handleInput(Container* c, Uint32 time, const SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == ctrlKey_) 
		{
			if (!static_cast<GameManager*>(c)->getRunning())
			{
				if (static_cast<GameManager*>(c)->getLives() == 3
					&& static_cast<GameManager*>(c)->getScore() == 0) 
				{
					//msg::Message tipo GAME_START
				}
				//msg::Message tipo ROUND_START
				
			}
			
		}
	}
}