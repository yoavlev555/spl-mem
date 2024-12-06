# Please implement your Makefile rules and targets below.
# Customize this file to define how to build your project.

all: clean compile link run 

compile: src/main.cpp src/Auxiliary.cpp src/Settlement.cpp src/Simulation.cpp src/FacilityType.cpp src/Facility.cpp src/NaiveSelection.cpp src/BalancedSelection.cpp src/EconomySelection.cpp src/SustainabilitySelection.cpp src/Plan.cpp src/BaseActions/BaseAction.cpp src/BaseActions/SimulateStep.cpp src/BaseActions/AddPlan.cpp src/BaseActions/AddSettlement.cpp src/BaseActions/AddFacility.cpp src/BaseActions/PrintPlanStatus.cpp src/BaseActions/ChangePlanPolicy.cpp src/BaseActions/PrintActionsLog.cpp src/BaseActions/Close.cpp src/BaseActions/BackupSimulation.cpp src/BaseActions/RestoreSimulation.cpp
	@echo "Compiling sources..."
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/main.o src/main.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Settlement.o src/Settlement.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Auxiliary.o src/Auxiliary.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Simulation.o src/Simulation.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/FacilityType.o src/FacilityType.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Facility.o src/Facility.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/NaiveSelection.o src/NaiveSelection.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/BalancedSelection.o src/BalancedSelection.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/EconomySelection.o src/EconomySelection.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/SustainabilitySelection.o src/SustainabilitySelection.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Plan.o src/Plan.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/BaseAction.o src/BaseActions/BaseAction.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/SimulateStep.o src/BaseActions/SimulateStep.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/AddPlan.o src/BaseActions/AddPlan.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/AddSettlement.o src/BaseActions/AddSettlement.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/AddFacility.o src/BaseActions/AddFacility.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/PrintPlanStatus.o src/BaseActions/PrintPlanStatus.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/ChangePlanPolicy.o src/BaseActions/ChangePlanPolicy.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/PrintActionsLog.o src/BaseActions/PrintActionsLog.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/Close.o src/BaseActions/Close.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/BackupSimulation.o src/BaseActions/BackupSimulation.cpp
	g++ -g -Wall -Weffc++ -c -Iinclude -std=c++11 -o bin/RestoreSimulation.o src/BaseActions/RestoreSimulation.cpp


link: bin/main.o bin/Settlement.o bin/Auxiliary.o bin/Simulation.o bin/FacilityType.o bin/Facility.o bin/NaiveSelection.o bin/BalancedSelection.o bin/EconomySelection.o bin/SustainabilitySelection.o bin/Plan.o bin/BaseAction.o bin/SimulateStep.o bin/AddPlan.o bin/AddSettlement.o bin/AddFacility.o bin/PrintPlanStatus.o bin/ChangePlanPolicy.o bin/PrintActionsLog.o bin/Close.o bin/BackupSimulation.o bin/RestoreSimulation.o
	@echo "Linking object files..."
	g++ -o bin/main bin/main.o bin/Settlement.o bin/Auxiliary.o bin/Simulation.o bin/FacilityType.o bin/Facility.o bin/NaiveSelection.o bin/BalancedSelection.o bin/EconomySelection.o bin/SustainabilitySelection.o bin/Plan.o bin/BaseAction.o bin/SimulateStep.o bin/AddPlan.o bin/AddSettlement.o bin/AddFacility.o bin/PrintPlanStatus.o bin/ChangePlanPolicy.o bin/PrintActionsLog.o bin/Close.o bin/BackupSimulation.o bin/RestoreSimulation.o

run: bin/main
	@echo "Running the program..."
	./bin/main config_file.txt


clean:
	@echo "Cleaning binaries..."
	rm -f bin/*
