
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <iostream>
#include <ctime>
#include "cRentUnit.hpp"
#include "cCustomer.hpp"
#include "MainMenu.hpp"


//=============== CONSTRUCTORS =======================


cCustomer::cCustomer(MainMenu& aMENU) : mBill(0), mDays(0), mStatus(0), mPayStatus(0)
{
    //std::cout<<"cCustomer: Constructor called"<<std::endl;
    this->mID = aMENU.generateID(aMENU.vCustomers);
}




//=============== DESTRUCTOR ==========================



cCustomer::~cCustomer()
{
   // std::cout<<"cCustomer: Destructor called"<<std::endl;
}

//=============== OTHER METHODS ==========================


int cCustomer::searchID(int aID)
{
    if(this->vUnitsID.empty())
    {
        return 0;
    }
    for(auto it = this->vUnitsID.begin();  it != this->vUnitsID.end(); ++it)
    {
        if(*it == aID)
        {
            return 1;
        }
    }
    return -1;
}




void cCustomer::info() const
{
    for(int i=0; i<12; i++)
    {
        std::cout<<"===";
    }
    std::cout<<std::endl;
    std::cout<<"ID: "<<this->mID<<std::endl;
    std::cout<<"FirstName: "<<this->mFirstName<<std::endl;
    std::cout<<"LastName: "<<this->mLastName<<std::endl;
    std::cout<<"PhoneNum: "<<this->mPhoneNum<<std::endl;
    std::cout<<"Bill: ";    printf("%.2f\n", this->mBill);
   
    std::cout<<"Days: "<<this->mDays<<std::endl;
    std::cout<<"Status: "<<this->mStatus<<std::endl;
    std::cout<<"PayStatus: "<<this->mPayStatus<<std::endl;
    std::cout<<"Adress: "<<this->mAdress<<std::endl;
    std::cout<<"FromDate: "<<this->mFromDate<<std::endl;
    std::cout<<"ToDate: "<<this->mToDate<<std::endl;
    std::cout<<"RentUnits: ";
    for(auto it = vUnitsID.begin();  it != vUnitsID.end();  ++it)
    {
        std::cout<<*it<<"\t";
    }
    std::cout<<std::endl;
    for(int i=0; i<12; i++)
    {
        std::cout<<"===";
    }
    std::cout<<std::endl;


}




int cCustomer::addUnitID(cRentUnit *Uptr)
{
    if(Uptr->getStatus() == 0)
       {
          vUnitsID.push_back(Uptr->getID());
           return 1;
       }
    return 0;
}





bool cCustomer::rmUnitID(int aID)
{
    if(vUnitsID.empty())
    {
        return false;
    }
 
    
    for(auto it = vUnitsID.begin(); it != vUnitsID.end(); ++it)
    {
        if(*it == aID)
        {
            vUnitsID.erase(it);
            return true;
        }
    }
    
    
    return 0;
}



void cCustomer::clearUnitsID()
{
    this->vUnitsID.clear();
}




//================= SETTERS ============================




void cCustomer::setBill(double aBill)
{
    this->mBill = aBill;
}



void cCustomer::setDays(int aDays)
{
    this->mDays = abs(aDays);
}


int cCustomer::setStatus(int aStatus)
{
    
    //Status: 1 - checked in
    //        0 - checked out
    
    aStatus = toupper(aStatus);
    
    if(aStatus == 0 or aStatus == 1)
    {
        this->mStatus = aStatus;
        return aStatus;
    }
    return -1;
}




int cCustomer::setPayStatus(int aPayStatus)
{
    //PayStatus: 1 - cash in
    //           0 - cash out
    //           2 - waiting,
    
    
    if(aPayStatus == 0 or aPayStatus == 1 or aPayStatus == 2)
    {
        this->mPayStatus = aPayStatus;
        return aPayStatus;
    }
    return -1;
}


void cCustomer::setFirstName(std::string aFirstName)
{
    this->mFirstName = aFirstName;
}




void cCustomer::setLastName(std::string aLastName)
{
    this->mLastName = aLastName;
}




void cCustomer::setPhoneNum(std::string aPhoneNum)
{
    this->mPhoneNum = aPhoneNum;
}


void cCustomer::setAdress(std::string aAdress)
{
    this->mAdress = aAdress;
}


void cCustomer::setFromDate(std::string aFromDate)
{
    this->mFromDate = aFromDate;
}


void cCustomer::setToDate(std::string aToDate)
{
    this->mToDate = aToDate;
}

//================== GETTERS ============================



int cCustomer::getID() const
{
    return (this->mID);
}


int cCustomer::getBill() const
{
    return (this->mBill);
}


int cCustomer::getDays() const
{
    return (this->mDays);
}


int cCustomer::getStatus() const
{
    return (this->mStatus);
}


int cCustomer::getPayStatus() const
{
    return (this->mPayStatus);
}


std::string cCustomer::getFirstName() const
{
    return (this->mFirstName);
}


std::string cCustomer::getLastName() const
{
    return (this->mLastName);
}

std::string cCustomer::getPhoneNum() const
{
    return (this->mPhoneNum);
}

std::string cCustomer::getAdress() const
{
    return (this->mAdress);
}


std::string cCustomer::getToDate() const
{
    return (this->mToDate);
}


std::string cCustomer::getFromDate() const
{
    return (this->mFromDate);
}

const std::vector<int>* cCustomer::getUnitsID() const
{
    const std::vector<int>* ptr = &vUnitsID;
    return ptr;
}
