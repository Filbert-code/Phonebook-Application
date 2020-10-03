#ifndef PHONEBOOK_H
#define PHONEBOOK_H
using namespace std;
#include <string>

class Phonebook
{
    private:
        string fileName;
    public:
        Phonebook() {}
        Phonebook(string fileName):fileName(fileName) {}
        int get_file_length();
        
};

#endif