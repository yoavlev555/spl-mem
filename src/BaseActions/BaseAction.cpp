#include "Action.h"

// Constructor
BaseAction::BaseAction():status(ActionStatus::ERROR), errorMsg(""){}
BaseAction::BaseAction(const BaseAction& other):status(other.status),errorMsg(other.errorMsg){}
BaseAction::BaseAction(const ActionStatus& otherStatus, const string otherMsg):status(otherStatus),errorMsg(otherMsg){}

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
            s = "Error";
            break;
        case ActionStatus::COMPLETED:
            s = "Completed";
            break;
    }

    return s;
}










