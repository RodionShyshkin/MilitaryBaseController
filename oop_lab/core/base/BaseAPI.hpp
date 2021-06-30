//
//  BaseAPI.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#ifndef BaseAPI_hpp
#define BaseAPI_hpp

#include <stdio.h>
#include "Base.hpp"

class BaseAPI {
public:
    static unsigned int GetPeopleAmount();
    static unsigned int GetVehiclesAmount();
    static double GetPetrolAmount();
    static double GetGoodsAmount();
    
    static bool AddPeople(unsigned int amount);
    static bool RemovePeople(unsigned int amount);
    
    static bool AddVehicle();
    static bool RemoveVehicle();
    
    static bool AddPetrol(double amount);
    static bool RemovePetrol(double amount);
    
    static bool AddGoods(double amount);
    static bool RemoveGoods(double amount);
    
    static bool CheckAddVehicle();
    static bool CheckRemoveVehicle();
    static bool CheckAddPeople(unsigned int amount);
    static bool CheckRemovePeople(unsigned int amount);
    static bool CheckAddGoods(double amount);
    static bool CheckRemoveGoods(double amount);
    static bool CheckAddPetrol(double amount);
    static bool CheckRemovePetrol(double amount);
    
    static std::string GetInformation();
};

#endif /* BaseAPI_hpp */
