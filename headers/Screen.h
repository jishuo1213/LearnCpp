#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <string>
#include <vector>

#include <string>
#include <iostream>
#include "WIndow_mgr.h"

using namespace std;

class Screen {

    friend void Window_mgr::clear(Window_mgr::ScreenIndex);
    friend istream &read(istream &is,Screen &s);

public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht,pos wt):height(ht),width(wt),contents(ht * wt,' ') {}
    Screen(pos ht,pos wt,char c):height(ht),width(wt),contents(ht * wt,c) {}
    Screen(istream &is);

    char get() const {
        return contents[cursor];
    }

    Screen &set(char);
    Screen &set(pos,pos,char);
    Screen &move(pos r,pos c);

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos height = 0,width = 0;
    pos cursor = 0;
    string contents;

    void do_display(ostream &os) const {
        os << contents;
    }
};

istream &read(istream &is,Screen &s) {
    Screen::pos ht,wt;
    char c;
    is>>ht>>wt>>c;
    s.contents = string(ht * wt,c);
    s.height = ht;
    s.width = wt;
    return is;
}

Screen::Screen(istream &is) {
    read(is,*this);
}


inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r,pos col,char c) {
    contents[r * width + col] = c;
    return *this;
}

inline Screen &Screen::move(pos r,pos c) {
    cursor = r * width + c;
    return *this;
}

void Window_mgr::clear(ScreenIndex index) {
    Screen &s = screens[index];
    s.contents = string(s.height * s.width,' ');
}

void Window_mgr::print(ScreenIndex index) {
    Screen &s = screens[index];
    s.display(std::cout);
}

#endif // SCREEN_H_INCLUDED
