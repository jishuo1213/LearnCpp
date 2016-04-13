//
// Created by fan on 16-4-13.
//

#ifndef LEARNCPP_QUOTE_H
#define LEARNCPP_QUOTE_H

#include <string>

class Quote {

public:
    Quote() = default;

    Quote(const std::string &isbn, double sale_price) : book_isbn(isbn), price(sale_price) { }

    std::string isbn() const;

    virtual double net_price(std::size_t n) const = 0;

    virtual ~Quote() = default;

private:
    std::string book_isbn;

protected:
    double price = 0.0;
};

std::string Quote::isbn() const {
    return book_isbn;
}


#endif //LEARNCPP_QUOTE_H
