//
// Created by Administrator on 2016/3/31.
//

#ifndef LEARNCPP_TEXTQUERY_H
#define LEARNCPP_TEXTQUERY_H

#include <set>
#include <map>
#include "StrVec.h"

using namespace std;


class QueryResult;

class TextQuery {
public:

    TextQuery() = default;

    TextQuery(ifstream &in);

    const QueryResult Query(const string &s);

private:
    shared_ptr<StrVec> file_lines;
    map<string, shared_ptr<set<size_t >>> word_lines;
};


#endif //LEARNCPP_TEXTQUERY_H
