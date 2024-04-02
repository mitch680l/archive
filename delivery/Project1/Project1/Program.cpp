#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "UIHelper.h"
#include "FileIO.h"
#include "Program.h"
#include "Driver.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;


Program::Program() {
	//loads all data at init.
	loadData(orderList);
	loadData(restaurantList);
	loadData(customerList);
	loadData(driverList);

	deliveryFee = 5;
	deliveryPayment = 2;

	currCustomer = nullptr;
	currDriver = nullptr;

}

Program::~Program() {
	//saves when deconstructed.
	saveData(customerList);
	saveData(restaurantList);
	saveData(orderList);
	saveData(driverList);
	delete currCustomer;
	delete currDriver;
}

void Program::Run() {
	
	int userChoice;
	bool exit = false;

	while (!exit) {
		
		loginScreen(); //Shows login screen
		userChoice = getUserChoice(); //Selection

		switch (userChoice) {
		case 0:
			exit = true; //exit condition
			break;

		case 1:
			signUp(false); //creates a new customer object
			customerView(); //entering new branch
			break;
			 
		case 2:
			signUp(true); //creates a new driver object
			loadDriverHistory(orderList, currDriver); //loads driver's history
			driverView(); //entering new branch
			break;
		case 3:
			adminView(); //entering new branch
			break;
		}
	}
}

void Program::signUp(bool isDriver) {
	string name = "";
	string phoneNumber = "";
	int userChoice = -1;

	userChoice = loginTemplate(); //sign up or log in ?

	if (userChoice == 1) {
		cout << "NAME: ";
		cin.ignore();
		getline(cin, name);
		cout << endl;
 
		cout << "PHONENUMBER: ";
		cin.ignore();
		getline(cin, phoneNumber);
		cout << endl;

		if (isDriver) {
			currDriver = new Driver(name, phoneNumber);
			driverList.push_back(*currDriver);
			(driverList.size() > 0) ? currDriver->setID(driverList.size()) : currDriver->setID(0); //driver id is based off number in the list
		}
		else {
			currCustomer = new Customer(name, phoneNumber);

			(customerList.size() > 0) ? currCustomer->setID(customerList.size()) : currCustomer->setID(0); //customer id is based off number in the list
			customerList.push_back(*currCustomer);
		}
		clearScreen();
	}

	else if (userChoice == 2) {
		try {
			cout << "NAME: ";
			cin.ignore();
			getline(cin, name);
			cout << endl;

			if (isDriver) {
				currDriver = findDriver(driverList, name); //searches through the list, returns address to the correct driver
			}
			else {
				currCustomer = findCustomer(customerList, name); //searches through the list, returns address to the correct customer
			}
			clearScreen();
		}
		catch (...) {
			clearScreen();
			cout << "NAME NOT FOUND, TRY SIGN UP INSTEAD?" << endl; //NOT WORKING, JUST CRASHES
			userChoice = 1;
		}
	}
	

	clearScreen();
	
}

void Program::customerView() {
	bool logout = false;
	string userInput;

	while (!logout) {
		cout << "Welcome, " << currCustomer->getName() << "!" << endl << endl;
		customerOptions();

		int userChoice = getUserChoice();

		switch (userChoice) {
		case(0):
			logout = true; //exit condtion
			clearScreen();
			break;

		case(1):
			updateTemplate("NAME");
			userInput = getUserInput();
			currCustomer->setName(userInput); //updates name
			break;

		case(2):
			updateTemplate("PHONE NUMBER");
			userInput = getUserInput();
			currCustomer->setPhoneNumber(userInput); //updates phonenumber
			break;
		case(3):
			newOrderScreen(restaurantList);

			userChoice = getUserChoice();
			if (userChoice != 0) {
				
				//Checks if address is on file
				if (currCustomer->getAddress() == "") {
					cin.ignore();
					cout << "ENTER ADDRESS TO DELIVER TO: "; //Gets customers address
					getline(cin, userInput);

					restaurantList.at(userChoice - 1).setAddress(userInput);
					currCustomer->setAddress(userInput);
				}
				else {
					restaurantList.at(userChoice - 1).setAddress(currCustomer->getAddress());
				}

				//Sets address, restaurants don't have their own address for now.
				
				
				int totalOrderPrice = orderMeal(restaurantList.at(userChoice - 1));

				//making a new order and adding it to the list.
				Order currOrder = Order(restaurantList.at(userChoice - 1), *currCustomer);
				currOrder.setMealFee(deliveryFee);
				currOrder.setDeliveryPay(deliveryPayment);
				currOrder.setMealPrice(totalOrderPrice);
				(orderList.size() > 0) ? currOrder.setOrderNum(orderList.size()) : currOrder.setOrderNum(0);
				orderList.push_back(currOrder);

			}
			clearScreen();

			break;
		case(4):
			showOrderHistor(*currCustomer, orderList); //order history.
			break;
		}



	}
}

void Program::driverView() {
	bool logout = false;

	clearScreen();

	while (!logout) {
		cout << "Welcome, " << currDriver->getName() << "!" << endl;
		driverOptions();

		int userChoice = getUserChoice();

		switch (userChoice) {
		case(0):
			logout = true; //exit condition
			clearScreen();
			break;
		case(1):
			findNextOrder(orderList, currDriver); //next order
			break;
		case(2):
			showOrderHistor(currDriver, orderList, deliveryPayment); //history
			break;

		}
	}
}

void Program::adminView() {
	bool logout = false;

	clearScreen();

	while (!logout) {
		cout << "WELCOME, FOODDOOD" << endl << endl;
		adminOptions();

		int userChoice = getUserChoice();


		switch (userChoice) {
		case(0):
			logout = true; //exit condition
			clearScreen();
			break;
		case(1):
			viewAllRestruants(restaurantList); //displays all restruants
			cout << endl << "0. EXIT" << endl;
			while (userChoice != 0) {
				userChoice = getUserChoice();
			}
			clearScreen();
			break;
		case(2):
			addNewRestruant(restaurantList); //add new restruant
			break;
		case(3):

			editRestruant(restaurantList); //edit restruant
			break;
		case(4):
			viewAllCustomers(customerList); //displays all customers
			break;
		case(5):
			viewAllDrivers(driverList); //displays all drivers
			break;
		case(6):
			viewAllOrders(orderList); //displays all orders
			break;
		case(7):
			updateDeliveryFee(); //updates fee
			break;
		case(8):
			updateDeliveryPay(); //updates payment
			break;

	}
}
}

void Program::updateDeliveryFee() {
	int userInput;

	cout << "NEW DELIVERY FEE: ";
	cin >> userInput;
	clearScreen();

	deliveryFee = userInput;

}

void Program::updateDeliveryPay() {
	
	clearScreen();
	
	int userInput;
	int userChoice = -1;
	
	cout << "NEW DELIVERY PAY: ";
	cin >> userInput;

	deliveryPayment = userInput;

	cout << endl << endl;
	cout << "DELIVERY FEE: " << deliveryFee << endl;
	cout << "DRIVER GETS: " << deliveryPayment << endl;
	cout << "RAYMOND GETS: " << deliveryFee - deliveryPayment << endl << endl;

	cout << "0. EXIT" << endl;

	while (userChoice != 0) {
		userChoice = getUserChoice();
	}
	clearScreen();
}