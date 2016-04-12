//
// Created by Administrator on 2016/3/31.
//

#include "../headers/StrVec.h"

void StrVec::push_back(const string &str) {
    cout << "push_back" << str << endl;
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

size_t StrVec::size() const {
    if (first_free == nullptr && element == nullptr)
        return 0;
    return first_free - element;
}

size_t StrVec::capacity() const {
    if (cap == nullptr && element == nullptr) {
        return 0;
    }
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
/*        for (auto p = first_free; p != element;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(first_free, cap - element);*/
        for_each(element, first_free, [this](string &p) { this->alloc.destroy(&p); });
        alloc.deallocate(element, cap - element);
    }
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), new_data);
    free();
    element = new_data;
    first_free = last;
    cap = element + new_capacity;
/*    auto dest = new_data;
    auto elem = element;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, move(*elem++));
    }
    free();
    element = new_data;
    first_free = dest;
    cap = element + new_capacity;*/
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

StrVec &StrVec::operator=(StrVec &&rhs) {
    cout << "Rvalue" << endl;
    if (this != &rhs) {
        free();
        element = rhs.element;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.first_free = rhs.element = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::push_back(string &&str) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(str));
}



