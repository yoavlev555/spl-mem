#include "Action.h"

//Constructor
PrintPlanStatus::PrintPlanStatus(int PlanId):BaseAction::BaseAction(),planId(PlanId){}

//Overrides
void PrintPlanStatus::act(Simulation &simulation){
    if(planId >= simulation.getPlansCounter()){
        error("Plan doesn't exist");
        std::cout<<getErrorMsg()<<std::endl;
    }
    else{
        Plan plan = simulation.getPlan(planId);
        plan.printPlan();
        BaseAction::complete();
    }
}

PrintPlanStatus *PrintPlanStatus::clone() const{return new PrintPlanStatus(planId);}
const string PrintPlanStatus::toString() const{return "planStatus " + std::to_string(planId) + " " +BaseAction::getStatusAsString();}
