#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer()
{
}


LivesViewer::~LivesViewer()
{
}

void LivesViewer::render(Container* c, Uint32 time) {

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
}