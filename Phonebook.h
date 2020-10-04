// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
using namespace std;
#include "Contact.h"
#include <string>

class Phonebook
{
    private:
        string fileName;
        Contact *arr;
        int numOfContacts;
        int capacity;
    public:
        Phonebook() {}
        Phonebook(string fileName);
        void run();
        int get_file_size(); // returns number of lines in the .txt file
        void fillArray(Contact *&arr, int size); // creates a dynamic array of Contact objects with the file data
        void add(string fName, string lName, int phoneNum);
        int search(string fName, string lName);
        int search(string fName, string lName, int phoneNum);
        void remove(string fName, string lName);
        void list();
        void update_phonebook();
        bool is_all_upper(const std::string& word);
        bool name_uppercase_check(string fName, string lName);
};

#endif