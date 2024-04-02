#include "Customer.h"
#include "UIHelper.h"

using namespace std;


Customer::Customer() {
	phoneNumber = "";
	name = "";
}

Customer::Customer(string name, string phoneNumber) {
	this->phoneNumber = phoneNumber;
	this->name = name;
}


void Customer::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Customer::setName(string name) {
	this->name = name;
}
void Customer::setID(int id) {
	this->id = id;
}
void Customer::setAddress(string address) {
	this->address = address;
}


string Customer::getPhoneNumber() {
	return phoneNumber;
}
string Customer::getName() {
	return name;
}
int Customer::getID() {
	return id;
}
string Customer::getAddress() {
	return address;
}

