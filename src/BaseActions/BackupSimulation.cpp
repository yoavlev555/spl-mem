#include "Action.h"
extern Simulation* backup;

// Constructor
BackupSimulation::BackupSimulation():BaseAction::BaseAction(){}
BackupSimulation::BackupSimulation(const BackupSimulation& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()){}

// Destructor - Default

// Operators
BackupSimulation& BackupSimulation::operator=(const BackupSimulation& other){return *this;}

// Overrides
void BackupSimulation::act(Simulation &simulation){
    delete backup;
    backup = new Simulation(simulation);
    BaseAction::complete();
}

BackupSimulation *BackupSimulation::clone() const{return new BackupSimulation(*this);}

const string BackupSimulation::toString() const{return "backup " + BaseAction::getStatusAsString();}
