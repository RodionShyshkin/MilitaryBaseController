//
//  Bus.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#ifndef Bus_hpp
#define Bus_hpp

#include <stdio.h>
#include "Vehicle.hpp"

class Bus : public Vehicle {
public:
    Bus(const Bus& bus);
    
    static std::unique_ptr<Bus>     Create(unsigned int people,
                                           unsigned int max_people,
                                           double petrol, double max_petrol);
    
    VehicleData GetVehicleData()    const   override;
    
    bool        Arrive()                    override;
    bool        Leave()                     override;
    
    unsigned int GetMaxPeople()     const;
    unsigned int GetPeople()        const;
    
    bool        SetNewParams(std::optional<double> people, std::optional<double> petrol);
    
private:
    Bus(const VehicleData& data, unsigned int people, unsigned int max_people);
    
private:
            VehicleData     data_;
            unsigned int    people_;
    const   unsigned int    max_people_;
};

#endif /* Bus_hpp */
