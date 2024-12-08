#include "Facility.h"

// Constructors
Facility::Facility(const string &name, const string &settlementName, const FacilityCategory category, const int price, const int lifeQuality_score, const int economy_score, const int environment_score)
:FacilityType(name, category, price, lifeQuality_score, economy_score, environment_score), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(price){}
Facility::Facility(const FacilityType &type, const string &settlementName)
:FacilityType(type.getName(), type.getCategory(), type.getCost(), type.getLifeQualityScore(), type.getEconomyScore(), type.getEnvironmentScore()), settlementName(settlementName), status(FacilityStatus::UNDER_CONSTRUCTIONS), timeLeft(type.getCost()){}
Facility::Facility(const Facility& other)
:FacilityType::FacilityType(other.name, other.category, other.price, other.lifeQuality_score, other.economy_score, other.environment_score), settlementName(other.settlementName), status(other.status), timeLeft(other.price){}

// Destructor - Default

// Operators
Facility& Facility::operator=(const Facility& other){ 
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
FacilityStatus Facility::step(){
    if(timeLeft > 0){
        timeLeft--;
    }
    
    if(timeLeft == 0){
        setStatus(FacilityStatus::OPERATIONAL);
        return FacilityStatus::OPERATIONAL;
    }

    return FacilityStatus::UNDER_CONSTRUCTIONS;
}

Facility* Facility::clone(){
    return new Facility(*this);
}

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

