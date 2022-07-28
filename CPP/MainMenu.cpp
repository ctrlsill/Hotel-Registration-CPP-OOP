
#include "MainMenu.hpp"


#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <algorithm>
using namespace std;



//=============== CONSTRUCTORS =======================


MainMenu::MainMenu()
{
    //std::cout<<"MainMenu: Constructor called"<<std::endl;
    
    cRoom* rptr = new cRoom("S", *this);
    vRooms.push_back(rptr);

    cApartment* aptr = new cApartment("T0", *this);
    vApartments.push_back(aptr);

    cCustomer* cptr = new cCustomer(*this);
    vCustomers.push_back(cptr);

    
}

//=============== DESTRUCTOR ==========================

MainMenu::~MainMenu()
{
    //std::cout<<"MainMenu: Destructor called"<<std::endl;

    for(auto it = vRooms.begin(); it != vRooms.end(); ++it)
    {
        delete *it;
    }
   
    for(auto it = vApartments.begin(); it != vApartments.end(); ++it)
    {
        delete *it;
    }
    
    for(auto it = vCustomers.begin(); it != vCustomers.end(); ++it)
    {
        delete *it;
    }

}

//=============== OTHER METHODS ==========================



bool MainMenu::checkIN()
{
    int uID, cID;
    int aDays;
    std::string aDate;
    
    
    cout<<"ENTER CUSTOMER ID: ";
    cin>>cID;
    while(searchCustomerbyID(cID) == nullptr)
    {
        cout<<"[INFO] Customer ID not found. Try again or press <0+ENTER> to exit.\n";
        cout<<"ENTER CUSTOMER ID: ";
        cin>>cID;
        if(cID == 0)
        {
            return false;
        }
    }
    
    cout<<"ENTER UNIT ID: ";
    cin>>uID;
    while(searchUnitbyID(uID) == nullptr)
    {
        cout<<"[INFO] Unit ID not found. Try again or press <0+ENTER> to exit.\n";
        cout<<"ENTER UNIT ID: ";
        cin>>cID;
        if(cID == 0)
        {
            return false;
        }
    }
    
   
    cCustomer* aCustomer = searchCustomerbyID(cID);
    cRentUnit* aUnit     = searchUnitbyID(uID);
    
    if(aUnit->getStatus() != 0)
    {
        std::cout<<"\n[INFO] Checking in failed. Unit is not free.\n";
        return false;
    }
    
    cout<<"ENTER FROM DATE (DD/MM/YYYY):";   cin>>aDate;
    cout<<"ENTER DAYS: ";                    cin>>aDays;

    
    aCustomer->setFromDate(aDate);
    aCustomer->setDays(abs(aDays));
    aCustomer->addUnitID(aUnit);
    aCustomer->setStatus(1);
    aCustomer->setBill(aCustomer->getBill()+(aUnit->getPricePD() * abs(aDays)));
    aUnit->setStatus(1);
    std::cout<<"\n[INFO] Checked in succesfully.\n";

    return true;
}



