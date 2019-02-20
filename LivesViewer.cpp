#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer()
{
}


LivesViewer::~LivesViewer()
{
}

void LivesViewer::render(Container* c, Uint32 time) {

	int aux = static_cast<GameManager*>(c)->getLives();
	Texture msg(c->getGame()->getRenderer(),
		"Lives: "  + aux,
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0xff000000) });

	msg.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 4 - msg.getWidth() / 2, c->getGame()->getWindowHeight() - 600);
}