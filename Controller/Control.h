#pragma once
#include "Grid.h"
#include <chrono>

class Control
{
public:
	Grid *grid = new Grid();
	bool endGame = false;
	Control();
	bool Process();
	void MoveRight();
	void MoveLeft();
	void Rotate();
	void Fell();
	void SetNextStick();
	int getScore();
	void Restart();
	~Control();
private:
	const std::chrono::duration<double, std::milli> stepSpan = std::chrono::duration<double, std::milli>(500);
	const int scoreForLine = 100;
	const int scoreForBlock = 10;
	bool nextStick = false;
	int score = 0;
	std::chrono::high_resolution_clock::time_point lastTetrisStep;
	int fallingBlock;
};

