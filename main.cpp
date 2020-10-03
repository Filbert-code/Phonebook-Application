#include <iostream>
#include <fstream>
#include "Contact.h"

int main()
{
    // file extract variables
    string fName, lName;
    int phoneNum;
    ifstream file("phonebook.txt");

    // ----- getting number of lines in the file
    string line;
    int size;
    while(getline(file, line))
        size++;
    size--;
    // ----->

    int **arr = new int*[size]; // creating a 2d array
    for(int i = 0; i < size; ++i)
        arr[i] = new int[3]; // each subarray stores 3 values

    string fName, lName;
    int phoneNum;
    for(int i = 0; i < 5; ++i)
    {
        file >> fName >> lName >> phoneNum;
        
    }

    //file >> fName >> lName >> phoneNum;
    //cout << fName << " " << lName << " " << phoneNum << endl;


}