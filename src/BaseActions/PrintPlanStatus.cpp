#include "Action.h"

// Constructor
PrintPlanStatus::PrintPlanStatus(int planId):planId(planId){}
PrintPlanStatus::PrintPlanStatus(const PrintPlanStatus& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()),planId(other.planId){}

// Destructor - Default

// Operators 
PrintPlanStatus& PrintPlanStatus::operator=(const PrintPlanStatus& other){return *this;}

// Overrides
void PrintPlanStatus::act(Simulation &simulation){
    if(planId >= simulation.getPlansCounter()){
        error("Error: Plan doesn't exist");
        std::cout<<getErrorMsg()<<std::endl;
    }
    else{
        Plan plan = simulation.getPlan(planId);
        plan.printPlan();
        BaseAction::complete();
    }
}

PrintPlanStatus *PrintPlanStatus::clone() const{return new PrintPlanStatus(*this);}

const string PrintPlanStatus::toString() const{return "planStatus " + std::to_string(planId) + " " +BaseAction::getStatusAsString();}
