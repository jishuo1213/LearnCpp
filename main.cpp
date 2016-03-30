#include <iostream>
#include <fstream>

#include "./headers/TextQuery.h"
#include "./headers/QueryResult.h"

using namespace std;

int main() {

    ifstream in("./others/input");
    TextQuery text_query(in);
    const auto res = text_query.Query("we");

    PrintResult(cout, res);
//    vector<string> temp = {"a", "b", "c", "d"};

//    for_each(temp.begin(), temp.end(), [](string &p) { cout << p << endl; });

/*    HasPtr temp("aaa");
    Print(cout,temp);
    HasPtr first;
    Print(cout,first);
    first = temp;
    Print(cout,first);*/

//    Print(cout, first);
//    Print(cout, second);
//    Print(cout, third);

    /*    auto p = new int();
        auto sp = make_shared<int>();

        process(shared_ptr<int>(p));*/
    /*
        shared_ptr<int> p(new int(42));

        process(shared_ptr<int>(p));

        cout << *p << endl;*/

    /*    map<string, size_t> word_count; // empty map from string to size_t
        string word;
        while(cin >> word)
            ++word_count[word];         // fetch and increment the counter for word
        for(const auto& w : word_count) // for each element in the map
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;*/
    // PartitionOddAndEnevNum("../nums", "../odd", "../enev");

    //    ReadAndSortNum();

    /*    vector<string> words;
        ReadTextFile("../input", words);

        cout << words.size() << endl;
        for_each(words.cbegin(), words.cend(), [](const string& s) { cout << s << endl; });*/
    /*    vector<int> ivec = { 0, 1, 2, 3, 4, 5, 67, 8, 9, 90 };
        auto res = find_if(ivec.begin(), ivec.end(), bind(CheckSize, "hello world", placeholders::_1));
        cout << *res << endl;*/
    /*    int value = -1;
        auto f = [value]() mutable -> bool {
            while(value > 0) {
                --value;
            }
            return value == 0;
        };

        bool res = f();
        cout << res << endl;*/

    /*    vector<string> string_vector = { "whataa", "is", "yourasdf", "namedsaa", "hellosafasf", "world" };

        size_t res = CountBiggerWords(string_vector, 6);
        cout << res << endl;*/

    /*    size_t value = 44;
        auto f = [value]() mutable { return ++value; };

        value = 0;
        auto res = f();
        cout << res << endl;*/

    /*    vector<string> string_vector = { "what", "is", "your", "name", "hello", "world" };

        auto partition_iterator = partition(string_vector.begin(), string_vector.end(), CompareStringLength);

        auto first = string_vector.begin();
        while(first != partition_iterator) {
            cout << *first << endl;
            ++first;
        }*/

    /*    list<int> ilist = { 0, 1, 2, 3, 4, 5, 0, 7, 5, 8, 0 };

        vector<int> ivec;

        cout << ivec.size() << "=====" << ivec.capacity() << endl;

        replace_copy(ilist.begin(), ilist.end(), back_inserter(ivec), 0, 20);

        cout << ivec.size() << "=====" << ivec.capacity() << endl;
        for(int i : ivec) {
            cout << i << endl;
        }*/

    /*    vector<string> svec;
        readFileByWord("../input", svec);

        cout << vector<string>::value_type << endl;
        string::size_type maxLength = 0;
        string finalString;

        for(const string& word : svec) {
            if(!word_contains_illegal_letter(word)) {
                if(word.size() > maxLength) {
                    maxLength = word.size();
                    finalString = word;
                }
            }
        }

        cout << finalString << endl;*/

    /*    string first = "我们一起";

        replaceThreeString(first, "我们", "地点");
        cout << first << endl;*/
    /*    const char* cp = "Hello World!!!"; // null-terminated array
        char noNull[] = { 'H', 'i' };      // not null terminated

        string s1(cp);        // copy up to the null in cp; s1 == "Hello World!!!"
        string s2(noNull, 2); // copy two characters from no_null; s2 == "Hi"
        string s3(noNull);    // undefined: noNull not null terminated
        string s4(cp + 6, 5); // copy 5 characters starting at cp[6]; s4 == "World"
        string s5(s1, 6, 5);  // copy 5 characters starting at s1[6]; s5 == "World"
        string s6(s1, 6);     // copy from s1 [6] to end of s1; s6 == "World!!!"
        string s7(s1, 6, 20); // ok, copies only to end of s1; s7 == "World!!!"
                              //  string s8(s1, 16);                 // throws an out_of_range exception

        cout << s3 << endl;


        vector<char> chvec = { 'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', ' ' };

        string s;
        s.assign(chvec.begin(), chvec.end());

        cout << s << endl;*/
    /*    forward_list<string> ilist;

        for(int i = 1; i < 20; ++i) {
            ilist.emplace_front(i, 'a');
        }

        string s1 = "bb";
        string s2 = "cc";

        findAndInsert(ilist, s1, s2);

        for(string s : ilist)
            cout << s << endl;*/

    /* vector<int> ivec;
     for(int i = 0; i < 20; ++i) {
         ilist.push_front(i);
         ivec.push_back(i);
     }

     deleteOddNum(ilist);

     for(int i : ilist)
         cout << i << endl;*/

    //    int temp = 90;
    //    ilist.push_back(temp);
    //    temp = 434;
    //    int &last = ilist.back();
    //    cout << last<<endl;

    /*
        ivecItertor first = ivec.begin();
        ivecItertor middle = ivec.end();
        middle = middle - 9;

        cout << *first << endl;
        ivec.insert(first, 12);

        cout << *first << "=====" << endl;


        ivecItertor iend = ivec.end();
        while(first != iend) {
            cout << *first << endl;
            ++first;
        }*/

    //    bool res = compareListAndVector(ilist, ivec);
    //    cout << res << endl;
    /*    vector<string> strVec;
        char cstr[] = { 'a', 'a', 'a', '\0' };
        cout << sizeof(cstr) << endl;
        list<char*> sList(10, cstr);
        listToVector(sList, strVec);
        for(char* str : sList) {
            cout << str << endl;
        }
        for(string& str : strVec) {
            cout << str << endl;
        }*/
    //    vector<int> ivec;
    //    for(int i = 0 ; i != 20; ++i) {
    //        ivec.push_back(i);
    //    }
    //    int res = *(findNumIterator(ivec.begin(),ivec.end(),50));
    //    cout << res <<endl;
    //    readFileScreen("input");
    //    vector<string> svec;
    //    readFileByWord("note",svec);
    //    cout << svec.size()<<endl;
    //    for(string &s:svec) {
    //        cout<<s<<endl;
    //    }
    //    endoffilebit(cin);
    //    ca.print(cout);
    //    cout << ca.scval<<endl;
    //    Screen s2(24,80,' ');
    //    Screen s1(24,80,'c');
    //    Window_mgr windows;
    //    windows.add(s2);
    //    windows.add(s1);
    //    windows.print(1);
    //    windows.clear(1);
    //    windows.print(1);
    return 0;
}
