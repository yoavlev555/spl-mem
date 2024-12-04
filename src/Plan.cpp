#include "Plan.h"
#include <iostream>

// Constructors
Plan::Plan(const int planId, const Settlement &settlement, SelectionPolicy *selectionPolicy, const vector<FacilityType> &facilityOptions)
:plan_id(planId),settlement(settlement),selectionPolicy(selectionPolicy),facilityOptions(facilityOptions),status(PlanStatus::AVALIABLE),facilities(vector<Facility*>()),underConstruction(vector<Facility*>()){
    life_quality_score = 0;
    environment_score = 0;
    economy_score = 0;
}

Plan::Plan(const Plan& other):Plan(other.plan_id,other.settlement,other.selectionPolicy->clone(),other.facilityOptions){
    life_quality_score = other.life_quality_score;
    environment_score = other.environment_score;
    economy_score = other.economy_score;
    for(Facility* f : other.facilities){
        facilities.push_back(f->clone());
    }

    for(Facility* f : other.underConstruction){
        underConstruction.push_back(f->clone());
    }
}

// Destructor
Plan::~Plan(){
    delete selectionPolicy;

    for(int i=0; i < facilities.size(); i++){
        delete facilities[i];
    }

    for(int i=0; i < underConstruction.size(); i++){
        delete underConstruction[i];
    }
}

// Operators
Plan Plan::operator=(const Plan& other){
    if(this != &other){
        plan_id = other.plan_id;
        status = other.status;
        life_quality_score = other.life_quality_score;
        environment_score = other.environment_score;
        economy_score = other.economy_score;


        delete selectionPolicy;
        selectionPolicy = other.selectionPolicy->clone();

        for(Facility* f : facilities){
            delete f;
        }

        for(Facility* f : underConstruction){
            delete f;
        }
        
        facilities.clear();
        underConstruction.clear();

        for(Facility* f : other.facilities){
            facilities.push_back(f->clone());
        }

        for(Facility* f : other.underConstruction){
            underConstruction.push_back(f->clone());
        }
        
        
        
    }
    
}

// Getters
const int Plan::getlifeQualityScore() const{return life_quality_score;}
const int Plan::getEconomyScore() const{return economy_score;}
const int Plan::getEnvironmentScore() const{return environment_score;}
const vector<Facility*>& Plan::getFacilities() const{return facilities;}
const SelectionPolicy& Plan::getPolicy() const{return *selectionPolicy;}
// Setters
void Plan::setSelectionPolicy(SelectionPolicy *selectionPolicy){
    delete selectionPolicy;
    selectionPolicy = selectionPolicy->clone();
}

// Other Methods
void Plan::step(){
    if(status != PlanStatus::BUSY){
        while(underConstruction.size() < settlement.getMaxCapacity()){
            underConstruction.push_back(new Facility(selectionPolicy->selectFacility(facilityOptions),settlement.toString()));
        }
    }

    status = PlanStatus::BUSY;
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
    }

    if(underConstruction.size() != settlement.getMaxCapacity()){
        status = PlanStatus::AVALIABLE;
    }
}

void Plan::addFacility(Facility* facility){ 
    underConstruction.push_back(facility);
}

void Plan::printStatus(){
    switch (status)
    {
    case PlanStatus::AVALIABLE:
        std::cout << "Status is Available" << std::endl;
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


