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
        NaiveSelection(const NaiveSelection& other);
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        NaiveSelection *clone() const override;
        const string getType() const override;
        ~NaiveSelection() override = default;
        const string getFullType() const override;
        NaiveSelection& operator=(const NaiveSelection& other);
    private:
        int lastSelectedIndex;
};

class BalancedSelection: public SelectionPolicy {
    public:
        BalancedSelection(int LifeQualityScore, int EconomyScore, int EnvironmentScore);
        BalancedSelection(const BalancedSelection& other);
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        BalancedSelection *clone() const override;
        const string getType() const override;
        ~BalancedSelection() override = default;
        int checkDiff(int lifeScore, int economyScore, int environmentScore);
        BalancedSelection& operator=(const BalancedSelection& other);
        const string getFullType() const override;

    private:
        int LifeQualityScore;
        int EconomyScore;
        int EnvironmentScore;
};

class EconomySelection: public SelectionPolicy {
    public:
        EconomySelection();
        EconomySelection(const EconomySelection& other);        
        EconomySelection& operator=(const EconomySelection& other);
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        EconomySelection *clone() const override;
        const string getType() const override;
        ~EconomySelection() override = default;
        const string getFullType() const override;
    private:
        int lastSelectedIndex;

};

class SustainabilitySelection: public SelectionPolicy {
    public:
        SustainabilitySelection();
        SustainabilitySelection(const SustainabilitySelection& other);        
        SustainabilitySelection& operator=(const SustainabilitySelection& other);
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        SustainabilitySelection *clone() const override;
        const string getType() const override;
        ~SustainabilitySelection() override = default;
        const string getFullType() const override;
    private:
        int lastSelectedIndex;
};