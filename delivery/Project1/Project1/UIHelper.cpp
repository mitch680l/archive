#include "UIHelper.h"
#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "Meal.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int stringToInt(string integerString) {
	int number;
	try {
		number = stoi(integerString);
	}
	catch (...) {
		cout << "Error. Not Valid Integer. Exiting(Setting x = 0)" << endl;
		number = 0;
	}
	return number;
}

void customerOptions() {
	cout << "OPTIONS" << endl;
	cout << "0. LOG OUT" << endl;
	cout << "1. UPDATE NAME" << endl;
	cout << "2. UPDATE PHONE NUMBER" << endl;
	cout << "3. NEW ORDER" << endl;
	cout << "4. ORDER HISTORY" << endl << endl;

}

int getUserChoice() {
	string userInput;
	int userChoice;
	
	cout << ">> ";
	cin >> userInput;
	cout << endl << endl;

	userChoice = stringToInt(userInput);
	
	return userChoice;
}

string getUserInput() {
	string userInput;
	
	cout << ">> ";
	cin.ignore();
	getline(cin, userInput);
	cout << endl << endl;
	
	clearScreen();

	return userInput;
}

int loginTemplate() {
	
	clearScreen();
	int userChoice = -1;
	cout << "SELECT AN OPTION" << endl << endl;
	cout << "0. EXIT" << endl;
	cout << "1. SIGN UP" << endl;
	cout << "2. LOG IN" << endl << endl;

	while (userChoice != 0) {
		userChoice = getUserChoice();
		clearScreen();
		switch (userChoice) {
		case(0): 
			return -1;
			break;
		case(1):
			cout << "ENTER NAME & PHONENUMBER" << endl << endl;
			return userChoice;
			break;
		case(2):
			cout << "ENTER NAME" << endl << endl;
			return userChoice;
			break;
		}
	}

	
}

void loginScreen() {
	cout << "FoodDood App" << endl;
	cout << endl;
	cout << "0. Quit" << endl;
	cout << "1. Customer View" << endl;
	cout << "2. Driver View" << endl;
	cout << "3. Admin View" << endl << endl;
}

void updateTemplate(string attributeName) {
	clearScreen();
	cout << "UPDATE " << attributeName << endl;
	cout << endl;
	cout << "ENTER NEW " << attributeName << endl << endl;
}

void clearScreen()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
	system("clear");
#endif
}

void driverOptions() {
	cout << "OPTIONS" << endl;
	cout << "0. LOG OUT" << endl;
	cout << "1. GET NEXT ORDER" << endl;
	cout << "2. VIEW DELIVERY HISTORY" << endl;
}

void adminOptions() {
	cout << "OPTIONS" << endl;
	cout << "0. LOG OUT" << endl << endl;

	cout << "1. VIEW ALL RESTRUANTS" << endl;
	cout << "2. ADD SUPPORTED RESTAURANT" << endl;
	cout << "3. EDIT RESTAURANT" << endl << endl;

	cout << "4. VIEW ALL CUSTOMERS" << endl;
	cout << "5. VIEW ALL DRIVERS" << endl;
	cout << "6. VIEW ALL ORDERS (DELIVERY HISTORY)" << endl << endl;

	cout << "7. SET DELIVERY FEE" << endl;
	cout << "8. SET DRIVER PAYMENT" << endl << endl;
}

void newOrderScreen(vector<Restaurant>& restaurantList) {

	clearScreen();

	cout << "NEW ORDER" << endl << endl;
	cout << "SELECT RESTAURANT:" << endl;

	cout << 0 << ". CANCEL/GO BACK" << endl;
	for (unsigned int i = 0; i < restaurantList.size(); i++) {
		cout << i + 1 << ". " << restaurantList.at(i).getName() << endl;
	}
	cout << endl;

}

