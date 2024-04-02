#include "FileIO.h"
#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "Driver.h"
#include "UIHelper.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Meal.h"

using namespace std;

void loadData(vector<Customer>& customerList)
{
	string currName;
	string currPhone;
	string currID;
	string currAddress;
	int currIdNum;
	ifstream input("Customers.txt");
	if (input.fail())
	{
		// No customers yet
		return;
	}

	Customer newCustomer;

	string buffer;
	while (getline(input, buffer))
	{
		if (buffer == "NAME")
		{
			getline(input, currName);
			newCustomer.setName(currName);
		}
		else if (buffer == "PHONENUMBER")
		{
			getline(input, currPhone);
			newCustomer.setPhoneNumber(currPhone);
		}
		else if (buffer == "ADDRESS") {
			getline(input, currAddress);
			newCustomer.setAddress(currAddress);
		}
		else if (buffer == "ID")
		{
			input >> currID;
			input.ignore();
			currIdNum = stringToInt(currID);
			newCustomer.setID(currIdNum);
		}
		else if (buffer == "CUSTOMER_END")
		{
			customerList.push_back(newCustomer);
		}
	}

	cout << customerList.size() << " CUSTOMERS LOADED" << endl << endl;
	input.close();
}

void loadData(vector<Restaurant>& restaurantList)
{
	string currName;
	string currAddress;
	string currID;
	string currMealPrice;
	string currMealName;
	
	int currPriceNum;
	int currIdNum;
	int currMealPriceNum;
	ifstream input("Restaurants.txt");
	if (input.fail())
	{
		// No customers yet
		return;
	}

	Restaurant newStore;
	Restaurant emptyStore;
	Meal currMeal;

	string buffer;
	while (getline(input, buffer))
	{
		if (buffer == "STORE_BEGIN") {
			
		}
		else if (buffer == "NAME")
		{
			getline(input, currName);
			newStore.setName(currName);
		}
		else if (buffer == "ADDRESS")
		{
			getline(input, currAddress);
			newStore.setAddress(currAddress);
		}
		else if (buffer == "ITEM0") {
			getline(input, currMealPrice);
			getline(input, currMealName);
			currMealPriceNum = stringToInt(currMealPrice);
			currMeal.name = currMealName;
			currMeal.mealPrice = currMealPriceNum;
			newStore.addMeal(currMeal);

		}
		else if (buffer == "ITEM1") {
			getline(input, currMealPrice);
			getline(input, currMealName);
			currMealPriceNum = stringToInt(currMealPrice);
			currMeal.name = currMealName;
			currMeal.mealPrice = currMealPriceNum;
			newStore.addMeal(currMeal);
		}
		else if (buffer == "ITEM2") {
			getline(input, currMealPrice);
			getline(input, currMealName);
			currMealPriceNum = stringToInt(currMealPrice);
			currMeal.name = currMealName;
			currMeal.mealPrice = currMealPriceNum;
			newStore.addMeal(currMeal);
		}
		else if (buffer == "ID")
		{
			input >> currID;
			input.ignore();
			currIdNum = stringToInt(currID);
			newStore.setId(currIdNum);
		}
		else if (buffer == "STORE_END")
		{
			// Add to the map
			restaurantList.push_back(newStore);
			newStore = emptyStore;
		}
	}

	cout << restaurantList.size() << " STORES LOADED" << endl << endl;
	input.close();
}

void loadData(vector<Order>& orderList)
{
	string currName;
	string currAddress;
	string currCustName;
	string currPhoneNumber;
	string currPrice;
	string currPayment;
	string currID;
	string currDriver;
	string currSta;
	
	int currIdNum = -1;
	int currPriceNum = -1;
	int deliveryFee = 0;
	int currPay = -1;
	int currDeliveryDriver = -1;
	bool currStatus = false;
	Restaurant newStore;
	Customer newCust;

	ifstream input("Orders.txt");
	if (input.fail())
	{
		return;
	}



	string buffer;
	while (getline(input, buffer))
	{
		if (buffer == "STORE_NAME")
		{
			getline(input, currName);
			newStore.setName(currName);
		}
		else if (buffer == "ADDRESS")
		{
			getline(input, currAddress);
			newStore.setAddress(currAddress);
		}
		else if (buffer == "TOTAL_MEAL_PRICE") {
			getline(input, currPrice);
			currPriceNum = stringToInt(currPrice);
		}
		else if (buffer == "DELIVERY FEE") 
		{
			input >> currPrice;
			input.ignore();
			deliveryFee = stringToInt(currPrice);
		}
		else if (buffer == "CUST_NAME")
		{
			getline(input, currAddress);
			newCust.setName(currAddress);
		}
		else if (buffer == "PHONENUMBER")
		{
			getline(input, currAddress);
			newCust.setPhoneNumber(currAddress);
		}
		else if (buffer == "ORDER_NUM")
		{
			input >> currID;
			input.ignore();
			currIdNum = stringToInt(currID);

		}
		else if (buffer == "DELIVERY PAYMENT") 
		{
			input >> currPayment;
			input.ignore();
			currPay = stringToInt(currPayment);

		}
		else if (buffer == "DELIVERY DRIVER")
		{
			input >> currDriver;
			input.ignore();
			currDeliveryDriver = stringToInt(currDriver);

		}
		else if (buffer == "STATUS")
		{
			input >> currSta;
			input.ignore();
			if (currSta == "0") {
				currStatus = false;
			}
			else {
				currStatus = true;
			}

		}
		else if (buffer == "ORDER_END")
		{
			Order newOrder = Order(newStore, newCust);
			newOrder.setMealFee(deliveryFee);
			newOrder.setOrderNum(currIdNum);
			newOrder.setDeliverDriver(currDeliveryDriver);
			newOrder.setDeliveryPay(currPay);
			newOrder.setMealPrice(currPriceNum);
			if (currStatus) {
				newOrder.completeOrder();
			}
			orderList.push_back(newOrder);
		}
	}

	cout << orderList.size() << " ORDERS LOADED" << endl << endl;
	input.close();
}

