#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant() {
	address = "";
	name = "";
}

Restaurant::Restaurant(string name, string address) {
	this->address = address;
	this->name = name;
}

void Restaurant::setAddress(string address) {
	this->address = address;
}

void Restaurant::setName(string name) {
	this->name = name;
}

void Restaurant::setId(int id) {
	this->id = id;
}

string Restaurant::getAddress() {
	return address;
}

string Restaurant::getName() {
	return name;
}

int Restaurant::getId() {
	return id;
}

void Restaurant::addMeal(Meal menuItem) {
	menuItems.push_back(menuItem);
}

Meal* Restaurant::getMealItem(int index) {
	return &menuItems.at(index);
}

void Restaurant::getMenuItems(vector<Meal>& temp) {
	temp = menuItems;
}