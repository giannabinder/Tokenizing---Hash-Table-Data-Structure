// include libraries and header files
#include <string>
#include "Organizer.hpp"

using namespace std;

// define constant member variables
Organizer::Organizer() : _hash(nullptr) {}

Organizer::~Organizer() {
    delete this-> _hash;
    this-> _hash = nullptr;
}

void Organizer::init_hash(){
    int m;
    cin >> m;

    (this-> _hash) = new HashTable(m);
    cout << "success\n" ;
}

bool Organizer::insert_word(const string& word) {

    int ascii_sum = _alpha_ascii_sum(word);

    if ( ascii_sum != -1 ) {
        if ( (this-> _hash-> insert_word(word, this-> _dictionary.get_num_token(), ascii_sum)) ) { 
            this-> _dictionary.insert_token(word);
            return true; 
        } 
        return false;
    }

    return false; 
}

// use of fstream to parse external text files inspired by Mike's video "parsing_input_files"
void Organizer::read_file_words(const string& filename) {

    fstream fin(filename.c_str());

    string word;
    bool word_added = false;

    while ( fin >> word ) { if ( insert_word(word) && !(word_added)) { word_added = true; } }

    fin.close(); // Close the file

    if (word_added) { cout << "success\n";} 
    else { cout << "failure\n"; }
}

void Organizer::tokenize(const string& word, const bool verify, const string& end) const { 
    int ascii_sum = _alpha_ascii_sum(word);
    if ( ascii_sum != -1 ) { this-> _hash-> tokenize(word, verify, end, ascii_sum); } 
    else { cout << "0" << end; }
}

void Organizer::stok() const {
    
    string word;
    cin >> word;

    // stop taking in STOK input when the flag is reached
    while (word != "_DONE_") { 
        tokenize(word, false, " ");
        cin >> word;
    }

    cout << endl;
    return;
}

void Organizer::retrieve(const int& t, const string& end) const { this-> _dictionary.retrieve(t, end);}

void Organizer::toks() const {
  
  int token;
  cin >> token;

  // stop taking in STOK input when the flag is reached
  while (token != -1) {
    this-> _dictionary.retrieve(token, " ");
    cin >> token;
  } 

  cout << endl; 
  return;   
}

void Organizer::print() const {
    int hash;
    cin >> hash;
    this-> _hash-> print(hash);
}

int Organizer::_alpha_ascii_sum(const string& word) const {

    int word_size = word.size(); // get the size of the word
    int ascii_sum = 0;

    // add the ascii values of each character in the word
    for (int i = 0; i < word_size; i++){ 
        if ( !((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) ) { return -1; }
        ascii_sum += static_cast<int>(word[i]);
    }

    return ( ascii_sum ); 
}