#ifndef _DRIVER_H
#define _DRIVER_H
#include "Customer.h"
#include "Order.h"
#include <string>
#include <vector>
class Driver : public Customer {
public:
	Driver();
	Driver(std::string name, std::string phoneNumber);
	void operator=(Customer customer);
	std::string getName();
	void setName(std::string name);
	void setPhoneNumber(std::string phoneNumber);
	void setID(int id);
	int getID();
	std::string getPhoneNumber();
	void addOrder(int orderNum);
	std::vector<int> getOrderNums();
private:
	std::string name;
	std::string phoneNumber;
	std::vector<int> orderNums;
	int id;
};


#endif