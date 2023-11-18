#include <iostream>
#include <cstdlib>
#include "Equipment.h"


//test comment



/*void runProgram() {
    int Opt;
    cout << "Enter a option" << endl;
    cin >> Opt;
    switch (Opt) {
    case 1:     //for lend equipments
        cout << "Lend Equipment option selected" << endl;
        break;
    case 2:
        cout << "Add Equipment option selected" << endl;
        break;
    default:
        cout << "Please enter a valid option key" << endl;
        break;
    }
}*/

int main() {
    // runProgram();
    EquipmentList dll;
    dll.insertFirst("Oscilloscope", "Measurement", "Tektronix TDS210", "OS-12345", true);
    dll.insertFirst("Function Generator", "Signal Generator", "Agilent 33500B", "FG-67890", false);
    dll.insertFirst("Multimeter", "Measurement", "Fluke 87V", "MM-24680", true);
    dll.insertFirst("Power Supply", "Power", "Agilent E3631A", "PS-13579", false);
    dll.insertFirst("Spectrum Analyzer", "Signal Analyzer", "Rohde & Schwarz FSW", "SA-54321", true);
    dll.insertFirst("Digital Logic Analyzer", "Measurement", "Keysight MSO-X 3034T", "DL-98765", false);
    dll.insertFirst("Signal Generator", "Signal Generator", "Keysight 33522A", "SG-11223", true);
    dll.insertFirst("Function Generator", "Signal Generator", "Rigol DG1022Z", "FG-45678", false);
    dll.insertFirst("Digital Oscilloscope", "Measurement", "Tektronix MSO2014B", "OS-13579", true);
    dll.insertFirst("Voltage Regulator", "Power", "LM317", "VR-98765", false);
    dll.insertFirst("Signal Generator", "Signal Generator", "B&K Precision 4040A", "SG-24680", true);
    dll.insertFirst("Logic Probe", "Measurement", "HP 1043A", "LP-11223", false);
    dll.insertFirst("Power Supply", "Power", "Agilent E3646A", "PS-54321", true);
    dll.insertFirst("Waveform Generator", "Signal Generator", "Teledyne LeCroy ArbStudio 1102", "WG-13579", false);
    dll.insertFirst("Frequency Counter", "Measurement", "Fluke 725", "FC-98765", true);
    dll.insertFirst("DC Motor", "Motors", "NEMA 23", "DM-11223", false);
    dll.insertFirst("Soldering Station", "Tools", "Hakko FX-888D", "SS-24680", true);
    dll.insertFirst("Logic Analyzer", "Measurement", "Agilent 16802A", "LA-13579", false);
    dll.insertFirst("Capacitance Meter", "Measurement", "Keysight U1733C", "CM-98765", true);
    dll.insertFirst("Digital Power Supply", "Power", "Rigol DP832A", "DPS-11223", false);
    dll.print();
    return 45;
}



//insertFirst(string N, string cat, string mod,string Snum, bool lent)
/*

*/