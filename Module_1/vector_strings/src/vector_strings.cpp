#include "vector_strings.hpp"

#include <iostream>
#include <vector>

void Adder(std::vector<std::string>& names) {
    std::string name;
    std::cout << "Enter a name:" << std::endl;
    std::cin >> name;
    names.push_back(name);

    std::cout << "Number of names in the vector:" << std::endl
            << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
    std::cout << "Removing the last element:" << std::endl
            << names.back() << std::endl;
    names.pop_back();
}

void Printer(std::vector<std::string>& names) {
    for (unsigned int i=0; i<names.size(); i++) {
        std::cout << names[i] << std::endl;
    }
}

void CMDReader() {
    std::string command;
    std::vector<std::string> namelist;
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;

    while (true){
        std::cout << "Enter a command:" << std::endl;
        std::cin >> command;

        if (command == "ADD"){
            Adder(namelist);
        }
        
        if (command == "PRINT"){
            Printer(namelist);
        }

        if (command == "REMOVE"){
            Remover(namelist);
        }

        if (command == "QUIT"){
            return;
        }
    }


    
}

