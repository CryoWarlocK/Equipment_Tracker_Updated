#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

//8.16

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
    int lendDate;
    int lendMonth;
    int lendYear;
   // string* student = new string[3];
    LabEquipment* next;
    LabEquipment* prev;

    LabEquipment() {
        name = "";
        category = "";
        model = "";
        serial = "";
        isLent = false;
        studentName = "NULL";
        studentRegisterNumber = "NULL";
        lendDate = INT_MIN;
        lendMonth = INT_MIN;
        lendYear = INT_MIN;
        next = nullptr;
        prev = nullptr;
    }

    LabEquipment(string N, string cat, string mod, string Snum, bool lent) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        studentName = "NULL";
        studentRegisterNumber = "NULL";
        lendDate = INT_MIN;
        lendMonth = INT_MIN;
        lendYear = INT_MIN;
        next = nullptr;
        prev = nullptr;
    }

    LabEquipment(string N, string cat, string mod, string Snum, bool lent, string sName, string sRegNum, int lDate, int lMonth, int lYear) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        studentName = sName;
        studentRegisterNumber = sRegNum;
        lendDate = lDate;
        lendMonth = lMonth;
        lendYear = lYear;
        next = nullptr;
        prev = nullptr;
    }
};

class EquipmentList {
private:
    LabEquipment* head;
    LabEquipment* tail;
    int size;

    // Janitha
    // Helper function to write a LabEquipment object to a CSV file
    void writeEquipmentToCSV(ofstream& file, const LabEquipment* equipment) {
        file << equipment->name << "," << equipment->category << ","
            << equipment->model << "," << equipment->serial << ","
            << equipment->isLent << "," << equipment->studentName << ","
            << equipment->studentRegisterNumber << "," 
            << equipment->lendDate <<"," << equipment->lendMonth << "," <<equipment->lendYear << "\n";
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
    // Janitha
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
    // Janitha
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Janitha
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
            // Janitha
            // Parse the line using commas
            string data[10];  // Assuming there are 8 fields in the CSV data
            int index = 0;
            while (getline(ss, token, ',')) {
                data[index++] = token;
                if (index >=10) {
                    break;  // Assuming there are 8 fields in the CSV data
                }
            }
           
            // Create a LabEquipment object from the CSV data
            if (index >= 10) {
                insertLastWS(data[0], data[1], data[2], data[3], stoi(data[4]), data[5], data[6], stoi(data[7]), stoi(data[8]), stoi(data[9]));
            }
        }

