#include "SelectionPolicy.h"

// Constructors
BalancedSelection::BalancedSelection(int LifeQualityScore, int EconomyScore, int EnvironmentScore):LifeQualityScore(LifeQualityScore),EconomyScore(EconomyScore),EnvironmentScore(EnvironmentScore){}
BalancedSelection::BalancedSelection(const BalancedSelection& other):LifeQualityScore(other.LifeQualityScore),EconomyScore(other.EconomyScore),EnvironmentScore(other.EnvironmentScore){}

// Destructor (Default)

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

const FacilityType& BalancedSelection::selectFacility(const vector<FacilityType>& facilitiesOptions){
    int index = 0;
    int minDiff = INT32_MAX; // We want to get the minimum value after reduction
    int i = 0;
    for (FacilityType ft:facilitiesOptions){
        int current = checkDiff(LifeQualityScore + ft.getLifeQualityScore(), EconomyScore + ft.getEconomyScore(), EnvironmentScore + ft.getEnvironmentScore());
        if( current < minDiff){
            minDiff = current;
            index = i;
        }
        i=i+1;
    }
    const FacilityType& res = facilitiesOptions.at(index);
    LifeQualityScore += res.getLifeQualityScore();
    EconomyScore += res.getEconomyScore();
    EnvironmentScore += res.getEnvironmentScore();
    return res;
}

int BalancedSelection::checkDiff(int lifeScore, int economyScore, int environmentScore){
    if(lifeScore > economyScore){
        if(economyScore > environmentScore){
            return lifeScore - environmentScore;
        }
        else{
            return lifeScore - economyScore;
        }
    }

    else{
        if(lifeScore > environmentScore){
            return economyScore - environmentScore;
        }
        else{
            return economyScore - lifeScore;
        }
    }
    
}

const string BalancedSelection::toString() const{
    return "Life Score: " + std::to_string(LifeQualityScore) + "Economy Score: " + std::to_string(EconomyScore) + "Environment Score: " + std::to_string(EnvironmentScore);
}
