//
// Created by Administrator on 2016/3/31.
//

#include <fstream>
#include <set>
#include <sstream>

#include "../headers/TextQuery.h"
#include "../headers/QueryResult.h"

using namespace std;

TextQuery::TextQuery(ifstream &in) : file_lines(new StrVec()) {
    string s;
    size_t line_num = 0;
    while (!in.eof() && !in.fail()) {
        getline(in, s);
        cout << "===========" << s << endl;
        file_lines->push_back(s);
        istringstream line(s);
        string word;
        while (line >> word) {
            auto &lines = word_lines[word];
            if (!lines) {
//                assert(lines != nullptr);
                lines.reset(new set<size_t>);
            }
            cout << word << "====" << line_num << endl;
            lines->insert(line_num);
        }
        ++line_num;
    }
    cout << file_lines->size() << endl;
}

QueryResult TextQuery::Query(const string &s) {
    cout << "Query" << endl;
    static shared_ptr<set<size_t >> no_data(new set<size_t>);
    auto loc = word_lines.find(s);
    if (loc == word_lines.end()) {
//        QueryResult result(s, no_data, file_lines);
        return {s, no_data, file_lines};
    } else {
//        QueryResult result(s, loc->second, file_lines);
        return {s, loc->second, file_lines};
    }
}

ostream &PrintResult(ostream &os, const QueryResult &&result) {
    cout << "PrintResult" << endl;
    size_t time = result.lines->size();
    cout << "PrintResult" << time << endl;
    os << result.word << " occurs " << result.lines->size() << " " << (time > 1 ? "time" : "times") << endl;
    for (auto num : *result.lines) {
        os << "\t (line " << num + 1 << " )" << *(result.file->begin() + num) << endl;
    }
    return os;
}

