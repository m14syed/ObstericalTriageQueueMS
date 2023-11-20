#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;
enum Condition { UNKNOWN, LABOUR, ADMIT };

class Patient {
private:
    //Patient name, HC #, condition (Unknown, Labour, Admit), cervix dilation
    string name; 
    int healthCardNumber;
    Condition condition;
    int cervixDilation;

public:
    //Initialize patient object with the name and HC #
    Patient(const string& name, int healthCardNumber);

    string getName() const;
    int getHealthCardNumber() const;
    Condition getCondition() const;
    int getCervixDilation() const;

    void setCondition(Condition condition);
    void setCervixDilation(int dilation);

    // Converts enum to string
    string conditionToString() const;
};

#endif // PATIENT_H


