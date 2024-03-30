// include header files
#include "Organizer.hpp"

using namespace std;

int main() {

  // declare pointers for dynamic memory allocation of objects
  Organizer* organizer = new Organizer;

  string command;

  // Handle user inputted commands through function calls
  while (cin >> command){
    
    // Dynamically allocate memory for a HashTable of size 'm'
    if (command == "M") { organizer-> init_hash(); }
    
    // Insert a word into the data structures
    else if (command == "INSERT") {
      string word;
      cin >> word; 

      if (organizer-> insert_word(word)) { cout << "success\n"; }
      else { cout << "failure\n"; }
     }

    // Read words from a file and insert them into the data strcutures
    else if (command == "READ") {   
      string filename;
      cin >> filename;

      organizer-> read_file_words(filename);
    }

    // Print the given word's token 
    else if (command == "TOKENIZE") { 
      string word;
      cin >> word;

      organizer-> tokenize(word, true, "\n");
    }
    
    // Print the given token's word
    else if (command == "RETRIEVE") { 
      int t;
      cin >> t; 

      organizer-> retrieve(t, "\n");
    } 

    // Print the tokens of the corresponding string of words
    else if (command == "STOK") { organizer-> stok(); }

    // Print the words asscoiated with the string of tokens
    else if (command == "TOKS") { organizer-> toks(); }

    // Print the all the keys in the specified hash
    else if (command == "PRINT") { organizer-> print(); }

    // deallocate memory and exit the program  
    else if (command == "EXIT") {
      delete organizer;
      organizer = nullptr;
      return 0 ;
    }
  }
}