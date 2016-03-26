#ifndef A_CLASS_H_INCLUDED
#define A_CLASS_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class A_class
{

public:
    constexpr A_class(string& str) : s(&str){}
    //    constexpr A_class(int ival = 0) :s(ival){}
    A_class& combine(const A_class& a)
    {
        *s += *(a.s);
        return *this;
    }
    void print(ostream& os) const
    {
        os << *(this->s) << endl;
    }

    void set(string& str)
    {
        s = &str;
    }
    static constexpr int scval = 0;

private:
    //    int s;
    string* s;
};

constexpr int A_class::scval;

#endif // A_CLASS_H_INCLUDED
