#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class Facility;

enum class SettlementType {
    VILLAGE,
    CITY,
    METROPOLIS,
};


class Settlement {
    public:
        Settlement(const string &name, SettlementType type);
        Settlement(const Settlement& other);
        Settlement& operator=(const Settlement& other);
        const string &getName() const;
        SettlementType getType() const;
        const string toString() const;
        static string SettlementTypeToString (SettlementType s);
        const int getMaxCapacity() const;
        Settlement* clone();


        private:
            const string name;
            SettlementType type;
};