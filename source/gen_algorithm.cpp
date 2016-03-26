#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

bool CompareStringLength(string& word)
{
    return word.length() >= 5;
}

size_t CountBiggerWords(vector<string> words_vector, size_t length)
{
    return count_if(words_vector.begin(), words_vector.end(), [length](string& word) { return word.size() > length; });
}

bool CheckSize(const string& str, int num)
{
    return num >= 0 ? (static_cast<unsigned int>(num) > str.size()) : false;
}

void ReadTextFile(const string& file_name, vector<string>& words_vector)
{
    ifstream in(file_name);
    istream_iterator<string> instream_iterator(in);
    istream_iterator<string> endf;
    while(instream_iterator != endf) {
        words_vector.push_back(*instream_iterator++);
    }
}

void ReadAndSortNum()
{
    istream_iterator<int> in_iterator(cin);
    istream_iterator<int> endf;
    vector<int> num_vector(in_iterator, endf);
    sort(num_vector.begin(), num_vector.end());
    ostream_iterator<int> out_interator(cout, "\n");
    unique_copy(num_vector.begin(), num_vector.end(), out_interator);
}

void PartitionOddAndEnevNum(const string& input_file, const string& odd_num_file, const string& enev_num_file)
{
    ifstream in(input_file);
    istream_iterator<int> input_iterator(in);
    istream_iterator<int> endf;
    ofstream odd_num_stream(odd_num_file);
    ostream_iterator<int> odd_num_out_stream(odd_num_stream, " ");
    ofstream enev_num_stream(enev_num_file);
    ostream_iterator<int> enev_num_out_stream(enev_num_stream, "\n");
    partition_copy(input_iterator, endf, odd_num_out_stream, enev_num_out_stream, [](int num) { return num % 2; });
}