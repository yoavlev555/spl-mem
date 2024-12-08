#include "SelectionPolicy.h"

// Constructors
SustainabilitySelection::SustainabilitySelection():lastSelectedIndex(0){}
SustainabilitySelection::SustainabilitySelection(const SustainabilitySelection& other):lastSelectedIndex(other.lastSelectedIndex){}

// Destructor - Default

// Operators
SustainabilitySelection& SustainabilitySelection::operator=(const SustainabilitySelection& other){
    if(this != &other){
        lastSelectedIndex = other.lastSelectedIndex;
    }

    return *this;
}

// Getters
const string SustainabilitySelection::getType() const{return "env";}
const string SustainabilitySelection::getFullType() const{return "Sustainability";}

// Overrides 
const FacilityType& SustainabilitySelection::selectFacility(const vector<FacilityType>& facilitiesOptions){  
    if (lastSelectedIndex >= int(facilitiesOptions.size())) {
        lastSelectedIndex = 0;
    }
    for (int i = int((lastSelectedIndex)); i < int(facilitiesOptions.size()); i++) {
        if (facilitiesOptions[i].getCategory() == FacilityCategory::ENVIRONMENT) {
            lastSelectedIndex = i + 1;
            return facilitiesOptions[i];
        }
    }
    for (int i = 0; i < int((lastSelectedIndex)); i++) {
        if (facilitiesOptions[i].getCategory() == FacilityCategory::ENVIRONMENT) {
            lastSelectedIndex = i + 1;
            return facilitiesOptions[i];
        }
    }
    throw std::runtime_error("No Environment Category found in the facilitiesOptions vector");
}

SustainabilitySelection* SustainabilitySelection::clone() const{
    return new SustainabilitySelection(*this);
}

const string SustainabilitySelection::toString() const{
    return "last selected index is: " + std::to_string(lastSelectedIndex);
}

