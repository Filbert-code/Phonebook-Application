#include <fstream>
#include "Contact.h"
#include "Phonebook.h"

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

    Contact *arr = new Contact[size];

    // ----- creating an array of Contact objects with file data
    string fName, lName;
    int phoneNum;
    for(int i = 0; i < size + 1; ++i)
    {
        file >> fName >> lName >> phoneNum;
        Contact contact(fName, lName, phoneNum);
        arr[i] = contact;
    }

    Phonebook pb("phonebook.txt");
    pb.print();

    //file >> fName >> lName >> phoneNum;
    //cout << fName << " " << lName << " " << phoneNum << endl;


}