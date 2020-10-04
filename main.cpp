#include <fstream>
#include "Contact.h"
#include "Phonebook.h"


int main()
{
    Phonebook pb("phonebook.txt");
    pb.print();
}