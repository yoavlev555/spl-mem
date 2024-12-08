#include "Settlement.h"

// Constructors
Settlement::Settlement(const string& otherName, SettlementType otherType): name(otherName), type(otherType){}
Settlement::Settlement(const Settlement& other): name(other.name), type(other.type){}

// Destructor - Default

// Operators
Settlement& Settlement::operator=(const Settlement& other){
    if(this != &other){
        type = other.type;
    }
    
    return *this;
}

// Getters
const string& Settlement::getName() const {return name;}
SettlementType Settlement::getType() const {return type;}
const int Settlement::getMaxCapacity() const{
    if (type == SettlementType::VILLAGE) {
        return 1;
    }
    if (type == SettlementType::CITY){
        return 2;
    }
    else{ 
        return 3;
    }
}

// Other Methods
string Settlement::SettlementTypeToString (SettlementType s){
    if (s==SettlementType::VILLAGE) {
        return "VILLAGE";
    }
    if (s==SettlementType::CITY){
        return "CITY";
    }
    else{ 
        return "METROPOLIS";
    }
}
const string Settlement::toString() const{

    return "Settlement name:" + name + " Type:" + SettlementTypeToString(type); 
}
Settlement* Settlement::clone(){
    return new Settlement(*this);
}

SettlementType Settlement::getType(int i){
    if(i==0){return SettlementType::VILLAGE;}
    else if(i==1){return SettlementType::CITY;}
    else if(i==2){return SettlementType::METROPOLIS;}
}