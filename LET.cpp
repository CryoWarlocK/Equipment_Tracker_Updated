#include <iostream>
#include <cstdlib>
#include "Equipment.h"
#include <string>

//test comment 4
using namespace std;

// ANSI escape codes for text color
const char* RED_COLOR = "\033[1;31m";
const char* LIGHTBLUE_COLOR = "\033[1;36m";
const char* RESET_COLOR = "\033[0m";

int main() {
    EquipmentList dll;
    bool isRunning = true;  // Boolean variable to control the loop
    string name, model, serial, equipmentToDelete, serialNumber;
    string categoryName;
    bool isLent;
    string filename = "equipment_data.csv";
    while (isRunning) {
        //system("cls");
        int Opt;
        int selectedCategory = -1;
        cout << "________________________________________________________________" << endl;
        cout <<  RED_COLOR << "_____________ Lab Equipment Tracker Version 1.124 ______________" << RESET_COLOR<< endl;
        cout << "________________________________________________________________" << endl;
        
        cout << "                                                              " << endl;
        cout << "                    ----- MENU -----" << endl;
        cout << "                                                              " << endl;
        cout << " 1. Load data from local machine" << endl;
        cout << " 2. Lend Equipment"<< endl;
        cout << " 3. Return Equipment"<< endl;
        cout << " 4. Add Equipment by selecting existing category " << endl;
        cout << " 5. Add Equipment with category" << endl;
        cout << " 6. Delete an Equipment " << endl;
        cout << " 7. Search Equipment " << endl;
        cout << " 8. Print Equipment relevant to its category" << endl;
        cout << " 9. Save data locally" << endl;
        cout << "10. Instructions" << endl;
        cout << "11. Exit" << RESET_COLOR << endl;
        

        
        cout << "_____________________________________________________________" << endl;
        cout << "Enter the number corresponding to your instruction : ";
        cin >> Opt;

        switch (Opt) {
        case 1: // Load data from CSV
            system("cls");
            cout << "Data loaded from local machine" << endl;
            dll.loadFromCSV(filename);
            break;

        case 2:     //for lend equipments
            system("cls");
            cout << "Lend Equipment option selected" << endl;
            cout << "................................................." << endl;
            dll.lendEquipment();
            break;

        case 3:
            system("cls");
            cout << "Return Equipment option selected" << endl;
            cout << "Enter the serial number of the equipment to be returned: ";
            cin >> serialNumber;

            dll.returnEquipment(serialNumber);
            break;

        case 4:
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
            dll.addEquipmentToCategory(selectedCategory);
            cout << "                                                              " << endl;
            cout << "Equipment added successfully!" << endl;
            break;
        case 5:
            system("cls");
            cout << "Add Equipment with category option is selected" << endl;
            cout << "______________________________________________" << endl;
            dll.addEquipment();
            break;
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
            dll.printEquipmentByCategory();

            break;

        case 9: // Save data to CSV and exit
            system("cls");
            dll.saveToCSV(filename);
            break;

        case 10:
            system("cls");
            cout << "________________________________ INSTRUCTIONS ________________________________" << endl;
            cout << "                                                                              " << endl;
            cout << "~ Use the number corresponding to the menu item for interact with the program." << endl;
            cout << "~ Initially the program will not include any equipment data." << endl;
            cout << "~ You can add dummy data by selecting option 1." << endl;
            break;

        case 11:
            system("cls");
            dll.saveToCSV(filename);
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