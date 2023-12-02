#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>


using namespace std;
//Node in our code
class LabEquipment {
public:
    string name;
    string category;
    string model;
    string serial;
    bool isLent;
    string studentName;
    string studentRegisterNumber;
    string lendDate;
   // string* student = new string[3];
    LabEquipment* next;
    LabEquipment* prev;

    LabEquipment() {
        name = "";
        category = "";
        model = "";
        serial = "";
        isLent = false;
        studentName = "-1";
        studentRegisterNumber = "-1";
        lendDate = "-1";
        next = nullptr;
        prev = nullptr;
    }

    LabEquipment(string N, string cat, string mod, string Snum, bool lent) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        studentName = "-1";
        studentRegisterNumber = "-1";
        lendDate = "-1";
        next = nullptr;
        prev = nullptr;
    }

    LabEquipment(string N, string cat, string mod, string Snum, bool lent, string sName, string sRegNum, string lDate) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        studentName = sName;
        studentRegisterNumber = sRegNum;
        lendDate = lDate;
        next = nullptr;
        prev = nullptr;
    }
};

class EquipmentList {
private:
    LabEquipment* head;
    LabEquipment* tail;
    int size;


    // Helper function to write a LabEquipment object to a CSV file
    void writeEquipmentToCSV(ofstream& file, const LabEquipment* equipment) {
        file << equipment->name << "," << equipment->category << ","
            << equipment->model << "," << equipment->serial << ","
            << equipment->isLent << "," << equipment->studentName << ","
            << equipment->studentRegisterNumber << "," << equipment->lendDate << "\n";
    }


public:
    EquipmentList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LabEquipment* getHead() {
        return head;
    }

    LabEquipment* getTail() {
        return tail;
    }

// test comment

    // Method to save equipment data to a CSV file
    void saveToCSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        LabEquipment* current = head;

        while (current != nullptr) {
            writeEquipmentToCSV(file, current);
            current = current->next;
        }

