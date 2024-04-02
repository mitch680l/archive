#include "Order.h"

Order::Order(Restaurant restaurant, Customer customer) {
	this->restaurant = restaurant;
	this->customer = customer;
	isCompleted = false;
}
Order::Order() {
	isCompleted = false;
	mealFee = -1;
	orderNum = -1;
	deliveryPay = -1;
	deliveryDriver = -1;
}

bool Order::getStatus() {
	return isCompleted;
}

Customer Order::getCustomer() {
	return customer;
}

Restaurant Order::getRestaurant() {
	return restaurant;
}

int Order::getOrderNum() {
	return orderNum;
}

void Order::completeOrder() {
	isCompleted = true;
}

void Order::setOrderNum(int orderNum) {
	this->orderNum = orderNum;
}

void Order::setMealFee(int mealFee) {
	this->mealFee = mealFee;
}

int Order::getMealFee() {
	return mealFee;
}

void Order::setDeliverDriver(int deliveryDriver) {
	this->deliveryDriver = deliveryDriver;
}

void Order::setDeliveryPay(int deliveryPay) {
	this->deliveryPay = deliveryPay;
}

int Order::getDeliveryDriver() {
	return deliveryDriver;
}

int Order::getDeliveryPay() {
	return deliveryPay;
}

void Order::setMealPrice(int mealPrice) {
	this->mealPrice = mealPrice;
}

int Order::getMealPrice() {
	return mealPrice;
}