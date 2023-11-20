#include "Patient.h"
using namespace std;

//Initializes a Patient object
Patient::Patient(const string& name, int healthCardNumber)
    : name(name), healthCardNumber(healthCardNumber), condition(UNKNOWN), cervixDilation(0) {}

//Gets patient name
string Patient::getName() const {
    return name;
}

//Gets patients HC #
int Patient::getHealthCardNumber() const {
    return healthCardNumber;
}

//Gets patient condition
Condition Patient::getCondition() const {
    return condition;
}

//Gets patients cervix dilation
int Patient::getCervixDilation() const {
    return cervixDilation;
}

//Sets patients condition
void Patient::setCondition(Condition newCondition) {
    condition = newCondition;
}

//Sets patients cervix dilation
void Patient::setCervixDilation(int dilation) {
    cervixDilation = dilation;
}

//Converts enum to string
string Patient::conditionToString() const {
    switch (condition) {
        case UNKNOWN: return "UNKNOWN";
        case LABOUR: return "LABOUR";
        case ADMIT: return "ADMIT";
        default: return "INVALID";
    }
}