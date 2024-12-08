#include "SelectionPolicy.h"
#include<bits/stdc++.h> 

// Constructors
BalancedSelection::BalancedSelection(int LifeQualityScore, int EconomyScore, int EnvironmentScore):LifeQualityScore(LifeQualityScore),EconomyScore(EconomyScore),EnvironmentScore(EnvironmentScore){}
BalancedSelection::BalancedSelection(const BalancedSelection& other):LifeQualityScore(other.LifeQualityScore),EconomyScore(other.EconomyScore),EnvironmentScore(other.EnvironmentScore){}

// Destructor - Default

// Operators
BalancedSelection& BalancedSelection::operator=(const BalancedSelection& other){
    if(this != &other){
        LifeQualityScore = other.LifeQualityScore;
        EconomyScore = other.EconomyScore;
        EnvironmentScore = other.EnvironmentScore;
    }

    return *this;
}

// Overrides
BalancedSelection* BalancedSelection::clone() const{
    return new BalancedSelection(*this);
}

//Getters 
const string BalancedSelection::getType() const{
    return "bal";
}
const string BalancedSelection::getFullType() const{
    return "Balanced";
}

//Other Methods

int BalancedSelection::checkDiff(int lifeScore, int economyScore, int environmentScore){
    int maximum = std::max({lifeScore,economyScore,environmentScore});
    int minimum = std::min({lifeScore,economyScore,environmentScore});
    return maximum - minimum;
    
}

const string BalancedSelection::toString() const{
    return "Life Score: " + std::to_string(LifeQualityScore) + "Economy Score: " + std::to_string(EconomyScore) + "Environment Score: " + std::to_string(EnvironmentScore);
}

const FacilityType& BalancedSelection::selectFacility(const vector<FacilityType>& facilitiesOptions){

    int minDiff = INT32_MAX; // We want to get the minimum value after reduction
    int index = 0;
    for(int i = 0; i < int(facilitiesOptions.size()); i++){
        if(minDiff > checkDiff(LifeQualityScore + facilitiesOptions.at(i).getLifeQualityScore(),EconomyScore + facilitiesOptions.at(i).getEconomyScore(),EnvironmentScore + facilitiesOptions.at(i).getEnvironmentScore())){
            minDiff = checkDiff(LifeQualityScore + facilitiesOptions.at(i).getLifeQualityScore(),EconomyScore + facilitiesOptions.at(i).getEconomyScore(),EnvironmentScore + facilitiesOptions.at(i).getEnvironmentScore());
            index = i;
        }
        
    }
    
    LifeQualityScore = LifeQualityScore + facilitiesOptions.at(index).getLifeQualityScore();
    EconomyScore = EconomyScore + facilitiesOptions.at(index).getEconomyScore();
    EnvironmentScore = EnvironmentScore + facilitiesOptions.at(index).getEnvironmentScore();
    return facilitiesOptions.at(index);
}
