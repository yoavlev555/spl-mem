#include "Simulation.h"
#include "Settlement.h"
#include <iostream>

using namespace std;

Simulation* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "usage: simulation <config_path>" << endl;
        return 0;
    }
    // string configurationFile = argv[1];
    // Simulation simulation(configurationFile);
    // simulation.start();
    // if(backup!=nullptr){
    // 	delete backup;
    // 	backup = nullptr;
    // }

    Settlement* test = new Settlement("I am a test", SettlementType::VILLAGE);
    Settlement* test2 = new Settlement("Bilski the king", SettlementType::METROPOLIS);
    Settlement* test3 = new Settlement(*test2);
    FacilityType f = FacilityType("FAC1",FacilityCategory::ECONOMY,23,4,1,64);

    f.getName() = string("a;sldkjfas");
    cout << f.getName() << endl;
    return 0;
}