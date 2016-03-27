#include <fstream>
#include <iterator>
#include <set>
#include <sstream>
#include <cassert>
#include "../headers/TextQuery.h"
#include "../headers/QueryResult.h"

using namespace std;

TextQuery::TextQuery(ifstream &in) {
    string s;
    size_t line_num = 0;
    while (!in.eof() && !in.fail()) {
        getline(in, s);
        file_lines->push_back(s);
        istringstream line(s);
        string word;
        while (line >> word) {
            auto &lines = word_lines[word];
            if (!lines) {
                assert(lines != nullptr);
                lines.reset(new set<size_t>);
            }
            lines->insert(line_num);
        }
    }
}

QueryResult &TextQuery::Query(const string &s) {
    static shared_ptr<set<size_t >> no_data(new set<size_t>);
    auto loc = word_lines.find(s);
    if (loc == word_lines.end()) {
        return {s, no_data, file_lines};
    } else {
        return {s, loc->second, file_lines};
    }
}
