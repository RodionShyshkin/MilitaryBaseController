//
//  Truck.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#include "Truck.hpp"

Truck::Truck(const Truck& truck) : max_load_(truck.GetMaxLoad()), load_(truck.GetLoad()),
                                    data_(VehicleData::Create(truck.GetVehicleData().GetTankVolume(),
                                    truck.GetVehicleData().GetPetrolAmount()).value()){

}

Truck::Truck(const VehicleData& data, double load, double max_load) : data_(data), max_load_(max_load), load_(load) {
    
}

std::unique_ptr<Truck> Truck::Create(double load, double max_load,
                                     double petrol, double max_petrol) {
    if(load > max_load) return nullptr;
    auto vehicle_data = VehicleData::Create(max_petrol, petrol);
    if(!vehicle_data.has_value()) return nullptr;
    auto instance = Truck{vehicle_data.value(), load, max_load};
    return std::make_unique<Truck>(instance);
}

VehicleData Truck::GetVehicleData() const {
    return data_;
}

double Truck::GetLoad() const {
    return load_;
}

double Truck::GetMaxLoad() const {
    return max_load_;
}

bool Truck::Arrive() {
    if(!BaseAPI::CheckAddVehicle()) return false;
    if(!BaseAPI::CheckAddGoods(load_)) return false;
    if(!BaseAPI::CheckAddPeople(1)) return false;
    if(!BaseAPI::CheckAddPetrol(data_.GetPetrolAmount())) return false;
    if(data_.GetOnBaseFlag()) return false;
    
    BaseAPI::AddGoods(load_);
    BaseAPI::AddPeople(1);
    BaseAPI::AddPetrol(data_.GetPetrolAmount());
    BaseAPI::AddVehicle();
    
    data_.SetOnBaseFlag(true);
    data_.SetPetrolAmount(0.0);
    load_ = 0;
    return true;
}

bool Truck::Leave() {
    if(!BaseAPI::CheckRemoveVehicle()) return false;
    if(!BaseAPI::CheckRemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount())) return false;
    if(!BaseAPI::CheckRemovePeople(1)) return false;
    if(!data_.GetOnBaseFlag()) return false;
    
    auto load_need = max_load_ - load_ + 1;
    if(BaseAPI::GetPeopleAmount() >= load_need) {
        load_ = max_load_;
        BaseAPI::RemoveGoods(load_need);
    }
    else {
        load_ += BaseAPI::GetGoodsAmount();
        BaseAPI::RemoveGoods(BaseAPI::GetGoodsAmount());
    }
    
    BaseAPI::RemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount());
    BaseAPI::RemoveVehicle();
    
    data_.SetPetrolAmount(data_.GetTankVolume());
    data_.SetOnBaseFlag(false);
    return true;
}

bool Truck::SetNewParams(std::optional<double> load, std::optional<double> petrol) {
    if(load.has_value()) {
        if(load.value() <= max_load_) load_ = load.value();
        else return false;
    }
    if(petrol.has_value()) {
        return data_.SetPetrolAmount(petrol.value());
    }
    return true;
}
