#include "Action.h"
extern Simulation* backup;

//Constructor
BackupSimulation::BackupSimulation():BaseAction::BaseAction(){}

//Overrides
void BackupSimulation::act(Simulation &simulation){
    delete backup;
    backup = new Simulation(simulation);
    BaseAction::complete();
}

BackupSimulation *BackupSimulation::clone() const{return new BackupSimulation();}
const string BackupSimulation::toString() const{return "backup " + BaseAction::getStatusAsString();}



// (plans, facilities, settlement, and actions history