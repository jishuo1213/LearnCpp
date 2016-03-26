#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

//using namespace std;

extern std::istream& endoffilebit(std::istream &);

extern void readFileByLine(const std::string &fileName,std::vector<std::string> &svec);

extern void readFileByWord(const std::string &fileName,std::vector<std::string> &svec);

extern void readFileScreen(const std::string &fileName);


#endif // IO_H_INCLUDED
