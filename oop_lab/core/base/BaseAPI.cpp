//
//  BaseAPI.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#include "BaseAPI.hpp"

bool BaseAPI::AddPeople(unsigned int amount) {
    if(!CheckAddPeople(amount)) return false;
    Base::people_on_base_ += amount;
    return true;
}

bool BaseAPI::RemovePeople(unsigned int amount) {
    if(!CheckRemovePeople(amount)) return false;
    Base::people_on_base_ -= amount;
    return true;
}

bool BaseAPI::AddVehicle() {
    if(!CheckAddVehicle()) return false;
    Base::vehicles_on_base_++;
    return true;
}

bool BaseAPI::RemoveVehicle() {
    if(!CheckRemoveVehicle()) return false;
    Base::vehicles_on_base_--;
    return true;
}

bool BaseAPI::AddPetrol(double amount) {
    if(!CheckAddPetrol(amount)) return false;
    Base::petrol_on_base_ += amount;
    return true;
}

bool BaseAPI::RemovePetrol(double amount) {
    if(!CheckRemovePetrol(amount)) return false;
    Base::petrol_on_base_ -= amount;
    return true;
}

bool BaseAPI::AddGoods(double amount) {
    if(!CheckAddGoods(amount)) return false;
    Base::goods_on_base_ += amount;
    return true;
}

bool BaseAPI::RemoveGoods(double amount) {
    if(!CheckRemoveGoods(amount)) return false;
    Base::goods_on_base_ -= amount;
    return true;
}

unsigned int BaseAPI::GetPeopleAmount() {
    return Base::people_on_base_;
}

unsigned int BaseAPI::GetVehiclesAmount() {
    return Base::vehicles_on_base_;
}

double BaseAPI::GetPetrolAmount() {
    return Base::petrol_on_base_;
}

double BaseAPI::GetGoodsAmount() {
    return Base::goods_on_base_;
}

bool BaseAPI::CheckAddVehicle() {
    return !(Base::vehicles_on_base_ == Base::VEHICLES_MAX_);
}

bool BaseAPI::CheckRemoveVehicle() {
    return (Base::vehicles_on_base_ != 0);
}

bool BaseAPI::CheckAddPeople(unsigned int amount) {
    return ((Base::people_on_base_ + amount) <= Base::PEOPLE_MAX_);
}

bool BaseAPI::CheckRemovePeople(unsigned int amount) {
    return (Base::people_on_base_ >= amount);
}

bool BaseAPI::CheckAddGoods(double amount) {
    return ((Base::goods_on_base_ + amount) <= Base::GOODS_MAX_);
}

bool BaseAPI::CheckRemoveGoods(double amount) {
    return ((Base::goods_on_base_ - amount) > 0);
}

bool BaseAPI::CheckAddPetrol(double amount) {
    return ((Base::petrol_on_base_ + amount) <= Base::PETROL_MAX_);
}

bool BaseAPI::CheckRemovePetrol(double amount) {
    return ((Base::petrol_on_base_ - amount) > 0);
}

std::string BaseAPI::GetInformation() {
    std::string result = "--- [BASE INFO]\nPeople on base: " + std::to_string(Base::people_on_base_) + "\nVehicles on base: " + std::to_string(Base::vehicles_on_base_) + "\nPetrol on base: " + std::to_string(Base::petrol_on_base_) +
    "\nGoods on base: " + std::to_string(Base::goods_on_base_) + "\n";
    return result;
}
