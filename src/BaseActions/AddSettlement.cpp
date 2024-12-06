#include "Action.h"

// Constructors
AddSettlement::AddSettlement(const string &settlementName,SettlementType settlementType):BaseAction::BaseAction(),settlementName(settlementName),settlementType(settlementType){}

// Destructor - Default

// Other methods 
void AddSettlement::act(Simulation &simulation){
    if(!simulation.addSettlement(new Settlement(settlementName,settlementType))){
        BaseAction::error("Settlement already exists");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        BaseAction::complete();
    }
}

AddSettlement *AddSettlement::clone() const{return new AddSettlement(settlementName,settlementType);}
const string AddSettlement::toString() const{
    int type;
    if (settlementType == SettlementType::VILLAGE){type = 0;}
    else if (settlementType == SettlementType::CITY){type = 1;}
    else if (settlementType == SettlementType::METROPOLIS){type = 2;}    
    return "settlement " + settlementName + " " + std::to_string(type) + " " + BaseAction::getStatusAsString();
}
