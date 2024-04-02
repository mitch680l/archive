#include "Restaurant.h"
#include "RestaurantManager.h"
#include "Program.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	/*
	RestaurantManager newMan;
	newMan.Load();

	
	Restaurant newRest;
	newRest.Setup("Sherman", "75th", "Shawnee", "Kansas", 66202);
	newMan.AddRestaurant(newRest);

	vector<Restaurant> restaurants = newMan.GetAllRestaurants();
	cout << left << setw(3) << "#" << setw(20) << "NAME" << setw(25) << "STREET" << setw(15) << "CITY" << setw(8) << "STATE" << setw(6) << "ZIP" << endl << string(80, '-') << endl;
	for (size_t i = 0; i < restaurants.size(); i++)
	{
		cout << left << setw(3) << i;
		restaurants[i].Display();
	}

	newMan.Save();
	*/

	Program program;
	program.Run();
	return -1;
}