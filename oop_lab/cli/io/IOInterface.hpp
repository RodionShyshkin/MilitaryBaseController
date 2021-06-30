//
//  IOInterface.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef IOInterface_hpp
#define IOInterface_hpp

#include <stdio.h>
#include <string>

class IOInterface {
public:
    virtual ~IOInterface() = default;
    
    virtual std::string Read() = 0;
    virtual void Write(const std::string& string) = 0;
};

#endif /* IOInterface_hpp */
