#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

// Patient structure
struct Patient {
    string name;
    int age;
    string problem;
    int severity;   // 1 = Critical, 2 = Serious, 3 = Normal
};

// Comparator for priority queue
struct ComparePatient {
    bool operator()(const Patient &a, const Patient &b) {
        return a.severity > b.severity;
    }
};

priority_queue<Patient, vector<Patient>, ComparePatient> pq;

// Display all patients
void displayAllPatients() {
    if (pq.empty()) {
        cout << "\nNo patients available.\n";
        return;
    }

    priority_queue<Patient, vector<Patient>, ComparePatient> temp = pq;

    cout << "\n===== CURRENT PATIENT LIST =====\n";
    cout << "+-----+----------------------+-------+------------+-------------------+\n";
    cout << "| No. | Name                 | Age   | Severity   | Problem           |\n";
    cout << "+-----+----------------------+-------+------------+-------------------+\n";

    int count = 0;

    while (!temp.empty()) {
        Patient p = temp.top();
        temp.pop();
        count++;

        string level;
        if (p.severity == 1) level = "Critical";
        else if (p.severity == 2) level = "Serious";
        else level = "Normal";

        cout << "| " << setw(3) << left << count
             << " | " << setw(20) << left << p.name
             << " | " << setw(5) << left << p.age
             << " | " << setw(10) << left << level
             << " | " << setw(17) << left << p.problem
             << " |\n";
    }

    cout << "+-----+----------------------+-------+------------+-------------------+\n";
    cout << "Total patients = " << count << endl;
}

// Add new patient
void addPatient() {
    Patient p;
    string temp;

    cout << "\nEnter patient name: ";
    getline(cin, p.name);

    cout << "Enter age: ";
    getline(cin, temp);
    p.age = stoi(temp);

    cout << "Enter problem: ";
    getline(cin, p.problem);

    // Validate severity input
    do {
        cout << "Enter severity (1 = Critical, 2 = Serious, 3 = Normal): ";
        getline(cin, temp);
    } while (temp != "1" && temp != "2" && temp != "3");

    p.severity = stoi(temp);

    pq.push(p);

    cout << "Patient added based on severity.\n";
}

// Treat next patient
void treatPatient() {
    if (pq.empty()) {
        cout << "\nNo patients to treat.\n";
        return;
    }

    Patient p = pq.top();
    pq.pop();

    string level = (p.severity == 1 ? "Critical" :
                    p.severity == 2 ? "Serious" : "Normal");

    cout << "\nTreating " << level << " patient: " << p.name << endl;
}

// Count remaining patients
void countPatients() {
    cout << "\nTotal patients waiting: " << pq.size() << endl;
}

// Search patient by name
void searchPatient() {
    if (pq.empty()) {
        cout << "\nNo patients to search.\n";
        return;
    }

    string name;
    cout << "\nEnter name to search: ";
    getline(cin, name);

    priority_queue<Patient, vector<Patient>, ComparePatient> temp = pq;
    bool found = false;

    while (!temp.empty()) {
        Patient p = temp.top();
        temp.pop();

        if (p.name == name) {
            string level = (p.severity == 1 ? "Critical" :
                            p.severity == 2 ? "Serious" : "Normal");

            cout << "\nFound patient:\n";
            cout << "Name: " << p.name
                 << ", Age: " << p.age
                 << ", Severity: " << level
                 << ", Problem: " << p.problem << endl;

            found = true;
        }
    }

    if (!found) cout << "\nPatient not found.\n";
}

int main() {
    while (true) {
        system(CLEAR);

        cout << "==============================\n";
        cout << " Hospital Emergency Manager\n";
        cout << "==============================\n";

        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Treat Next Patient\n";
        cout << "4. Count Patients\n";
        cout << "5. Search Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        string temp;
        getline(cin, temp);

        if (temp == "" || temp.find_first_not_of("0123456789") != string::npos) {
            cout << "Invalid input. Enter only numbers.\n";
            continue;
        }

        int choice = stoi(temp);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayAllPatients(); break;
            case 3: treatPatient(); break;
            case 4: countPatients(); break;
            case 5: searchPatient(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
    }
}