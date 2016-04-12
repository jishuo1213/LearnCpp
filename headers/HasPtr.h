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

class HasPtr {
    friend std::ostream &Print(std::ostream &os, const HasPtr &has_ptr);

    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr() : ps(new std::string()), i(0) {
        std::cout << "default constructor called" << std::endl;
        serial_num = random_generator()();
    }

    HasPtr(const std::string &s) : ps(new std::string(s)), i(0) {
        std::cout << "constructor called" << std::endl;
        serial_num = random_generator()();
    };

    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
        std::cout << "move constructor called" << std::endl;
        p.ps = 0;
    }


    HasPtr(const HasPtr &has_ptr) : ps(new std::string(*(has_ptr.ps))), i(has_ptr.i) {
        std::cout << "copy constructor called" << std::endl;
        serial_num = random_generator()();
    };

//    HasPtr &operator=(const HasPtr &has_ptr);

    HasPtr &operator=(const HasPtr &has_ptr);

    HasPtr &operator=(HasPtr &&rhs);

    bool operator<(const HasPtr &has_ptr);

    ~HasPtr();

private:
    std::string *ps;
    int i;
    uuid serial_num;
};

HasPtr &HasPtr::operator=(const HasPtr &has_ptr) {
    std::cout << "operator = called" << std::endl;
    auto temp_str = new std::string(*has_ptr.ps);
    delete ps;
    ps = temp_str;
    i = has_ptr.i;
    serial_num = random_generator()();
    return *this;
}


/*HasPtr &HasPtr::operator=(HasPtr has_ptr) {
    std::cout << "operator = called" << std::endl;
    swap(*this, has_ptr);
    return *this;
}*/

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.serial_num, rhs.serial_num);
}

HasPtr::~HasPtr() {
    std::cout << "~ called" << std::endl;
    delete ps;
}

std::ostream &Print(std::ostream &os, const HasPtr &has_ptr) {
    os << has_ptr.serial_num << std::endl;
    os << *has_ptr.ps << std::endl;
    return os;
}

bool HasPtr::operator<(const HasPtr &has_ptr) {
    return *ps < *has_ptr.ps;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) {
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;
        serial_num = rhs.serial_num;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}


#endif //LEARNCPP_HASPTR_H
