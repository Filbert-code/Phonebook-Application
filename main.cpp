#include <iostream>
#include <fstream>
#include "Contact.h"

int main()
{
    // file extract variables
    ifstream file("phonebook.txt");

    // ----- getting number of lines in the file
    string line;
    int size;
    while(getline(file, line))
        size++;
    size--;
    // get back to the beginning of the file
    file.clear();
    file.seekg(0);
    // ----->

    Contact *arr = new Contact[size]; // creating a 2d array

    // ----- creating an array of Contact objects with file data
    string fName, lName;
    int phoneNum;
    for(int i = 0; i < size + 1; ++i)
    {
        file >> fName >> lName >> phoneNum;
        Contact contact(fName, lName, phoneNum);
        arr[i] = contact;
    }

    

    //file >> fName >> lName >> phoneNum;
    //cout << fName << " " << lName << " " << phoneNum << endl;


}