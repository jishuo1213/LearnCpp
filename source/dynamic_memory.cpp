#include <iostream>
#include <string>
#include "../headers/dynamic_memory.h"

using namespace std;

void process(shared_ptr<int> ptr)
{
    cout << ptr.unique() << endl;
    cout << ptr.use_count() << endl;
    (*ptr)++;
    cout << *ptr << endl;
}

const string* ConcatenateString(const string& s1, const string& s2)
{
    char* resultchar = new char[s1.length() + s2.length() + 1];
    size_t index = 0;
    for(const char& c : s1) {
        *(resultchar + index++) = c;
    }
    for(const char& c : s2) {
        *(resultchar + index++) = c;
    }
//    *(resultchar + index) = '\0';
    const string* res = new string(resultchar);
    cout << static_cast<void*>(resultchar) << endl;
    cout << res << endl;
    delete[] resultchar;
    return res;
}