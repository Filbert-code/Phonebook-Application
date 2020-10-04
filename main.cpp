#include <fstream>
#include "Contact.h"
#include "Phonebook.h"


int main()
{
    Phonebook pb("phonebook.txt");
    pb.add("Alex", "Filbert", 2068491090);
    pb.print();
}