#ifndef _RESTAURANT_H
#define _RESTAURANT_H
#include <string>
#include <ostream>
#include <istream>

using namespace std;

class Restaurant {
public:
	void Setup(string name, string address, string city, string state, int zipcode);
	void Display() const;
private:
	string m_name;
	string m_address;
	string m_city;
	string m_state;
	int m_zipcode;

	friend class RestaurantManager;
	friend ostream& operator<<(ostream& out, const Restaurant& item);
	friend istream& operator>>(istream& in, Restaurant& item);
};

#endif 
