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

/*
    Deletes the Contact object associated with the given first and last 
    name arguments. The contact is deleted from the array and the 
    .txt file. 
*/
void Phonebook::remove(string fName, string lName) 
{
    for(int i = 0; i < numOfContacts + 1; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName)
        {
            --numOfContacts;
            // shift all array elements 1 position to the left
            for(int k = i; k < numOfContacts + 1; ++k)
            {
                arr[k] = arr[k + 1];
            }
            break;
        }
    }
}

/*
    Returns the phone number of the Contact with the associated fName and lName 
    given as arguments. 
*/
int Phonebook::search(string fName, string lName)
{
    for(int i = 0; i < numOfContacts + 1; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName)
            return arr[i].get_phoneNum();
    }
    return -1;
}

/*
    Outputs the first 5 contact entries to the console
*/
void Phonebook::list()
{
    for(int i = 0; i < 5; ++i)
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    cout << "..." << endl;
}

/*
    Update the phonebook.txt file when the user exits the program.
*/
void Phonebook::update_phonebook()
{
    ofstream file(fileName, ofstream::trunc); // deletes all contents of the file
    for(int i = 0; i < numOfContacts; ++i) // repopulate the file with the current array state
    {
        file << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
    file << arr[numOfContacts].get_fName() << " " << arr[numOfContacts].get_lName() << " " << arr[numOfContacts].get_phoneNum();
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
    cout << "Number of contacts:" << numOfContacts << endl << endl;
}