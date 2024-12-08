#include "Action.h"

// Constructors
AddFacility::AddFacility(const string &facilityName, const FacilityCategory facilityCategory, const int price, const int lifeQualityScore, const int economyScore, const int environmentScore)
:BaseAction::BaseAction(), facilityName(facilityName),facilityCategory(facilityCategory), price(price), lifeQualityScore(lifeQualityScore), economyScore(economyScore), environmentScore(environmentScore){}

AddFacility::AddFacility(const AddFacility& other):BaseAction::BaseAction(other.getStatus(), other.getErrorMsg()), facilityName(other.facilityName), facilityCategory(other.facilityCategory), price(other.price), lifeQualityScore(other.lifeQualityScore), economyScore(other.economyScore), environmentScore(other.environmentScore){}

// Destructor - Default

// Operators
AddFacility& AddFacility::operator=(const AddFacility& other){return *this;}

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

AddFacility *AddFacility::clone() const{return new AddFacility(*this);}
const string AddFacility::toString() const{
    int category;
    if (facilityCategory == FacilityCategory::LIFE_QUALITY){category = 0;}
    else if (facilityCategory == FacilityCategory::ECONOMY){category = 1;}
    else if (facilityCategory == FacilityCategory::ENVIRONMENT){category = 2;}
    return "facility " + facilityName + " " + std::to_string(category) + " " + std::to_string(price) + " " + std::to_string(lifeQualityScore) + " " + std::to_string(economyScore) + " " + std::to_string(environmentScore) + " " + BaseAction::getStatusAsString();
}
