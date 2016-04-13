//
// Created by fan on 16-4-13.
//

#ifndef LEARNCPP_INTEQUAL_H
#define LEARNCPP_INTEQUAL_H

#include <vector>
#include <algorithm>

class IntEqual {

public:

    IntEqual(int value) : lhs(value) { }

    bool operator()(int rhs) {
        return rhs == lhs;
    }

private:
    int lhs;
};


void replace_all_equal_value(std::vector<int> &ivec, int value) {
    std::replace_if(ivec.begin(), ivec.end(), IntEqual(value), 13);
}

#endif //LEARNCPP_INTEQUAL_H
