

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "cCustomer.hpp"
#include "cRentUnit.hpp"
#include "cRoom.hpp"
#include "cApartment.hpp"
#include <vector>
#include <string>
#include <memory>





class MainMenu
{
    std::vector<cRoom*> vRooms;
    std::vector<cApartment*> vApartments;
    std::vector<cCustomer*> vCustomers;
 
    
public:
    friend cRoom::cRoom(std::string, MainMenu&);
    friend cApartment::cApartment(std::string, MainMenu&);
    friend cCustomer::cCustomer(MainMenu&);

    MainMenu();
    ~MainMenu();
    
    
    //UI
    void showDB(cRoom*)      const;
    void showDB(cApartment*) const;
    void showDB(cCustomer*)  const;

    bool addNewCustomer();
    bool addNewRoom();
    bool addNewApartment();
    
    bool checkIN();
    bool checkOUT();
    
    
    //NOT UI
    cRentUnit* searchUnitbyID(int)     const;
    cCustomer* searchCustomerbyID(int) const;
    int generateID(std::vector<cRoom*>&) const;
    int generateID(std::vector<cApartment*>&) const;
    int generateID(std::vector<cCustomer*>&) const;

    bool addToDB(cRoom*);
    bool addToDB(cApartment*);
    bool addToDB(cCustomer*);
    bool rmUnitFromDB(int);
    bool rmCustomerFromDB(int);

  
    
 
    
};



#endif /* MainMenu_hpp */
