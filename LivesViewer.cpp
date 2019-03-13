#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer() :  
	texture_(nullptr), clip_() {
	}


LivesViewer::LivesViewer(Texture* texture, SDL_Rect clip) :
	texture_(texture), clip_(clip) {
}



LivesViewer::~LivesViewer()
{
}

/*void LivesViewer::render(Container* c, Uint32 time) {

	int l = static_cast<GameManager*>(c)->getLives();

	string s = std::to_string(l);

	Texture msg(c->getGame()->getRenderer(),
		"Lives: " + s,
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0xff000000) });

	//int h = msg.getHeight();
	//int w = msg.getWidth();

	msg.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 4 - msg.getWidth(), c->getGame()->getWindowHeight() - 600);
}*/

void LivesViewer::render(Container* c, Uint32 time) {
	int hp = static_cast<GameManager*>(c)->getLives();
	for (int i = 1; i < hp + 1; i++) {
		SDL_Rect dest = RECT((i * 40), 10, 50, 50);
		texture_->render(dest, &clip_);
	}
}