#ifndef cApartment_hpp
#define cApartment_hpp


#include "cRentUnit.hpp"
class MainMenu;


class cApartment : public cRentUnit
{
public:
    explicit cApartment(std::string, MainMenu&);
    ~cApartment();

    bool setType(std::string);
    
};

#endif 