bool MainMenu::checkOUT()
{
    int cID;
   
    cout<<"ENTER CUSTOMER ID: ";
    cin>>cID;
    while(searchCustomerbyID(cID) == nullptr)
    {
        cout<<"[INFO] Customer ID not found. Try again or press <0+ENTER> to exit.\n";
        cout<<"ENTER CUSTOMER ID: ";
        cin>>cID;
        if(cID == 0)
        {
            return false;
        }
    }
    
    
    cRentUnit* aUnit;
    cCustomer * aCustomer = searchCustomerbyID(cID);
    const vector<int> * avUnits = aCustomer->getUnitsID();
    
    aCustomer->info();
    
    if(avUnits->empty())
    {
        cout<<"[INFO] Checking out failed. Customer has 0 units on list.\n";
        return true;
    }
    
    char ch;
    cout<<"[INFO] Check out Customer "<<cID<<"? Press <C+ENTER> to confirm or <OTHER KEY+ENTER> to exit.\n";
    cout<<"ENTER CUSTOMER ID: ";
    cin>>ch;
    if(toupper(ch) == 'C')
    {
        for(auto it = avUnits->begin(); it != avUnits->end(); ++it)
        {
            aUnit = searchUnitbyID(*it);
            aUnit->setStatus(0);
        }
        aCustomer->clearUnitsID();
        aCustomer->setFromDate("");
        aCustomer->setBill(0.00);
        aCustomer->setToDate("");
        aCustomer->setDays(0);
        aCustomer->setStatus(0);
        aCustomer->setPayStatus(1);
        std::cout<<"\n[INFO] Checked out succesfully.\n";
        return true;
    }

    std::cout<<"\n[INFO] Checked out cancelled.\n";

      return false;
    

    /*
     cCustomer * aCustomer = searchCustomerbyID(cID);
     aCustomer->info();
     cout<<"ENTER UNIT ID: ";
     cin>>cID;
     
    while(aCustomer->searchID(cID) == false)
    {
        cout<<"[INFO] Unit ID not found on Customer "<<cID<<" list. Try again or press <0+ENTER> to exit.\n";
        cout<<"ENTER UNIT ID: ";
        cin>>cID;
        if(cID == 0)
        {
            return false;
        }
    }
    
    
    
    const vector<int>* avUnits = aCustomer->getUnitsID();
    cRentUnit* aUnit;
    
    for(auto it = avUnits->begin(); it != avUnits->end(); ++it)
    {
        if(*it == cID)
        {
            aUnit = searchUnitbyID(*it);
        }
    }
    
    aCustomer->rmUnitID(cID);
    aUnit->setStatus(0);
    
    if(avUnits->empty())
    {
        aCustomer->setFromDate("");
        aCustomer->setDays(0);
        aCustomer->setStatus(0);
        aCustomer->setPayStatus(0);

    }
    aCustomer->setBill(aCustomer->getBill() - (aCustomer->getDays() * aUnit->getPricePD()) );
    */
    
    

    

  
    
    
}





bool MainMenu::addToDB(cRoom* aR)
{
    
    vRooms.push_back(aR);
    return true;
}


bool MainMenu::addToDB(cApartment* aA)
{
    vApartments.push_back(aA);
    return true;
}



bool MainMenu::addToDB(cCustomer* aC)
{

    vCustomers.push_back(aC);
    return true;
}



bool MainMenu::rmUnitFromDB(int aID)
{
    if(vRooms.size() == 1)
    {
        return false;
    }
    
    //if ID belongs to cRoom
    if(aID > 0 and aID < 1000)
    {
        for(auto it = vRooms.begin()+1; it != vRooms.end(); ++it)
        {
            if((*it)->getID() == aID)
            {
                delete *it;
                vRooms.erase(it);
                return true;
            }
        }
    }
    
    //if ID belongs to cApartment
    if(aID > 1000 and aID < 2000)
    {
        for(auto it = vApartments.begin()+1; it != vApartments.end(); ++it)
        {
            if((*it)->getID() == aID)
            {
                delete *it;
                vApartments.erase(it);
                return true;
            }
        }
    }

    

    return false;
}




bool MainMenu::rmCustomerFromDB(int aID)
{
    if(vCustomers.size() == 1)
    {
        return false;
    }
    
    
        for(auto it = vCustomers.begin()+1; it != vCustomers.end(); ++it)
        {
            if((*it)->getID() == aID)
            {
                delete *it;
                vCustomers.erase(it);
                return true;
            }
        }
    

    return false;
}



int MainMenu::generateID(std::vector<cRoom*>&vUnits) const
{
    //if DB is empty setting ID = 1 to its first element
    if(vUnits.empty())
    {
        return 0;
    }
    
    
    //rewriting all IDs from DB to vector<int>
     std::vector<int> IDs;
    
    for(auto it = vUnits.begin(); it != vUnits.end(); ++it)
    {
        IDs.push_back( (*it)->getID() );
    }
    
    sort(IDs.begin(), IDs.end());
    
    //finding lowest possible unique ID and returning it
    for(int i = 1; i < IDs.size()+2; i++)
    {
        std::vector<int>::iterator it;
        if( find(IDs.begin(), IDs.end(), i) == IDs.end() )
        {
            return i;
        }
    }
    
    return 0;
}




