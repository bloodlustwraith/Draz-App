#pragma once

#include <string>
#include <iostream>
#include "BST.h"

class Product
{
private:
    BST& store_data_bst;

public:
    Product(BST& bst);
    void AddInitialProducts();
    int productcount();
    bool searchproduct(int);
    void Add();
    void Search();
    void DisplayAll();
    void Modify();
    void Delete();
    void Total();
};
