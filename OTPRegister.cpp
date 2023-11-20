#include "OTPRegister.h"
#include <iostream>
using namespace std;

// Destructor to delete all Patient pointers in the deque
OTPRegister::~OTPRegister() {
    for (auto patient : queue) {
        delete patient;
    }
}

// Register a new patient
void OTPRegister::registerPatient(const Patient& patient) {
    Patient* newPatient = new Patient(patient);
    queue.push_back(newPatient);
    cout << "Patient " << newPatient->getName() << " registered." << endl;
}

// Examine the next patient
void OTPRegister::examinePatient() {
    if (queue.empty()) {
        cout << "No patients in the queue." << endl;
        return;
    }

    Patient* frontPatient = queue.front();

    // Check the condition 
    if (frontPatient->getCondition() == UNKNOWN) {
        int cervixDilation;
        cout << "Enter cervix dilation for patient " << frontPatient->getName() << ": ";
        cin >> cervixDilation;

        // Update the patient's condition based on cervix dilation
        if (cervixDilation >= 4) {
            frontPatient->setCondition(ADMIT);
            cout << "Patient " << frontPatient->getName() << " is admitted." << endl;
            delete frontPatient; // Delete the patient
            queue.pop_front();   // Remove from the deque
        } else {
            frontPatient->setCondition(LABOUR);
            cout << "Patient " << frontPatient->getName() << " is in labour." << endl;
        }
    } else if (frontPatient->getCondition() == LABOUR) {
        // If the condition is LABOUR, prompt for cervix dilation
        int cervixDilation;
        cout << "Enter cervix dilation for patient " << frontPatient->getName() << ": ";
        cin >> cervixDilation;

        // Update condition 
        if (cervixDilation >= 4) {
            frontPatient->setCondition(ADMIT);
            cout << "Patient " << frontPatient->getName() << " is admitted." << endl;
            delete frontPatient; // Delete the patient
            queue.pop_front();   // Remove from the deque
        } else {
            cout << "Patient " << frontPatient->getName() << " remains in labour." << endl;
        }
    }
}

// Display all patients in the queue
void OTPRegister::displayPatients() const {
    if (queue.empty()) {
        cout << "No patients in the queue." << endl;
        return;
    }

    for (const Patient* patient : queue) {
        cout << "Name: " << patient->getName() << endl;
        cout << "Health Card Number: " << patient->getHealthCardNumber() << endl;
        cout << "Condition: " << patient->conditionToString() << endl;
        cout << "Cervix Dilation: " << patient->getCervixDilation() << " cm" << endl;
        cout << "----------------------------------------" << endl; // Separator
    }
}

// Check if queue is empty
bool OTPRegister::isEmpty() const {
    return queue.empty();
}

// Outputs the number of patients in the queue
int OTPRegister::patientCount() const {
    return queue.size();
}