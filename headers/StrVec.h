//
// Created by Administrator on 2016/3/31.
//

#ifndef LEARNCPP_STRVEC_H
#define LEARNCPP_STRVEC_H

#include <memory>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class StrVec {
public:
    StrVec() : element(nullptr), first_free(nullptr), cap(nullptr) {
        cout << "default construct" << endl;
    }

    StrVec(initializer_list<string> sl) {
        auto first = alloc.allocate(sl.size() * 2);
        element = first;
        first_free = uninitialized_copy(sl.begin(), sl.end(), first);
        cap = first_free + sl.size();
    }

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
        cout << size() << "====" << capacity() << endl;
        if (size() == capacity()) {
            cout << "reallocate" << endl;
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


#endif //LEARNCPP_STRVEC_H
