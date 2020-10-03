#include "Phonebook.h"
#include <fstream>

Phonebook::Phonebook(string fileName)
{
    int size = get_file_length(); // get the number of Contacts 
    Contact *arr = new Contact[size];
}

/*
    Returns the number of lines in the .txt file; the name was given 
    as a parameter for Phonebook. 
*/
int Phonebook::get_file_length() 
{
    ifstream file(fileName); // create file object 

    // ----- getting number of lines in the file
    string line;
    int size;
    while(getline(file, line))
        // increment size on each line of the file
        size++;
    size--; // deincrement due to 0-index nature of arrays
    return size;
}

/*
    Creates a dynamic array of Contact objects and points the private Phonebook
    variable named arr to the reference of the dynamic array.  
*/
void Phonebook::fillArray(int size) 
{
    ifstream file(fileName); // create file object

    Contact *arr = new Contact[size]; // initialize dynamic Contact array

    // ----- creating an array of Contact objects with file data
    string fName, lName;
    int phoneNum;
    for(int i = 0; i < size + 1; ++i)
    {
        file >> fName >> lName >> phoneNum;
        Contact contact(fName, lName, phoneNum);
        arr[i] = contact;
    }
}

void Phonebook::print() 
{
    arr[0].print();
}