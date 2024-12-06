#include "Action.h"
extern Simulation* backup;
 
//Constructor
RestoreSimulation::RestoreSimulation():BaseAction::BaseAction(){}

//Overrides
void RestoreSimulation::act(Simulation &simulation){
    if (*backup = nullptr){
        BaseAction::error("No backup available");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else {
        simulation = *backup;
        BaseAction::complete();
    }
}

RestoreSimulation *RestoreSimulation::clone() const{return new RestoreSimulation();}
const string RestoreSimulation::toString() const{return "restore " + BaseAction::getStatusAsString();}

