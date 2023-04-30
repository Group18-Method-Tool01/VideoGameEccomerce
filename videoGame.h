#pragma once
#include <string>

using namespace std;

class videoGame
{
private:
	string gameName;
	double gameCost;
	int itemNum;
	int stock;
public:
	videoGame();
	videoGame(string n, double cost, int num, int snum);

	//setters
	void setName(string n) { gameName = n; }
	void setCost(double cost) { gameCost = cost; }
	void setItemNum(int num) { itemNum = num; }
	void setStock(int snum) { stock = snum; }

	//getters
	string getName() { return gameName; }
	double getCost() { return gameCost; }
	int getItemNum() { return itemNum; }
	int getStock() { return stock; }
};