void loadData(vector<Driver>& driverList)
{
	string currName;
	string currPhone;
	string currID;
	string currOrd;
	int currIdNum = -1;
	int currOrderNum = -1;;
	vector<int> orderNumbers;

	ifstream input("Drivers.txt");
	if (input.fail())
	{
		return;
	}

	Driver newDriver;

	string buffer;
	while (getline(input, buffer))
	{
		if (buffer == "NAME")
		{
			getline(input, currName);
			newDriver.setName(currName);
		}
		else if (buffer == "PHONENUMBER")
		{
			getline(input, currPhone);
			newDriver.setPhoneNumber(currPhone);
		}
		else if (buffer == "ID")
		{
			input >> currID;
			input.ignore();
			currIdNum = stringToInt(currID);
			newDriver.setID(currIdNum);
		}
		else if (buffer == "DRIVER_END")
		{
			driverList.push_back(newDriver);
		}
	}

	cout << driverList.size() << " DRIVERS LOADED" << endl << endl;
	input.close();
}

void saveData(vector<Customer>& customerList) {

	ofstream output("Customers.txt");

	for (auto& customer : customerList)
	{
		output << "CUSTOMER_BEGIN" << endl;
		output << "NAME" << endl;
		output << customer.getName() << endl;
		output << "PHONENUMBER" << endl;
		output << customer.getPhoneNumber() << endl;
		output << "ADDRESS" << endl;
		output << customer.getAddress() << endl;
		output << "ID" << endl;
		output << customer.getID() << endl;
		output << "CUSTOMER_END" << endl;
	}

}

void saveData(vector<Driver>& driverList) {

	ofstream output("Drivers.txt");

	for (auto& driver : driverList)
	{
		output << "DRIVER_BEGIN" << endl;
		output << "NAME" << endl;
		output << driver.getName() << endl;
		output << "PHONENUMBER" << endl;
		output << driver.getPhoneNumber() << endl;
		output << "ID" << endl;
		output << driver.getID() << endl;
		output << "DRIVER_END" << endl;
	}

}

void saveData(vector<Restaurant>& restaurantList) {

	ofstream output("Restaurants.txt");
	vector<Meal> menuItems;

	for (auto& store : restaurantList)
	{
		output << "STORE_BEGIN" << endl;
		output << "NAME" << endl;
		output << store.getName() << endl;
		output << "ADDRESS" << endl;
		output << store.getAddress() << endl;
		store.getMenuItems(menuItems);
		for (unsigned int i = 0; i < menuItems.size(); i++) {
			output << "ITEM" << i << endl;
			output << menuItems.at(i).mealPrice << endl;
			output << menuItems.at(i).name << endl;
		}
		output << "ID" << endl;
		output << store.getId() << endl;
		output << "STORE_END" << endl;
	}

}

void saveData(vector<Order>& orderList) {
	ofstream output("Orders.txt");

	for (auto& currOrder : orderList)
	{
		Restaurant store = currOrder.getRestaurant();
		Customer customer = currOrder.getCustomer();

		output << "ORDER_BEGIN" << endl;
		output << "STORE_NAME" << endl;
		output << store.getName() << endl;
		output << "ADDRESS" << endl;
		output << store.getAddress() << endl;
		output << "TOTAL_MEAL_PRICE" << endl;
		output << currOrder.getMealPrice() << endl;
		output << "DELIVERY FEE" << endl;
		output << currOrder.getMealFee() << endl;
		output << "CUST_NAME" << endl;
		output << customer.getName() << endl;
		output << "PHONENUMBER" << endl;
		output << customer.getPhoneNumber() << endl;
		output << "ORDER_NUM" << endl;
		output << currOrder.getOrderNum() << endl;
		output << "DELIVERY PAYMENT" << endl;
		output << currOrder.getDeliveryPay() << endl;
		output << "DELIVERY DRIVER" << endl;
		output << currOrder.getDeliveryDriver() << endl;
		output << "STATUS" << endl;
		output << currOrder.getStatus() << endl;
		output << "ORDER_END" << endl;
	}

}

void loadDriverHistory(vector<Order>& orderList, Driver* currDriver) {
	for (Order order : orderList) {
		if (order.getDeliveryDriver() == currDriver->getID()) {
			currDriver->addOrder(order.getOrderNum());
		}
	}
}