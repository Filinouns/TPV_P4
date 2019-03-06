#pragma once
#include "Container.h"
#include "GameCtrlIC.h"
#include "ScoreViewerGC.h"
#include "LivesViewer.h"
#include "GameStatusViewGC.h"
#include "FighterAsteroidCollision.h"
#include "BulletsAsteroidsCollision.h"

class GameManager : public Container {
public:
	GameManager(SDLGame* game);
	virtual ~GameManager();

	bool getRunning() { return running_; }	
	bool getGameOver() { return gameOver_; }	
	int getScore() { return score_; }
	int getLives() { return lives_; }	
	int getWinner() { return winner_; }
	void receive(const void* senderObj, const msg::Message& msg);

protected:
	void setRunning(bool r) { running_ = r; }
	void setGameOver(bool g) { gameOver_ = g; }
	void setScore(int s) { score_ = s; }
	void setLives(int l) { lives_ = l; }
	void setWinner(int w) { winner_ = w; }

private:

	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_;
	int lives_;
	int winner_; // 0=none, 1=asteroids, 2=fighter
	
	// components of GameManager
	GameCtrlIC gameCtrl_;
	ScoreViewerGC scoreView_;
	GameStatusViewGC gameStatusView_;
	LivesViewer livesViewer_;
	FighterAsteroidCollision fighterAsteroidCollision_;
	BulletsAsteroidsCollision bulletsAsteroidsCollision_;
};


