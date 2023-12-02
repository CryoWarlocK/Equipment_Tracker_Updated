#include <iostream>
#include <cstdlib>
#include "Equipment.h"
#include<string>

//test comment 4
using namespace std;

// ANSI escape codes for text color
const char* RED_COLOR = "\033[1;31m";
const char* LIGHTBLUE_COLOR = "\033[1;36m";
const char* RESET_COLOR = "\033[0m";

void runProgram() {
 
    
}



int main() {
    EquipmentList dll;
    bool isRunning = true;  // Boolean variable to control the loop
    string name, model, serial, equipmentToDelete, serialNumber;
    bool isLent;
    string filename = "equipment_data.csv";
    while (isRunning) {
        system("cls");
        int Opt;
        int selectedCategory = -1;
        cout << "_____________________________________________________________" << endl;
        cout << LIGHTBLUE_COLOR << "------------ Lab Equipment Tracker Version 1.0 --------------" << RESET_COLOR<< endl;
        cout << "Please enter a menu number corresponding to your need." << endl;
        cout << "1. Lend Equipment" << endl;
        cout << "2. Return Equipment" << endl;
        cout << "3. Add Equipment " << endl;
        cout << "4. See all Categories " << endl;
        cout << "5. " << endl;
        cout << "6. Delete an Equipment " << endl;
        cout << "7. Search Equipment " << endl;
        cout << "8. Print all the equipments " << endl;
        cout << "9. Save data locally" << endl;
        cout << "10. Load data from local machine" << endl;
        cout << "11. Exit " << endl;
        
        cout << "_____________________________________________________________" << endl;
        cin >> Opt;

        switch (Opt) {
        case 1:     //for lend equipments
            system("cls");
            cout << "Lend Equipment option selected" << endl;
            cout << "................................................." << endl;
            dll.lendEquipment();
            break;

        case 2:
            system("cls");
            cout << "Return Equipment option selected" << endl;
            cout << "Enter the serial number of the equipment to be returned: ";
            cin >> serialNumber;

            dll.returnEquipment(serialNumber);
            break;

        case 3:
            system("cls");
            cout << "Add Equipment option selected" << endl;
            cout << "_______________________________" << endl;
            cout << "Please select a category from below list to add a equipment" << endl;

            // Print all unique categories with numbers or letters
            dll.printUniqueCategories();
            cout << "____________________________________" << endl;
            //cout << "Please enter a category from above list" << endl;
            cout << "Please select a category by entering its corresponding number" << endl;
            cin >> selectedCategory;
            fflush(stdin);

            
            // Add equipment to the selected category
            cout << "Enter equipment name: ";
            cin >> name;
            fflush(stdin);
            cout << "Enter equipment model: ";
            cin >> model;
            fflush(stdin);
            cout << "Enter equipment serial: ";
            cin >> serial;
            fflush(stdin);
            cout << "Enter availability (1 for true, 0 for false): ";
            cin >> isLent;
            fflush(stdin);

            dll.addEquipmentToCategory(selectedCategory, name, model, serial, isLent);

            cout << "Equipment added successfully to category: " << selectedCategory << endl;
            break;
        case 4:
            system("cls");
            // Print all unique categories with numbers or letters
            dll.printUniqueCategories();
            break;
        case 5:
            
        case 6:
            system("cls");
            cout << "Delete an Equipment option selected" << endl << endl;
            cout << "Enter the serial number of the equipment you want to delete: ";

            cin >> serialNumber;

            // Delete the equipment by serial number
            dll.deleteEquipmentBySerialNumber(serialNumber);
            break;

        case 7:
            system("cls");
            cout << "Enter the equipment serial number : ";
            cin >> serialNumber;
            dll.searchBySerial(serialNumber);
            break;

        case 8:
            system("cls");
            cout << "Print all the equipments option selected" << endl;
            dll.print();
            break;
        

        case 9: // Save data to CSV and exit
            system("cls");
            dll.saveToCSV(filename);
            isRunning = false;
            break;

        case 10: // Load data from CSV
            system("cls");
            cout << "Data loaded from local machine" << endl;
            dll.loadFromCSV(filename);
            break;

        case 11:
            system("cls");
            isRunning = false;  // Set the boolean variable to false to exit the loop
            break;

        default:
            cout << "Please enter a valid option key" << endl;
            isRunning = false;
            break;
        }

    }
  
    return 0;
}


//find the time complexities
//implement a seacrh method by serial number
//implement a print method for one by one printing.