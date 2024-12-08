#include "Action.h"

// Constructors
AddPlan::AddPlan(const string &settlementName, const string &selectionPolicy):BaseAction::BaseAction(), settlementName(settlementName), selectionPolicy(selectionPolicy){}
AddPlan::AddPlan(const AddPlan& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()), settlementName(other.settlementName), selectionPolicy(other.selectionPolicy){}

// Destructor - Default

// Operators
AddPlan& AddPlan::operator=(const AddPlan& other){return *this;}

// Other methods 
void AddPlan::act(Simulation &simulation){
    if(!(simulation.isSettlementExists(settlementName) && isValidPolicy())){ 
        BaseAction::error("Cannot create this plan");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    
    else{
        Settlement& curr = simulation.getSettlement(settlementName);
        SelectionPolicy* selectionP = nullptr;
        if(selectionPolicy == "nve"){selectionP = new NaiveSelection();}
        else if(selectionPolicy == "bal"){selectionP = new BalancedSelection(0,0,0);} 
        else if(selectionPolicy == "eco"){selectionP = new EconomySelection();}
        else if(selectionPolicy == "env"){selectionP = new SustainabilitySelection();}
        simulation.addPlan(curr,selectionP);
        BaseAction::complete();
    }
}

bool AddPlan::isValidPolicy(){
    if(selectionPolicy != "nve" && selectionPolicy != "env" && selectionPolicy != "eco" && selectionPolicy != "bal"){
        return false;
    }
    return true;
}

AddPlan *AddPlan::clone() const{return new AddPlan(*this);}

const string AddPlan::toString() const{return "plan " + settlementName + " " + selectionPolicy + " " + BaseAction::getStatusAsString();}
