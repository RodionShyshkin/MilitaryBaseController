//
//  VehicleData.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#include "VehicleData.hpp"

VehicleData::VehicleData() : tank_volume_(0.0), petrol_amount_(0.0), on_base_flag_(false) {}

VehicleData::VehicleData(double tank_volume, double petrol_amount) : petrol_amount_(petrol_amount),
                                                                    tank_volume_(tank_volume),
                                                                    on_base_flag_(false) {
                                                                        
}

VehicleData::VehicleData(const VehicleData& data) : petrol_amount_(data.GetPetrolAmount()),
                                                    tank_volume_(data.GetTankVolume()),
                                                    on_base_flag_(data.GetOnBaseFlag()) {
}

std::optional<VehicleData> VehicleData::Create(double tank_volume, double petrol_amount) {
    if(petrol_amount > tank_volume) return std::nullopt;
    return VehicleData{tank_volume, petrol_amount};\
}

double VehicleData::GetTankVolume() const {
    return tank_volume_;
}

double VehicleData::GetPetrolAmount() const {
    return petrol_amount_;
}

bool VehicleData::GetOnBaseFlag() const {
    return on_base_flag_;
}

bool VehicleData::SetPetrolAmount(double value) {
    if(value > tank_volume_) return false;
    petrol_amount_ = value;
    return true;
}

void VehicleData::SetOnBaseFlag(bool value) {
    on_base_flag_ = value;
}
