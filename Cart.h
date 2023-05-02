#define CART_H
#include <string>
using namespace std;

class Cart
{
private:
	string item;
	float totals;

public:
	Cart();
	Cart(string i, float t);

	//setters
	void setprintTotal(int t) { totals = t; }
	void setaddItems(string i) { item = i; }
	void setremoveItems(string i) { item = i; }
	void setprintItems(int t) { totals = t; }

	//getters
	float getprintTotal() { return totals; }
	string getaddItems() { return item; }
	string getremoveItems() { return item; }
	float getprintItems() { return totals; }
	
	void updateCart(string i, float t)
	{
	    
	    item = i;
	    totals = t;
	    
	}

};
