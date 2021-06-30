//
//  ConsoleIO.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#include "ConsoleIO.hpp"

std::string ConsoleIO::Read() {
    std::string string;
    std::cin >> string;
    return string;
}

void ConsoleIO::Write(const std::string& string) {
    std::cout << "[IO] " << string << std::endl;
}
