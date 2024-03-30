// encircle in define conditionals to ensure it is only run once
#ifndef _NODE_HPP_
#define _NODE_HPP_

// include libraries
#include <iostream>

using namespace std;

class Node {
  private:
    Node(const string& word, const int token, Node* p_next, const int _ascii_sum); // declare custom constructor

    // declare member variables
    const int _token;
    const int _ascii_sum;
    const string _word;
    const Node* _p_next;

  friend class List; // declare List as a friend
};

#endif // end definition