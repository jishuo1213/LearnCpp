//
// Created by fan on 16-4-13.
//

#ifndef LEARNCPP_BULKQUOTE_H
#define LEARNCPP_BULKQUOTE_H

#include "Quote.h"

class BulkQuote : public Quote {


public:
    double net_price(std::size_t n) const override {
        return 100;
    }
};


#endif //LEARNCPP_BULKQUOTE_H
