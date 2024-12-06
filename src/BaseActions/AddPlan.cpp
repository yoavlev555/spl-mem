#include "Action.h"

// Constructors
AddPlan::AddPlan(const string &settlementName, const string &selectionPolicy):BaseAction::BaseAction(),settlementName(settlementName), selectionPolicy(selectionPolicy){}


// Destructor - Default

// Other methods 
void AddPlan::act(Simulation &simulation){
    if(!(simulation.isSettlementExists(settlementName) && isValidPolicy()) ){ // lo haser 34 shurot code
        BaseAction::error("Cannot create this plan");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        if(selectionPolicy == "nve"){simulation.addPlan(simulation.getSettlement(settlementName),new NaiveSelection());}
        else if(selectionPolicy == "bal"){simulation.addPlan(simulation.getSettlement(settlementName),new BalancedSelection(0,0,0));} 
        else if(selectionPolicy == "eco"){simulation.addPlan(simulation.getSettlement(settlementName),new EconomySelection());}
        else if(selectionPolicy == "env"){simulation.addPlan(simulation.getSettlement(settlementName),new SustainabilitySelection());}
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
const string AddPlan::toString() const{return "plan " + settlementName + " " + selectionPolicy + " " + BaseAction::getStatusAsString();}