        file.close();
        cout << "Equipment data saved to '" << filename << "' successfully." << endl;
    }

    // Insert equipment details into the list
    void insertLastWS(
        const string& N, const string& cat, const string& mod, const string& Snum,
        bool lent, const string& studentName, const string& registerNumber, const string& lendDate
    ) {
        // Create the node
        LabEquipment* temp = new LabEquipment(N, cat, mod, Snum, lent, studentName, registerNumber, lendDate);

        if (head == NULL) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            size++;
        }
    }

    // Load equipment data from a CSV file
    void loadFromCSV(const string& filename) {
        // Clear the existing list
        clearList();

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream ss(line);
            string token;

            // Parse the line using commas
            string data[8];  // Assuming there are 8 fields in your CSV data
            int index = 0;
            while (getline(ss, token, ',')) {
                data[index++] = token;
                if (index >= 8) {
                    break;  // Assuming there are 8 fields in your CSV data
                }
            }

            // Create a LabEquipment object from the CSV data
            if (index >= 8) {
                insertLastWS(data[0], data[1], data[2], data[3], stoi(data[4]), data[5], data[6], data[7]);
            }
        }

        file.close();
    }

    void clearList() {
        LabEquipment* current = head;
        LabEquipment* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    
   
    void insertLast(string N, string cat, string mod, string Snum, bool lent) {
        //Create the node
        LabEquipment* temp = new LabEquipment(N, cat, mod, Snum, lent);

        if (head == NULL) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            tail->next = temp;
            temp->prev = tail; //*************
            tail = temp;
            size++;
        }
    }
    /*
    void availability() {
        if (current->isLent == 1)
            cout << "Available" << endl;
        else
            cout << "Not Available" << endl;
    }
    */

    void print() {
        LabEquipment* current;
        current = head;
        while (current != NULL)
        {
            
            cout << "Name          : " << current->name << endl;
            cout << "Category      : " << current->category << endl;
            cout << "Model         : " << current->model << endl;
            cout << "Serial Number : " << current->serial << endl;
            cout << "Availability  : " << (current->isLent ? "Not Available" : "Available") << endl;
            cout << endl;
            cout << endl;
            current = current->next;
        }
        cout << endl;
    }

    // Method to filter and display equipment based on a specific category
    void filterByCategory(const string& filterCategory) {
        LabEquipment* current = head;
        while (current != NULL) {
            if (current->category == filterCategory) {
                cout << "Name          : " << current->name << endl;
                cout << "Category      : " << current->category << endl;
                cout << "Model         : " << current->model << endl;
                cout << "Serial Number : " << current->serial << endl;
                cout << "Availability  : " << current->isLent << endl;
                cout << endl;
                cout << endl;
            }
            current = current->next;
        }
        cout << endl;
    }

    void lendEquipment(const string& Snum, const string& studentName, const string& registerNumber, const string& lendDate) {
        LabEquipment* current = head;

        while (current != nullptr) {
            if (current->serial == Snum) {
                // Update equipment status and add student details
                current->isLent = true;
                current->studentName = studentName;
                current->studentRegisterNumber = registerNumber;
                current->lendDate = lendDate;
                return;
            }
            current = current->next;
        }

        // Equipment with the specified serial number not found
        cout << "Equipment with the specified serial number not found." << endl;
    }

    void printUniqueCategories() {
        LabEquipment* current = head;
        LabEquipment* temp;
        int categoryNumber = 1;

        while (current != NULL) {
            temp = head;
            bool isUnique = true;

            while (temp != current) {
                if (temp->category == current->category) {
                    isUnique = false;
                    break;
                }
                temp = temp->next;
            }

            if (isUnique) {
                cout << categoryNumber << ". " << current->category << endl;
                categoryNumber++;
            }

            current = current->next;
        }

        cout << endl;
    }

    void lendEquipment() {
        string serialNum;
        cout << "Enter the serial number of the equipment you want to lend: ";
        cin >> serialNum;

        LabEquipment* current = head;
        bool found = false;

        // Traverse the list to find the equipment by serial number
        while (current != nullptr) {
            if (current->serial == serialNum) {
                // Found the equipment
                cout << "----------------------------" << endl;
                cout << "--- Details of Equipment ---" << endl;
                cout << "----------------------------" << endl << endl;
                cout << "Name        : " << current->name << endl;
                cout << "Category    : " << current->category << endl;
                cout << "Model       : " << current->model << endl;
                cout << "Availability: " << (current->isLent ? "Not Available" : "Available") << endl << endl;

                if (current->isLent) {
                    cout << "Details of the student who has the equipment" << endl;
                    cout << "Student Name               : " << current->studentName << endl;
                    cout << "Student Register Number    : " << current->studentRegisterNumber << endl;
                    cout << "Date of the record         : " << current->lendDate << endl << endl;
                }

                if (!current->isLent) {
                    // Equipment is available, ask for confirmation to lend
                    char confirm;
                    cout << "Do you want to borrow this equipment? (Yes -y/No -n): ";
                    cin >> confirm;

                    if (confirm == 'y' || confirm == 'Y') {
                        // Get student details
                        string studentName, registerNumber, lendDate;
                        cout << "Enter Student name: ";
                        cin >> studentName;
                        cout << "Enter Student's register number: ";
                        cin >> registerNumber;
                        cout << "Enter the lending date (YYYY-MM-DD): ";
                        cin >> lendDate;

                        // Update equipment status and add student details
                        current->isLent = true;
                        current->studentName = studentName;
                        current->studentRegisterNumber = registerNumber;
                        current->lendDate = lendDate;

                        cout << "Equipment borrowed successfully." << endl;
                    }
                    else {
                        cout << "Borrowing canceled." << endl;
                    }
                }

                found = true;
                break;
            }
            current = current->next;
        }

        // Equipment with the specified serial number not found
        if (!found) {
            cout << "Equipment with the specified serial number not found." << endl;
        }
    }

    void addEquipment() {
        string name, model, category, serial;
        bool isLent;

        cout << "Enter equipment name: ";
        cin >> name;

        cout << "Enter equipment model: ";
        cin >> model;

        cout << "Enter equipment category: ";
        cin >> category;

        cout << "Enter equipment serial number: ";
        cin >> serial;

        cout << "Enter availability (1 for true, 0 for false): ";
        cin >> isLent;

        if (isLent) {
            string studentName, registerNumber, lendDate;

            cout << "Enter student name: ";
            cin >> studentName;

            cout << "Enter student register number: ";
            cin >> registerNumber;

            cout << "Enter lend date: ";
            cin >> lendDate;

            insertLastWS(name, category, model, serial, isLent, studentName, registerNumber, lendDate);
        }
        else {
            insertLast(name, category, model, serial, isLent);
        }

        cout << "Equipment added successfully." << endl;
    }

    // Method to add equipment to a specific category
    void addEquipmentToCategory(int categoryNumber) {
        string name, model, serial;
        bool isLent;

        cout << "Enter equipment name: ";
        cin >> name;
        cout << "Enter equipment model: ";
        cin >> model;
        cout << "Enter equipment serial: ";
        cin >> serial;
        cout << "Enter availability (1 for true, 0 for false): ";
        cin >> isLent;

        LabEquipment* current = head;
        int currentCategoryNumber = 1;

        // Find the category corresponding to the selected category number
        while (current != NULL) {
            LabEquipment* temp = head;
            bool isUnique = true;

            while (temp != current) {
                if (temp->category == current->category) {
                    isUnique = false;
                    break;
                }
                temp = temp->next;
            }

            if (isUnique) {
                if (currentCategoryNumber == categoryNumber) {
                    // Add equipment to the found category
                    LabEquipment* newEquipment = new LabEquipment(name, current->category, model, serial, isLent);

                    if (current->next == NULL) {
                        // The category is the last one in the list
                        current->next = newEquipment;
                        newEquipment->prev = current;
                        tail = newEquipment;
                    }
                    else {
                        // Insert the new equipment between two categories
                        newEquipment->next = current->next;
                        newEquipment->prev = current;
                        current->next->prev = newEquipment;
                        current->next = newEquipment;
                    }

                    size++;
                    cout << "Equipment added successfully to category: " << current->category << endl;
                    return;
                }

                currentCategoryNumber++;
            }

            current = current->next;
        }

        // If the category is not found
        cout << "Invalid category number. Equipment not added." << endl;
    }

  

    void deleteAt(int index) {
        if (head == nullptr || index < 0) {
            cout << "Invalid operation: List is empty or index is negative." << endl;
            return;
        }

        LabEquipment* current = head;
        LabEquipment* previous = nullptr;

        if (index == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete current;
            cout << "Deleted at index " << index << " successfully." << endl;
            return;
        }

        int count = 0;
        while (current != nullptr && count < index) {
            previous = current;
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Index out of range." << endl;
            return;
        }

        previous->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = previous;
        }
        delete current;
        //cout << "Deleted at index " << index << " successfully." << endl;
    }

    void deleteEquipmentBySerialNumber(const string& serialNumber) {
        LabEquipment* current = head;
        int index = 0;

        // Traverse the list to find the equipment by serial number
        while (current != nullptr) {
            if (current->serial == serialNumber) {
                // Found the equipment, display details
                cout << "----------------------------" << endl;
                cout << "--- Details of Equipment ---" << endl;
                cout << "----------------------------" << endl << endl;
                cout << "Name     : " << current->name << endl;
                cout << "Category : " << current->category << endl;
                cout << "Model    : " << current->model << endl;
                cout << endl;
                if (current->isLent == true) {
                    cout << "Details of the students who have the equipment" << endl;
                    cout << "Student Name               : " << current->studentName << endl;
                    cout << "Student Register Number    : " << current->studentRegisterNumber << endl;
                    cout << "Date of the record         : " << current->lendDate << endl <<endl;
                }
                

                // Ask user if details are correct
                char choice;
                cout << "Are these details correct? (Yes - y/No - n)  : ";
                cin >> choice;

                if (choice == 'y') {
                    // Delete equipment using deleteAt method at the found index
                    deleteAt(index);

                    // Display success message
                    cout << endl;
                    cout << "Equipment with serial number '" << serialNumber << "' deleted successfully." << endl;
                    return;
                }
                else if (choice == 'n') {
                    // User wants to retry, break the loop
                    break;
                }
                else {
                    // Invalid choice
                    cout << "Invalid choice. Please enter y or n." << endl;
                    return;
                }
            }
            current = current->next;
            index++;
        }

        // If equipment not found
        cout << "\nEquipment with serial number '" << serialNumber << "' not found." << endl;
    }

    

    // Method to search for an equipment by serial number
    void searchBySerial(const string& serialNumber) {
        LabEquipment* current = head;
        bool found = false;

        // Traverse the list to find the equipment by serial number
        while (current != nullptr) {
            if (current->serial == serialNumber) {
                // Found the equipment, display details
                cout << "----------------------------" << endl;
                cout << "--- Details of Equipment ---" << endl;
                cout << "----------------------------" << endl << endl;
                cout << "Name        : " << current->name << endl;
                cout << "Category    : " << current->category << endl;
                cout << "Model       : " << current->model << endl;
                cout << "Avalability : "  << (current->isLent ? "Not Available" : "Available") << endl << endl;
                if (current->isLent == true) {
                    cout << "Details of the students who have the equipment" << endl;
                    cout << "Student Name               : " << current->studentName << endl;
                    cout << "Student Register Number    : " << current->studentRegisterNumber << endl;
                    cout << "Date of the record         : " << current->lendDate << endl << endl;
                }

                found = true;
                break;
            }
            current = current->next;
        }

        // Equipment with the specified serial number not found
        if (!found) {
            cout << "Equipment with the specified serial number not found." << endl;
        }
    }

    void returnEquipment(const string& serialNumber) {
        LabEquipment* current = head;

        // Traverse the list to find the equipment by serial number
        while (current != nullptr) {
            if (current->serial == serialNumber) {
                 // Found the equipment, display details
                cout << "----------------------------" << endl;
                cout << "--- Details of Equipment ---" << endl;
                cout << "----------------------------" << endl << endl;
                cout << "Name        : " << current->name << endl;
                cout << "Category    : " << current->category << endl;
                cout << "Model       : " << current->model << endl;
                cout << "Avalability : " << (current->isLent ? "Not Available" : "Available") << endl << endl;
                if (current->isLent == true) {
                    cout << "Details of the students who have the equipment" << endl;
                    cout << "Student Name               : " << current->studentName << endl;
                    cout << "Student Register Number    : " << current->studentRegisterNumber << endl;
                    cout << "Date of the record         : " << current->lendDate << endl << endl;
                }

                // Mark the equipment as available
                current->isLent = false;

                // Clear student data
                current->studentName = "-1";
                current->studentRegisterNumber = "-1";
                current->lendDate = "-1";

                cout << "Equipment with serial number '" << serialNumber << "' returned successfully." << endl;
                return;
            }
            current = current->next;
        }

        // Equipment with the specified serial number not found
        cout << "Equipment with serial number '" << serialNumber << "' not found." << endl;
    }



};
