//
//  SimpleCLI.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef SimpleCLI_hpp
#define SimpleCLI_hpp

#include <stdio.h>
#include <memory>
#include "CLI.hpp"
#include "io/IOInterface.hpp"
#include "../core/base/BaseAPI.hpp"

class SimpleCLI : public CLI {
public:
    SimpleCLI(std::unique_ptr<IOInterface> io);
    
    void Start() override;
    
private:
    std::unique_ptr<IOInterface> io_;
};

#endif /* SimpleCLI_hpp */
