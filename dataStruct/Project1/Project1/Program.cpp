#include "MyVector.h"
#include "Product.h"
#include "Program.h"
#include <iomanip>
#include <iostream>
using namespace std;

Program::Program() 
{
	run = true;
	totalCart = 0.00;

	addToProduct(Product("Pizza", 6.99)); //init 1
	addToProduct(Product("Cheese", 4.99)); //init 2
	addToProduct(Product("Butter", 2.99)); //init 3
	addToProduct(Product("Beef", 6.99)); //init 4
	addToProduct(Product("Garlic", 1.00)); //init 5
	addToProduct(Product("Bread", 1.50)); //init 6
}

void Program::Start() 
{
	cout << "Program 6" << endl << endl;
	cout << fixed << setprecision(2);
	bool done = false;
	while (!done)
	{
		cout << "0. Exit" << endl;
		cout << "1. Add Item To Cart" << endl;
		cout << "2. View Shopping Cart" << endl;

		cout << endl << ">> ";
		int choice;
		cin >> choice;
		cout << endl;

		if (choice == 0)
		{
			done = true;
			cout << "Thanks for shopping with us!" << endl;
		}
		else if (choice == 1)
		{
			displayList(products);

			cout << "Choose an item to put into your cart!" << endl;
			cout << endl << ">> ";
			int indexSelected;
			cin >> indexSelected;
			cout << endl;
			addToCart(indexSelected);
		}
		else if (choice == 2)
		{
			displayList(shoppingCart);

			cout << "Grand Total: $" << totalCart << endl << endl;
		}
		else 
		{
			cout << "ERROR: Invalid Choice" << endl << endl;
		}
	}
}

void Program::displayList(MyVector<Product>& tempVect)
{
	if (tempVect.GetSize() != 0)
	{
		for (size_t i = 0; i < tempVect.GetSize(); i++)
		{
			cout << i << ".) $" << tempVect.GetAt(i).price << " " << tempVect.GetAt(i).name << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "There dosn't seem to be any items in your cart!" << endl << endl;
	}
}

void Program::addToCart(int index) 
{
	if(index <= products.GetSize()) 
	{
		Product itemSelected = products.GetAt(index);
		shoppingCart.Pushback(itemSelected);
		totalCart += itemSelected.price;
	}
	else 
	{
		cout << "ERROR: Invalid Index" << endl << endl;
	}
	
}

void Program::addToProduct(Product newItem) 
{
	products.Pushback(newItem);
}

