#pragma once
#include <string>
#include <vector>
#include "Facility.h"
#include "Plan.h"
#include "Settlement.h"
using std::string;
using std::vector;

class BaseAction;
class SelectionPolicy;

class Simulation {
    public:
        Simulation(const string &configFilePath);
        /*--------------------RO3--------------------*/
        Simulation(const Simulation& other);
        ~Simulation();
        Simulation& operator=(const Simulation& other);

        /*--------------------RO5--------------------*/
        // Simulation(Simulation&& other);
        Simulation& operator=(Simulation&& other);

        /*-------------------OTHER-------------------*/

        void start();
        void addPlan(const Settlement &settlement, SelectionPolicy *selectionPolicy);
        void addAction(BaseAction *action);
        bool addSettlement(Settlement *settlement);
        bool addFacility(FacilityType facility);
        bool isSettlementExists(const string &settlementName);
        Settlement &getSettlement(const string &settlementName);
        Plan &getPlan(const int planID);
        const vector<Plan>& getPlans() const;
        const int getPlansCounter() const;
        bool isValid(const vector<string>& line);
        void step();
        void close();
        void open();
        const vector<BaseAction*>& getActionLog(); 

    private:
        bool isRunning;
        int planCounter; //For assigning unique plan IDs
        vector<Plan> plans; 
        vector<FacilityType> facilitiesOptions;
        vector<Settlement*> settlements;
        vector<BaseAction*> actionsLog;
};