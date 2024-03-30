// encircle in define conditionals to ensure it is only run once
#ifndef _HASH_HPP_
#define _HASH_HPP_

// include libraries and header files
#include <fstream>
#include "List.hpp"

using namespace std;

class HashTable {
  public:
    HashTable(int m);
    ~HashTable();
    bool insert_word(const string& word, const int& token, const int& ascii_sum);
    void tokenize(const string& word, const bool verify, const string& end, const int& ascii_sum) const;
    void print(const int& hash) const;

  private:
    int _hash(const int& ascii_sum) const;
    const int _m; 
    List* _list;
};

#endif // end definition