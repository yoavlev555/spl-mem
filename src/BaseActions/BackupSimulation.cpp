#include "Action.h"

//Constructor
BackupSimulation::BackupSimulation():BaseAction::BaseAction(){}

//Overrides
void BackupSimulation::act(Simulation &simulation){
    
}

BackupSimulation *BackupSimulation::clone() const{return new BackupSimulation();}
const string BackupSimulation::toString() const{return "backup " + BaseAction::getStatusAsString();}



