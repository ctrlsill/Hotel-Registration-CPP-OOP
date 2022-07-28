#ifndef cCustomer_hpp
#define cCustomer_hpp

#include <string>
#include <vector>
#include <cstdio>


class cRentUnit;
class MainMenu;


class cCustomer
{

    int mID;
    double mBill;
    int mDays;
    int mStatus;
    int mPayStatus;
    std::string mFirstName;
    std::string mLastName;
    std::string mPhoneNum;
    std::string mAdress;
    std::string mFromDate;
    std::string mToDate;
    std::vector<int> vUnitsID;

    
public:
    explicit cCustomer(MainMenu&);
    ~cCustomer();
    void info() const;
    int  addUnitID(cRentUnit*);
    void clearUnitsID();
    bool rmUnitID(int);
    int  searchID(int);
    
    
    
    void setBill(double);
    void setDays(int);
    int  setStatus(int);
    int  setPayStatus(int);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setPhoneNum(std::string);
    void setAdress(std::string);
    void setFromDate(std::string);
    void setToDate(std::string);

    int getID() const;
    int getBill() const;
    int getDays() const;
    int getStatus() const;
    int getPayStatus() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNum() const;
    std::string getAdress() const;
    std::string getFromDate() const;
    std::string getToDate() const;
    const std::vector<int>* getUnitsID() const;

    
};

#endif /* cCustomer_hpp */
