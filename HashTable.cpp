// include header files
#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int m) : _m(m) { this-> _list = new List[ (this-> _m) ]; }

HashTable::~HashTable(){

    // call the destructor of each object associated with the array
    for (int i = 0; i < this-> _m; i++) { _list[i].~List(); }

    delete[] _list;
    _list = nullptr;
}

bool HashTable::insert_word(const string& word, const int& token, const int& ascii_sum) {  

    int hash = _hash(ascii_sum);
    
    // check if the word is already in the database
    if ( this-> _list[hash].search_word(word) ) { return false; }

    _list[hash].insert_word(word, (token + 1), ascii_sum); 
    return true;
}

void HashTable::tokenize(const string& word, const bool verify, const string& end, const int& ascii_sum) const{

    int hash = this-> _hash(ascii_sum);

    cout << _list[hash].search_word(word) << end; 
    return;
}

void HashTable::print(const int& hash) const{

    // check if the key given is invalid
    if ( (hash < 0) || (hash > (_m) ) ) {
        cout << "chain is empty\n" ;
        return;
    }

    _list[hash].print(); // call the function to print out the list's tokens
    return;
}

int HashTable::_hash(const int& ascii_sum) const { return (ascii_sum % (this-> _m)); }