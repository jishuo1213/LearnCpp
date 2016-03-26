#ifndef WINDOW_MGR_H_INCLUDED
#define WINDOW_MGR_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    void add(Screen&);
    void print(ScreenIndex);

private:
    std::vector<Screen> screens;
};

void Window_mgr::add(Screen &s) {
    screens.push_back(s);
}

#endif // WINDOW_MGR_H_INCLUDED
