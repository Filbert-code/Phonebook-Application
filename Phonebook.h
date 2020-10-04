// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
// Class purpose: 
//      To make an object that will create a dynamic array of Contact objects 
//      with functions to add, search, delete, and list the contents of the 
//      array. 
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
using namespace std;
#include "Contact.h"

class Phonebook
{
    private:
        string fileName; // name of .txt file
        Contact *arr; // pointer to Contact array
        int numOfContacts; // num of contact entries
        int capacity; // capacity of Contact array
    public:
        Phonebook() {} // default constructor
        // 1 arg constructor for inistialization with .txt file
        Phonebook(string fileName); 
        // destructor for deleting the dynamic Contact array
        ~Phonebook();
        // loop that continuously prompts the user with choices to iteract with the phonebook data
        void run(); 
        // returns number of lines in the .txt file
        int get_file_size(); 
        // creates a dynamic array of Contact objects with the file data
        void fillArray(Contact *&arr, int size); 
        // appends a Contact object to the Contact array
        void add(string fName, string lName, int phoneNum); 
        // deletes a Contact object from the Contact array
        void remove(string fName, string lName); 
        // returns the phone number of the Contact object
        int search(string fName, string lName); 
        // outputs the first 5 contact entries to the console
        void list(); 
        // updates the phonebook.txt file when the user exits the program
        void update_phonebook();
        // checks the inputed string whether all letters are uppercase or not
        bool is_all_upper(string& word); 
        // Returns true if all string arguments are uppercase
        bool name_uppercase_check(string fName, string lName); 
        // Returns true if Contact object with given name exists
        bool check_if_name_exists(string fName, string lName);
        // Captures user input for adding a new Contact object to the Contact array
        void run_switch_add_case(); 
        // Captures user input for searching and then outputting the phone number to console
        void run_switch_search_case(); 
        // Captures user input for name of Contact to delete and deletes the Contact if it exists
        void run_switch_del_case(); 
        
};

#endif