#include <string>
#include <ostream>
#include <vector>
#include <istream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Restaurant.h"
#include "RestaurantManager.h"
#include "Program.h"

using namespace std;

Program::Program() {
	m_restaurantManager.Load();
}

Program::~Program() {
	m_restaurantManager.Save();
}

void Program::DisplayRestaurants(const vector<Restaurant>& restaurants) {
	cout << endl << "SEARCH RESULTS" << endl;
	cout << left << setw(3) << "#" << setw(20) << "NAME" << setw(25) << "STREET" << setw(15) << "CITY" << setw(8) << "STATE" << setw(6) << "ZIP" << endl << string(80, '-') << endl;
	for (size_t i = 0; i < restaurants.size(); i++)
	{
		cout << left << setw(3) << i;
		restaurants[i].Display();
	}
}

void Program::Run() {
	int userChoice = -1;
	cout << "MAIN MENU" << endl;
	cout << string(80, '-') << endl;
	cout << "0. EXIT" << endl;
	cout << "1. Add new restaurant" << endl;
	cout << "2. View all restaurants" << endl;
	cout << "3. Search restaurants by name" << endl;
	cout << "4. Search restaurants by city" << endl;
	cout << "5. Search restaurants by state" << endl;
	cout << "6. Search restaurants by zipcode" << endl;
	while (userChoice != 0) {
		string userInput;
		int zip;
		cout << endl << endl;
		cout << ">> ";
		cin >> userChoice;
		cout << endl << endl;
		switch (userChoice) {
		case(0):
			break;
		case(1):
			m_restaurantManager.AddRestaurant();
			break;
		case(2):
			DisplayRestaurants(m_restaurantManager.GetAllRestaurants());
			break;
		case(3):
			cout << "What name" << endl;
			cin >> userInput;
			cout << endl;
			DisplayRestaurants(m_restaurantManager.FindByName(userInput));
			break;
		case(4):
			cout << "What City" << endl;
			cin >> userInput;
			cout << endl;
			DisplayRestaurants(m_restaurantManager.FindByCity(userInput));
			break;
		case(5):
			cout << "What State" << endl;
			cin >> userInput;
			cout << endl;
			DisplayRestaurants(m_restaurantManager.FindByState(userInput));
			break;
		case(6):
			cout << "What Zip" << endl;
			cin >> zip;
			cout << endl;
			DisplayRestaurants(m_restaurantManager.FindByZipcode(zip));
			break;
	}
	
	}
}