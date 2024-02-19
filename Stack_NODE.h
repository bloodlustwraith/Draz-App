#pragma once

#include <string>

using namespace std;

class Stack_NODE
{
public:
    string PRODUCT_NAME;
    string CUSTOMER_NAME;
    int ID;
    bool is_Faviorite;
    int PRICE;
    Stack_NODE* next; // Pointer to the next node

    Stack_NODE(); // Constructor
};
