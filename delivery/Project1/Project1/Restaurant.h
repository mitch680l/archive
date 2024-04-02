#ifndef _RESTAURANT_H
#define _RESTAURANT_H
#include <string>
#include <vector>
#include "Meal.h"

class Restaurant {
public:
	Restaurant();
	Restaurant(std::string name, std::string address);
	void setAddress(std::string address);
	void setName(std::string name);
	void setId(int id);
	void addMeal(Meal menuItem);
	void getMenuItems(std::vector<Meal>& temp);
	Meal* getMealItem(int index);
	std::string getAddress();
	std::string getName();
	int getId();
private:
	std::string address;
	std::string name;
	int id;
	std::vector<Meal> menuItems;
};

#endif