        file.close();
    }
    // Janitha
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
    // Sasini
    // Insert equipment details into the list
    void insertLastWS(const
        const string& N,  string& cat, const string& mod, const string& Snum,
        bool lent, const string& studentName, const string& registerNumber, const int& lDate, const int& lMonth, const int& lYear
    ) {
        // Create the node
        LabEquipment* temp = new LabEquipment(N, cat, mod, Snum, lent, studentName, registerNumber, lDate, lMonth, lYear);

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
    // Sasini
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
    // Hansika
    void print() {
        LabEquipment* current;
        current = head;
        if (current == NULL) {
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Oops! It's seems like you don't have and data to print" << endl;
            cout << "Please insert equipment to the list first using add equipment option" << endl;
            cout << "Otherwise you can load sample data from load from local machine option" << endl;
        }
        else {
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
        
    }
    
    // Hansika
    void printUniqueCategories() {
        // Check if the list is empty
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
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
        cout << "Please select a category from above list to add a equipment" << endl;
        cout << endl;
    }
    
    // Sasini
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
                    cout << "Student Name                   : " << current->studentName << endl;
                    cout << "Student Register Number        : " << current->studentRegisterNumber << endl;
                    cout << "Date of the record(YYYY-MM-DD) : " << current->lendYear <<"-" <<current->lendMonth<< "-" 
                        << current->lendDate<< endl << endl;
                }

                if (!current->isLent) {
                    // Equipment is available, ask for confirmation to lend
                    char confirm;
                    cout << "Do you want to borrow this equipment? (Yes -y/No -n): ";
                    cin >> confirm;

                    if (confirm == 'y' || confirm == 'Y') {
                        // Get student details
                        clearInputBuffer();
                        cout << "Enter Student name: ";
                        getline(cin, current->studentName);
                        cout << "Enter Student's register number: ";
                        cin >> current->studentRegisterNumber;
                        clearInputBuffer();
                        cout << "Enter the lending Day (DD): ";
                        int lDate;
                        cin >> lDate;
                        clearInputBuffer();
                        cout << "Enter the lending Month (MM): ";
                        int lMonth;
                        cin >> lMonth;
                        clearInputBuffer();
                        cout << "Enter the lending Year (YYYY): ";
                        int lYear;
                        cin >> lYear;
                        clearInputBuffer();

                        // Validate the lend date 
                        if (!isValidDate(lDate, lMonth, lYear)) {
                            cout << "Invalid date. Equipment not borrowed." << endl;
                            return;
                        }

                        // Update equipment status
                        current->isLent = true;
                        current->lendDate = lDate;
                        current->lendMonth = lMonth;
                        current->lendYear = lYear;

                        cout << "Equipment borrowed successfully." << endl;
                    }
                    else if (confirm == 'n' || confirm == 'N') {
                        cout << "Borrowing canceled." << endl;
                    }
                    else {
                        cout << "Please enter a valid input yes or no" << endl;
                        return;
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
   
    // Janitha

    void addEquipment() {
        string name, model, category, serial;
        bool isLent;

        cout << "Enter equipment name: ";
        cin >> name;
        clearInputBuffer();
        cout << "Enter equipment model: ";
        cin >> model;
        clearInputBuffer();
        cout << "Enter equipment category: ";
        cin >> category;
        clearInputBuffer();
        cout << "Enter equipment serial number: ";
        cin >> serial;
        clearInputBuffer();

        // Check if the serial number already exists
        if (isSerialNumberExists(serial)) {
            cout << "Equipment with the specified serial number already exists." << endl;
            return;
        }

        // Insert the new equipment
        insertLast(name, category, model, serial, 0);

        cout << "Equipment added successfully." << endl;
    }

    bool isSerialNumberExists(const string& serial) {
        LabEquipment* current = head;
        while (current != nullptr) {
            if (current->serial == serial) {
                return true; // Serial number already exists
            }
            current = current->next;
        }
        return false; // Serial number does not exist
    }

    // Janitha
    void addEquipmentToSelectedCategory() {
        // Check if the list is empty
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        LabEquipment* current = head;
        LabEquipment* temp;
        int categoryNumber = 1;

        // Print unique categories in a numbered list
        while (current != nullptr) {
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

        cout << "Please select a category from the above list to add an equipment: ";
        int selectedCategory;
        cin >> selectedCategory;

        current = head;
        int currentCategoryNumber = 1;

      
        // Find the category corresponding to the selected category number
        while (current != nullptr) {
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
                if (currentCategoryNumber == selectedCategory) {
                    // Add equipment to the found category
                    string name, model, serial;
                    bool isAvailable;

                    cout << "Enter equipment name: ";
                    cin >> name;
                    clearInputBuffer();
                    cout << "Enter equipment model: ";
                    cin >> model;
                    clearInputBuffer();
                    cout << "Enter equipment serial: ";
                    cin >> serial;
                    clearInputBuffer();

                    // Check if the serial number already exists
                    if (isSerialNumberExists(serial)) {
                        cout << "Equipment with the specified serial number already exists." << endl;
                        return;
                    }

                    LabEquipment* newEquipment = new LabEquipment(name, current->category, model, serial, 0);

                    if (current->next == nullptr) {
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
    // Hansika
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
        //cout << "Deleted at index " << index << " successfully." <<�endl;
    }
    // Hansika
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
                    cout << "Date of the record(YYYY-MM-DD) : " << current->lendYear << "-" << current->lendMonth << "-"
                        << current->lendDate << endl << endl;
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

   // Hansika

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
                    cout << "Date of the record(YYYY-MM-DD) : " << current->lendYear << "-" << current->lendMonth << "-"
                        << current->lendDate << endl << endl;
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
    // Sasini
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
                    cout << "Date of the record(YYYY-MM-DD) : " << current->lendYear << "-" << current->lendMonth << "-"
                        << current->lendDate << endl << endl;
                    // Mark the equipment as available
                    current->isLent = false;

                    // Clear student data
                    current->studentName = "NULL";
                    current->studentRegisterNumber = "NULL";
                    current->lendDate = INT_MIN;
                    current->lendMonth = INT_MIN;
                    current->lendYear = INT_MIN;

                    cout << "Equipment with serial number '" << serialNumber << "' returned successfully." << endl;
                    return;
                }

                else {
                    cout << "The equipment has not been borrowed and is available in the laboratory." << endl;
                    return;
                
                }
            }
            current = current->next;
        }

        // Equipment with the specified serial number not found
        cout << "Equipment with serial number '" << serialNumber << "' not found." << endl;
    }
    // Hansika
    void printEquipmentByCategory() {
        // Display unique categories
        cout << "Unique Categories" << endl;
        cout << "-----------------" << endl;
        printUniqueCategories();

        int categoryChoice;
        cout << "Enter the category number to view the equipment under choosen category: ";
        cin >> categoryChoice;
        cout << endl;

        LabEquipment* current = head;
        int currentCategory = 1;
        bool found = false;

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
                if (currentCategory == categoryChoice) {
                    cout << "Equipment under category '" << current->category << "':" << endl << endl;
                    found = true;

                    // Print equipment under the selected category
                    LabEquipment* categoryCurrent = head;
                    while (categoryCurrent != NULL) {
                        if (categoryCurrent->category == current->category) {
                            cout << "Name          : " << categoryCurrent->name << endl;
                            cout << "Category      : " << categoryCurrent->category << endl;
                            cout << "Model         : " << categoryCurrent->model << endl;
                            cout << "Serial Number : " << categoryCurrent->serial << endl;
                            cout << "Availability  : " << (categoryCurrent->isLent ? "Not Available" : "Available") << endl;
                            cout << endl;
                        }
                        categoryCurrent = categoryCurrent->next;
                    }
                }
                currentCategory++;
            }

            current = current->next;
        }

        if (!found) {
            cout << "Invalid category number selected." << endl;
        }
    }
    // Sasini
    bool isValidDate(int day, int month, int year) {
        if (validateYear(year) && validateMonth(month) && validateDay(day, month, year)) {
            return true;
        }
        return false;
    }

    int validateDay(int day, int month, int year) {
        int maxDay;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDay = 30;
        }
        else if (month == 2 && isLeapYear(year)) {
            maxDay = 29;
        }
        else if (month == 2 && !isLeapYear(year)) {
            maxDay = 28;
        }
        else {
            maxDay = 31;
        }

        if (day >= 1 && day <= maxDay) {
            return day;
        }
        return 0; // This is for invalid day
    }

    int validateMonth(int month) {
        if (month >= 1 && month <= 12)
            return month;
        return 0; // this is for invalid Month
    }

    bool isLeapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int validateYear(int year) {
        if (year >= 1 && year <= 9999)
            return year;
        return 0; // this is for invalid year 
    }

    
    

    
};
