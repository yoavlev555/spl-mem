#include "SelectionPolicy.h"

// Constructors
EconomySelection::EconomySelection():lastSelectedIndex(0){}
EconomySelection::EconomySelection(const EconomySelection& other):lastSelectedIndex(other.lastSelectedIndex){}

// Destructor - Default

// Operators
EconomySelection& EconomySelection::operator=(const EconomySelection& other){
    if(this != &other){
        lastSelectedIndex = other.lastSelectedIndex;
    }

    return *this;
}


// Getters 
const string EconomySelection::getType() const{return "eco";}
const string EconomySelection::getFullType() const{return "Economy";}


// Overrides 
const FacilityType& EconomySelection::selectFacility(const vector<FacilityType>& facilitiesOptions){  
    if (lastSelectedIndex >= int(facilitiesOptions.size())) {
        lastSelectedIndex = 0;
    }
    for (int i = lastSelectedIndex; i < int(facilitiesOptions.size()); i++) {
        if (facilitiesOptions[i].getCategory() == FacilityCategory::ECONOMY) {
            lastSelectedIndex = i + 1;
            return facilitiesOptions[i];
        }
    }
    for (int i = 0; i < int(lastSelectedIndex); i++) {
        if (facilitiesOptions[i].getCategory() == FacilityCategory::ECONOMY) {
            lastSelectedIndex = i + 1;
            return facilitiesOptions[i];
        }
    }
    throw std::runtime_error("No Economy Category found in the facilitiesOptions vector");
}

EconomySelection* EconomySelection::clone() const{
    return new EconomySelection(*this);
}

const string EconomySelection::toString() const{
    return "last selected index is: " + std::to_string(lastSelectedIndex);
}