#include <iostream>
#include <fstream>
#include <string>

std::string find_replace(std::string string, std::string s1, std::string s2)
{
    std::size_t found = 0;
    while (found != std::string::npos)
    {
        found = string.find(s1, found);
        if (found != std::string::npos)
        {
            string.erase(found, s1.length());
            string.insert(found, s2);
            found += s2.length();
        }
    }
    return (string);
}

int main(int argc, char **argv)
{
    std::string texte;
    std::string inFile;
    std::string newFile;
    std::fstream ifs(inFile);

    if (argc < 3 || argc > 4)
        return (0);
    if (argv[2][0] == '\0')
        return (0);
    inFile = argv[1];
    newFile = inFile;
    ifs.open(inFile);
    if (ifs.fail())
    {
        std::cout << "Bad file..!" << std::endl;
        return (1);
    }
    if (ifs.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "File is empty..!" << std::endl;
        return (1);
    }
    newFile = newFile.append(".replace");


    std::ofstream ofs(newFile);

    while(std::getline(ifs, texte))
    {
        ofs << find_replace(texte, argv[2], argv[3]);
        if (ifs.peek() != std::ifstream::traits_type::eof())
            ofs << std::endl;
    }
    ifs.close();
    return (0);
}
