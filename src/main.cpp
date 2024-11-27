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

    vector<FacilityType> ft = vector<FacilityType>();
    ft.push_back(FacilityType("Hospital",FacilityCategory::LIFE_QUALITY,6,9,5,3));
    ft.push_back(FacilityType("Terner Stadium",FacilityCategory::LIFE_QUALITY,12,9,9,0));
    ft.push_back(FacilityType("Water Disinffection",FacilityCategory::ENVIRONMENT,2,4,10,8));

    NaiveSelection ns = NaiveSelection();
    cout<< ns.selectFacility(ft).getName() + " " << endl;
    cout << ns.toString() << endl;
    NaiveSelection* newNS = new NaiveSelection(ns);
    cout<< newNS->selectFacility(ft).getName() + " " << endl;
    cout << ns.toString() << endl;
    cout << newNS->toString() << endl;



    return 0;
}