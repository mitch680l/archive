#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <string>
#include <vector>


class Customer {
public:
	Customer();
	Customer(std::string name, std::string phoneNumber);
	void setPhoneNumber(std::string phoneNumber);
	void setName(std::string name);
	void setAddress(std::string address);
	void setID(int id);
	std::string getPhoneNumber();
	std::string getName();
	std::string getAddress();
	int getID();
	bool isDriver = false;
private:
	std::string phoneNumber;
	std::string name;
	std::string address;
	int id;
};

#endif