#include <iostream>
#include "Simulation.h"
#include "Auxiliary.h"
#include "Action.h"
#include <fstream> 
using namespace std;

// Constructors
Simulation::Simulation(const string &configFilePath):isRunning(false), planCounter(0),actionsLog(vector<BaseAction*>()), plans(vector<Plan>()), settlements(vector<Settlement*>()), facilitiesOptions(vector<FacilityType>()){
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
            int settlementIndex;
            for (int i = 0; i< settlements.size(); i++){
                if(settlements.at(i)->getName() == lineArguments.at(1)){
                    settlementIndex = i;
                    break;
                }
            }

            if (lineArguments.at(2)=="nve"){
                plans.push_back(Plan(planCounter,*(settlements.at(settlementIndex)) , new NaiveSelection(), facilitiesOptions));
                planCounter++;
            }

            else if (lineArguments.at(2)=="bal"){
                plans.push_back(Plan(planCounter,*(settlements.at(settlementIndex)) , new BalancedSelection(0,0,0), facilitiesOptions));
                planCounter++;
            }

            else if (lineArguments.at(2)=="eco"){
                plans.push_back(Plan(planCounter,*(settlements.at(settlementIndex)) , new EconomySelection(), facilitiesOptions));
                planCounter++;
            }

            else if (lineArguments.at(2)=="env"){
                plans.push_back(Plan(planCounter,*(settlements.at(settlementIndex)) , new SustainabilitySelection(), facilitiesOptions));
                planCounter++;
            }
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
const vector<Plan>& Simulation::getPlans() const{return plans;};
const int Simulation::getPlansCounter() const{return planCounter;}
const vector<BaseAction*>& Simulation::getActionLog(){return actionsLog;}
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
    if(isSettlementExists(settlement->getName())){
        return false;
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
    // delete unused resources
    isRunning = false;
}

void Simulation::open(){
    isRunning = true;
}

void Simulation::start(){
    cout << "The simulation has started" << endl;
    open();
    while(isRunning){
        string action = std::cin<<std::endl;
        vector<string> actionVec = Auxiliary.parseArguments(action);
        if (isValid(actionVec)){
            switch (actionVec.at(0)) {
                case "facility" : 
                    actionsLog.push_back(new AddFacility(actionVec.at(1), actionVec.at(2), actionVec.at(3), actionVec.at(4), actionVec.at(5), actionVec.at(6));
                    BaseAction
                    break;
                case "plan" :
                    actionsLog.push_back(new addPlan())
                    break;
                case "settlement" :
                    actionsLog.push_back()
                    break;
                case "backup" :
                    actionsLog.push_back
                    break;
                case "restore" :
                    actionsLog.push_back
                    break;
                case "changePolicy" :
                    actionsLog.push_back
                    break;
                case "close" :
                    actionsLog.push_back
                    break;
                case "log" :
                    actionsLog.push_back
                    break;
                case "planStatus" :
                    actionsLog.push_back
                    break;  
                case "step" :
                    actionsLog.push_back
                    break;

                default:
                    break; 
            }
            
        }
        else{
            // input noVladimir
        }
       

    }
}





