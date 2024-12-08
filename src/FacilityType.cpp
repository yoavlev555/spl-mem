#include "Facility.h"


// Constructors
FacilityType::FacilityType(const string &otherName, const FacilityCategory otherCategory, const int otherPrice, const int otherLifeQuality_score, const int otherEconomy_score, const int otherEnvironment_score):name(otherName), category(otherCategory), price(otherPrice), lifeQuality_score(otherLifeQuality_score), economy_score(otherEconomy_score), environment_score(otherEnvironment_score){}
FacilityType::FacilityType(const FacilityType& other):name(other.name), category(other.category), price(other.price), lifeQuality_score(other.lifeQuality_score), economy_score(other.economy_score), environment_score(other.environment_score){}

// Destructor - Default


// Operators
FacilityType& FacilityType::operator=(const FacilityType& other){return *this;}

// Getters
const string& FacilityType::getName() const {return name;}
int FacilityType::getCost() const {return price;}
int FacilityType::getLifeQualityScore() const{return lifeQuality_score;}
int FacilityType::getEnvironmentScore() const{return environment_score;}
int FacilityType::getEconomyScore() const{return economy_score;}
FacilityCategory FacilityType::getCategory() const{return category;}
const int FacilityType::getFacilityCategory() const{
    if (category == FacilityCategory::LIFE_QUALITY){return 0;}
    else if (category == FacilityCategory::ECONOMY){return 1;}
    else {return 2;}
}
FacilityCategory FacilityType::getCategory(int i){
    if(i == 0) {return FacilityCategory::LIFE_QUALITY;}
    else if(i == 1) {return FacilityCategory::ECONOMY;}
    else {return FacilityCategory::ENVIRONMENT;}
}