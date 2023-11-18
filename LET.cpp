#include <iostream>
#include <cstdlib>
#include "Equipment.h"


//test comment



void runProgram() {
    int Opt;
    cout << "_____________Lab Equipment Tracker Version 1.0______________" << endl;
    cout << "Please enter a menu number corresponding to your need." << endl;
    cout << "1. Lend Equipment" << endl;
    cout << "2. Add Equipment " << endl;
    cout << "3. See all Categories " << endl;
    cout << "4. See all the equipment (sorted) " << endl;
    cout << "5. Delete an Equipment " << endl;
    cout << "6. Search Equipment " << endl;
    cout << "______________________________________________________" << endl;
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
}



int main() {
    runProgram();
    //dummyData();
   /* 
    dll.print();
    */
    return 45;
}



//insertFirst(string N, string cat, string mod,string Snum, bool lent)
/*

*/