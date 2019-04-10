#pragma once
#include "InputComponent.h"
class GameCtrlIC : public InputComponent
{
public:
	GameCtrlIC(SDL_Keycode ctrlKey);
	virtual ~GameCtrlIC();
	virtual void handleInput(Container* c, Uint32 time);

private:
	SDL_Keycode ctrlKey_;
};

