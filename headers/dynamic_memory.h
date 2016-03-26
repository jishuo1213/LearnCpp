#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include <memory>
#include <string>

extern void process(std::shared_ptr<int> ptr);
extern const std::string* ConcatenateString(const std::string& s1, const std::string& s2);
#endif