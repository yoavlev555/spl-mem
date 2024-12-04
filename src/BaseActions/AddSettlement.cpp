#include "Action.h"

// Constructors
AddSettlement::AddSettlement(const string &settlementName,SettlementType settlementType):settlementName(settlementName),settlementType(settlementType){}

// Destructor - Default

// Other methods 
void AddSettlement::act(Simulation &simulation){
    if(!simulation.addSettlement(Settlement(settlementName,settlementType))){
        BaseAction::error("Settlement already exists");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        BaseAction::complete();
    }
}

AddSettlement *AddSettlement::clone() const{return new AddSettlement(settlementName,settlementType);}
const string AddSettlement::toString() const{return "Status: " + BaseAction::getStatusAsString();}
