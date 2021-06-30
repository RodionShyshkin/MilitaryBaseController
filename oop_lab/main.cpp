//
//  main.cpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#include <iostream>
#include "BaseAPI.hpp"
#include "cli/SimpleCLI.hpp"
#include "cli/io/ConsoleIO.hpp"

int main(int argc, const char * argv[]) {
    /*auto bus = Bus::Create(12, 20, 20, 70);
    auto truck = Truck::Create(300, 400, 30, 80);
    auto truck2 = Truck::Create(300, 400, 30, 80);
    
    BaseAPI::Show();
    auto res = bus->Arrive();
    BaseAPI::Show();
    res = truck->Arrive();
    truck2->Arrive();
    BaseAPI::Show();
    res = bus->Leave();
    BaseAPI::Show();
    truck2 = Truck::Create(600, 1000, 80, 80);
    truck2->Arrive();
    BaseAPI::Show();*/
    
    std::unique_ptr<IOInterface> io = std::make_unique<ConsoleIO>();
    std::unique_ptr<CLI> cli = std::make_unique<SimpleCLI>(std::move(io));
    cli->Start();
    return 0;
}
