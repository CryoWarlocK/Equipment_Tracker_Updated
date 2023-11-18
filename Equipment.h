#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

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

};