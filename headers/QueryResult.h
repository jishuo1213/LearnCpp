//
// Created by Administrator on 2016/3/31.
//

#ifndef LEARNCPP_QUERYRESULT_H
#define LEARNCPP_QUERYRESULT_H

#include <string>
#include <memory>
#include <set>
#include <iostream>
#include "StrVec.h"

class QueryResult {
    friend ostream &PrintResult(ostream &os, const QueryResult &result);

public:
    QueryResult() = default;

    QueryResult(string s, shared_ptr<set<size_t>> result_lines, shared_ptr<StrVec> file_lines) :
            word(s), lines(result_lines), file(file_lines) { };

private:
    string word;
    shared_ptr<set<size_t >> lines;
    shared_ptr<StrVec> file;
};

#endif //LEARNCPP_QUERYRESULT_H
