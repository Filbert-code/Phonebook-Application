#include <fstream>
#include "Contact.h"
#include "Phonebook.h"


int main()
{
    Phonebook pb("phonebook.txt");
    pb.add("Alex", "Filbert", 2068491090);
    pb.print();
    pb.remove("ELIZABETH", "JONES");
    pb.remove("Alex", "Filbert"); 
    pb.remove("MAUD", "SHAFRON");
    pb.update_phonebook();
    pb.print();
}