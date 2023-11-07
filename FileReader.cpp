#include "fileReader.h"


FileReader::FileReader(){};

void FileReader::readFile(std::string path)
{
    // 5 colonnes dans les txt
    // 16 character par colonne dans les txt

    std::fstream newfile;
    std::string result = "";
    _tabFile.resize(5);

    int i = 0;
    int j = 0;

    newfile.open(path, std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) { //checking whether the file is open
        std::string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            result += tp; // incr�mentation d'une string � partir du fichier txt
        }
    }
    newfile.close(); //close the file object.


    /* incr�mentation du tableau � parti des valeurs pr�sentes dans le fichier txt */
    while (i < 5)
    {
        if (result[j] == *" ")
        {
            _tabFile[i].push_back(0);
        }
        else if (result[j] == *"&")
        {
            _tabFile[i].push_back(- 1);
            i++;
        }
        else
        {
           _tabFile[i].push_back(result[j] - 48);
        }
        j++;
    }

}


bool FileReader::compareFileRead(std::vector<std::vector<int>> startFile)
{
    /* Comparaison entre deux tableaux des valeurs enregistrer depuis un fichier txt */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (_tabFile[i][j] != startFile[i][j])
            {
                return false;
            }
        }
    }
    return true;
}