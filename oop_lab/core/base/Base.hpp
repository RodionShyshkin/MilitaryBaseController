//
//  Base.hpp
//  oop_lab
//
//  Created by Rodion Shyshkin on 29.06.2021.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>
#include <string>

struct Base {
public:
    const static unsigned int PEOPLE_MAX_ = 600;
    const static unsigned int VEHICLES_MAX_ = 120;
    constexpr const static double PETROL_MAX_ = 3000.67;
    constexpr const static double GOODS_MAX_ = 8000.43;
    const static unsigned int PEOPLE_DEFAULT_ = 0;
    const static unsigned int VEHICLES_DEFAULT_ = 0;
    constexpr const static double PETROL_DEFAULT_ = 0.0;
    constexpr const static double GOODS_DEFAULT_ = 0.0;
    
    friend class BaseAPI;
    
private:
    static unsigned int people_on_base_;
    static unsigned int vehicles_on_base_;
    static double petrol_on_base_;
    static double goods_on_base_;
};

#endif /* Base_hpp */
