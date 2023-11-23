#include <iostream>
#include "Equipment.h"

void EquipmentList::print() {
    LabEquipment* current = head;
    while (current != nullptr) {
        std::cout << "Name          : " << current->name << std::endl;
        std::cout << "Category      : " << current->category << std::endl;
        std::cout << "Model         : " << current->model << std::endl;
        std::cout << "Serial Number : " << current->serial << std::endl;
        std::cout << "Availability  : " << current->isLent << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

void EquipmentList::filterByCategory(const std::string& category) {
    LabEquipment* current = head;
    while (current != nullptr) {
        if (current->category == category) {
            std::cout << "Name          : " << current->name << std::endl;
            std::cout << "Category      : " << current->category << std::endl;
            std::cout << "Model         : " << current->model << std::endl;
            std::cout << "Serial Number : " << current->serial << std::endl;
            std::cout << "Availability  : " << current->isLent << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void dummyData() {
    EquipmentList dll;
    // insertFirst calls...
    dll.print();
}

void runProgram() {
    EquipmentList dll;
    int Opt;
    std::string category;

    std::cout << "_____________Lab Equipment Tracker Version 1.0______________" << std::endl;
    std::cout << "Please enter a menu number corresponding to your need." << std::endl;
    std::cout << "1. Lend Equipment" << std::endl;
    std::cout << "2. Add Equipment " << std::endl;
    std::cout << "3. See all Categories " << std::endl;
    std::cout << "4. See all the equipment (sorted) " << std::endl;
    std::cout << "5. Delete an Equipment " << std::endl;
    std::cout << "6. Search Equipment " << std::endl;
    std::cout << "7. Sample Data Display " << std::endl;
    std::cout << "______________________________________________________" << std::endl;

    std::cin >> Opt;
    switch (Opt) {
    case 1:
        std::cout << "Lend Equipment option selected" << std::endl;
        break;
    case 2:
        std::cout << "Add Equipment option selected" << std::endl;
        break;
    case 6:
        std::cout << "Search Equipment by Category option selected" << std::endl;
        std::cout << "Enter category to filter: ";
        std::cin >> category;
        std::cout << "Equipment in category '" << category << "':" << std::endl;
        dll.filterByCategory(category);
        break;
    case 7:
        std::cout << "Sample data display option selected" << std::endl;
        dummyData();
        break;
    default:
        std::cout << "Please enter a valid option key" << std::endl;
        break;
    }
}

int main() {
    runProgram();
    return 0;
}
