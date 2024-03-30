// encircle in define conditionals to ensure it is only run once
#ifndef _MASTERMIND_HPP_
#define _MASTERMIND_HPP_

// include libraries and header files
#include <fstream>
#include "HashTable.hpp"
#include "GrowableArray.hpp"

using namespace std;

class Organizer {
  public:
    Organizer();
    ~Organizer();
    void init_hash();
    bool insert_word(const string& word);
    void read_file_words(const string& filename);
    void tokenize(const string& word, const bool verify, const string& end) const;
    void retrieve(const int& t, const string& end) const;
    void stok() const;
    void toks() const;
    void print() const;

  private:
    int _alpha_ascii_sum(const string& word) const;
    HashTable* _hash;
    GrowableArray _dictionary;
};

#endif // end definition