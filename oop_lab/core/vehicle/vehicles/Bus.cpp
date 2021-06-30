//
//  Bus.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#include "Bus.hpp"

Bus::Bus(const VehicleData& data, unsigned int people, unsigned int max_people) : data_(data), max_people_(max_people), people_(people) {
    
}

Bus::Bus(const Bus& bus) : max_people_(bus.GetMaxPeople()), people_(bus.GetPeople()),
                            data_(VehicleData::Create(bus.GetVehicleData().GetTankVolume(),
                                                      bus.GetVehicleData().GetPetrolAmount()).value()){

}

std::unique_ptr<Bus> Bus::Create(unsigned int people,
                                 unsigned int max_people,
                                 double petrol, double max_petrol) {
    if(people > max_people) return nullptr;
    auto vehicle_data = VehicleData::Create(max_petrol, petrol);
    if(!vehicle_data.has_value()) return nullptr;
    auto instance = Bus{vehicle_data.value(), people, max_people};
    return std::make_unique<Bus>(instance);
}

bool Bus::Arrive() {
    if(!BaseAPI::CheckAddVehicle()) return false;
    if(!BaseAPI::CheckAddPeople(people_ + 1)) return false;
    if(!BaseAPI::CheckAddPetrol(data_.GetPetrolAmount())) return false;
    if(data_.GetOnBaseFlag()) return false;
    
    BaseAPI::AddPeople(people_ + 1);
    BaseAPI::AddPetrol(data_.GetPetrolAmount());
    BaseAPI::AddVehicle();
    
    data_.SetOnBaseFlag(true);
    data_.SetPetrolAmount(0.0);
    people_ = 0;
    return true;
}


bool Bus::Leave() {
    if(!BaseAPI::CheckRemoveVehicle()) return false;
    if(!BaseAPI::CheckRemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount())) return false;
    if(!BaseAPI::CheckRemovePeople(1)) return false;
    if(!data_.GetOnBaseFlag()) return false;
    
    auto people_need = max_people_ - people_ + 1;
    if(BaseAPI::GetPeopleAmount() >= people_need) {
        BaseAPI::RemovePeople(people_need);
        people_ = max_people_;
    }
    else {
        people_ += BaseAPI::GetPeopleAmount();
        BaseAPI::RemovePeople(BaseAPI::GetPeopleAmount());
    }
    
    BaseAPI::RemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount());
    BaseAPI::RemoveVehicle();
    
    data_.SetPetrolAmount(data_.GetTankVolume());
    data_.SetOnBaseFlag(false);
    return true;
}

VehicleData Bus::GetVehicleData() const {
    return data_;
}

unsigned int Bus::GetMaxPeople() const {
    return max_people_;
}

unsigned int Bus::GetPeople() const {
    return people_;
}

bool Bus::SetNewParams(std::optional<double> people, std::optional<double> petrol) {
    if(people.has_value()) {
        if(people.value() <= max_people_) people_ = people.value();
        else return false;
    }
    if(petrol.has_value()) {
        return data_.SetPetrolAmount(petrol.value());
    }
    return true;
}
