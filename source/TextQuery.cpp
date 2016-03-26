#include <fstream>
#include <iterator>
#include <stream>
#include <set>

#include "../headers/TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream& in)
{
    string s;
    while(!in.eof() && !in.fail()) {
        getline(in, s);
        file_lines.push_back(s);
    }
}

TextQuery::Query(const string& s)
{
    for(string& s : file_lines) {
        
        stringstream sin(s);
        istream_iterator<string> 
    }
}
