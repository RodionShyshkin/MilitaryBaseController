//
//  Truck.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef Truck_hpp
#define Truck_hpp

#include <stdio.h>
#include "../Vehicle.hpp"

class Truck : public Vehicle {
public:
    Truck(const Truck& truck);
    
    static std::unique_ptr<Truck>   Create(double load, double max_load,
                                         double petrol, double max_petrol);
    
    VehicleData GetVehicleData()    const   override;
    
    bool        Arrive()                    override;
    bool        Leave()                     override;
    
    double      GetMaxLoad()        const;
    double      GetLoad()           const;
    
    bool        SetNewParams(std::optional<double> load, std::optional<double> petrol);
    
private:
    Truck(const VehicleData& data, double load, double max_load);
    
private:
            VehicleData     data_;
            double          load_;
    const   double          max_load_;
};

#endif /* Truck_hpp */
