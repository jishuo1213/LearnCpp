#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Person {

    friend istream& read(istream& is, Person& person) ;
    friend ostream& print(ostream& os,const Person& person);

public:
    Person() = default;
    Person(istream &);
    Person(const string &personName,const string &personAddress) : name(personName),address(personAddress) {}

private:
    mutable string name;
    string address;

public:
    string getname() const {
        return name;
    }

    string getaddress() const {
        return address;
    }

    void setname(const string &newname) const {
        (*this).name = newname;
    }
};

extern istream& read(istream &is, Person &person) ;

extern ostream& print(ostream &os, const Person &preson) ;

extern int add(int a,int b);

#endif // PERSON_H_INCLUDED
