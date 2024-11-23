#include "Settlement.h"


Settlement::Settlement(const string &otherName, SettlementType otherType): name(otherName), type(otherType){}

string& Settlement::getName(){
    return name;
}