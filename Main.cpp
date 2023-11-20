#include "OTPRegister.h"
#include <iostream>
#include <string>
using namespace std;

//Main function that allows user to read menu options and calls the required functions when an option is entered
int main() {
    OTPRegister reg;
    int choice = 0;

    do {
        cout << "There are currently " << (reg.isEmpty() ? 0 : reg.patientCount()) << " patient(s) in the list\n";
        cout << "Please choose an option:" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Examine Patient" << endl;
        cout << "3. Display Patients" << endl;
        cout << "4. Quit\n";
        cout << ">> ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int healthCardNumber;
                cout << "[Register Patient]" << endl;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Health Card Number: ";
                cin >> healthCardNumber;
                reg.registerPatient(Patient(name, healthCardNumber));
                break;
            }
            case 2:
                reg.examinePatient();
                break;
            case 3:
                reg.displayPatients();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
