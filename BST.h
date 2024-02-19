#pragma once

#include "Node_bst.h"
#include<fstream>

class BST {
public:

    Node_bst* root;
    fstream adminfile;

    BST();
    ~BST();

    Node_bst* Get_root();
    Node_bst* Insert(string name, int id, int count, int price, Node_bst* temp);
    void Search_bst(Node_bst* temp, int id, bool& found, Node_bst*& copy_node_dataa);
    Node_bst* Search_and_decrease_count(Node_bst* temp, int id, bool& found, Node_bst*& copy_node_dataa);
    void Display_Inorder(Node_bst* temp);
    Node_bst* Delete_Node_BST(Node_bst* root_temp, int data_que);
    int Total_nodes(Node_bst* temp);
    Node_bst* Modify_Product(string name, int id, int count, int price, Node_bst* make_modify, Node_bst* temp);
    Node_bst* return_product_and_count_increase(int copy_data_id, Node_bst* temp);
    void saveinfiletemp();
    void saveinfile(Node_bst* temp);
};