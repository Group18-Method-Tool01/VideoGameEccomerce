#include "videoGame.h"
#include <iostream>
#include <fstream>

using namespace std;

//constructor; initializing everything to empty string
videoGame::videoGame()
{
	gameName = " ";
	gameCost = 0;
	itemNum = 0.0;
}

videoGame::videoGame(string n, double cost, int num)
{
	gameName = n;
	gameCost = cost;
	itemNum = num;
}
