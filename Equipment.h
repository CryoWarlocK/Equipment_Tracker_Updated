#pragma once
#include <cstddef>
#include <iostream>
#include <fstream>


using namespace std;
//Node in our code
class LabEquipment {
public:
    string name;        //equipment name
    string category;    //equipment catagory
    string model;       //equipment model
    string serial;      // whether equipment is lend to student or not
    bool isLent;
    LabEquipment* next; // pointer to next node
    LabEquipment* prev; // Pointer to the previous node


    //overide the default constructor
    LabEquipment() {
        name = "";
        category = "";
        model = "";
        serial = "";
        isLent = false;
        next = NULL;
        prev = NULL;
    }

    //overloaded default constructor
    LabEquipment(string N, string cat, string mod, string Snum, bool lent) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        next = NULL;
        prev = NULL;
    }
};

//A doubly linked list
class EquipmentList {
private:
    LabEquipment* head;
    LabEquipment* tail;
    int size;

public:
    //default constructor
    EquipmentList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    LabEquipment* getHead() {
        return head;
    }

    LabEquipment* getTail() {
        return tail;
    }

    void insertFirst(string N, string cat, string mod, string Snum, bool lent) {
        //create the equipment
        LabEquipment* temp = new LabEquipment(N, cat, mod, Snum, lent);
        if (head == NULL) { //empty list
            head = temp;
            tail = temp;
            size++;
        }
        else { //non empty list
            temp->next = head; //arrow (->) is used with pointers | dot (.) is used with objects
            head->prev = temp; //*************
            head = temp;
            size++;
        }
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


    void print() {


        LabEquipment* current;
        current = head;
        while (current != NULL)
        {
            std::cout << "Name          : " << current->name << endl;
            std::cout << "Category      : " << current->category << endl;
            std::cout << "Model         : " << current->model << endl;
            std::cout << "Serial Number : " << current->serial << endl;
            std::cout << "Availability  : " << current->isLent << endl;
            std::cout << endl;
            std::cout << endl;
            current = current->next;
        }
        std::cout << endl;
    }

    // Method to filter and display equipment based on a specific category
    void filterByCategory(const string& filterCategory) {
        LabEquipment* current = head;
        while (current != NULL) {
            if (current->category == filterCategory) {
                std::cout << "Name          : " << current->name << endl;
                std::cout << "Category      : " << current->category << endl;
                std::cout << "Model         : " << current->model << endl;
                std::cout << "Serial Number : " << current->serial << endl;
                std::cout << "Availability  : " << current->isLent << endl;
                std::cout << endl;
                std::cout << endl;
            }
            current = current->next;
        }
        std::cout << endl;
    }

    // Method to traverse the list and print all unique categories
    void printUniqueCategories() {
        LabEquipment* current = head;
        LabEquipment* temp;
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
                std::cout << current->category << endl;
            }

            current = current->next;
        }

        std::cout << endl;
    }

    void addEquipmentToCategory(const string& category, const string& name, const string& model, const string& serial, bool isLent) {
        // Create the equipment
        LabEquipment* temp = new LabEquipment(name, category, model, serial, isLent);

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

};



// Function to lend equipment
void lendEquipment(EquipmentList& equipmentList) {
    std::string selectedCategory;
    std::string serialNumber;
    std::string borrowerName;
    std::string registerNumber;
    std::string date;

    std::cout << "Lend Equipment option selected" << std::endl;
    std::cout << "_______________________________" << std::endl;
    std::cout << "Please select a category from below list to lend equipment" << std::endl;
    equipmentList.printUniqueCategories();
    std::cout << "____________________________________" << std::endl;
    std::cout << "Please enter a category from the above list: ";
    std::cin >> selectedCategory;

    // Filter and display available equipment in the selected category
    std::cout << "Available equipment in category '" << selectedCategory << "':" << std::endl;
    equipmentList.filterByCategory(selectedCategory);

    std::cout << "Enter the serial number of the equipment to be borrowed: ";
    std::cin >> serialNumber;

    // Find the equipment with the given serial number
    LabEquipment* equipment = equipmentList.getHead();
    while (equipment != nullptr) {
        if (equipment->category == selectedCategory && equipment->serial == serialNumber && equipment->isLent == false) {
            // Equipment found and available for lending
            std::cout << "Enter borrower name: ";
            std::cin >> borrowerName;
            std::cout << "Enter borrower register number: ";
            std::cin >> registerNumber;

            // Update equipment information
            equipment->isLent = true;

            // Save lending information to a local text file
            std::fstream outFile ("lending_records.txt", std::ios::app);
            if (outFile.is_open()) {
                outFile << "Category: " << selectedCategory << std::endl;
                outFile << "Equipment Name: " << equipment->name << std::endl;
                outFile << "Serial Number: " << serialNumber << std::endl;
                outFile << "Borrower Name: " << borrowerName << std::endl;
                outFile << "Register Number: " << registerNumber << std::endl;
                outFile << "Date of Borrowed: " <<date<< std::endl;
                outFile << "-------------------------" << std::endl;
                outFile.close();
                std::cout << "Successfully borrowed equipment. Lending details saved to lending_records.txt" << std::endl;
            }
            else {
                std::cout << "Error: Unable to save lending information" << std::endl;
            }

            return;
        }
        equipment = equipment->next;
    }

    // Equipment not found or not available for lending
    std::cout << "Error: Equipment not found or not available for lending." << std::endl;
}

// Function to delete an equipment
//void d }
