//
// Created by fan on 16-3-28.
//

#ifndef LEARNCPP_HASPTRPOINTERTYPE_H
#define LEARNCPP_HASPTRPOINTERTYPE_H

#include <string>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/random/mersenne_twister.hpp>

using namespace std;
using namespace boost::uuids;

class HasPtrPointerType {

public:
    friend std::ostream &Print(std::ostream &os, const HasPtrPointerType &has_ptr);

    HasPtrPointerType(string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {
        serial_num = random_generator()();
    };

    HasPtrPointerType(HasPtrPointerType &h) : ps(new string(*h.ps)), i(0), use(h.use) {
        ++*use;
        serial_num = random_generator()();
    };

    HasPtrPointerType &operator=(HasPtrPointerType &h);

    ~HasPtrPointerType();

private:
    std::string *ps;
    int i;
    size_t *use;
    uuid serial_num;
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-value"
HasPtrPointerType &HasPtrPointerType::operator=(HasPtrPointerType &rhs) {
    *++rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    serial_num = rhs.serial_num;
    return *this;
}
#pragma clang diagnostic pop

HasPtrPointerType::~HasPtrPointerType() {
    if (*use == 0) {
        delete ps;
        delete use;
    }
}

std::ostream &Print(std::ostream &os, const HasPtrPointerType &has_ptr) {
    os << has_ptr.serial_num << endl;
    return os;
}


#endif //LEARNCPP_HASPTRPOINTERTYPE_H
