
#ifndef cRoom_hpp
#define cRoom_hpp

#include <vector>
#include <string>
#include "cRentUnit.hpp"

class MainMenu;

class cRoom : public cRentUnit
{
public:
    explicit cRoom(std::string, MainMenu& aMENU);
    ~cRoom();

    bool setType(std::string);


};


#endif 
