#include <iostream>
#include <cstdlib>
#include "Equipment.h"
#include <string>

//test comment 4
using namespace std;

// ANSI escape codes for text color
const char* DARK_BLUE_COLOR = "\033[1;34m";

const char* PINK_COLOR = "\033[1;35m";
const char* LIGHTBLUE_COLOR = "\033[1;36m";
const char* GREEN_COLOR = "\033[1;32m";
const char* YELLOW_COLOR = "\033[1;33m";
const char* RED_COLOR = "\033[1;31m";

const char* RESET_COLOR = "\033[0m";

#define UBLK "\e[4;30m"
#define reset "\e[0m"



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
        cout << DARK_BLUE_COLOR <<"________________________________________________________________" << endl;
        cout<<"------------- Lab Equipment Tracker Version 1.124 --------------" << endl;
        cout << "----------------------------------------------------------------" << RESET_COLOR << endl;
        
        cout << "                                                              " << endl;
        cout <<RED_COLOR << "                    ----- MENU -----" <<RESET_COLOR<< endl;
        cout << "                                                              " << endl;
        cout <<YELLOW_COLOR<< " 1. Load data from local machine" << endl;
        cout << " 2. Lend Equipment"<< endl;
        cout << " 3. Return Equipment"<< endl;
        cout << " 4. Add Equipment by Selecting Existing Category " << endl;
        cout << " 5. Add Equipment with Category" << endl;
        cout << " 6. Delete an Equipment " << endl;
        cout << " 7. Search Equipment " << endl;
        cout << " 8. Print Equipment Relevant to Its' Category" << endl;
        cout << " 9. Save Data locally" << endl;
        cout << "10. Instructions for Using the Program" << endl;
        cout << "11. Exit" << RESET_COLOR << endl;
        

        
        cout << "_____________________________________________________________" << endl;
        cout << "Enter the Number Corresponding to Your Instruction : ";
        cin >> Opt;

        switch (Opt) {
        case 1: // Load data from CSV
            system("cls");
            cout << GREEN_COLOR<< "Local Data Successfully Loaded"<< RESET_COLOR << endl;
            dll.loadFromCSV(filename);
            break;

        case 2:     //for lend equipments
            system("cls");
            cout << GREEN_COLOR << "--Equipment Lending Option Selected--" << GREEN_COLOR << endl;;
            cout << LIGHTBLUE_COLOR<< "----------------------------------------------------------" <<RESET_COLOR << endl;
            dll.lendEquipment();
            break;

        case 3:
            system("cls");
            cout << GREEN_COLOR<< "Equipment Return Option Selected"<<RESET_COLOR << endl;
            cout << "Enter the serial number of the equipment to be returned: ";
            cin >> serialNumber;

            dll.returnEquipment(serialNumber);
            break;

        case 4:
            system("cls");
            cout << GREEN_COLOR << "Add Equipment Option Selected"<< RESET_COLOR << endl;
            cout << "_______________________________" << endl;
            dll.addEquipmentToSelectedCategory();
            break;
        case 5:
            system("cls");
            cout << GREEN_COLOR << "Add Equipment with Category Option is Selected" << RESET_COLOR << endl;
            cout << "______________________________________________" << endl;
            dll.addEquipment();
            break;
        case 6:
            system("cls");
            cout << GREEN_COLOR << "Delete an Equipment option selected" << RESET_COLOR << endl << endl;
            cout << "Enter the serial number of the equipment you want to delete: ";

            cin >> serialNumber;

            // Delete the equipment by serial number
            dll.deleteEquipmentBySerialNumber(serialNumber);
            break;
        case 7:
            system("cls");
            cout << "Enter the Serial Number of the Equipment : ";
            cin >> serialNumber;
            dll.searchBySerial(serialNumber);
            break;

        case 8:
            system("cls");
            cout << GREEN_COLOR << "Print All the Equipments Option Selected" << RESET_COLOR << endl;
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