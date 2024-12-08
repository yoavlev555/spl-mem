#include <iostream>
#include "Simulation.h"
#include "Auxiliary.h"
#include "Action.h"
#include <fstream> 
using namespace std;

// Constructors
Simulation::Simulation(const string &configFilePath):isRunning(false), planCounter(0), plans(), facilitiesOptions(), settlements(), actionsLog(){
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
            for (int i = 0; i < int(settlements.size()); i++){
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


Simulation::Simulation(const Simulation& other):isRunning(other.isRunning),planCounter(other.planCounter), plans(),facilitiesOptions(other.facilitiesOptions.begin(),other.facilitiesOptions.end()), settlements(),actionsLog(){ 
    
    facilitiesOptions = other.facilitiesOptions;
    for(int i=0; i<int(other.actionsLog.size()); i++){
        actionsLog.push_back(other.actionsLog.at(i) -> clone());
    }
    
    for(int i=0; i<int(other.settlements.size()); i++){
        settlements.push_back(other.settlements.at(i) -> clone());
    }

    for(int i =0; i < int(other.plans.size()); i++){
        plans.push_back(Plan(other.plans.at(i),getSettlement(other.plans.at(i).getSettlement().getName()),facilitiesOptions));
    }
}

// Simulation::Simulation(Simulation&& other):isRunning(other.isRunning),planCounter(other.planCounter),plans(other.plans),facilitiesOptions(other.facilitiesOptions){
//     actionsLog = other.actionsLog;
//     settlements = other.settlements;
    
//     other.actionsLog.clear();
//     other.settlements.clear();
// }

// Destructor
Simulation::~Simulation(){
    for(int i = 0; i < int(actionsLog.size()); i++){
       delete actionsLog.at(i);
    }

    for(int i = 0; i < int(settlements.size()); i++){
       delete settlements.at(i);
    }
}

// Operators
Simulation& Simulation::operator=(const Simulation& other){
    if(this != &other){
        isRunning = other.isRunning;
        planCounter = other.planCounter;
        

        plans.clear();
        facilitiesOptions.clear();

        facilitiesOptions = other.facilitiesOptions;

        for (int i=0; i < int(settlements.size());i++){
            delete settlements.at(i);
        }

        for (int i=0; i < int(actionsLog.size());i++){
            delete actionsLog.at(i);
        }

        settlements.clear();
        //std::cout << to_string(settlements.size()) << std::endl;
        actionsLog.clear();
        
        for(int i=0 ; i < int(other.settlements.size()); i++)
        {
            //std::cout<< (other.settlements.at(i)->toString()) << std::endl;
            settlements.push_back(other.settlements.at(i)->clone());
        }
        for(int i=0 ; i < int(other.actionsLog.size()); i++)
        {
            actionsLog.push_back(other.actionsLog.at(i)->clone());
        }
       
        for (int i=0; i < int(other.plans.size());i++){
            plans.push_back((Plan(other.plans.at(i),getSettlement(other.plans.at(i).getSettlement().getName()),facilitiesOptions)));
        } 
    }
    
    return *this;
}

Simulation& Simulation::operator=(Simulation&& other){
    if(this != &other){
        isRunning = other.isRunning;
        planCounter = other.planCounter;
        

        

        for (int i=0; i < int(actionsLog.size()); i++){
            delete actionsLog.at(i);
        }

        for (int i=0; i < int(settlements.size()); i++){
            delete settlements.at(i);
        }


        plans.clear();
       
     
        actionsLog = other.actionsLog;
        settlements = other.settlements;

        other.actionsLog.clear();
        other.settlements.clear();
    }
    
    return *this;
}

// Getters
Plan& Simulation::getPlan(const int planID){return plans.at(planID);}
const vector<Plan>& Simulation::getPlans() const{return plans;};
const int Simulation::getPlansCounter() const{return planCounter;}
const vector<BaseAction*>& Simulation::getActionLog(){return actionsLog;}
Settlement& Simulation::getSettlement(const string &settlementName){
    for(Settlement* s : settlements){
        if(s->getName() == settlementName){
            return *s;
        }
    }
    throw std::runtime_error("No such settlement exists");
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
    for(int i = 0; i < int(plans.size()); i++){
        plans.at(i).step();
    }
}

void Simulation::close(){
    // delete unused resources
    isRunning = false;
}

void Simulation::open(){
    isRunning = true;
}

bool Simulation::isValid(const vector<string>& command){
    if(command.at(0) == "facility"){if(command.size() == 7){return true;}}
    else if(command.at(0) == "plan"){if(command.size() == 3){return true;}}
    else if(command.at(0) == "settlement"){if(command.size() == 3){return true;}}
    else if(command.at(0) == "backup"){if(command.size() == 1){return true;}}
    else if(command.at(0) == "restore"){if(command.size() == 1){return true;}}
    else if(command.at(0) == "changePolicy"){if(command.size() == 3){return true;}}
    else if(command.at(0) == "close"){if(command.size() == 1){return true;}}
    else if(command.at(0) == "log"){if(command.size() == 1){return true;}}
    else if(command.at(0) == "planStatus"){if(command.size() == 2){return true;}}
    else if(command.at(0) == "step"){if(command.size() == 2){return true;}}
    return false;
}

void Simulation::start(){
    cout << "The simulation has started" << endl;
    open();
    while(isRunning){
        string action;
        std::getline(std::cin, action);
        vector<string> actionVec = Auxiliary::parseArguments(action);
        if(isValid(actionVec) == true){
            BaseAction* action;
            if(actionVec.at(0) == "facility") {action = new AddFacility(actionVec.at(1), FacilityType::getCategory(stoi(actionVec.at(2))), stoi(actionVec.at(3)), stoi(actionVec.at(4)), stoi(actionVec.at(5)), stoi(actionVec.at(6)));}      
            else if(actionVec.at(0) == "plan"){action = new AddPlan(actionVec.at(1),actionVec.at(2));}
            else if(actionVec.at(0) == "settlement"){action = new AddSettlement(actionVec.at(1), Settlement::getType(stoi(actionVec.at(2))));} 
            else if(actionVec.at(0) == "backup"){action = new BackupSimulation();}
            else if(actionVec.at(0) == "restore"){action = new RestoreSimulation();}
            else if(actionVec.at(0) == "changePolicy"){action = new ChangePlanPolicy(stoi(actionVec.at(1)), actionVec.at(2));}
            else if(actionVec.at(0) == "close"){action = new Close();}
            else if(actionVec.at(0) == "log"){action = new PrintActionsLog();}
            else if(actionVec.at(0) == "planStatus"){action = new PrintPlanStatus(stoi(actionVec.at(1)));}
            else if(actionVec.at(0) == "step"){action = new SimulateStep(stoi(actionVec.at(1)));}
            
            action->act(*this);
            actionsLog.push_back(action);

        }
        else{
                cout<< "Нир Сурани – настоящий король" << endl;
        }
    }
}





