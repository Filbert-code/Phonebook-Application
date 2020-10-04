// Author: Alex Filbert
// Date: 10/4/2020
// Course: CS 300B
// Assignment: Homework 1
#include <fstream>
#include "Contact.h"
#include "Phonebook.h"

/*
    Instantiates a Phonebook object and runs the user interactive loop.
*/
int main()
{
    Phonebook pb("phonebook.txt"); // instantiate a Phonebook object
    pb.run(); // start user interactive loop
}