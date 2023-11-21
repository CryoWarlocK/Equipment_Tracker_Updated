#include <iostream>
#include <cstdlib>
#include "Equipment.h"


//test comment



void runProgram() {
 
    
}



int main() {
    EquipmentList dll;
    dll.insertLast("Oscilloscope", "Measurement", "Tektronix TDS210", "OS-12345", true);
    dll.insertLast("Function Generator", "Signal Generator", "Agilent 33500B", "FG-67890", false);
    dll.insertLast("Multimeter", "Measurement", "Fluke 87V", "MM-24680", true);
    dll.insertLast("Power Supply", "Power", "Agilent E3631A", "PS-13579", false);
    dll.insertLast("Spectrum Analyzer", "Signal Analyzer", "Rohde & Schwarz FSW", "SA-54321", true);
    dll.insertLast("Digital Logic Analyzer", "Measurement", "Keysight MSO-X 3034T", "DL-98765", false);
    dll.insertLast("Signal Generator", "Signal Generator", "Keysight 33522A", "SG-11223", true);
    dll.insertLast("Function Generator", "Signal Generator", "Rigol DG1022Z", "FG-45678", false);
    dll.insertLast("Digital Oscilloscope", "Measurement", "Tektronix MSO2014B", "OS-13579", true);
    dll.insertLast("Voltage Regulator", "Power", "LM317", "VR-98765", false);
    dll.insertLast("Signal Generator", "Signal Generator", "B&K Precision 4040A", "SG-24680", true);
    dll.insertLast("Logic Probe", "Measurement", "HP 1043A", "LP-11223", false);
    dll.insertLast("Power Supply", "Power", "Agilent E3646A", "PS-54321", true);
    dll.insertLast("Waveform Generator", "Signal Generator", "Teledyne LeCroy ArbStudio 1102", "WG-13579", false);
    dll.insertLast("Frequency Counter", "Measurement", "Fluke 725", "FC-98765", true);
    dll.insertLast("DC Motor", "Motors", "NEMA 23", "DM-11223", false);
    dll.insertLast("Soldering Station", "Tools", "Hakko FX-888D", "SS-24680", true);
    dll.insertLast("Logic Analyzer", "Measurement", "Agilent 16802A", "LA-13579", false);
    dll.insertLast("Capacitance Meter", "Measurement", "Keysight U1733C", "CM-98765", true);
    dll.insertLast("Digital Power Supply", "Power", "Rigol DP832A", "DPS-11223", false);

    bool isRunning = true;  // Boolean variable to control the loop
    while (isRunning) {
        int Opt;
        string selectedCategory = "NULL";
        cout << "                                                            " << endl;
        cout << "_____________Lab Equipment Tracker Version 1.0______________" << endl;
        cout << "Please enter a menu number corresponding to your need." << endl;
        cout << "1. Lend Equipment" << endl;
        cout << "2. Add Equipment " << endl;
        cout << "3. See all Categories " << endl;
        cout << "4. See all the equipment (sorted) " << endl;
        cout << "5. Delete an Equipment " << endl;
        cout << "6. Search Equipment " << endl;
        cout << "7. Sample Data Display " << endl;
        cout << "8. Exit " << endl;
        cout << "_____________________________________________________________" << endl;
        cin >> Opt;

        switch (Opt) {
        case 1:     //for lend equipments
            cout << "Lend Equipment option selected" << endl;
            break;
        case 2:
            cout << "Add Equipment option selected" << endl;
            cout << "_______________________________" << endl;
            cout << "Please select a category from below list to add a equipment" << endl;
            dll.printUniqueCategories();
            cout << "____________________________________" << endl;
            cout << "Please enter a category from above list" << endl;
            cin >> selectedCategory;
            cout << "Here are all the equipment in the category you selected" << endl;
            dll.filterByCategory(selectedCategory);
            break;
        case 7:
            cout << "Sample data display option selected" << endl;
            
            break;
        case 8:
            isRunning = false;  // Set the boolean variable to false to exit the loop
            break;

        default:
            cout << "Please enter a valid option key" << endl;
            break;
        }

    }
  
    return 0;
}

