#include "Action.h"

// Constructors
AddSettlement::AddSettlement(const string &settlementName, SettlementType settlementType):BaseAction::BaseAction(),settlementName(settlementName),settlementType(settlementType){}
AddSettlement::AddSettlement(const AddSettlement& other): BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()),settlementName(other.settlementName),settlementType(other.settlementType){}

// Destructor - Default

// Operators
AddSettlement& AddSettlement::operator=(const AddSettlement& other){return *this;}

// Other methods 
void AddSettlement::act(Simulation &simulation){
    if(!simulation.addSettlement(new Settlement(settlementName,settlementType))){
        BaseAction::error("Settlement already exists");
        std::cout << BaseAction::getErrorMsg() << std::endl;
    }
    
    else{
        BaseAction::complete();
    }
}

AddSettlement *AddSettlement::clone() const{return new AddSettlement(*this);}

const string AddSettlement::toString() const{
    int type;
    if (settlementType == SettlementType::VILLAGE){type = 0;}
    else if (settlementType == SettlementType::CITY){type = 1;}
    else if (settlementType == SettlementType::METROPOLIS){type = 2;}    
    return "settlement " + settlementName + " " + std::to_string(type) + " " + BaseAction::getStatusAsString();
}
