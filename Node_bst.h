#pragma once

#include <string>
using namespace std;

class Node_bst {
public:
    string PRODUCT_NAME;
    int ID;
    int COUNT;
    int PRICE;
    int QUANTITY;
    Node_bst* left;
    Node_bst* right;

    Node_bst();
};
