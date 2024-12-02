#include <iostream>
#include "Simulation.h"
#include "Auxiliary.h"
#include "Action.h"
#include <fstream> 
using namespace std;

// Constructors
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
}

Simulation::Simulation(const Simulation& other):isRunning(other.isRunning),planCounter(other.planCounter),actionsLog(vector<BaseAction*>()),settlements(vector<Settlement*>()),facilitiesOptions(other.facilitiesOptions),plans(other.plans){
    isRunning = other.isRunning;
    planCounter = other.planCounter;
    
    for(BaseAction* action : other.actionsLog){
        actionsLog.push_back(action -> clone());
    }

    for(Settlement* s : other.settlements){
        settlements.push_back(s -> clone());
    }
}

// Destructor
Simulation::~Simulation(){
    for(BaseAction* action : actionsLog){
       delete action;
    }

    for(Settlement* s : settlements){
        delete s;
    }

    actionsLog.clear();
    settlements.clear();
}

// Operators
Simulation& Simulation::operator=(const Simulation& other){
    if(this != &other){
        isRunning = other.isRunning;
        planCounter = other.planCounter;
        plans = other.plans;
        facilitiesOptions = other.facilitiesOptions;

        settlements.clear();
        actionsLog.clear();


        for(Settlement* s : other.settlements){
            settlements.push_back(s -> clone());
        }

        
        for(BaseAction* action : other.actionsLog){
            actionsLog.push_back(action -> clone());
        }
    }

    return *this;
}

// Getters
Plan &Simulation::getPlan(const int planID){return plans.at(planID);}
Settlement& Simulation::getSettlement(const string &settlementName){
    for(Settlement* s : settlements){
        if(s->getName() == settlementName){
            return *s;
        }
    }
}

// Other Methods
void Simulation::addPlan(const Settlement &settlement, SelectionPolicy *selectionPolicy){
    plans.push_back(Plan(planCounter,settlement,selectionPolicy,facilitiesOptions));
    planCounter++;
}

void Simulation::addAction(BaseAction *action){
    actionsLog.push_back(action);
}

bool Simulation::addSettlement(Settlement *settlement){ // Return true if settlement was added
    for(Settlement* s : settlements){
        if(s->getName() == settlement->getName()){
            return false;
        }
    }

    settlements.push_back(settlement);
    return true;
}

bool Simulation::addFacility(FacilityType facility){ // Return true if facility was added
     for(FacilityType ft : facilitiesOptions){
        if(facility.getName() == ft.getName()){
            return false;
        }
    }

    facilitiesOptions.push_back(facility);
    return true;
}

bool Simulation::isSettlementExists(const string &settlementName){
    for(Settlement* s : settlements){
        if(s->getName() == settlementName){
            return true;
        }
    }

    return false;
}

void Simulation::step(){
    for(Plan plan : plans){
        plan.step();
    }
}

void Simulation::close(){
    // Print stats
    isRunning = false;
}

void Simulation::open(){
    isRunning = true;
}







void Simulation::start(){
    cout << "The simulation has started" << endl;
    open();
    while(isRunning){

    }
}



