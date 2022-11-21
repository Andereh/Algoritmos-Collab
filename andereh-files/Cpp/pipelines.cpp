#include <iostream>

int main(int argc, char *argv[])
{
    char txt[100];
    std::cin.getline(txt, 100);

    std::cout << "Has Introducido: " << txt << std::endl;
    return 0;
}

