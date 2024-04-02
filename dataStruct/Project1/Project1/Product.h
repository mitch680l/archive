#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <string>
using namespace std;

struct Product
{
    Product()
    {
        name = "";
        price = 0;
    }

    Product(string name, float price)
    {
        this->name = name;
        this->price = price;
    }

    string name;
    float price;
};
#endif
