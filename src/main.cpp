#include "Simulation.h"
#include "Settlement.h"
#include "SelectionPolicy.h"
#include <iostream>

using namespace std;

Simulation* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "usage: simulation <config_path>" << endl;
        return 0;
    }

    Simulation* s = new Simulation(argv[1]);

    return 0;
}