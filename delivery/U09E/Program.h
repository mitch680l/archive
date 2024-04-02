#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "Restaurant.h";
#include "RestaurantManager.h"

class Program {
public:
	Program();
	~Program();
	void Run();
private:
	RestaurantManager m_restaurantManager;
	void DisplayRestaurants(const vector<Restaurant>& restaurants);
};


#endif