void findNextOrder(vector<Order>& orderList, Driver* currDriver) {
	int index = -1;
	int userChoice;
	clearScreen();

	for (unsigned int i = 0; i < orderList.size(); i++) {
		if (!orderList.at(i).getStatus()) {
			index = i;
			break;
		}
	}

	try {

		cout << "NEXT ORDER" << endl << endl;
		cout << "FROM: " << endl;
		cout << orderList.at(index).getRestaurant().getName() << endl;
		cout << orderList.at(index).getRestaurant().getAddress() << endl << endl;

		cout << "TO: " << endl;
		cout << orderList.at(index).getCustomer().getName() << endl;
		cout << orderList.at(index).getCustomer().getPhoneNumber() << endl << endl;

		cout << "0. GO BACK" << endl;
		cout << "1. MARK ORDER COMPLETED" << endl;

		currDriver->addOrder(orderList.at(index).getOrderNum());
		orderList.at(index).setDeliverDriver(currDriver->getID());

		userChoice = getUserChoice();
	}
	catch (...) {
		cout << "ERROR. NO AVALIBLE ORDERS" << endl;
		userChoice = 0;
	}

	switch (userChoice) {
	case(0):
		clearScreen();
		break;
	case(1):
		clearScreen();
		orderList.at(index).completeOrder();
		break;
	}

}

void viewAllOrders(vector<Order>& orderList) {
	int userChoice = 1;
	clearScreen();
	cout << "ALL ORDERS" << endl << endl;
	cout << "       FROM              TO                 MEAL TOTAL   FEE   DRIVER-PAY   PROFIT" << endl;
	for (unsigned int i = 0; i < orderList.size(); i++) {
		int mealFee = orderList.at(i).getMealFee();
		int pay = orderList.at(i).getDeliveryPay();
		int profit = mealFee - pay;
		int meal = orderList.at(i).getMealPrice();
		cout << i << ".     " << orderList.at(i).getRestaurant().getName();
		cout << "       " << orderList.at(i).getCustomer().getName();
		cout << "              " << meal;
		cout << "Working on mealPrice sorry :/";
		cout << "     " << mealFee;
		cout << "     " << pay;
		cout << "            " << profit << endl;

	}

	cout << endl << "0. EXIT" << endl;
	while (userChoice != 0) {
		userChoice = getUserChoice();
	}
	clearScreen();
}

void viewAllCustomers(vector<Customer>& customerList) {
	int userChoice = 1;
	clearScreen();

	cout << "CUSTOMER LIST" << endl << endl;

	for (unsigned int i = 0; i < customerList.size(); i++) {
		cout << i << ". " << customerList.at(i).getName() << endl;
	}

	cout << endl << "0. EXIT" << endl;
	while (userChoice != 0) {
		userChoice = getUserChoice();
	}
	clearScreen();
}

void viewAllRestruants(vector<Restaurant>& restaurantList) {
	clearScreen();

	cout << "RESTAURANT LIST" << endl << endl;

	for (unsigned int i = 0; i < restaurantList.size(); i++) {
		cout << i << ". " << restaurantList.at(i).getName() << endl;
	}

	
}

void editRestruant(vector<Restaurant>& restaurantList) {
	int choice = -1;
	int userChoice = -1;
	int newMenuPrice = -1;
	string userInput;
	
	clearScreen();
	viewAllRestruants(restaurantList);
	cout << endl << "SELECT WHICH ONE TO UPDATE: " << endl << endl;
	choice = getUserChoice();
	
	clearScreen();
	cout << "YOU HAVE SELECTED " << restaurantList.at(choice).getName() << endl << endl;

	cout << "0. EXIT" << endl;
	cout << "1. UPDATE NAME" << endl;
	cout << "2. UPDATE ADDRESS" << endl;
	cout << "3. UPDATE MENU" << endl;
	cout << endl << "SELECT WHAT TO UPDATE: " << endl << endl;
	
	
	while (userChoice != 0) {
		userChoice = getUserChoice(); 
		switch (userChoice) {
		case(0):
			break;
		case(1):

			cout << "ENTER NEW NAME" << endl;
			userInput = getUserInput();
			restaurantList.at(choice).setName(userInput);
			userChoice = 0;
			break;
		case(2):
			cout << "ENTER NEW ADRESS" << endl;
			userInput = getUserInput();
			restaurantList.at(choice).setAddress(userInput);
			userChoice = 0;
			break;
		case(3):
			editRestruantMenu(restaurantList.at(choice));
			userChoice = 0;
			break;
		}
	}
	clearScreen();
}

