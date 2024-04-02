#include "RestaurantManager.h"
#include <string>
#include <ostream>
#include <vector>
#include <istream>
#include <iostream>
#include <fstream>
#include "Restaurant.h"

using namespace std;

vector<Restaurant> RestaurantManager::m_restaurants;


void RestaurantManager::Load() {
	ifstream input("Restaurants.txt");
	if (input.fail())
	{
		return;
	}
	Restaurant buffer;
	while (input >> buffer)
	{
		m_restaurants.push_back(buffer);
	}

}

void RestaurantManager::Save() {
	ofstream output("Restaurants.txt");
	if (output.fail())
	{
		return;
	}
	
	for (const Restaurant& restaurant : m_restaurants)
	{
		output << restaurant;
	}
}

void RestaurantManager::AddRestaurant(Restaurant newRest) {
	m_restaurants.push_back(newRest);
}

void RestaurantManager::AddRestaurant() {
	Restaurant newRest;
	cin.ignore();
	cout << "Enter Restaurant Name" << endl;
	getline(cin, newRest.m_name);
	cout << endl;
	cout << "Enter Address" << endl;
	getline(cin, newRest.m_address);
	cout << endl;
	cout << "Enter State" << endl;
	getline(cin, newRest.m_state);
	cout << endl;
	cout << "Enter City" << endl;
	getline(cin, newRest.m_city);
	cout << endl;
	cout << "Enter zipcode" << endl;
	cin >> newRest.m_zipcode;


	m_restaurants.push_back(newRest);
}

vector<Restaurant> RestaurantManager::GetAllRestaurants() {
	return m_restaurants;
}

vector<Restaurant> RestaurantManager::FindByName(string name) {
	vector<Restaurant> matches;

	for (Restaurant restaurant : m_restaurants) {
		if (restaurant.m_name == name) {
			matches.push_back(restaurant);
		}
	}

	return matches;
}

vector<Restaurant> RestaurantManager::FindByCity(string city) {
	return [](vector<Restaurant> restaurants, string city) -> vector<Restaurant> {
		vector<Restaurant> matches;
		for (auto& r : restaurants)
		{
			if (r.m_city == city)
			{
				matches.push_back(r);
			}
		}
		return matches;
	} (m_restaurants, city);

}

vector<Restaurant> RestaurantManager::FindByState(string state)
{
	return
		[=]()
	{
		vector<Restaurant> matches;
		for (auto& r : m_restaurants)
		{
			if (r.m_state == state)
			{
				matches.push_back(r);
			}
		}
		return matches;
	}();
}

vector<Restaurant> RestaurantManager::FindByZipcode(int zipcode)
{
	return
		[=]()
	{
		vector<Restaurant> matches;
		for (auto& r : m_restaurants)
		{
			if (r.m_zipcode == zipcode)
			{
				matches.push_back(r);
			}
		}
		return matches;
	}();
}
