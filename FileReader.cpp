#include "fileReader.h"


FileReader::FileReader(){};

std::vector<std::vector<int>> FileReader::readFile(std::string path)
{
    // 5 colonnes dans les txt
    // 16 character par colonne dans les txt

    std::fstream newfile;
    std::vector<std::vector<int>> tab;
    std::string result = "";
    tab.resize(5);

    int i = 0;
    int j = 0;

    newfile.open(path, std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) { //checking whether the file is open
        std::string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            /*std::cout << tp << std::endl;*/ //print the data of the string
            result += tp;
        }
    }
    newfile.close(); //close the file object.

    while (i < 5)
    {
        if (result[j] == *" ")
        {
            tab[i][j] = 0;
        }
        else if (result[j] == *"&")
        {
            tab[i][j] = -1;
            i++;
            j = 0;
        }
        else
        {
            tab[i][j] = std::stoi(&result[j]);
        }
        j++;
    }
   

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
        std::cout << "pass";
        std::cout << std::endl;
    }


    return tab;
}