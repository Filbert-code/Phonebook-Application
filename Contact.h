// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
// Class purpose: 
//      To create an object that holds a first name, last name, and phone
//      number. 
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
        Contact() {} // default constructor
        // constructor that initializes private member variables
        Contact(string fName, string lName, int phoneNum):
            fName(fName), lName(lName), phoneNum(phoneNum) {}
        // getter and setter functions
        void set_fName(string name) { fName = name; }
        string get_fName() { return fName; }
        void set_lName(string name) { lName = name; }
        string get_lName() { return lName; }
        void set_phoneNum(int num) {}
        int get_phoneNum() { return phoneNum; } 
};

#endif