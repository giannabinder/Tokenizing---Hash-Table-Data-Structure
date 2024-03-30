// include libraries and header files
#include "List.hpp"
#include "Node.hpp"

using namespace std;

List::List() : _p_head(nullptr) {}

List::~List() {
  Node *p_temp = this-> _p_head;

  // go through the list and delete all nodes
  while (p_temp) {
    _p_head = const_cast<Node*>(this-> _p_head-> _p_next);
    delete p_temp;
    p_temp = _p_head;
  }

  // set pointers to null to avoid dangling pointers
  _p_head = nullptr;
  p_temp = nullptr;

}

void List::insert_word(const string& word, const int token, const int ascii_sum) {

  // if the list is empty, make this node the head of the list
  // initialize their pointer to null as there are no other nodes
  if ( (this-> _p_head) == nullptr) { this-> _p_head = new Node(word, token, nullptr, ascii_sum); }

  // if the list is populated, push the node to the front of the list
  else {
    Node *p_new = new Node(word, token, this-> _p_head, ascii_sum);
    this-> _p_head = p_new;
    p_new = nullptr; // set pointers to null to avoid dangling pointers
  }

  return;
}

int List::search_word(const string& word) const {

  // if the list associated to its key is empty do not continue
  if ( !(this-> _p_head) ) { return 0; }

  int token = 0;
  Node* p_traverse = this-> _p_head;

  // go thorugh the entire list to find the word
  while (p_traverse) {
    
    // if the word is found, set the return vairable and break out of the while loop
    if (p_traverse-> _word == word) { 
      token = p_traverse-> _token;
      break;
    }

    p_traverse = const_cast<Node*>(p_traverse-> _p_next); // check the next node
  }

  p_traverse = nullptr;
  return token;
}

void List::print() const {

  Node* p_traverse = this-> _p_head;

  if ( !(this-> _p_head) ) { 
    cout << "chain is empty\n"; 
    return;
  }

  // go thorugh the entire list
  while (p_traverse) {
    cout << (p_traverse-> _ascii_sum) << " " ; // print the token
    p_traverse = const_cast<Node*>(p_traverse-> _p_next); // go to the next node
  }

  cout << endl;

  p_traverse = nullptr;
  return;
}