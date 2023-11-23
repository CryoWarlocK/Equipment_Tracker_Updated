#pragma once

#include <string>

class LabEquipment {
public:
    std::string name;
    std::string category;
    std::string model;
    std::string serial;
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

    void print();

    void filterByCategory(const std::string& category);
};

void dummyData();
