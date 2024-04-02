#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "UIHelper.h"
#include "FileIO.h"
#include "Driver.h"

#include <vector>
#include <string>
#include <iostream>

class Program {
public:
	Program();
	~Program();
	void Run();
	void signUp(bool isDriver);
	void customerView();
	void driverView();
	void adminView();
	void updateDeliveryFee();
	void updateDeliveryPay();

private:
	Customer* currCustomer;
	Driver* currDriver;
	std::vector<Customer> customerList;
	std::vector<Order> orderList;
	std::vector<Restaurant> restaurantList;
	std::vector<Driver> driverList;

	int deliveryFee;
	int deliveryPayment;

};

#endif