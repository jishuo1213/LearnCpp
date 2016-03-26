#ifndef GEN_ALGORITHM_H
#define GEN_ALGORITHM_H

#include <string>
#include <vector>

using namespace std;

extern bool CompareStringLength(string& word);
extern size_t CountBiggerWords(vector<string> words_vector, size_t length);
extern bool CheckSize(const string& str, int num);
extern void ReadTextFile(const string& file_name, vector<string>& words_vector);
extern void ReadAndSortNum();
extern void PartitionOddAndEnevNum(const string& input_file, const string& odd_num_file, const string& enev_num_file);

#endif