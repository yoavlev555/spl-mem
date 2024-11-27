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

FacilityType *ftype = new FacilityType("Gan Yavne", FacilityCategory::LIFE_QUALITY, 2, 1, 1, 3);
Facility *facility = new Facility(*ftype, "Hara Tahor");

FacilityType *facility1 = new FacilityType("Gardens of Hope", FacilityCategory::ENVIRONMENT, 19,31,11,10);
Facility *facilityOp = new Facility(*facility1, "thats some good shit");


cout<<facility->toString()<<endl;
cout<<facilityOp->toString()<<endl;


facilityOp->setStatus(FacilityStatus::OPERATIONAL);
cout<<facilityOp->toString()<<endl;

*facility = *facilityOp;

cout<<facility->toString()<<endl;
cout<<facilityOp->toString()<<endl;
/*
operator=
toString()*

*/

    return 0;
}