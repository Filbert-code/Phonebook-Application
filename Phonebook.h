#ifndef PHONEBOOK_H
#define PHONEBOOK_H
using namespace std;
#include "Contact.h"
#include <string>

class Phonebook
{
    private:
        string fileName;
        Contact arr[];
    public:
        Phonebook() {}
        Phonebook(string fileName);
        int get_file_length(); // returns number of lines in the .txt file
        void fillArray(int size); // creates a dynamic array of Contact objects with the file data
        void add();
        void search();
        void remove();
        void list();

        void print();
};

#endif