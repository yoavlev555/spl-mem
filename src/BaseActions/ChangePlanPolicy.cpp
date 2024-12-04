#include "Action.h"

// Constructor
ChangePlanPolicy::ChangePlanPolicy(const int planId, const string &newPolicy): planID(planID), newPolicy(newPolicy){}

// Desctructor - Default

// Other methods
void ChangePlanPolicy::act(Simulation &simulation){
    if(planID >= simulation.getPlansCounter() || newPolicy == simulation.getPlan(planID).getPolicy().getType()){
        BaseAction::error("Cannot change selection policy");
        std::cout<<BaseAction::getErrorMsg()<<std::endl;
    }
    else{
        Plan p = simulation.getPlan(planID);
        switch (newPolicy){
            case "nve":
                simulation.getPlan(plan_id).ChangePlanPolicy(new NaiveSelection());
                break;
            case "bal":
                simulation.getPlan(plan_id).ChangePlanPolicy(new BalancedSelection(simlation.getTotalLifeQualityScore(),simlation.getTotalEconomyScore(),simlation.getTotalEnvironmentScore()));
                break;
            case "eco":
                simulation.getPlan(plan_id).ChangePlanPolicy(new EconomySelection());
                break;
            case "env":
                simulation.getPlan(plan_id).ChangePlanPolicy(new SustainabilitySelection());
                break;
            
        }
        }
        BaseAction::complete();
    }



/*
public:
        ChangePlanPolicy(const int planId, const string &newPolicy);
        void act(Simulation &simulation) override;
        ChangePlanPolicy *clone() const override;
        const string toString() const override;
    private:
        const int planId;
        const string newPolicy;
*/