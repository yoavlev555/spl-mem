#include "Action.h"
using namespace std;

//Constructor
Close::Close():BaseAction::BaseAction(){}

//Overrides
void Close::act(Simulation &simulation){
    // print all plans with their accumulated results
    for(Plan plan : simulation.getPlans()){
        cout << "planID: " + to_string(plan.getID()) << endl;
        cout << "settlementName " + plan.getSettlement().getName() << endl; 
        cout << "LifeQuality_Score: " + to_string(plan.getlifeQualityScore()) << endl;
        cout << "Economy_Score: " + to_string(plan.getEconomyScore()) << endl;
        cout << "Environment_Score: " + to_string(plan.getEnvironmentScore()) << endl;
    }

    BaseAction::complete();
    simulation.close();
}

Close *Close::clone() const{return new Close();}
const string Close::toString() const{return "close " + BaseAction::getStatusAsString();}

