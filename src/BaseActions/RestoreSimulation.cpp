#include "Action.h"

//Constructor
RestoreSimulation::RestoreSimulation():BaseAction::BaseAction(){}

//Overrides
void RestoreSimulation::act(Simulation &simulation){
    
}

RestoreSimulation *RestoreSimulation::clone() const{return new RestoreSimulation();}
const string RestoreSimulation::toString() const{return "restore " + BaseAction::getStatusAsString();}

