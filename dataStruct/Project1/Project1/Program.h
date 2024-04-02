#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "MyVector.h"
#include <iostream>
#include "Product.h"


using namespace std;

class Program
{
public:
	Program();
	void Start();
	void displayList(MyVector<Product>& tempVect);
	void addToCart(int index);
	void addToProduct(Product newItem);
	void removeFromCart(int index);
private:
	MyVector<Product> products;
	MyVector<Product> shoppingCart;
	float totalCart;
	bool run;

};


#endif
