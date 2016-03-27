//
// Created by fan on 16-3-27.
//

#ifndef LEARNCPP_HASPTR_H
#define LEARNCPP_HASPTR_H


#include <string>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/random/mersenne_twister.hpp>

using namespace boost::uuids;
using namespace boost::random;

class HasPtr {
    friend std::ostream &Print(std::ostream &os, const HasPtr &has_ptr);

public:
/*    HasPtr() : ps(new std::string()), i(0) {
        serial_num = random_generator()();
    };*/

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {
        serial_num = random_generator()();
    };


    HasPtr(const HasPtr &has_ptr) : ps(new std::string(*(has_ptr.ps))), i(has_ptr.i) {
        serial_num = random_generator()();
    };

    HasPtr &operator=(const HasPtr &has_ptr);

    ~HasPtr();

private:
    std::string *ps;
    int i;
    uuid serial_num;

};

HasPtr &HasPtr::operator=(const HasPtr &has_ptr) {
    ps = new std::string(*has_ptr.ps);
    i = has_ptr.i;
    serial_num = random_generator()();
    return *this;
}

HasPtr::~HasPtr() {
    delete ps;
}

std::ostream &Print(std::ostream &os, const HasPtr &has_ptr) {
    os << has_ptr.serial_num << std::endl;
    return os;
}


#endif //LEARNCPP_HASPTR_H
