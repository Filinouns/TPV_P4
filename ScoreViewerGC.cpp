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

	string s = std::to_string(auxScore);

	Texture msg0(c->getGame()->getRenderer(),
		"Score: " + s,
		*(c->getGame()->getServiceLocator()->getFonts()->getFont(
			Resources::ARIAL24)), { COLOR(0x0022ffff) });

	msg0.render(c->getGame()->getRenderer(),
		c->getGame()->getWindowWidth() / 1.5 - msg0.getWidth() / 2 + 150, c->getGame()->getWindowHeight() - 575);

}