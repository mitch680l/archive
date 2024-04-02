#ifndef _FILEIO_H
#define _FILEIO_H

#include <vector>
#include "Restaurant.h"
#include "Customer.h"
#include "Order.h"
#include "Driver.h"

//Loading File Data
void loadData(std::vector<Customer>& customerList);
void loadData(std::vector<Restaurant>& restaurantList);
void loadData(std::vector<Order>& orderList);
void loadData(std::vector<Driver>& driverList);
void loadDriverHistory(std::vector<Order>& orderList, Driver* currDriver);

//Saving File Data
void saveData(std::vector<Customer>& customerList);
void saveData(std::vector<Restaurant>& restaurantList);
void saveData(std::vector<Order>& orderList);
void saveData(std::vector<Driver>& driverList);

#endif