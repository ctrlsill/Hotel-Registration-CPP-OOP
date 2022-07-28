
#include "cRoom.hpp"
#include "MainMenu.hpp"
#include <iostream>
#include <ctime>
#include <vector>

//=============== CONSTRUCTORS =======================
//int mID;
//int mPricePD;
//int mSlots;
//char mStatus;
//char mType;

cRoom::cRoom(std::string aType, MainMenu& aMENU)
{
   // std::cout<<"cRoom: Constructor called"<<std::endl;
   
    
    //ID in range (0; 10000)
    this->mID = aMENU.generateID(aMENU.vRooms);
    this->setStatus(0);

    
    if(this->setType(aType) == false)
    {
        this->setType("S");
    }
   


}





//=============== DESTRUCTOR ==========================

cRoom::~cRoom()
{
    //std::cout<<"cRoom: Destructor called"<<std::endl;

}



//=============== OTHER METHODS ==========================





//================= SETTERS ============================




bool cRoom::setType(std::string aType)
{
    if(aType == "S")
    {
        this->mType = aType;
        this->setSlots(1);
        this->setPricePD(10);
        return true;
    }
    if(aType == "D")
    {
        this->mType = aType;
        this->setSlots(2);
        this->setPricePD(20);
        return true;
    }
    if(aType == "T")
    {
        this->mType = aType;
        this->setSlots(3);
        this->setPricePD(30);
        return true;
    }
    if(aType == "Q")
    {
        this->mType = aType;
        this->setSlots(4);
        this->setPricePD(40);
        return true;
    }
    
    return false;
}



//================== GETTERS ============================