int MainMenu::generateID(std::vector<cApartment*>&vUnits) const
{
    //if DB is empty setting ID = 1000 to its first element
    if(vUnits.empty())
    {
        return 1000;
    }
    
    
    //rewriting all IDs from DB to vector<int>
    std::vector<int> IDs;
    
    for(auto it = vUnits.begin(); it != vUnits.end(); ++it)
    {
        IDs.push_back( (*it)->getID() );
    }
    
    sort(IDs.begin(), IDs.end());
    
    //finding lowest possible unique ID and returning it
    for(int i = 1000; i < 1000+IDs.size()+2; i++)
    {
        std::vector<int>::iterator it;
        if( find(IDs.begin(), IDs.end(), i) == IDs.end() )
        {
            return i;
        }
    }
    
    return 0;
}






int MainMenu::generateID(std::vector<cCustomer*>&vCustomers) const
{
    //if DB is empty setting ID = 1 to its first element
    if(vCustomers.empty())
    {
        return 0;
    }
    
    
    
    
    //rewriting all IDs from DB to vector<int>
    std::vector<int> IDs;
    
    for(auto it = vCustomers.begin(); it != vCustomers.end(); ++it)
    {
        IDs.push_back( (*it)->getID() );
    }
    
    sort(IDs.begin(), IDs.end());
    
    //finding lowest possible unique ID and returning it
    for(int i = 1; i < IDs.size()+2; i++)
    {
        std::vector<int>::iterator it;
        if( find(IDs.begin(), IDs.end(), i) == IDs.end() )
        {
            return i;
        }
    }
    
    return 0;
}




cRentUnit* MainMenu::searchUnitbyID(int aID) const
{
    // if ID belongs to cRoom
    if(aID > 0 and aID < 1000)
    {
        for(auto it = vRooms.begin(); it != vRooms.end(); ++it)
        {
            if( (*it)->getID() == aID )
            {
                return *it;
            }
        }
        return nullptr;
    }
    
   
    // if ID belongs to cApartment
    if(aID > 1000 and aID < 2000)
    {
        for(auto it = vApartments.begin(); it != vApartments.end(); ++it)
        {
            if( (*it)->getID() == aID )
            {
                return *it;
            }
        }
        return nullptr;
    }
    
    
    return nullptr;
}




void MainMenu::showDB(cRoom* aR) const
{
    if(vRooms.empty())
    {
        std::cout<<"[INFO] DATA BASE EMPTY\n";
    }
    
    for(auto it = vRooms.begin(); it != vRooms.end(); ++it)
    {
        (*it)->info();
    }
    std::cout<<std::endl;

}




void MainMenu::showDB(cApartment* aA) const
{
    if(vApartments.empty())
    {
        std::cout<<"[INFO] DATA BASE EMPTY\n";
    }
    for(auto it = vApartments.begin(); it != vApartments.end(); ++it)
    {
        (*it)->info();
    }
    std::cout<<std::endl;
    
}


void MainMenu::showDB(cCustomer* aC) const
{
    if(vRooms.empty())
    {
        std::cout<<"[INFO] DATA BASE EMPTY\n";
    }
    for(auto it = vCustomers.begin(); it != vCustomers.end(); ++it)
    {
        (*it)->info();
    }

}




cCustomer* MainMenu::searchCustomerbyID(int aID) const
{
    if(aID > 0 and aID < 1000000000)
    {
        for(auto it = vCustomers.begin(); it != vCustomers.end(); ++it)
        {
            if( (*it)->getID() == aID )
            {
                return *it;
            }
        }
        return nullptr;
    }
   
    return nullptr;
}



