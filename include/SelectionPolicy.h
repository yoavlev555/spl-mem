#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Facility.h"
using std::vector;
using std::string;

class SelectionPolicy {
    public:
        virtual const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) = 0;
        virtual const string toString() const = 0;
        virtual SelectionPolicy* clone() const = 0;
        virtual ~SelectionPolicy() = default;
        virtual const string getType() const = 0;
        virtual const string getFullType() const = 0;
};

class NaiveSelection: public SelectionPolicy {
    public:
        NaiveSelection();
        /*--------------------RO3--------------------*/ 
        NaiveSelection(const NaiveSelection& other);
        ~NaiveSelection() override = default;
        NaiveSelection& operator=(const NaiveSelection& other);

        /*-------------------OTHER-------------------*/
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        NaiveSelection *clone() const override;
        const string getType() const override;
        const string getFullType() const override;
    private:
        int lastSelectedIndex;
};

class BalancedSelection: public SelectionPolicy {
    public:
        BalancedSelection(int LifeQualityScore, int EconomyScore, int EnvironmentScore);
        /*--------------------RO3--------------------*/ 
        BalancedSelection(const BalancedSelection& other);
        ~BalancedSelection() override = default;
        BalancedSelection& operator=(const BalancedSelection& other);

        /*-------------------OTHER-------------------*/
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        BalancedSelection *clone() const override;
        const string getType() const override;
        int checkDiff(int lifeScore, int economyScore, int environmentScore);
        const string getFullType() const override;

    private:
        int LifeQualityScore;
        int EconomyScore;
        int EnvironmentScore;
};

class EconomySelection: public SelectionPolicy {
    public:
        EconomySelection();
        /*--------------------RO3--------------------*/ 
        EconomySelection(const EconomySelection& other);        
        ~EconomySelection() override = default;
        EconomySelection& operator=(const EconomySelection& other);

        /*-------------------OTHER-------------------*/
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        EconomySelection *clone() const override;
        const string getType() const override;
        const string getFullType() const override;
    private:
        int lastSelectedIndex;

};

class SustainabilitySelection: public SelectionPolicy {
    public:
        SustainabilitySelection();
        /*--------------------RO3--------------------*/ 
        SustainabilitySelection(const SustainabilitySelection& other);        
        ~SustainabilitySelection() override = default;
        SustainabilitySelection& operator=(const SustainabilitySelection& other);
        
        /*-------------------OTHER-------------------*/
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        SustainabilitySelection *clone() const override;
        const string getType() const override;
        const string getFullType() const override;
        
    private:
        int lastSelectedIndex;
};