void addNewRestruant(vector<Restaurant>& restaurantList) {
	int userChoice = -1;
	string address;
	string name;
	string mealName;
	string mealPrice;
	int mealPriceNum;
	Restaurant newRestruant;

	clearScreen();
	cout << "ADD SUPPORTED RESTAURANT" << endl << endl;
	cout << "NAME: ";
	cin.ignore();
	getline(cin, name);
	cout << endl;
	cout << "ADDRESS: ";
	cin.ignore();
	getline(cin, address);

	newRestruant = Restaurant(name, address);
	newRestruant.setId(restaurantList.size());

	clearScreen();

	while (userChoice != 0) {
		cout << endl << endl;
		cout << "MENU CREATION" << endl << endl;
		cout << "0. EXIT" << endl;
		cout << "1. ADD MENU ITEM" << endl << endl;
		userChoice = getUserChoice();

		if (userChoice == 1) {
			Meal temp;
			cout << "NAME: " << endl;
			cin.ignore();
			getline(cin, mealName);
			cout << endl;

			cout << "PRICE: " << endl;
			cin >> mealPrice;
			mealPriceNum = stringToInt(mealPrice);
			cout << endl;

			temp.mealPrice = mealPriceNum;
			temp.name = mealName;

			newRestruant.addMeal(temp);
		}
		clearScreen();
	}
	cout << endl << endl;

	restaurantList.push_back(newRestruant);

	clearScreen();
	cout << endl << "RESTAURANT SUCCESSFULLY ADDED" << endl << endl;
}

Customer* findCustomer(vector<Customer>& customerList, string name) {
	string phoneNumber;
	Customer temp;
	try {
		for (unsigned int i = 0; i < customerList.size(); i++) {

			if (customerList.at(i).getName() == name) {
				return &customerList.at(i);
			}

		}
	}
	catch(...) {
		cout << "NAME NOT FOUND" << endl << endl;
		return &temp;
	}

}

Driver* findDriver(vector<Driver>& driverList, string name) {
	string phoneNumber;
	Driver temp;
	try {
		for (unsigned int i = 0; i < driverList.size(); i++) {

			if (driverList.at(i).getName() == name) {
				return &driverList.at(i);
			}

		}
	}
	catch (...) {
		cout << "NAME NOT FOUND" << endl << endl;
		return &temp;
	}
}

void viewAllDrivers(vector<Driver>& driverList) {
	int userChoice = -1;
	clearScreen();

	cout << "DRIVER LIST" << endl << endl;

	for (unsigned int i = 0; i < driverList.size(); i++) {
		cout << i << ". " << driverList.at(i).getName() << endl;
	}

	cout << endl << "0. EXIT" << endl;
	while (userChoice != 0) {
		userChoice = getUserChoice();
	}

	clearScreen();
}

