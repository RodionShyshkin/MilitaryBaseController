//
//  CLI.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef CLI_hpp
#define CLI_hpp

#include <stdio.h>

class CLI {
public:
    virtual ~CLI() = default;
    
    virtual void Start() = 0;
};

#endif /* CLI_hpp */
