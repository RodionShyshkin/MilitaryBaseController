//
//  Car.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#include "Car.hpp"

Car::Car(const Car& car) : data_(VehicleData::Create(car.GetVehicleData().GetTankVolume(),
                                    car.GetVehicleData().GetPetrolAmount()).value()){

}

Car::Car(const VehicleData& data) : data_(data) {
    
}

std::unique_ptr<Car> Car::Create(double petrol, double max_petrol) {
    auto vehicle_data = VehicleData::Create(max_petrol, petrol);
    if(!vehicle_data.has_value()) return nullptr;
    auto instance = Car{vehicle_data.value()};
    return std::make_unique<Car>(instance);
}

VehicleData Car::GetVehicleData() const {
    return data_;
}

bool Car::Arrive() {
    if(!BaseAPI::CheckAddVehicle()) return false;
    if(!BaseAPI::CheckAddPeople(1)) return false;
    if(!BaseAPI::CheckAddPetrol(data_.GetPetrolAmount())) return false;
    if(data_.GetOnBaseFlag()) return false;
    
    BaseAPI::AddPeople(1);
    BaseAPI::AddPetrol(data_.GetPetrolAmount());
    BaseAPI::AddVehicle();
    
    data_.SetOnBaseFlag(true);
    data_.SetPetrolAmount(0.0);
    return true;
}

bool Car::Leave() {
    if(!BaseAPI::CheckRemoveVehicle()) return false;
    if(!BaseAPI::CheckRemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount())) return false;
    if(!BaseAPI::CheckRemovePeople(1)) return false;
    if(!data_.GetOnBaseFlag()) return false;
    
    BaseAPI::RemovePeople(1);
    BaseAPI::RemovePetrol(data_.GetTankVolume() - data_.GetPetrolAmount());
    BaseAPI::RemoveVehicle();
    
    data_.SetPetrolAmount(data_.GetTankVolume());
    data_.SetOnBaseFlag(false);
    return true;
}

bool Car::SetNewParams(std::optional<double> petrol) {
    if(petrol.has_value()) {
        return data_.SetPetrolAmount(petrol.value());
    }
    return true;
}
