#pragma once

#include "GraphicsComponent.h"

class LivesViewer : public GraphicsComponent {
public:
	LivesViewer();
	LivesViewer(Texture* texture, SDL_Rect clip);
	virtual ~LivesViewer();
	virtual void render(Container* c, Uint32 time);

private:
	Texture* texture_;
	SDL_Rect clip_;
};

