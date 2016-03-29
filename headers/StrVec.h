//
// Created by fan on 16-3-29.
//

#ifndef LEARNCPP_STRVEC_H
#define LEARNCPP_STRVEC_H

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class StrVec {

public:

    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) { }

    StrVec(const StrVec &rhs);

    StrVec &operator=(StrVec &rhs);

    ~StrVec();

    void push_back(const string &str);

    size_t size() const;

    size_t capacity() const;

    string *begin() const;

    string *end() const;


private:
    allocator<string> alloc;

    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    };

    pair<string *, string *> alloc_n_copy(const string *, const string *);

    void free();

    void reallocate();

    string *element;
    string *first_free;
    string *cap;
};

void StrVec::push_back(const string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

size_t StrVec::size() const {
    return first_free - element;
}

size_t StrVec::capacity() const {
    return cap - element;
}

string *StrVec::begin() const {
    return element;
}

string *StrVec::end() const {
    return first_free;
}

void StrVec::free() {
    if (element) {
        for (auto p = first_free; p != element;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(first_free, cap - element);
    }
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = element;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, move(*elem++));
    }
    free();
    element = new_data;
    first_free = dest;
    cap = element + new_capacity;
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

StrVec::StrVec(const StrVec &rhs) {
    auto pair = alloc_n_copy(rhs.begin(), rhs.end());
    element = pair.first;
    first_free = cap = pair.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(StrVec &rhs) {
    auto res = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    element = res.first;
    first_free = cap = res.second;
    return *this;
}


#endif //LEARNCPP_STRVEC_H
