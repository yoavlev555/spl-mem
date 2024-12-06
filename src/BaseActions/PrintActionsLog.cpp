#include "Action.h"

//Constructor
PrintActionsLog::PrintActionsLog():BaseAction::BaseAction(){}

//Overrides
void PrintActionsLog::act(Simulation &simulation){
    for (BaseAction* ba : simulation.getActionLog()){
        std::cout<<ba->toString()<<std::endl;
    }
    BaseAction::complete();
}

PrintActionsLog *PrintActionsLog::clone() const{return new PrintActionsLog();}
const string PrintActionsLog::toString() const{return "Status: " + BaseAction::getStatusAsString();}







