#include "SelectionPolicy.h"

// Constructors
NaiveSelection::NaiveSelection():lastSelectedIndex(0){};
NaiveSelection::NaiveSelection(const NaiveSelection& other):lastSelectedIndex(other.lastSelectedIndex){}

// Destructor - use default, not needed

// Operators
NaiveSelection& NaiveSelection::operator=(const NaiveSelection& other){
    if(this != &other){
        lastSelectedIndex = other.lastSelectedIndex;
    }

    return *this;
}

// Getters
const string NaiveSelection::getType() const{return "nve";}
const string NaiveSelection::getFullType() const{return "Naive";}

// Overrides
const FacilityType& NaiveSelection::selectFacility(const vector<FacilityType>& facilitiesOptions){
    const FacilityType& res = facilitiesOptions.at(lastSelectedIndex);

    lastSelectedIndex = (lastSelectedIndex + 1) % facilitiesOptions.size();
    return res;
}

NaiveSelection* NaiveSelection::clone() const{
    return new NaiveSelection(*this);
}

const string NaiveSelection::toString() const{
    return "last selected index is: " + std::to_string(lastSelectedIndex);
}





