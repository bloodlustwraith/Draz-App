#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Stack_NODE.h"

using namespace std;

class Stack
{
public:
    Stack_NODE* Stack_TOP;
    ofstream customerfile;

public:
    Stack();
    ~Stack();

    bool IsEmpty();
    void Push(string name, int id, bool favorite, int price, string name_custmr);
    bool Pop(string& name, int& id, bool& is_fav, int& price, string& name_custmr);
    void show_favorit_products(Stack_NODE* temp);
    void Display(Stack_NODE* temp);
    void Search_value(int id, bool& is_present, Stack_NODE*& copy_data, Stack_NODE* temp);
    Stack_NODE* Delete_this_data(int deletion_id);
    void saveinfilecustomer(Stack_NODE* temp);
    void saveinfilecustomerhelp();
};
