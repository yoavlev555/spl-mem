# Please implement your Makefile rules and targets below.
# Customize this file to define how to build your project.

all: clean compile link run 

compile: src/main.cpp src/Auxiliary.cpp src/Settlement.cpp src/Simulation.cpp src/FacilityType.cpp src/Facility.cpp src/NaiveSelection.cpp src/BalancedSelection.cpp src/EconomySelection.cpp src/SustainabilitySelection.cpp
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


link: bin/main.o bin/Settlement.o bin/Auxiliary.o bin/Simulation.o bin/FacilityType.o bin/Facility.o bin/NaiveSelection.o bin/BalancedSelection.o bin/EconomySelection.o bin/SustainabilitySelection.o
	@echo "Linking object files..."
	g++ -o bin/main bin/main.o bin/Settlement.o bin/Auxiliary.o bin/Simulation.o bin/FacilityType.o bin/Facility.o bin/NaiveSelection.o bin/BalancedSelection.o bin/EconomySelection.o bin/SustainabilitySelection.o

run: bin/main
	@echo "Running the program..."
	./bin/main config_file.txt


clean:
	@echo "Cleaning binaries..."
	rm -f bin/*
