#include <iostream>
#include "cApartment.hpp"
#include "MainMenu.hpp"


//=============== CONSTRUCTORS =======================



cApartment::cApartment(std::string aType, MainMenu& aMENU)
{
    //std::cout<<"cRoom: Constructor called"<<std::endl;
    
    //ID in range (1000; 2000)
    this->mID = aMENU.generateID(aMENU.vApartments);

    this->setStatus(0);
    
    
    if(this->setType(aType) == false)
    {
        this->setType("T0");
    }
    
    
    
    
}





//=============== DESTRUCTOR ==========================

cApartment::~cApartment()
{
    //std::cout<<"cApartment: Destructor called"<<std::endl;
    
}



//=============== OTHER METHODS ==========================




//================= SETTERS ============================




bool cApartment::setType(std::string aType)
{

    if(aType == "T0")
    {
        this->mType = aType;
        this->setSlots(2);
        this->setPricePD(30);
        return true;
    }
    if(aType == "T1")
    {
        this->mType = aType;
        this->setSlots(4);
        this->setPricePD(60);
        return true;
    }
    if(aType == "T2")
    {
        this->mType = aType;
        this->setSlots(6);
        this->setPricePD(90);
        return true;
    }
    if(aType == "T3")
    {
        this->mType = aType;
        this->setSlots(8);
        this->setPricePD(120);
        return true;
    }

    return false;
}



//================== GETTERS ============================




