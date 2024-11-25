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


Settlement::Settlement(const string& otherName, SettlementType otherType): name(otherName), type(otherType){}
const string& Settlement::getName() const {
    return name;
}

SettlementType Settlement::getType() const {
    return type;
}

const string Settlement::toString() const{
    return "Settlement name:" + name + " Type:" + SettlementTypeToString(type); 
}


