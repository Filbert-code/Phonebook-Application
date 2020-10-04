// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
#include "Phonebook.h"
#include <fstream>

/*
    Constructor with 1 argument that stores the name of the file. 
*/
Phonebook::Phonebook(string fileName)
{
    this->fileName = fileName;
    int size = get_file_size();
    this->capacity = size; // Total capacity of the array
    if(capacity == 0)
        capacity = 5;
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

void Phonebook::add(string fName, string lName, int phoneNum)
{
    // check if all strings arguments are uppercase
    if(!name_uppercase_check(fName, lName))
        return;
    ++numOfContacts;
    // check if array has enough space. If not, double the size of the array
    if(numOfContacts> capacity)
    {
        capacity *= 2; // double the capacity
        this->arr = new Contact[capacity];
        fillArray(arr, numOfContacts); // fill in the new array
    }
    
    Contact contact(fName, lName, phoneNum);
    this->arr[numOfContacts - 1] = contact;
}

/*
    Deletes the Contact object associated with the given first and last 
    name arguments. The contact is deleted from the array and the 
    .txt file. 
*/
void Phonebook::remove(string fName, string lName) 
{
    // check if all strings arguments are uppercase
    name_uppercase_check(fName, lName);
    for(int i = 0; i < numOfContacts; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName)
        {
            --numOfContacts;
            // shift all array elements 1 position to the left
            for(int k = i; k < numOfContacts; ++k)
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
    // check if all strings arguments are uppercase
    name_uppercase_check(fName, lName);
    for(int i = 0; i < numOfContacts; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName)
            return arr[i].get_phoneNum();
    }
    return -1; 
}

/*
    Overloaded search method that allows the search to include a phone number. 
    Used for not allowing duplicates during adding operation. 
*/
int Phonebook::search(string fName, string lName, int phoneNum)
{
    for(int i = 0; i < numOfContacts; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName && arr[i].get_phoneNum() == phoneNum)
            return arr[i].get_phoneNum();
    }
    return -1; 
}

/*
    Outputs the first 5 contact entries to the console
*/
void Phonebook::list()
{
    int listSize = 5;
    if((numOfContacts + 1) < listSize)
        listSize = numOfContacts;
    if(listSize == 0)
    {
        cout << "<Empty>" << endl;
        return;
    }
    for(int i = 0; i < listSize; ++i)
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    if(listSize >= 5)
        cout << "..." << endl;
}

/*
    Update the phonebook.txt file when the user exits the program.
*/
void Phonebook::update_phonebook()
{
    ofstream file(fileName, ofstream::trunc); // deletes all contents of the file
    for(int i = 0; i < numOfContacts - 1; ++i) // repopulate the file with the current array state
    {
        file << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
    if(numOfContacts != 0)
        file << arr[numOfContacts - 1].get_fName() << " " << arr[numOfContacts - 1].get_lName() << " " << arr[numOfContacts - 1].get_phoneNum();
}

/*
    Checks the inputed string whether all letters are uppercase or not.
*/
bool Phonebook::is_all_upper(const std::string& word)
{
    for(auto& c: word) 
        if(!isupper(static_cast<unsigned char>(c))) 
            return false;
    return true;
}

bool Phonebook::name_uppercase_check(string fName, string lName)
{
    // check if all strings arguments are uppercase
    if(!is_all_upper(fName) || !is_all_upper(lName))
    {
        cout << "Enter names in uppercase letters." << endl;
        return false;
    }
    return true;
}

/*
    A while loop that continuously prompts the user with choices to 
    iteract with the phonebook data. Ends when running = false.
*/
void Phonebook::run()
{
    cout << "***ALEX'S PHONEBOOK APPLICATION***" << endl;
    cout << "Please choose an operation:" << endl;
    bool running = true;
    while(running)
    {
        cout << "A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit): ";
        char userInput;
        cin >> userInput; // get user input

        // check if user entered a lowercase character
        if(islower(userInput))
            cout << "Enter operations in uppercase letters." << endl;

        switch(userInput)
        {
            case 'A': 
            {
                // add case
                cout << "Enter name: ";
                string fNameInput;
                string lNameInput;
                cin >> fNameInput >> lNameInput;
                cout << "Enter phone: ";
                int phoneInput;
                cin >> phoneInput;

                // checks if user is creating a duplicate contact
                if(search(fNameInput, lNameInput, phoneInput) == -1)
                {
                    add(fNameInput, lNameInput, phoneInput);
                }
                break;
            }
            case 'S': 
            {
                // search case
                cout << "Enter name: ";
                string fNameInput;
                string lNameInput;
                cin >> fNameInput >> lNameInput;
                int phoneNum = search(fNameInput, lNameInput);
                if(phoneNum != -1)
                    cout << "Phone number: " << phoneNum << endl;
                else 
                    cout << "Name not found." << endl;
                break;
            }
            case 'D':
            {
                // delete case
                cout << "Enter name: ";
                string fNameInput;
                string lNameInput;
                cin >> fNameInput >> lNameInput;
                remove(fNameInput, lNameInput);
                break;
            }
            case 'L': 
            {
                // list case
                list(); 
                break;
            }
                
            case 'Q':
                // quit case
                update_phonebook();
                running = false;
                break;
        }
    }
}