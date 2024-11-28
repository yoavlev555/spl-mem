#include "SelectionPolicy.h"

// Constructors
SustainabilitySelection::SustainabilitySelection():lastSelectedIndex(0){}
SustainabilitySelection::SustainabilitySelection(const SustainabilitySelection& other):lastSelectedIndex(other.lastSelectedIndex){}

// Destructor - use default, not needed

// Operators
SustainabilitySelection& SustainabilitySelection::operator=(const SustainabilitySelection& other){
    if(this != &other){
        lastSelectedIndex = other.lastSelectedIndex;
    }

    return *this;
}

// Overrides 
const FacilityType& SustainabilitySelection::selectFacility(const vector<FacilityType>& facilitiesOptions){  
    vector<int> indexes = vector<int>();
    int i=0;
    for (FacilityType ft : facilitiesOptions){
        if (ft.getCategory()==FacilityCategory::ENVIRONMENT){
            indexes.push_back(i);
        }
        i++;
    }

    if (indexes.size()>0){
        for(int i : indexes){
            if (i>=lastSelectedIndex){
                lastSelectedIndex=i;
                const FacilityType& res = facilitiesOptions.at(lastSelectedIndex);
                lastSelectedIndex = (lastSelectedIndex + 1) % facilitiesOptions.size();
                return res;
            }
        }

        lastSelectedIndex = indexes.at(0);
        const FacilityType& res = facilitiesOptions.at(lastSelectedIndex);
        return res;
    }
    throw std::runtime_error("No Environment Category found in the facilitiesOptions vector");
}

SustainabilitySelection* SustainabilitySelection::clone() const{
    return new SustainabilitySelection(*this);
}

const string SustainabilitySelection::toString() const{
    return "last selected index is: " + std::to_string(lastSelectedIndex);
}

