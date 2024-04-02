#ifndef _ORDER_H
#define _ORDER_H
#include <string>
#include "Restaurant.h"
#include "Customer.h"

class Order {
public:
	Order(Restaurant deliverFrom, Customer deliverTo);
	Order();
	Restaurant getRestaurant();
	Customer getCustomer();
	bool getStatus();
	int getOrderNum();
	void completeOrder();
	void setOrderNum(int orderNum);
	void setMealFee(int mealFee);
	void setDeliverDriver(int deliveryDriver);
	void setDeliveryPay(int deliveryPay);
	void setMealPrice(int mealPrice);
	int getDeliveryDriver();
	int getDeliveryPay();
	int getMealFee();
	int getMealPrice();
private:
	bool isCompleted;
	Restaurant restaurant;
	Customer customer;
	int orderNum;
	int mealFee;
	int mealPrice;
	int deliveryPay;
	int deliveryDriver;
};

#endif