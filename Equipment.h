#pragma once
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
    string* student = new string[3];
    LabEquipment* next;
    LabEquipment* prev;

    LabEquipment() {
        name = "";
        category = "";
        model = "";
        serial = "";
        isLent = false;
        next = nullptr;
        prev = nullptr;
    }

    LabEquipment(std::string N, std::string cat, std::string mod, std::string Snum, bool lent) {
        name = N;
        category = cat;
        model = mod;
        serial = Snum;
        isLent = lent;
        next = nullptr;
        prev = nullptr;
    }
};

class EquipmentList {
private:
    LabEquipment* head;
    LabEquipment* tail;
    int size;

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
            cout << "Availability  : " << (current->isLent ? "Available" : "Not Available")<< endl;
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



    // Method to add equipment to a specific category
    void addEquipmentToCategory(int categoryNumber, const string& name, const string& model, const string& serial, bool isLent) {
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

    //Method to delete equipment by name
    void deleteEquipmentByName(const string& equipmentName) {
        LabEquipment* current = head;

        while (current != nullptr) {
            // Print names of equipment while traversing (for debugging)
            cout << "Equipment Name: " << current->name << endl;

            if (current->name == equipmentName) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                }
                else {
                    current->prev->next = current->next;
                    if (current->next != nullptr) {
                        current->next->prev = current->prev;
                    }
                }

                delete current;
                cout << "Equipment '" << equipmentName << "' deleted successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Equipment '" << equipmentName << "' not found." << endl;
    }



};
