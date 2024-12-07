#include "Action.h"

//Constructor
PrintActionsLog::PrintActionsLog():BaseAction::BaseAction(){}
PrintActionsLog::PrintActionsLog(const PrintActionsLog& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()){}

// Destructor - Default

// Operators 
PrintActionsLog& PrintActionsLog::operator=(const PrintActionsLog& other){return *this;}

// Overrides
void PrintActionsLog::act(Simulation &simulation){
    for (int i=0; i<simulation.getActionLog().size(); i++){
        std::cout << simulation.getActionLog().at(i)->toString() << std::endl;
    }
    BaseAction::complete();
}

PrintActionsLog *PrintActionsLog::clone() const{return new PrintActionsLog();}
const string PrintActionsLog::toString() const{return "log: " + BaseAction::getStatusAsString();}







