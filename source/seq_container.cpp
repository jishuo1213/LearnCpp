#include "../headers/seq_container.h"
#include <vector>
#include <iterator>
#include <list>
#include <string>
#include <stdexcept>

using namespace std;

const string numeric = "0123456789";
const string illegal_letters = "bdfghijklpqty";

int findNum(vector<int>::iterator first, vector<int>::iterator second, int num)
{
    int index = 0;
    if(first > second) {
        return -1;
    }
    while(first <= second) {
        if(*first == num) {
            return index;
        }
        ++first;
        index++;
    }
    return -1;
}

vector<int>::iterator findNumIterator(vector<int>::iterator first, vector<int>::iterator second, int num)
{
    vector<int>::iterator res;
    if(first > second) {
        return res;
    }
    while(first <= second) {
        if(*first == num) {
            return first;
        }
        ++first;
    }
    return res;
}

void listToVector(list<char*>& cStringList, vector<string>& strVec)
{
    strVec.assign(cStringList.cbegin(), cStringList.cend());
}

bool compareListAndVector(list<int>& ilist, vector<int>& ivec)
{
    if(ilist.size() != ivec.size())
        return false;
    list<int>::iterator listBegin = ilist.begin();
    list<int>::iterator listEnd = ilist.end();
    vector<int>::iterator vecBegin = ivec.begin();
    while(listBegin != listEnd) {
        if(*listBegin == *vecBegin) {
            ++listBegin;
            ++vecBegin;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void deleteOddNum(forward_list<int>& flist)
{
    using flist_iterator = forward_list<int>::iterator;
    flist_iterator prev = flist.before_begin();
    flist_iterator curr = flist.begin();
    while(curr != flist.end()) {
        if(*curr % 2) {
            curr = flist.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
}

void findAndInsert(forward_list<string>& fstringlist, string& first, string& second)
{
    auto curr = fstringlist.begin();
    auto last = fstringlist.end();
    auto prev = fstringlist.before_begin();
    bool hasFind = false;
    while(curr != last) {
        if(*curr == first) {
            curr = fstringlist.insert_after(curr, second);
            hasFind = true;
        } else {
            ++curr;
            prev++;
        }
    }
    if(!hasFind)
        fstringlist.insert_after(prev, second);
}

/*void replaceThreeString(string& s, const string& oldVal, const string& newVal)
{
    if(s.size() < oldVal.size())
        throw runtime_error("error");
    auto first = s.begin();
    while(first != s.end()) {
        auto sFirst = first;
        auto oldValFirst = oldVal.begin();

        if((*sFirst == *oldValFirst)) {
            while(oldValFirst != oldVal.end()) {
                if(*sFirst == *oldValFirst) {
                    ++sFirst;
                    ++oldValFirst;
                } else {
                    break;
                }
            }
            if(oldValFirst == oldVal.end()) {
                first = s.erase(first, first + oldVal.size());
                first = s.insert(first, newVal.begin(), newVal.end());
                first += newVal.size();
            }
        } else {
            ++first;
        }
    }
}*/

void replaceThreeString(string& s, const string& oldVal, const string& newVal)
{
    if(s.size() < oldVal.size())
        throw runtime_error("error");
    string::size_type first = 0;
    while(first != s.size()) {
        string::size_type sFirst = first;
        string::size_type oldValFirst = 0;

        if((s[sFirst] == oldVal[oldValFirst])) {
            while(oldValFirst != oldVal.size()) {
                if(s[sFirst] == oldVal[oldValFirst]) {
                    ++sFirst;
                    ++oldValFirst;
                } else {
                    break;
                }
            }
            if(oldValFirst == oldVal.size()) {
                s.replace(first, oldVal.size(), newVal);
                first += newVal.size();
            }
        } else {
            ++first;
        }
    }
}

void addNameFix(string& name, const string& prefix, const string& stufix)
{
    name.insert(0, prefix);
    name.insert(name.size(), stufix);
}

string removeNumeric(string& word)
{
    string::size_type pos = 0;
    string res;
    while((pos = word.find_first_not_of(numeric, pos)) != string::npos) {
        res.insert(res.size(), 1, word[pos]);
        ++pos;
    }
    return res;
}

bool word_contains_illegal_letter(const string& word)
{
    return word.find_first_of(illegal_letters) == string::npos ? false : true;
}