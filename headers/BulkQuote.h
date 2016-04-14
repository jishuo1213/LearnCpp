//
// Created by fan on 16-4-13.
//

#ifndef LEARNCPP_BULKQUOTE_H
#define LEARNCPP_BULKQUOTE_H

#include "Quote.h"

class BulkQuote : public Quote {
public:
    BulkQuote() = default;

    BulkQuote(const std::string isbn, double sale_price, std::size_t min_qty, double discount);

    double net_price(std::size_t n) const override {
        return 100;
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

BulkQuote::BulkQuote(const std::string isbn, double sale_price, std::size_t min_qty, double discount) {
    this->min_qty = min_qty;
    this->discount = discount;

}


#endif //LEARNCPP_BULKQUOTE_H
