#include "Plan.h"
#include <iostream>

using namespace std;

// Constructors
Plan::Plan(const int planId, const Settlement &settlement, SelectionPolicy *selectionPolicy, const vector<FacilityType> &facilityOptions)
:plan_id(planId),settlement(settlement),selectionPolicy(selectionPolicy),facilityOptions(facilityOptions),status(PlanStatus::AVALIABLE),facilities(vector<Facility*>()),underConstruction(vector<Facility*>()){
    life_quality_score = 0;
    environment_score = 0;
    economy_score = 0;
}
Plan::Plan(const Plan& other,Settlement& otherSettlement)
:plan_id(other.plan_id),settlement(otherSettlement),status(other.status), facilityOptions(other.facilityOptions), life_quality_score(other.life_quality_score), environment_score(other.environment_score), economy_score(other.economy_score),facilities(),underConstruction(){
    selectionPolicy = other.selectionPolicy->clone();

    for (int i=0; i <int(other.facilities.size()); i++){
        facilities.push_back(other.facilities.at(i) -> clone());
    }

    for (int i=0; i <int(other.underConstruction.size()); i++){
        underConstruction.push_back(other.underConstruction.at(i) -> clone());
    }
}
Plan::Plan(const int planId, const Settlement &settlement,SelectionPolicy *selectionPolicy, const vector<FacilityType> &facilityOptions,int lifeScore, int economyScore, int enviromentScore) 
:plan_id(planId),settlement(settlement),selectionPolicy(selectionPolicy->clone()),status(PlanStatus::AVALIABLE), facilities(), underConstruction(),facilityOptions(facilityOptions), life_quality_score(0),economy_score(0), environment_score(0){}

Plan::Plan(const Plan& other):plan_id(other.plan_id),settlement(other.settlement),status(other.status), facilityOptions(other.facilityOptions), life_quality_score(other.life_quality_score), environment_score(other.environment_score), economy_score(other.economy_score),facilities(),underConstruction(){
   
    selectionPolicy = other.selectionPolicy->clone();

    for (int i=0; i <int(other.facilities.size()); i++){
        facilities.push_back(other.facilities.at(i) -> clone());
    }

    for (int i=0; i <int(other.underConstruction.size()); i++){
        underConstruction.push_back(other.underConstruction.at(i) -> clone());
    }
}
Plan::Plan(Plan&& other):plan_id(other.plan_id),settlement(other.settlement),facilityOptions(other.facilityOptions),status(other.status),life_quality_score(other.life_quality_score), economy_score(other.economy_score), environment_score(other.environment_score){
    for (int i = 0; i < int(other.facilities.size()) ; i++){
        facilities.push_back(other.facilities[i]);
        other.facilities.at(i) = nullptr;
    }
    for (int i = 0;  i < int(other.underConstruction.size()) ; i++){
        underConstruction.push_back(other.underConstruction[i]);
        other.underConstruction.at(i) = nullptr;
    }
        other.underConstruction.clear();
        other.facilities.clear();
        selectionPolicy=other.selectionPolicy;
        other.selectionPolicy = nullptr;
}

// Destructor
Plan::~Plan(){
    delete selectionPolicy;

    for(int i=0; i < int(facilities.size()); i++){
        if (facilities.at(i) != nullptr)
        delete facilities.at(i);
        facilities.at(i) = nullptr;
    }

    for(int i=0; i < int(underConstruction.size()); i++){
        delete underConstruction.at(i);
        underConstruction.at(i)= nullptr;
    }
}

// Operators - Deleted

// Getters
const int Plan::getID() const {return plan_id;}
const Settlement& Plan::getSettlement() const {return settlement;}
const int Plan::getlifeQualityScore() const{return life_quality_score;}
const int Plan::getEconomyScore() const{return economy_score;}
const int Plan::getEnvironmentScore() const{return environment_score;}
const vector<Facility*>& Plan::getFacilities() const{return facilities;}
const SelectionPolicy& Plan::getPolicy() const{return *selectionPolicy;}
int Plan::getTotalLifeQualityScore(){
    int val = life_quality_score;
    for (Facility* f: underConstruction){
        val = val + f->getLifeQualityScore();
    }
    return val;
}
int Plan::getTotalEconomyScore(){
    int val = economy_score;
    for (Facility* f: underConstruction){
        val = val + f->getEconomyScore();
    }
    return val;
}
int Plan::getTotalEnvironmentScore(){
    int val = environment_score;
    for (Facility* f: underConstruction){
        val = val + f->getEnvironmentScore();
    }
    return val;
}

