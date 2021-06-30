//
//  Vehicle.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <memory>
#include "../base/BaseAPI.hpp"
#include "VehicleData.hpp"

class Vehicle {
public:
    virtual         ~Vehicle() = default;
    
    virtual VehicleData GetVehicleData() const = 0;
    
    virtual bool    Leave() = 0;
    virtual bool    Arrive() = 0;
};

#endif /* Vehicle_hpp */
