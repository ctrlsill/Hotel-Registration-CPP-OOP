
#include <iostream>
#include "cRoom.hpp"
#include "MainMenu.hpp"
#include "cCustomer.hpp"
#include "cApartment.hpp"


using namespace std;




int main(int argc, const char * argv[]) {
    
    
    MainMenu MENU;
    
    for(int i = 5; i<10; ++i)
    {
        cRoom* r1 = new cRoom("D", MENU);
        MENU.addToDB(r1);
    }
    for(int i = 5; i<10; ++i)
    {
        cApartment* a1 = new cApartment("T2", MENU);
        MENU.addToDB(a1);
    }
    for(int i = 5; i<10; ++i)
    {
        cCustomer* c1 = new cCustomer(MENU);
        MENU.addToDB(c1);
    }
    
    
    
    cout<<"==================  WELCOME IN GRAND BUDAPEST HOTEL =========================\n";
    int ch;
    int lock = 1;
    while(lock)
    {
    
        cout<<"============= MENU =================\n"
                "[0] - EXIT\n"
                "[1] - CHECK IN\n"
                "[2] - CHECK OUT\n"
                "[3] - SHOW CUSTOMERS DB\n"
                "[4] - SHOW ROOMS DB\n"
                "[5] - SHOW APARTMENTS DB\n"
                "[6] - ADD NEW CUSTOMER\n"
                "[7] - ADD NEW ROOM\n"
                "[8] - ADD NEW APARTMENT\n"
                "[9] - FIND CUSTOMER BY ID\n"
                "[10]- FIND UNIT BY ID\n"
                "[11]- DELETE CUSTOMER\n"
                "[12]- DELETE UNIT\n"
        
        




              "====================================\n";
        cout<<"CHOICE: ";
        cin>>ch;
        cRentUnit* RU = nullptr;
        cCustomer*  C = nullptr;
        cRoom*      R = nullptr;
        cApartment* A = nullptr;
        
        switch(ch)
        {
            case 1:
                    MENU.checkIN();
                break;
            case 2:
                    MENU.checkOUT();
                break;
            case 3:
                    MENU.showDB(C);
                break;
            case 4:
                    MENU.showDB(R);
                break;
            case 5:
                    MENU.showDB(A);
                break;
            case 6:
                    MENU.addNewCustomer();
                break;
            case 7:
                    MENU.addNewRoom();
                break;
            case 8:
                    MENU.addNewApartment();
                break;
            case 9:
                    cout<<"ENTER CUSTOMER ID: ";
                    cin>>ch;
                    C = MENU.searchCustomerbyID(ch);
                    if(C != nullptr)
                    {
                        C->info();
                        break;
                    }
                    cout<<"\n[INFO] Customer ID not found.\n";
                break;
            case 10:
                    cout<<"ENTER UNIT ID: ";
                    cin>>ch;
                    RU = MENU.searchUnitbyID(ch);
                    if(RU != nullptr)
                    {
                        RU->info();
                        break;
                    }
                    cout<<"\n[INFO] Unit ID not found.\n";
                
                break;
            case 11:
                    cout<<"ENTER CUSTOMER ID: ";
                    cin>>ch;
                    if(MENU.rmCustomerFromDB(ch) == true)
                    {
                        cout<<"\n[INFO] Customer deleted succesfully.\n";
                        break;
                    }
                    cout<<"\n[INFO] Customer ID not found.\n";
                break;
            case 12:
                cout<<"ENTER UNIT ID: ";
                cin>>ch;
                if(MENU.rmUnitFromDB(ch) == true)
                {
                    cout<<"\n[INFO] Unit deleted succesfully.\n";
                    break;
                }
                cout<<"\n[INFO] Unit ID not found.\n";
                break;
            
            case 0:
            default:
                    cout<<"\nSEE YOU AGAIN IN GRAND BUDAPEST HOTEL.\n";
                    //here saving data to file
                lock = 0;
                break;
                
        }
    
    }
   
    
    return 0;
}
