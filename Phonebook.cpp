#include "Phonebook.h"
#include <fstream>

Phonebook::Phonebook(string fileName)
{
    this->fileName = fileName;
    int size = get_file_size();
    this->capacity = size; // Total capacity of the array
    this->numOfContacts = size; // Total number of contact entries
    this->arr = new Contact[capacity];
    fillArray(arr, numOfContacts);
}

/*
    Returns the number of lines in the .txt file; the name was given 
    as a parameter for Phonebook. 
*/
int Phonebook::get_file_size() 
{
    ifstream file(fileName); // create file object 

    // ----- getting number of lines in the file
    string line;
    int size;
    while(getline(file, line))
        // increment size on each line of the file
        size++;
    --size; // deincrement size to match 0-indexing of arrays
    return size;
}

/*
    Creates a dynamic array of Contact objects and points the private Phonebook
    variable named arr to the reference of the dynamic array.  
*/
void Phonebook::fillArray(Contact *&arr, int size) 
{
    ifstream file(fileName); // create file object

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

void Phonebook::add(string fName, string lName, int phoneNum)
{
    ++numOfContacts;
    // check if array has enough space. If not, double the size of the array
    if(numOfContacts > capacity)
    {
        capacity *= 2; // double the capacity
        this->arr = new Contact[capacity];
        fillArray(arr, numOfContacts); // fill in the new array
    }
    
    Contact contact(fName, lName, phoneNum);
    this->arr[numOfContacts] = contact;
}

void Phonebook::print() 
{
    // print first 5 and last 5 rows of the student data from the array
    cout << "First 5 rows: " << endl;
    for(int i = 0; i < 5; ++i)
    {
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
    cout << "Last 5 rows: " << endl;
    for(int i = numOfContacts - 4; i < numOfContacts + 1; ++i)
    {
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
}