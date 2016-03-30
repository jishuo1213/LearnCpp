#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <string>
#include <memory>
#include <set>
#include <iostream>
#include <vector>
#include "StrVec.h"

using namespace std;

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

ostream &PrintResult(ostream &os, const QueryResult &result) {
    size_t time = result.lines->size();
    os << result.word << " occurs " << result.lines->size() << " " << (time > 1 ? "time" : "times") << endl;
    for (auto num : *result.lines) {
        os << "\t (line " << num + 1 << " )" << *(result.file->begin() + num) << endl;
    }
    return os;
}


#endif //
