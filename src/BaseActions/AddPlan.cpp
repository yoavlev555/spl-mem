#include "Action.h"

// Constructors
AddPlan::AddPlan(const string &settlementName, const string &selectionPolicy):settlementName(settlementName), selectionPolicy(selectionPolicy){}


// Destructor - Default

// Other methods 
void AddPlan::act(Simulation &simulation){
    if(!(simulation.isSettlementExists(settlementName) && isValidPolicy()) ){ // lo haser 34 shurot code
        BaseAction::error("Cannot create this plan");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        simulation.addPlan(settlementName,selectionPolicy);
        BaseAction::complete();
    }
}

bool AddPlan::isValidPolicy(){
    if(selectionPolicy != "nve" && selectionPolicy != "env" && selectionPolicy != "eco" && selectionPolicy != "bal"){
        return false;
    }
    return true;
}
AddPlan *AddPlan::clone() const{return new AddPlan(settlementName,selectionPolicy);}
const string AddPlan::toString() const{return "Status: " + BaseAction::getStatusAsString();}
