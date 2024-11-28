#include "SelectionPolicy.h"

// Constructors
EconomySelection::EconomySelection():lastSelectedIndex(0){}
EconomySelection::EconomySelection(const EconomySelection& other):lastSelectedIndex(other.lastSelectedIndex){}

// Destructor - use default, not needed

// Operators
EconomySelection& EconomySelection::operator=(const EconomySelection& other){
    if(this != &other){
        lastSelectedIndex = other.lastSelectedIndex;
    }

    return *this;
}

// Overrides 
const FacilityType& EconomySelection::selectFacility(const vector<FacilityType>& facilitiesOptions){  
    vector<int> indexes = vector<int>();
    int i=0;
    for (FacilityType ft : facilitiesOptions){
        if (ft.getCategory()==FacilityCategory::ECONOMY){
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
    throw std::runtime_error("No Economy Category found in the facilitiesOptions vector");
}

EconomySelection* EconomySelection::clone() const{
    return new EconomySelection(*this);
}

const string EconomySelection::toString() const{
    return "last selected index is: " + std::to_string(lastSelectedIndex);
}

