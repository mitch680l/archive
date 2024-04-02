#include "Restaurant.h"
#include <string>
#include <ostream>
#include <istream>
#include <iostream>
#include <iomanip>

void Restaurant::Setup(string name, string address, string city, string state, int zipcode) {
	m_name = name;
	m_address = address;
	m_city = city;
	m_state = state;
	m_zipcode = zipcode;
}

void Restaurant::Display() const {
    cout << left
        << setw(20) << m_name
        << setw(25) << m_address
        << setw(15) << m_city
        << setw(8) << m_state
        << setw(6) << m_zipcode
        << endl;

}

ostream& operator<<(ostream& out, const Restaurant& item) {
    out << "RESTAURANT {" << endl;
    out << "NAME" << endl << item.m_name << endl;
    out << "ADDRESS" << endl << item.m_address << endl;
    out << "CITY" << endl << item.m_city << endl;
    out << "STATE" << endl << item.m_state << endl;
    out << "ZIPCODE" << endl << item.m_zipcode << endl;
    out << "}" << endl;
    return out;
}

istream& operator>>(istream& in, Restaurant& item) {
    string buffer;
    while (getline(in, buffer))
    {
        if (buffer == "}") { break; }
        else if (buffer == "NAME") { getline(in, item.m_name); }
        else if (buffer == "ADDRESS") { getline(in, item.m_address); }
        else if (buffer == "CITY") { getline(in, item.m_city); }
        else if (buffer == "STATE") { getline(in, item.m_state); }
        else if (buffer == "ZIPCODE") { in >> item.m_zipcode; }
    }
    return in;
}