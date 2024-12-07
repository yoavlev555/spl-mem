#include "Action.h"

// Constructor
BaseAction::BaseAction():errorMsg(""), status(ActionStatus::ERROR){}
BaseAction::BaseAction(const BaseAction& other):errorMsg(other.errorMsg), status(other.status){}
BaseAction::BaseAction(const ActionStatus& otherStatus, const string otherMsg):errorMsg(otherMsg), status(otherStatus){}

// Destructor - Default

// Operators
BaseAction& BaseAction::operator=(const BaseAction& other){
    if(this != &other){
        status = other.status;
        errorMsg = other.errorMsg;
    }

    return *this;
}

// Getters
ActionStatus BaseAction::getStatus() const{return status;}

// Other Functions

void BaseAction::complete(){
    status = ActionStatus::COMPLETED;
}

void BaseAction::error(string errorMessage){
    status = ActionStatus::ERROR;
    errorMsg = errorMessage;
}

const string &BaseAction::getErrorMsg() const{
    return (errorMsg);
}

const string BaseAction::getStatusAsString() const{
    string s;
    switch (status){
        case ActionStatus::ERROR:
            s = "ERROR";
            break;
        case ActionStatus::COMPLETED:
            s = "COMPLETED";
            break;
    }

    return s;
}










