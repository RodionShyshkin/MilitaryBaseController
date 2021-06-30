//
//  SimpleCLI.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 30.06.2021.
//

#include "SimpleCLI.hpp"
#include "../core/vehicle/vehicles/Bus.hpp"
#include "../core/vehicle/vehicles/Truck.hpp"
#include "../core/vehicle/vehicles/Car.hpp"

SimpleCLI::SimpleCLI(std::unique_ptr<IOInterface> io) : io_(std::move(io)) {}

void SimpleCLI::Start() {
    io_->Write("It could be Command Line Interpreter here, but there isn't due to the fact that the condition of the task does not provide for the creation of a CLI. If I create a CLI, I would do it using \'State\' design pattern.");
    io_->Write("In general case we should use CLI according to SOLID concept to provide independency of different layers and to ensure the inability to gain access from the client side to the kernel components.");
    io_->Write("But in our case we have a deal with some study task, so instead of writing a full-fledged CLI, I inserted code with API function calls here, with which this CLI could work, to demonstrate the functionality of the core.");
    io_->Write("I'm sorry for longread :)");
    io_->Write("---------------------------------");
    io_->Write("");
    
    auto bus = Bus::Create(12, 20, 20, 70);
    auto truck = Truck::Create(300, 400, 30, 80);
    auto truck2 = Truck::Create(300, 400, 30, 80);
    auto car = Car::Create(20, 80);
    
    io_->Write(BaseAPI::GetInformation());
    if(!bus->Arrive()) io_->Write("FAIL"); else io_->Write("Bus arrived");
    io_->Write(BaseAPI::GetInformation());
    if(!truck->Arrive()) io_->Write("FAIL"); else io_->Write("Truck arrived");
    if(!truck2->Arrive()) io_->Write("FAIL"); else io_->Write("Truck 2 arrived");
    io_->Write(BaseAPI::GetInformation());
    if(!bus->Leave()) io_->Write("FAIL"); else io_->Write("Bus left");
    io_->Write(BaseAPI::GetInformation());
    truck2 = Truck::Create(600, 1000, 80, 80);
    if(!truck2->Arrive()) io_->Write("FAIL"); else io_->Write("Truck 3 arrived");
    io_->Write(BaseAPI::GetInformation());
    if(!car->Arrive()) io_->Write("FAIL"); else io_->Write("Car arrived");
    io_->Write(BaseAPI::GetInformation());
    bus->SetNewParams(0, std::nullopt);
    if(!bus->Arrive()) io_->Write("FAIL"); else io_->Write("Bus left");
    io_->Write(BaseAPI::GetInformation());
}
