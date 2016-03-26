#ifndef SEQ_CONTAINER_H_INCLUDED
#define SEQ_CONTAINER_H_INCLUDED

#include <vector>
#include <iterator>
#include <string.h>
#include <list>
#include <forward_list>

using namespace std;

extern int findNum(vector<int>::iterator first, vector<int>::iterator second, int num);
extern vector<int>::iterator findNumIterator(vector<int>::iterator first, vector<int>::iterator second, int num);
extern void listToVector(list<char*>& cStringList, vector<string>& strVec);
extern bool compareListAndVector(list<int>& ilist, vector<int>& ivec);
extern void deleteOddNum(forward_list<int>& flist);
extern void findAndInsert(forward_list<string>& fstringlist, string& first, string& second);
extern void replaceThreeString(string& s, const string& oldVal, const string& newVal);
extern void addNameFix(string& name, const string& prefix, const string& stufix);
extern string removeNumeric(string& word);
extern bool word_contains_illegal_letter(const string& word);

#endif // SEQ_CONTAINER_H_INCLUDED
