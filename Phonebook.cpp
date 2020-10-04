// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
// Class purpose: 
//      To make an object that will create a dynamic array of Contact objects 
//      with functions to add, search, delete, and list the contents of the 
//      array. 
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
    if(capacity == 0) // if the file is empty, initialize the Contact array with 5 elements
        capacity = 5;
    this->numOfContacts = size; // Total number of contact entries
    this->arr = new Contact[capacity];
    fillArray(arr, numOfContacts);
}

/*
    Destructor for deleting the dynamic Contact array.
*/
Phonebook::~Phonebook()
{
    delete[] arr;
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

/*
    Appends a Contact object to the phonebook array. Doubles the capacity
    of the array when trying to add past capacity. 
*/
void Phonebook::add(string fName, string lName, int phoneNum)
{
    // check if all strings arguments are uppercase
    if(!name_uppercase_check(fName, lName))
        {
            cout << "Enter names in uppercase letters." << endl;
            return;
        }
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
    if(!name_uppercase_check(fName, lName))
    {
        cout << "Enter names in uppercase letters." << endl;
        return;
    }
        
    for(int i = 0; i < numOfContacts; i++)
    {
        if(arr[i].get_fName() == fName && arr[i].get_lName() == lName)
        {
            --numOfContacts;
            // shift all array elements 1 position to the left
            for(int k = i; k < numOfContacts; ++k)
                arr[k] = arr[k + 1];
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
    Outputs the first 5 contact entries to the console
*/
void Phonebook::list()
{
    int listSize = 5;
    // if the Contact array has less Contacts than listSize, set listSize = (num of Contacts)
    if((numOfContacts + 1) < listSize)
        listSize = numOfContacts;
    // if Contact array is empty, output to console
    if(listSize == 0)
    {
        cout << "<Empty>" << endl;
        return;
    }
    // output Contact information to console
    for(int i = 0; i < listSize; ++i)
        cout << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    if(listSize >= 5)
        cout << "..." << endl;
}

/*
    Updates the phonebook.txt file when the user exits the program.
*/
void Phonebook::update_phonebook()
{
    ofstream file(fileName, ofstream::trunc); // deletes all contents of the file
    for(int i = 0; i < numOfContacts - 1; ++i) // repopulate the file with the current array state
    {
        file << arr[i].get_fName() << " " << arr[i].get_lName() << " " << arr[i].get_phoneNum() << endl;
    }
    int num = numOfContacts - 1; // shortening the var name for better readability
    if(numOfContacts != 0)
        // last line of the file; won't return the last line
        file << arr[num].get_fName() << " " << arr[num].get_lName() << " " << arr[num].get_phoneNum();
}

/*
    Checks the inputed string whether all letters are uppercase or not.
*/
bool Phonebook::is_all_upper(string& word)
{
    for(char& c: word) 
        if(!isupper(static_cast<unsigned char>(c))) 
            return false;
    return true;
}

/*
    Returns a boolean true if all string arguments are uppercase; 
    returns false and outputs a warning message otherwise. 
*/
bool Phonebook::name_uppercase_check(string fName, string lName)
{
    // check if all string arguments are uppercase
    if(!is_all_upper(fName) || !is_all_upper(lName))
        return false;
    return true;
}

/*
    Searches the Contact array and returns a boolean specifying whether
    the given name already exists in the Contact array. 
*/
bool Phonebook::check_if_name_exists(string fName, string lName)
{
    int phoneNum = search(fName, lName);
    if(phoneNum != -1)
        return true;
    else 
        return false;
}

/*
    A switch case for the run() function. Captures user input for 
    adding a new Contact object to the Contact array. 
*/
void Phonebook::run_switch_add_case()
{
    cout << "Enter name: ";
    string fNameInput, lNameInput;
    cin >> fNameInput >> lNameInput;
    cout << "Enter phone: ";
    int phoneInput;
    cin >> phoneInput;

    // checks if user is creating a duplicate contact
    if(!check_if_name_exists(fNameInput, lNameInput))
        add(fNameInput, lNameInput, phoneInput);
}

/*
    A switch case for the run() function. Captures user input for 
    searching and then outputting the corresponding phone number to console. 
*/
void Phonebook::run_switch_search_case()
{
    cout << "Enter name: ";
    string fNameInput, lNameInput;
    cin >> fNameInput >> lNameInput;
    // checks if the inputs are in uppercase
    if(!name_uppercase_check(fNameInput, lNameInput))
    {
        cout << "Enter operations in uppercase letters." << endl;
        return;
    }
    // checks if the name exists in the array
    if(check_if_name_exists(fNameInput, lNameInput))
        cout << "Phone number: " << search(fNameInput, lNameInput) << endl;
    else 
        cout << "Name not found." << endl;
}

/*
    A switch case for the run() function. Captures user input for 
    name of Contact to delete and deletes the Contact if it exists. 
*/
void Phonebook::run_switch_del_case()
{
    cout << "Enter name: ";
    string fNameInput, lNameInput;
    cin >> fNameInput >> lNameInput;
    // checks if the inputs are in uppercase
    if(!name_uppercase_check(fNameInput, lNameInput))
    {
        cout << "Enter operations in uppercase letters." << endl;
        return;
    }
    // checks if there is a matching name in the array to delete
    if(check_if_name_exists(fNameInput, lNameInput))
        remove(fNameInput, lNameInput);
    else
        cout << "Name not found." << endl;
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
                run_switch_add_case();
                break;
            }
            case 'S': 
            {
                // search case
                run_switch_search_case();
                break;
            }
            case 'D':
            {
                // delete case
                run_switch_del_case();
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