void showOrderHistor(Customer& currCustomer, vector<Order>& orderList) {
	clearScreen();
	int userChoice = -1;
	cout << "DELIVERY HISTORY FOR " << currCustomer.getName() << endl << endl;
	
	cout << "       FROM                 TO               MEAL              FEE           TOTAL" << endl;
	for (unsigned int i = 0; i < orderList.size(); i++) {
		if (orderList.at(i).getCustomer().getName() == currCustomer.getName()) //&& orderList.at(i).getCustomer().getPhoneNumber() == currCustomer.getPhoneNumber())
		{
			cout << i << ".     " << orderList.at(i).getRestaurant().getName() << "    ";
			cout << orderList.at(i).getRestaurant().getAddress() << "         ";
			cout << orderList.at(i).getMealPrice() << "               ";
			cout << orderList.at(i).getMealFee() << "             ";
			cout << orderList.at(i).getMealPrice() + orderList.at(i).getMealFee() << endl << endl;
		}
	}

	cout << endl << endl;
	while (userChoice != 0) {
		cout << "0. EXIT" << endl;
		userChoice = getUserChoice();
		clearScreen();

	}

}

void showOrderHistor(Driver* currDriver, vector<Order>& orderList, int deliveryPayment) {
	
	clearScreen();
	
	vector<int> orderNumbers = currDriver->getOrderNums();
	
	cout << "DELIVERY HISTORY FOR " << currDriver->getName() << endl << endl;

	cout << "       FROM            TO               EARNED" << endl;
	for (unsigned int i = 0; i < orderNumbers.size(); i++) {
		int index = orderNumbers.at(i);
		if (orderList.at(index).getStatus())
		{
			cout << i << ".     " << orderList.at(index).getRestaurant().getName() << "    ";
			cout << orderList.at(index).getRestaurant().getAddress() << "         ";
			cout << deliveryPayment << "        " << endl << endl;
		}
		else {
			cout << i << ".     " << orderList.at(index).getRestaurant().getName() << "    ";
			cout << orderList.at(index).getRestaurant().getAddress() << "         ";
			cout << " ENROUTE " << "        " << endl << endl << endl;

		}
	}

	int userChoice = -1;
	cout << "0. EXIT" << endl;
	while (userChoice != 0) {
		userChoice = getUserChoice();
	}

	clearScreen();
}

void displayMenu(Restaurant& restaurant) {
	vector<Meal> menu;
	restaurant.getMenuItems(menu);
	for (unsigned int i = 0; i < menu.size(); i++) {
		cout << i+1 << ". DISH: " << menu.at(i).name << " PRICE: " << menu.at(i).mealPrice << endl;
	}
}

void editRestruantMenu(Restaurant& restaurant) {
	string userInput;
	int userChoice = -1;
	int userIntger;
	clearScreen();
	cout << "MENU FOR " << restaurant.getName() << endl;
	displayMenu(restaurant);

	cout << endl << endl;
	cout << "SELECT A MENU ITEM TO CHANGE" << endl;
	userChoice = getUserChoice();
	Meal* selectedMeal = restaurant.getMealItem(userChoice - 1);

	clearScreen();

	cout << "TYPE A NEW NAME FOR THE DISH" << endl << endl;
	cin.ignore();
	getline(cin, userInput);
	cout << endl;
	selectedMeal->name = userInput;
	cout << "TYPE A NEW PRICE FOR THE DISH" << endl << endl;
	cin >> userInput;
	cout << endl;
	userIntger = stringToInt(userInput);
	selectedMeal->mealPrice = userIntger;

	clearScreen();

}

int orderMeal(Restaurant& restaurant) {
	int totalOrderPrice = 0;
	int userChoice = -1;
	
	
	while (userChoice != 0) {
		string history = "";
		clearScreen();
		cout << "MENU FOR " << restaurant.getName() << endl << endl;
		cout << "SELECT ITEMS YOU WANT TO ORDER(CAN ORDER MULTIPLE)" << endl << endl;
		cout << "TOTAL PRICE: $" << totalOrderPrice << endl << endl;
		cout << "0. EXIT" << endl;
		displayMenu(restaurant);

		userChoice = getUserChoice();

		if (userChoice != 0) {
			totalOrderPrice += restaurant.getMealItem(userChoice - 1)->mealPrice;
		}

	}

	return totalOrderPrice;

}
