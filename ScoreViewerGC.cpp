#include "ScoreViewerGC.h"
#include "GameManager.h"


ScoreViewerGC::ScoreViewerGC()
{
}


ScoreViewerGC::~ScoreViewerGC()
{
}

void ScoreViewerGC::render(Container* c, Uint32 time) {
	
	int auxScore = static_cast<GameManager*>(c)->getScore();
	Texture msg0(c->getGame()->getRenderer(),
		"Score: " + auxScore,
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });

	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 1.5 - msg0.getWidth() / 2, c->getGame()->getWindowHeight() - 600);
}