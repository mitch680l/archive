#ifndef _RESTAURANTMANAGER_H
#define _RESTAURANTMANAGER_H
#include <string>
#include <ostream>
#include <vector>
#include <istream>
#include "Restaurant.h"

using namespace std;

class RestaurantManager {
public:
	static void Load();
	static void Save();
	static void AddRestaurant(Restaurant newRest);
	static void AddRestaurant();
	static vector<Restaurant> GetAllRestaurants();
	static vector<Restaurant> FindByName(string name);
	static vector<Restaurant> FindByCity(string city);
	static vector<Restaurant> FindByState(string state);
	static vector<Restaurant> FindByZipcode(int zipcode);
private:
	static vector<Restaurant> m_restaurants;
};




#endif