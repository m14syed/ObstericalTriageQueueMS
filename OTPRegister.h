#ifndef OTPREGISTER_H
#define OTPREGISTER_H

#include <deque>
#include "Patient.h"
using namespace std;

class OTPRegister {
private:
    //Implements a queue of pointers of the class Patient
    deque<Patient*> queue;

public:
    OTPRegister() = default; //default constructor 
    ~OTPRegister();  // Clean dynamically allocated patient objects

    void registerPatient(const Patient& patient);
    void examinePatient();
    void displayPatients() const;
    bool isEmpty() const;
    int patientCount() const;
};

#endif // OTPREGISTER_H