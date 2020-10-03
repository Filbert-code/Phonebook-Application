#ifndef CONTACT_H
#define CONTACT_H
using namespace std;
#include <iostream>
#include <string>

class Contact
{
    private:
        string fName, lName;
        int phoneNum;
    public:
        Contact() {}
        Contact(string fName, string lName, int phoneNum):
            fName(fName), lName(lName), phoneNum(phoneNum) {}
        // getter and setter functions
        void set_fName(string name) { fName = name; }
        string get_fName() { return fName; }
        void set_lName(string name) { lName = name; }
        string get_lName() { return lName; }
        void set_phoneNum(int num) {}
        int get_phoneNum() { return phoneNum; }

        void print() {cout << fName << " " << lName << " " << phoneNum << endl;}

        
};

#endif