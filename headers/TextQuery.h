#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery {
public:

    TextQuery() = default;

    TextQuery(ifstream &in);

    QueryResult &Query(const string &s);

private:
    shared_ptr<vector<string>> file_lines;
    map<string, shared_ptr<set<size_t >>> word_lines;
};

#endif // TEXTQUERY_H
