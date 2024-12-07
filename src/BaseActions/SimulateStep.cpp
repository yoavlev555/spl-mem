#include "Action.h"

//Constructor
SimulateStep::SimulateStep(const int numOfSteps):BaseAction::BaseAction(),numOfSteps(numOfSteps){}
SimulateStep::SimulateStep(const SimulateStep& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()),numOfSteps(other.numOfSteps){}

// Destructor - Default

// Operators
SimulateStep& SimulateStep::operator=(const SimulateStep& other){return *this;}

// Overrides
void SimulateStep::act(Simulation &simulation){
    for(int i = 0; i < numOfSteps; i++){
        simulation.step();
    }
    
    BaseAction::complete();
}

SimulateStep* SimulateStep::clone() const{return new SimulateStep(numOfSteps);}
const string SimulateStep::toString() const{return "step " + std::to_string(numOfSteps) + " " + BaseAction::getStatusAsString();}