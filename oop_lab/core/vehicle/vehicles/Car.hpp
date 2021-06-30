//
//  Car.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "../Vehicle.hpp"

class Car : public Vehicle {
public:
    Car(const Car& car);
    
    static std::unique_ptr<Car>   Create(double petrol, double max_petrol);
    
    VehicleData GetVehicleData()    const   override;
    
    bool        Arrive()                    override;
    bool        Leave()                     override;
    
    bool        SetNewParams(std::optional<double> petrol);
    
private:
    Car(const VehicleData& data);
    
private:
    VehicleData     data_;
};

#endif /* Car_hpp */
