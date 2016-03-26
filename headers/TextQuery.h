#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <map>
#include <fstream>

#include "QueryResult.h"

using namespace std;

class TextQuery
{
    friend class QueryResult;
public:
    TextQuery();
    TextQuery(ifstream &in);
    
    Query(const string &s);
private:
    vector<string> file_lines;
    map<int,string> query_result;
};

#endif // TEXTQUERY_H
