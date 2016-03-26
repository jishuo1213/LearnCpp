#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../headers/Screen.h"
#include "../headers/io.h"

std::istream& endoffilebit(std::istream& is)
{
    auto old_state = is.rdstate();
    is.clear();
    std::string s;
    int count = 0;
    while(!is.eof()) {
        is >> s;
        std::cout << count << s << std::endl;
        ++count;
    }
    is.setstate(old_state);
    return is;
}

void readFileByLine(const std::string& fileName, std::vector<std::string>& svec)
{
    std::ifstream in(fileName);
    std::string line;
    while(!in.eof()) {
        //        std::getline(in,line);
        std::getline(in, line);
        svec.push_back(line);
    }
}

void readFileByWord(const std::string& fileName, std::vector<std::string>& svec)
{
    std::ifstream in(fileName);
    std::string line;
    while(!in.eof()) {
        in >> line;
        svec.push_back(line);
    }
}

void readFileScreen(const std::string& fileName)
{
    std::ifstream in(fileName);
    Screen s;
    while(read(in, s)) {
        s.display(std::cout);
        std::cout << endl;
    }
}
