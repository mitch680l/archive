#ifndef _UIHELPER_H
#define _UIHELPER_H
#include <string>
#include <iostream>
#include <vector>
#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "Driver.h"


void loginScreen();
void customerOptions();
void driverOptions();
void clearScreen();
void updateTemplate(std::string attributeName);
void newOrderScreen(std::vector<Restaurant>& restaurantList);
void findNextOrder(std::vector<Order>& orderList, Driver* currDriver);
void viewAllOrders(std::vector<Order>& orderList);
void viewAllCustomers(std::vector<Customer>& customerList);
void viewAllRestruants(std::vector<Restaurant>& restaurantList);
void viewAllDrivers(std::vector<Driver>& driverList);
void addNewRestruant(std::vector<Restaurant>& restaurantList);
void adminOptions();
void editRestruant(std::vector<Restaurant>& restaurantList);
void showOrderHistor(Customer& currCustomer, std::vector<Order>& orderList);
void showOrderHistor(Driver* currDriver, std::vector<Order>& orderList, int deliveryPayment);
void editRestruantMenu(Restaurant& restaurant);
void displayMenu(Restaurant& restaurant);
int orderMeal(Restaurant& restaurant);

int loginTemplate();
Customer* findCustomer(std::vector<Customer>& customerList, std::string name);
Driver* findDriver(std::vector<Driver>& driverList, std::string name);

int getUserChoice();
std::string getUserInput();
int stringToInt(std::string integerString);

#endif