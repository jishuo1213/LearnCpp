#include "../headers/Person.h"
#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

istream& read(istream& is, Person& person)
{
    is >> person.name >> person.address;
    return is;
}

ostream& print(ostream& os, const Person& preson)
{
    os << "Name: " << preson.name << "\t"
       << "Address: " << preson.address;
    return os;
}

Person::Person(istream& in)
{
    read(in, *this);
}
