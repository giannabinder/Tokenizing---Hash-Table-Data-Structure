// encircle in define conditionals to ensure it is only run once
#ifndef _GROWABLE_ARRAY_HPP_
#define _GROWABLE_ARRAY_HPP_

// include libraries and header files
#include <iostream>
#include <string>

using namespace std;

class GrowableArray{
    public:
        GrowableArray();
        ~GrowableArray();
        void insert_token(const string& word);
        void retrieve(const int token, const string& end) const;
        int get_num_token() const;

    private:
        void _grow_array();
        string* _array;
        int _capacity;
        int _num_tokens;
};

#endif // end definition