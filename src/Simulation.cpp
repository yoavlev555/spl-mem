#include <iostream>
#include "Simulation.h"

using namespace std;

Simulation::Simulation(const string& config){
    this->isRunning = true;
    this->planCounter = 0;
}


void Simulation::start(){
    cout << "The simulation has started" << endl;
    while(isRunning){

    }
}