#include <fstream>
#include "Contact.h"
#include "Phonebook.h"


int main()
{
    Phonebook pb("phonebook.txt");

    pb.list();
    pb.update_phonebook();
    //pb.print();
}