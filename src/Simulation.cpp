#include <iostream>
#include "Simulation.h"
#include "Auxiliary.h"
#include <fstream> 
using namespace std;

Simulation::Simulation(const string &configFilePath):isRunning(true), planCounter(0),actionsLog(vector<BaseAction*>()), plans(vector<Plan>()), settlements(vector<Settlement*>()), facilitiesOptions(vector<FacilityType>()){
    string line;
    ifstream MyReadFile(configFilePath);
    while (getline (MyReadFile, line)){
        vector<string> lineArguments = Auxiliary::parseArguments(line);
        if (lineArguments.at(0) == "settlement"){
            string st = lineArguments.at(2);
            SettlementType type = SettlementType::CITY;

            if(st == "0"){
                type = SettlementType::VILLAGE;
            }

            else if(st == "1"){
                type = SettlementType::CITY;
            }

            else{
                type = SettlementType::METROPOLIS;
            }
            
            settlements.push_back(new Settlement(lineArguments.at(1),type));
        }

        else if (lineArguments.at(0) == "facility"){
            string fc = lineArguments.at(2);
            FacilityCategory category = FacilityCategory::ECONOMY;

            if(fc == "0"){
                category = FacilityCategory::LIFE_QUALITY;
            }

            else if(fc == "1"){
                category = FacilityCategory::ECONOMY;
            }

            else{
                category = FacilityCategory::ENVIRONMENT;
            }

            facilitiesOptions.push_back(FacilityType(lineArguments.at(1),category,stoi(lineArguments.at(3)),stoi(lineArguments.at(4)),stoi(lineArguments.at(5)),stoi(lineArguments.at(6))));
        }

        else if (lineArguments.at(0) == "plan"){
            Settlement* set;
            for (int i = 0; i< settlements.size(); i++){
                if(settlements.at(i)->getName() == lineArguments.at(1)){
                    set = settlements.at(i);
                    break;
                }
            }

            if (lineArguments.at(2)=="nve"){
                plans.push_back(Plan(planCounter,*set , new NaiveSelection(), facilitiesOptions));
            }

            else if (lineArguments.at(2)=="bal"){
                plans.push_back(Plan(planCounter,*set , new BalancedSelection(0,0,0), facilitiesOptions));
            }

            else if (lineArguments.at(2)=="eco"){
                plans.push_back(Plan(planCounter,*set , new EconomySelection(), facilitiesOptions));
            }

            else if (lineArguments.at(2)=="env"){
                plans.push_back(Plan(planCounter,*set , new SustainabilitySelection(), facilitiesOptions));
            }

            planCounter++;
        }
    }
    //# plan <settlement_name> <selection_policy>
}
/*
bool isRunning;
        int planCounter; //For assigning unique plan IDs
        vector<BaseAction*> actionsLog;
        vector<Plan> plans;
        vector<Settlement*> settlements;
        vector<FacilityType> facilitiesOptions;
        */


void Simulation::start(){
    cout << "The simulation has started" << endl;
    while(isRunning){

    }
}





/*
class Simulation {
    public:
        void start();
        void addPlan(const Settlement &settlement, SelectionPolicy *selectionPolicy);
        void addAction(BaseAction *action);
        bool addSettlement(Settlement *settlement);
        bool addFacility(FacilityType facility);
        bool isSettlementExists(const string &settlementName);
        Settlement &getSettlement(const string &settlementName);
        Plan &getPlan(const int planID);
        void step();
        void close();
        void open();

    private:
        bool isRunning;
        int planCounter; //For assigning unique plan IDs
        vector<BaseAction*> actionsLog;
        vector<Plan> plans;
        vector<Settlement*> settlements;
        vector<FacilityType> facilitiesOptions;
};*/