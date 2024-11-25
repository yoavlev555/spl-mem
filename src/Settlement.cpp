#include "Settlement.h"



 
string Settlement::SettlementTypeToString (SettlementType s)
{
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

// Constructors
Settlement::Settlement(const string& otherName, SettlementType otherType): name(otherName), type(otherType){}
Settlement::Settlement(const Settlement& other): name(other.name), type(other.type){}

// Destructor
Settlement::~Settlement(){} // do default destructor

// Operators
void Settlement::operator=(const Settlement& other){
    if(this != &other){
        type = other.type;
    }
}


const string& Settlement::getName() const {
    return name;
}


SettlementType Settlement::getType() const {
    return type;
}

const string Settlement::toString() const{
    return "Settlement name:" + name + " Type:" + SettlementTypeToString(type); 
}


