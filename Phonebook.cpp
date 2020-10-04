#include "Phonebook.h"
#include <fstream>

Phonebook::Phonebook(string fileName)
{
    this->fileName = fileName;
    int size = get_file_size();
    this->fileSize = size;
    this->arr = new Contact[fileSize];
    fillArray(arr, fileSize);
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
    for(int i = 0; i < size; ++i)
    {
        file >> fName >> lName >> phoneNum;
        Contact contact(fName, lName, phoneNum);
        arr[i] = contact;
    }
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
    for(int i = fileSize - 5; i < fileSize; ++i)
    {
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
}