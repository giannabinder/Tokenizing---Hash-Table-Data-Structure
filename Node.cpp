// include libraries and header files
#include <string>
#include "Node.hpp"

using namespace std;

// define constant member variables
Node::Node(const string& word, const int token, Node* p_next, const int ascii_sum) : _word(word), _token(token), _ascii_sum(ascii_sum), _p_next(p_next) {}