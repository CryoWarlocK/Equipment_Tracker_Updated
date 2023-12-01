#pragma once

using namespace std;
//Node in our code
class LabEquipment {
public:
    string name;
    string category;
    string model;
    string serial;
    bool isLent;
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

    void insertFirst(std::string N, std::string cat, std::string mod, std::string Snum, bool lent) {
        LabEquipment* temp = new LabEquipment(N, cat, mod, Snum, lent);
        if (head == nullptr) {
            head = temp;
            tail = temp;
            size++;
        }
        else {
            temp->next = head;
            head->prev = temp;
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
            cout << "Name          : " << current->name << endl;
            cout << "Category      : " << current->category << endl;
            cout << "Model         : " << current->model << endl;
            cout << "Serial Number : " << current->serial << endl;
            cout << "Availability  : " << current->isLent << endl;
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
                cout << current->category << endl;
            }

            current = current->next;
        }

        cout << endl;
    }

    // Method to print all unique categories with numbers or letters
    void printUniqueCategories(char categoryLetters[]) {
        LabEquipment* current = head;
        LabEquipment* temp;
        char categoryLetter = 'A';

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
                cout << categoryLetter << ". " << current->category << endl;
                categoryLetters[categoryLetter - 'A'] = categoryLetter;
                categoryLetter++;
            }

            current = current->next;
        }

        cout << endl;
    }



    // Method to add equipment to a specific category
    void addEquipmentToCategory(const string& category, const string& name, const string& model, const string& serial, bool isLent){
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
