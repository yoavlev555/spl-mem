#pragma once
#include <vector>
#include "Facility.h"
#include "Settlement.h"
#include "SelectionPolicy.h"
using std::vector;

enum class PlanStatus {
    AVALIABLE,
    BUSY,
};

class Plan {
    public:
        Plan(const int planId, const Settlement &settlement, SelectionPolicy *selectionPolicy, const vector<FacilityType> &facilityOptions);
        /*--------------------RO3--------------------*/ 
        Plan(const Plan& other);
        ~Plan();
        Plan& operator=(const Plan& other);




        /*--------------------RO5--------------------*/ 




        /*-------------------OTHER-------------------*/ 
        
        const int getlifeQualityScore() const;
        const int getEconomyScore() const;
        const int getEnvironmentScore() const;
        void setSelectionPolicy(SelectionPolicy *selectionPolicy);
        // void setSelectionPolicy(SelectionPolicy*&& selectionPolicy); if wanted
        void step();
        void step();
        void printStatus();
        const vector<Facility*> &getFacilities() const;
        void addFacility(Facility* facility);
        const string getPolicyName() const;
        const string toString() const;
        const int getID() const;
        const SelectionPolicy& getPolicy() const;
        const Settlement& getSettlement() const;
        int getTotalLifeQualityScore();
        int getTotalEconomyScore();
        int getTotalEnvironmentScore();
        void printPlan();
        
    private:
        int plan_id;
        const Settlement &settlement;
        SelectionPolicy *selectionPolicy; //What happens if we change this to a reference?
        PlanStatus status;
        vector<Facility*> facilities;
        vector<Facility*> underConstruction;
        const vector<FacilityType> &facilityOptions;
        int life_quality_score, economy_score, environment_score;
};