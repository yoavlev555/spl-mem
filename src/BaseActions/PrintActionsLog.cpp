#include "Action.h"

//Constructor
PrintActionsLog::PrintActionsLog():BaseAction::BaseAction(){}

//Overrides
void PrintActionsLog::act(Simulation &simulation){
    for (int i=0; i<simulation.getActionLog().size()-1; i++){
        std::cout << simulation.getActionLog().at(i)->toString() << std::endl;
    }
    BaseAction::complete();
}

PrintActionsLog *PrintActionsLog::clone() const{return new PrintActionsLog();}
const string PrintActionsLog::toString() const{return "log: " + BaseAction::getStatusAsString();}







