#include "Action.h"

// Constructor
ChangePlanPolicy::ChangePlanPolicy(const int planId, const string &newPolicy): BaseAction::BaseAction(), planId(planId), newPolicy(newPolicy){}
ChangePlanPolicy::ChangePlanPolicy(const ChangePlanPolicy& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()), planId(other.planId), newPolicy(other.newPolicy){}

// Destructor - Default

// Operators
ChangePlanPolicy& ChangePlanPolicy::operator=(const ChangePlanPolicy& other){return *this;}

// Other methods
void ChangePlanPolicy::act(Simulation &simulation){
    if(planId >= simulation.getPlansCounter() || newPolicy == simulation.getPlan(planId).getPolicy().getType()){
        BaseAction::error("Cannot change selection policy");
        std::cout << BaseAction::getErrorMsg() << std::endl;
    }
    else{
        Plan& p = simulation.getPlan(planId);
        string prevPoilcy = p.getPolicy().getFullType();
        if(newPolicy == "nve"){p.setSelectionPolicy(new NaiveSelection());}
        else if(newPolicy == "bal"){p.setSelectionPolicy(new BalancedSelection(p.getTotalLifeQualityScore(),p.getTotalEconomyScore(),p.getTotalEnvironmentScore()));} 
        else if(newPolicy == "eco"){p.setSelectionPolicy(new EconomySelection());}
        else if(newPolicy == "env"){p.setSelectionPolicy(new SustainabilitySelection());}

        std::cout << planId << std::endl;
        std::cout << "previousPolicy: " << prevPoilcy << std::endl;
        std::cout << "newPolicy: " << p.getPolicy().getFullType() << std::endl;
        BaseAction::complete();
    }
}

 ChangePlanPolicy *ChangePlanPolicy::clone() const{return new ChangePlanPolicy(*this);} 

 const string ChangePlanPolicy::toString() const{return "changePolicy " + std::to_string(planId) + " " + newPolicy + " " + BaseAction::getStatusAsString();}
