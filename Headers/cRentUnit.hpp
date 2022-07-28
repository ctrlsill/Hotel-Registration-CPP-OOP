#ifndef cRentUnit_hpp
#define cRentUnit_hpp

#include <string>

class cRentUnit
{
    
protected:
    int mID;
    int mPricePD;
    int mSlots;
    int mStatus;
    std::string mType;
    
public:
    cRentUnit();
    virtual ~cRentUnit();
    
    void info() const;
    
    int getID() const;
    
    std::string  getType() const;
    virtual bool setType(std::string) = 0;
    
    int  getSlots()   const;
    void setSlots(int);
    
    int  getPricePD() const;
    void setPricePD(int);
    
    int  getStatus()  const;
    void setStatus(int);
    
    
    
   
    
  

};



#endif /* cRentUnit_hpp */
