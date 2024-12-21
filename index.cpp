#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string address;
};

class Patient : public Person {
public:
    int patientID;
    string disease;
    double consultationFee;
    double medicationCost;

    void addPatient() {
        cout << "Enter Patient Name: ";
        
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        
        cout << "Enter Disease: ";
        getline(cin, disease);
        cout << "Enter Consultation Fee: ";
        cin >> consultationFee;
        cout << "Enter Medication Cost: ";
        cin >> medicationCost;
    }

    void generateReport() {
        cout << "\nGenerating Patient's Report..." << endl;
        cout << "Patient ID: " << patientID << "\nName: " << name << "\nAge: " << age << "\nDisease: " << disease << endl;
    }

    void generateBill() {
        cout << "\nGenerating Patient's Bill..." << endl;
        double totalBill = consultationFee + medicationCost;
        cout << "Patient ID: " << patientID << "\nName: " << name << "\nConsultation Fee: $" << consultationFee << "\nMedication Cost: $" << medicationCost << "\nTotal Bill: $" << totalBill << endl;
    }
};

class Doctor : public Person {
public:
    int doctorID;
    string specialization;

    void addDoctor() {
        cout << "Enter Doctor Name: ";
        
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Specialization: ";
        getline(cin, specialization);
    }
};

void showMenu() {
    cout << "\n***********";
    cout << "\n*         Main Menu           *";
    cout << "\n***********";
    cout << "\n1. Enter Into Doctor's Database";
    cout << "\n2. Enter into Patient's Database";
    cout << "\n3. Generate Patient's Report";
    cout << "\n4. Generate Patient's Bills";
    cout << "\n5. Exit";
    cout << "\n***********";
    cout << "\nPlease Choose Your Choice: ";
}

int main() {
    Patient patient;
    Doctor doctor;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            doctor.addDoctor();
            break;
        case 2:
            patient.addPatient();
            break;
        case 3:
            patient.generateReport();
            break;
        case 4:
            patient.generateBill();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}