#pragma once
#include <string>

using namespace std;

class videoGame
{
private:
	string gameName;
	double gameCost;
	int itemNum;

public:
	videoGame();
	videoGame(string n, double cost, int num);

	//setters
	void setName(string n) { gameName = n; }
	void setCost(double cost) { gameCost = cost; }
	void setItemNum(int num) { itemNum = num; }

	//getters
	string getName() { return gameName; }
	double getCost() { return gameCost; }
	int getItemNum() { return itemNum; }

};
