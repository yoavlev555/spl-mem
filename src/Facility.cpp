#include "Facility.h"




// Constructors
Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
:FacilityType(name,category,price,lifeQuality_score,economy_score,environment_score),settlementName(settlementName), timeLeft(price), status(FacilityStatus::UNDER_CONSTRUCTIONS){}

Facility::Facility(const FacilityType &type, const string &settlementName)
:FacilityType(type.getName(),type.getCategory(),type.getCost(),type.getLifeQualityScore(),type.getEconomyScore(),type.getEnvironmentScore()),settlementName(settlementName),timeLeft(type.getCost()), status(FacilityStatus::UNDER_CONSTRUCTIONS){}

Facility::Facility(const Facility& other)
:FacilityType(other.name,other.category,other.price,other.lifeQuality_score,other.economy_score,other.environment_score),settlementName(other.settlementName), timeLeft(other.price), status(other.status){}

// Destructor
Facility::~Facility(){} // Use default. Calls automaticly to ~FacilityType

// Operators
Facility& Facility::operator=(const Facility& other){ // We will never use this as this is makes no sense to assign another timeLeft or status to another facility.
    if(this != &other){
        timeLeft = other.timeLeft;
        status = other.status;
    }

    return *this;
} 


// Getters
const string &Facility::getSettlementName() const{return settlementName;}
const int Facility::getTimeLeft() const{return timeLeft;}
const FacilityStatus& Facility::getStatus() const{return status;}

// Setters
void Facility::setStatus(FacilityStatus otherStatus){status = otherStatus;}

// Other methods
FacilityStatus Facility::step(){}

const string Facility::toString() const{
    string statusVal;
    switch (status){
    case FacilityStatus::UNDER_CONSTRUCTIONS:
        statusVal = "Under Construction";
        break;
    case FacilityStatus::OPERATIONAL:
        statusVal = "Operetional";
        break;
    default:
        break;
    }

    return "Facility Name: " + name + " Status: " + statusVal + "Time Left: " + std::to_string(timeLeft) +  "Settlement Name: " + settlementName;
}