// Setters
void Plan::setSelectionPolicy(SelectionPolicy *otherSelectionPolicy){
    delete selectionPolicy;
    selectionPolicy = otherSelectionPolicy->clone();
    delete otherSelectionPolicy;
}

void Plan::moveSelectionPolicy(SelectionPolicy*&& otherSelectionPolicy){
    delete selectionPolicy;
    selectionPolicy = otherSelectionPolicy;
    otherSelectionPolicy = nullptr;
}

// Other Methods
void Plan::step(){
    if(status == PlanStatus::AVALIABLE){
        while(int(underConstruction.size()) < int(settlement.getMaxCapacity())){
            underConstruction.push_back(new Facility(selectionPolicy->selectFacility(facilityOptions),settlement.toString()));
        }
    }

    status = PlanStatus::BUSY;
    /*
    vector<Facility*>::iterator iter = underConstruction.begin();
    while(iter != underConstruction.end()){
        if((*iter)->step() == FacilityStatus::OPERATIONAL){
            facilities.push_back(*iter);
            life_quality_score += (*iter)->getLifeQualityScore();
            environment_score += (*iter)->getEnvironmentScore();
            economy_score += (*iter)->getEconomyScore();
            underConstruction.erase(iter);
        }
        else{
            iter++;
        }
    */

    for (int i=0; i < int(underConstruction.size());){
        FacilityStatus temp = underConstruction.at(i)->step();
        if (temp == FacilityStatus::OPERATIONAL){
            addFacility(underConstruction.at(i));
            underConstruction.erase(underConstruction.begin() + i);
        }
        else{
            i++;
        }
    }

    if(int(underConstruction.size()) < int(settlement.getMaxCapacity())){
        status = PlanStatus::AVALIABLE;
    }
    else{
        status = PlanStatus::BUSY;
    }
}

void Plan::printPlan(){
    cout << "PlanID: " + std::to_string(plan_id) << endl;
    cout << "SettlementName: " + settlement.getName() << endl;
    string stat = (status == PlanStatus::AVALIABLE)? "AVAILABLE" : "BUSY";
    cout << "PlanStatus: " + stat << endl;
    cout << "SelectionPolicy: " + selectionPolicy->getType() << endl;
    cout << "LifeQualityScore: " + to_string(life_quality_score) << endl;
    cout << "EconomyScore: " + to_string(economy_score) << endl;
    cout << "EnvironmentScore: " + to_string(environment_score) << endl;

    for (Facility* facility: underConstruction){
        cout << "FacilityName: " + facility->getName() << endl;
        cout << "FacilityStatus: UNDER_CONSTUCTIONS" << endl; 
    }

    for (Facility* facility: facilities){
        cout << "FacilityName: " + facility->getName() << endl;
        cout << "FacilityStatus: OPERATIONAL" << endl; 
    } 
}

void Plan::addFacility(Facility* facility){ 
    underConstruction.push_back(facility);
}

void Plan::printStatus(){
    string s;
    switch (status)
    {
    case PlanStatus::AVALIABLE:
        std::cout << "AVAILABLE" << std::endl;
        break;

    case PlanStatus::BUSY:
        std::cout << "Status is Busy" << std::endl;
        break;
    }
}

const string Plan::toString() const{
    
    std::cout << "Plan ID is: " + std::to_string(plan_id) << std::endl;
    switch (status)
    {
    case PlanStatus::AVALIABLE:
        std::cout << "Status is Available" << std::endl;
        break;

    case PlanStatus::BUSY:
        std::cout << "Status is Busy" << std::endl;
        break;
    }
    
    for(Facility* f : facilities){
        std::cout << f->toString() << std::endl;
    }

    for(Facility* f : underConstruction){
       std::cout << f->toString() << std::endl;
    }

    std::cout << "Score: " << std::to_string(life_quality_score) + "," << std::to_string(economy_score) + "," << std::to_string(environment_score)<<std::endl;
    return "";
}


