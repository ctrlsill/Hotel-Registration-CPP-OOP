#include "cRentUnit.hpp"
#include <iostream>


//=============== CONSTRUCTORS =======================




cRentUnit::cRentUnit()
{
    //std::cout<<"cRentUnit: Constructor called"<<std::endl;
}

//=============== DESTRUCTOR ==========================



cRentUnit::~cRentUnit()
{
   // std::cout<<"cRentUnit: Destructor called"<<std::endl;

}


//=============== OTHER METHODS ==========================


void cRentUnit::info() const
{
    for(int i=0; i<12; i++)
    {
        std::cout<<"===";
    }
    std::cout<<std::endl;
    std::cout<<"ID: "<<this->getID()<<std::endl;
    std::cout<<"Type: "<<this->getType()<<std::endl;
    std::cout<<"Status: "<<this->getStatus()<<std::endl;
    std::cout<<"PricePD: "<<this->getPricePD()<<std::endl;
    std::cout<<"Slots: "<<this->getSlots()<<std::endl;
    for(int i=0; i<12; i++)
    {
        std::cout<<"===";
    }
    std::cout<<std::endl;
    
}
//================== SETTERS ============================


void cRentUnit::setPricePD(int aPrice)
{
    
        this->mPricePD = abs(aPrice);
    
}




void cRentUnit::setStatus(int aStatus)
{
    if(aStatus == 0 or aStatus == 1 or aStatus == 2)
    {
        this->mStatus = aStatus;
    }
}



void cRentUnit::setSlots(int aSlots)
{
    mSlots = aSlots;
}


//================== GETTERS ============================

int cRentUnit::getID() const
{
    return mID;
}


std::string cRentUnit::getType() const
{
    return mType;
}



int cRentUnit::getPricePD() const
{
    return mPricePD;
}




int cRentUnit::getStatus() const
{
    return mStatus;
}




int cRentUnit::getSlots() const
{
    return mSlots;
}

