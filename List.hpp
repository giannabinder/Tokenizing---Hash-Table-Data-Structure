// encircle in define conditionals to ensure it is only run once
#ifndef _LIST_HPP_
#define _LIST_HPP_

// include libraries
#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

class List { 
  public:
    List();
    ~List();
    void insert_word(const string& word, const int token, const int ascii_sum);
    int search_word(const string& word) const;
    void print() const;

  private:
    Node* _p_head;
};

#endif // end definition