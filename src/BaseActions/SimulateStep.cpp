#include "Action.h"


//Constructor
SimulateStep::SimulateStep(const int numOfSteps):BaseAction::BaseAction(),numOfSteps(numOfSteps){}

//Overrides
void SimulateStep::act(Simulation &simulation){
    for(int i = 0; i < numOfSteps; i++){
        simulation.step();
    }
    
    BaseAction::complete();
}

SimulateStep* SimulateStep::clone() const{return new SimulateStep(numOfSteps);}
const string SimulateStep::toString() const{return "step " + std::to_string(numOfSteps) + " " + BaseAction::getStatusAsString();}