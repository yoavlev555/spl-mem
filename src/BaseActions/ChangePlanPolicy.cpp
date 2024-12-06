#include "Action.h"

// Constructor
ChangePlanPolicy::ChangePlanPolicy(const int planId, const string &newPolicy): BaseAction::BaseAction(),planId(planId), newPolicy(newPolicy){}

// Desctructor - Default

// Other methods
void ChangePlanPolicy::act(Simulation &simulation){
    if(planId >= simulation.getPlansCounter() || newPolicy == simulation.getPlan(planId).getPolicy().getType()){
        BaseAction::error("Cannot change selection policy");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        Plan p = simulation.getPlan(planId);
        if(newPolicy == "nve"){return p.setSelectionPolicy(new NaiveSelection());}
        else if(newPolicy == "bal"){return p.setSelectionPolicy(new BalancedSelection(p.getTotalLifeQualityScore(),p.getTotalEconomyScore(),p.getTotalEnvironmentScore()));} 
        else if(newPolicy == "eco"){return p.setSelectionPolicy(new EconomySelection());}
        else if(newPolicy == "env"){return p.setSelectionPolicy(new SustainabilitySelection());}
        BaseAction::complete();
    }
}

 ChangePlanPolicy *ChangePlanPolicy::clone() const{
    return new ChangePlanPolicy(planId,newPolicy);
 } 

 const string ChangePlanPolicy::toString() const{return "changePolicy " + std::to_string(planId) + " " + newPolicy + " " + BaseAction::getStatusAsString();}
