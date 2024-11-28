#include "Simulation.h"
#include "Settlement.h"
#include "SelectionPolicy.h"
#include <iostream>

using namespace std;

Simulation* backup = nullptr;

int main(int argc, char** argv){
    if(argc!=2){
        cout << "usage: simulation <config_path>" << endl;
        return 0;
    }
    // string configurationFile = argv[1];
    // Simulation simulation(configurationFile);
    // simulation.start();
    // if(backup!=nullptr){
    // 	delete backup;
    // 	backup = nullptr;
    // }

    /*class BalancedSelection: public SelectionPolicy {
    public:
        BalancedSelection(int LifeQualityScore, int EconomyScore, int EnvironmentScore);
        BalancedSelection(const BalancedSelection& other);
        const FacilityType& selectFacility(const vector<FacilityType>& facilitiesOptions) override;
        const string toString() const override;
        BalancedSelection *clone() const override;
        ~BalancedSelection() override = default;
        int checkDiff(int lifeScore, int economyScore, int environmentScore);
        BalancedSelection& operator=(const BalancedSelection& other);

    private:
        int LifeQualityScore;
        int EconomyScore;
        int EnvironmentScore;
};
*/




    vector<FacilityType> ft = vector<FacilityType>();
    ft.push_back(FacilityType("Desalination Plant",FacilityCategory::ECONOMY,2,2,1,2));
    ft.push_back(FacilityType("Kindergarten",FacilityCategory::ECONOMY,12,1,0,0));
    ft.push_back(FacilityType("Hospital",FacilityCategory::ECONOMY,6,3,1,2));
    ft.push_back(FacilityType("1",FacilityCategory::ECONOMY,12,1,0,0));
    ft.push_back(FacilityType("2",FacilityCategory::ECONOMY,12,1,0,0));
    ft.push_back(FacilityType("3",FacilityCategory::ECONOMY,12,1,0,0));

    SustainabilitySelection general = (SustainabilitySelection());
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;    
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;
    cout << general.selectFacility(ft).getName() << endl;






    return 0;
}