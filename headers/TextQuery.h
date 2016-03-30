#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <memory>
#include "StrVec.h"

using namespace std;

class QueryResult;

class TextQuery {
public:

    TextQuery() = default;

    TextQuery(ifstream &in);

    const QueryResult &Query(const string &s);

private:
    shared_ptr<StrVec> file_lines;
    map<string, shared_ptr<set<size_t >>> word_lines;
};

#endif //
