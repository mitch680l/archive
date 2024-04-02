
#include "Customer.h"
#include "Driver.h"
#include <string>
#include <iostream>



Driver::Driver() {
	name = "";
	phoneNumber = "";
}

Driver::Driver(std::string name, std::string phoneNumber) {
	this->name = name;
	this->phoneNumber = phoneNumber;

}

std::string Driver::getName() {
	return name;
}

std::string Driver::getPhoneNumber() {
	return phoneNumber;
}

void Driver::operator=(Customer customer) {
	name = customer.getName();
	phoneNumber = customer.getPhoneNumber();
}

void Driver::addOrder(int orderNum) {
	if (orderNums.size() > 0) {
		if (orderNum == orderNums.at(orderNums.size()-1)) {
			
		}
		else {
			orderNums.push_back(orderNum);
		}
	}
	else {
		orderNums.push_back(orderNum);
	}
	
}

std::vector<int> Driver::getOrderNums() {
	return orderNums;
}

void Driver::setName(std::string name) {
	this->name = name;
}

void Driver::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Driver::setID(int id) {
	this->id = id;
}

int Driver::getID() {
	return id;
}