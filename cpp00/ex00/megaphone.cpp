#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "\033[1;31m" << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\033[0;37m";
    else
        for (int i = 1; argv[i]; i++)
            for (int j = 0; argv[i][j]; j++)
                if (isascii(argv[i][j]))
                    std::cout << "\033[1;37m" << static_cast<char>(std::toupper(argv[i][j]));
                else
                    std::cout << static_cast<char>(std::toupper(argv[i][j]));
    std::cout << std::endl;
}
