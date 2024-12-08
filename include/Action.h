#pragma once
#include <string>
#include <vector>
#include "Simulation.h"
enum class SettlementType;
enum class FacilityCategory;

enum class ActionStatus{
    COMPLETED, ERROR
};

class BaseAction{
    public:
        BaseAction();
        BaseAction(const ActionStatus& otherStatus, const string otherMsg);
        /*--------------------RO3--------------------*/ 
        BaseAction(const BaseAction& other);
        virtual ~BaseAction() = default;
        BaseAction& operator=(const BaseAction& other);

        /*-------------------OTHER-------------------*/ 
        const string getStatusAsString() const;
        ActionStatus getStatus() const;
        virtual void act(Simulation& simulation)=0;
        virtual const string toString() const=0;
        virtual BaseAction* clone() const = 0;

    protected:
        void complete();
        void error(string errorMsg);
        const string &getErrorMsg() const;

    private:
        string errorMsg;
        ActionStatus status;
};

class SimulateStep : public BaseAction {
    public:
        SimulateStep(const int numOfSteps);
        /*--------------------RO3--------------------*/ 
        SimulateStep(const SimulateStep& other);
        ~SimulateStep() = default;
        SimulateStep& operator=(const SimulateStep& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        const string toString() const override;
        SimulateStep *clone() const override;

    private:
        const int numOfSteps;
};

class AddPlan : public BaseAction {
    public:
        AddPlan(const string &settlementName, const string &selectionPolicy);
        /*--------------------RO3--------------------*/ 
        AddPlan(const AddPlan& other);
        ~AddPlan() = default;
        AddPlan& operator=(const AddPlan& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        const string toString() const override;
        AddPlan *clone() const override;

    private:
        bool isValidPolicy();
        const string settlementName;
        const string selectionPolicy;
};


class AddSettlement : public BaseAction {
    public:
        AddSettlement(const string &settlementName,SettlementType settlementType);
        /*--------------------RO3--------------------*/ 
        AddSettlement(const AddSettlement& other);
        ~AddSettlement() = default;
        AddSettlement& operator=(const AddSettlement& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        AddSettlement *clone() const override;
        const string toString() const override;

    private:
        const string settlementName;
        const SettlementType settlementType;
};



class AddFacility : public BaseAction {
    public:
        AddFacility(const string &facilityName, const FacilityCategory facilityCategory, const int price, const int lifeQualityScore, const int economyScore, const int environmentScore);
        /*--------------------RO3--------------------*/ 
        AddFacility(const AddFacility& other);
        ~AddFacility() = default;
        AddFacility& operator=(const AddFacility& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        AddFacility *clone() const override;
        const string toString() const override;

    private:
        const string facilityName;
        const FacilityCategory facilityCategory;
        const int price;
        const int lifeQualityScore;
        const int economyScore;
        const int environmentScore;

};

class PrintPlanStatus: public BaseAction {
    public:
        PrintPlanStatus(int planId);
        /*--------------------RO3--------------------*/ 
        PrintPlanStatus(const PrintPlanStatus& other);
        ~PrintPlanStatus() = default;
        PrintPlanStatus& operator=(const PrintPlanStatus& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        PrintPlanStatus *clone() const override;
        const string toString() const override;

    private:
        const int planId;
};


class ChangePlanPolicy : public BaseAction {
    public:
        ChangePlanPolicy(const int planId, const string &newPolicy);
        /*--------------------RO3--------------------*/ 
        ChangePlanPolicy(const ChangePlanPolicy& other);
        ~ChangePlanPolicy() = default;
        ChangePlanPolicy& operator=(const ChangePlanPolicy& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        ChangePlanPolicy *clone() const override;
        const string toString() const override;

    private:
        const int planId;
        const string newPolicy;
};


class PrintActionsLog : public BaseAction {
    public:
        PrintActionsLog();
        /*--------------------RO3--------------------*/ 
        PrintActionsLog(const PrintActionsLog& other);
        ~PrintActionsLog() = default;
        PrintActionsLog& operator=(const PrintActionsLog& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        PrintActionsLog *clone() const override;
        const string toString() const override;

    private:
};

class Close : public BaseAction {
    public:
        Close();
        /*--------------------RO3--------------------*/ 
        Close(const Close& Close);
        ~Close() = default;
        Close& operator=(const Close& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        Close *clone() const override;
        const string toString() const override;

    private:
};

class BackupSimulation : public BaseAction {
    public:
        BackupSimulation();
        /*--------------------RO3--------------------*/ 
        BackupSimulation(const BackupSimulation& other);
        ~BackupSimulation() = default;
        BackupSimulation& operator=(const BackupSimulation& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        BackupSimulation *clone() const override;
        const string toString() const override;

    private:
};


class RestoreSimulation : public BaseAction {
    public:
        RestoreSimulation();
        /*--------------------RO3--------------------*/ 
        RestoreSimulation(const RestoreSimulation& other);
        ~RestoreSimulation() = default;
        RestoreSimulation& operator=(const RestoreSimulation& other);

        /*-------------------OTHER-------------------*/ 
        void act(Simulation &simulation) override;
        RestoreSimulation *clone() const override;
        const string toString() const override;
        
    private:
};

