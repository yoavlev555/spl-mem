#include "Action.h"

// Constructors
AddFacility::AddFacility(const string &facilityName, const FacilityCategory facilityCategory, const int price, const int lifeQualityScore, const int economyScore, const int environmentScore)
:facilityName(facilityName),facilityCategory(facilityCategory),price(price),lifeQualityScore(lifeQualityScore),economyScore(economyScore),environmentScore(environmentScore){}

// Destructor - Default

// Other methods 
void AddFacility::act(Simulation &simulation){
    if(simulation.addFacility(FacilityType(facilityName, facilityCategory, price, lifeQualityScore, economyScore, environmentScore)) == false){
        BaseAction::error("Facility already exists");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        BaseAction::complete();
    }
}

AddFacility *AddFacility::clone() const{return new AddFacility(facilityName, facilityCategory, price,lifeQualityScore, economyScore, environmentScore);}
const string AddFacility::toString() const{return "Status: " + BaseAction::getStatusAsString();}
