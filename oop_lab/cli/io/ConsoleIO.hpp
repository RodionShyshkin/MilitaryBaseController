//
//  ConsoleIO.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef ConsoleIO_hpp
#define ConsoleIO_hpp

#include <stdio.h>
#include <iostream>
#include "IOInterface.hpp"

class ConsoleIO : public IOInterface {
public:
    std::string     Read()                              override;
    void            Write(const std::string &string)    override;
};

#endif /* ConsoleIO_hpp */
