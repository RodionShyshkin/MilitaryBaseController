//
//  VehicleData.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#ifndef VehicleData_hpp
#define VehicleData_hpp

#include <stdio.h>
#include <optional>

class VehicleData {
public:
    VehicleData();
    VehicleData(const VehicleData& data);
    
    static std::optional<VehicleData> Create(double tank_volume, double petrol_amount);
    
    double  GetTankVolume()     const;
    double  GetPetrolAmount()   const;
    bool    GetOnBaseFlag()     const;
    
    bool    SetPetrolAmount(double value);
    void    SetOnBaseFlag(bool value);
    
private:
    VehicleData(double tank_volume, double petrol_amount);
    
private:
    const   double  tank_volume_;
            double  petrol_amount_;
            bool    on_base_flag_;
};

#endif /* VehicleData_hpp */