bool MainMenu::addNewCustomer()
{
    
    
    cCustomer* newC = new cCustomer(*this);
    std::string strbuff = "";
    char ch;
    
    std::cout<<"\n[INFO] ENTER NEW CUSTOMER DETAILS:\n";
         std::cout<<"Customer ID: "<<newC->getID()<<std::endl;
        std::cout<<"FirstName: ";   std::cin>>strbuff;
        newC->setFirstName(strbuff);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"LastName: ";    std::cin>>strbuff;
        newC->setLastName(strbuff);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"PhoneNum: ";    std::cin>>strbuff;
         newC->setPhoneNum(strbuff);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"Adress: ";      getline(std::cin, strbuff);
        newC->setAdress(strbuff);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout<<"\nNEW CUSTOMER DETAILS: \n";
        newC->info();
        std::cout<<"[INFO] Press <S + ENTER> to save changes.\n"
                    "\t  <OTHER KEY + ENTER> to exit without saving.\n";
        std::cout<<"CHOICE: ";
        std::cin>>ch;
    
        if(toupper(ch) == 'S')
        {
            this->addToDB(newC);
            std::cout<<"\n[INFO] Customer added succesfully.\n";
            return true;
        }
    
        std::cout<<"\n[INFO] Customer cancelled.\n";

    delete newC;
    return false;
}




bool MainMenu::addNewRoom()
{
    std::string strbuff;
    char ch;
    std::cout<<"\n[INFO] ENTER NEW ROOM DETAILS:"<<std::endl;
    while(true)
    {
        std::cout<<"Type(S/D/T/Q): ";   std::cin>>strbuff;
        strbuff.at(0) = toupper(strbuff.at(0));
        if(strbuff == "S" or strbuff == "D" or strbuff == "T"  or strbuff == "Q")
        {
            break;
        }
        std::cout<<"\n[INFO] Unknown type. Please try again.\n";
    }

    cRoom* newR = new cRoom(strbuff, *this);
    std::cout<<"\nNEW ROOM DETAILS: \n";

    newR->info();
    
    std::cout<<"[INFO] Press <S + ENTER> to save changes.\n"
    "\t  <OTHER KEY + ENTER> to exit without saving.\n";
    std::cout<<"CHOICE: ";
    std::cin>>ch;
    
    if(toupper(ch) == 'S')
    {
        this->addToDB(newR);
        std::cout<<"\n[INFO] Room added succesfully.\n";
        return true;
    }
    
    std::cout<<"\n[INFO] Room cancelled.\n";
    
    delete newR;
    return false;

}



bool MainMenu::addNewApartment()
{
    std::string strbuff;
    char ch;

    std::cout<<"\n[INFO] ENTER NEW APARTMENT DETAILS:"<<std::endl;
    while(true)
    {
        std::cout<<"Type(T0/T1/T2/T3): ";   std::cin>>strbuff;
        
        strbuff.at(0) = toupper(strbuff.at(0));
        
        if(strbuff == "T0" or strbuff == "T1" or strbuff == "T2"  or strbuff == "T3")
        {
            break;
        }
        std::cout<<"[INFO] Unknown type. Please try again.\n";
    }
    
    cApartment* newA = new cApartment(strbuff, *this);
    
    std::cout<<std::endl;
    std::cout<<"\nNEW APARTMENT DETAILS: \n";
    newA->info();
    std::cout<<"[INFO] Press <S + ENTER> to save changes.\n"
                "\t  <OTHER KEY + ENTER> to exit without saving.\n";
    std::cout<<"CHOICE: ";
    std::cin>>ch;
    
    if(toupper(ch) == 'S')
    {
        this->addToDB(newA);
        std::cout<<std::endl<<"[INFO] Apartment added succesfully.\n";
        return true;
    }
    
    std::cout<<std::endl<<"[INFO] Apartment cancelled.\n";
    
    delete newA;
    return true;
}


//================= SETTERS ============================



//================== GETTERS ============================


