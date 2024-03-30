// include header files
#include "GrowableArray.hpp"

using namespace std;

// note: we are not using index zero of the dictionary, as stated in the project instructions, thus have the actual size of the array be one larger than capacity
GrowableArray::GrowableArray() : _array(new string[17]), _capacity(16), _num_tokens(0) {}

GrowableArray::~GrowableArray() {
  delete[] _array;
  this-> _array = nullptr;
}

void GrowableArray::insert_token(const string& word) {

  // if the array is full, dynamically allocate a new array with double the capacity
  if (this->_capacity == this->_num_tokens) { this-> _grow_array();}

  this->_num_tokens++; // increase the token counter;
  this->_array[_num_tokens] = word; // add the element into the array

  return;
}

void GrowableArray::retrieve(const int token, const string& end) const{

  // if the token is not valid/fill array index or the database is empty, do not continue
  if ( !(_num_tokens) || (this->_num_tokens < token) || (token <= 0) ) {
    cout << "UNKNOWN" << end;
    return; 
  }

  cout << _array[token] << end;
  return;
}

int GrowableArray:: get_num_token() const { return _num_tokens; }

void GrowableArray::_grow_array() {
  string *new_array = new string[( (this-> _capacity) *2) + 1]; // create the new array with double the size

  // copy the contents of the original array into the new one
  for (int i = 1; i < (this-> _capacity) + 1; i++) { new_array[i] = _array[i]; }

  delete[] this-> _array; // deallocate the old array's memory
  this->_array = new_array; // point to the new array

  this->_capacity *= 2; // update the capacity
}