#include "Settlement.h"

// Constructors
Settlement::Settlement(const string& otherName, SettlementType otherType): name(otherName), type(otherType){}
Settlement::Settlement(const Settlement& other): name(other.name), type(other.type){}

// Destructor do default destructor

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