#include "BST.h"

#include <iostream>
#include<fstream>

using namespace std;

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    root = nullptr;
}

Node_bst* BST::Get_root() {
    return root;
}

Node_bst* BST::Insert(string name, int id, int count, int price, Node_bst* temp) {
    if(!temp) {
        Node_bst* newnode = new Node_bst;
        newnode->PRODUCT_NAME = name;
        newnode->ID = id;
        newnode->COUNT = count;
        newnode->PRICE = price;
        newnode->left = nullptr;
        newnode->right = nullptr;
        temp = newnode;
        return temp;
    }
    if(id < temp->ID) {
        temp->left = Insert(name, id, count, price, temp->left);
    }
    else if(id > temp->ID) {
        temp->right = Insert(name, id, count, price, temp->right);
    }
    return temp;
}

void BST::Search_bst(Node_bst* temp, int id, bool& found, Node_bst*& copy_node_dataa) {
    if(root == nullptr) {
        //cout << "BST is Empty\n";
        return;
    }
    if(temp != nullptr) {
        Search_bst(temp->left, id, found, copy_node_dataa);
        Search_bst(temp->right, id, found, copy_node_dataa);
        if(temp->ID == id) {
            copy_node_dataa = temp;
            found = true;
        }
    }
}

Node_bst* BST::Search_and_decrease_count(Node_bst* temp, int id, bool& found, Node_bst*& copy_node_dataa) {
    if(root == nullptr) {
        //cout << "BST is Empty\n";
        return nullptr;
    }
    if(temp != nullptr) {
        if(temp->ID == id && temp->COUNT >= 1) {
            temp->COUNT = temp->COUNT - 1;
            copy_node_dataa = temp;
            found = true;

            //Decrease quantity from the file also
            ifstream innn("productdata.txt");
            ofstream outtt("productdata_temp.txt");
            int _id;
            string product_name;
            int count;
            int price;
            while(innn >> product_name >> _id >> count >> price) {
                if(_id == id)
                    outtt << product_name << ' ' << _id << ' ' << --count << ' ' << price << endl;
                else
                    outtt << product_name << ' ' << _id << ' ' << count << ' ' << price << endl;
            }
            innn.close();
            outtt.close();
            remove("productdata.txt");
            rename("productdata_temp.txt", "productdata.txt");
        }
        else {
            if(id < temp->ID) {
                temp->left = Search_and_decrease_count(temp->left, id, found, copy_node_dataa);
            }
            else {
                temp->right = Search_and_decrease_count(temp->right, id, found, copy_node_dataa);
            }
        }
    }
    return temp;
}

void BST::Display_Inorder(Node_bst* temp) {
    if(root == nullptr) {
        cout << "No Data is Present\n";
        return;
    }
    if(temp) {
        if(temp == root) {
            cout << "Number of counts   :   ID of Product    :   Price of Product    :    Name of Product " << endl;
        }
        Display_Inorder(temp->left);
        if(temp->COUNT >= 0) {
            cout << "      ";
            if(temp->COUNT == 0) cout << "OUT OF STOCK" << "\t\t\t  ";
            else cout << temp->COUNT << "\t\t\t  ";
            cout << temp->ID << "\t\t\t";
            cout << temp->PRICE << "\t\t\t";
            cout << temp->PRODUCT_NAME << "\n";
        }
        Display_Inorder(temp->right);
    }
}

Node_bst* BST::Delete_Node_BST(Node_bst* root_temp, int data_que) {
    if(root_temp == nullptr)
        return root_temp;
    else if(data_que < root_temp->ID)
        root_temp->left = Delete_Node_BST(root_temp->left, data_que);
    else if(data_que > root_temp->ID)
        root_temp->right = Delete_Node_BST(root_temp->right, data_que);
    else {
        if(root_temp->left == nullptr && root_temp->right == nullptr) {
            delete root_temp;
            return nullptr;
        }
        else if(root_temp->left == nullptr) {
            Node_bst* temp = root_temp;
            root_temp = root_temp->right;
            delete temp;
        }
        else if(root_temp->right == nullptr) {
            Node_bst* temp = root_temp;
            root_temp = root_temp->left;
            delete temp;
        }
        else {
            Node_bst* temp = root_temp->right;
            while(temp->left) {
                temp = temp->left;
            }
            root_temp->ID = temp->ID;
            root_temp->right = Delete_Node_BST(root_temp->right, temp->ID);
        }
    }
    return root_temp;
}

int BST::Total_nodes(Node_bst* temp) {
    static int h = 0;
    if(temp != nullptr) {
        Total_nodes(temp->left);
        Total_nodes(temp->right);
        h = h + 1;
    }
    return h;
}

Node_bst* BST::Modify_Product(string name, int id, int count, int price, Node_bst* make_modify, Node_bst* temp) {
    if(root == nullptr) {
        return nullptr;
    }
    if(temp != nullptr) {
        if(temp == make_modify) {
            temp->PRODUCT_NAME = name;
            temp->ID = id;
            temp->COUNT = count;
            temp->PRICE = price;
            return temp;
        }
        else {
            temp->left = Modify_Product(name, id, count, price, make_modify, temp->left);
            temp->right = Modify_Product(name, id, count, price, make_modify, temp->right);
        }
    }
    return temp;
}

Node_bst* BST::return_product_and_count_increase(int copy_data_id, Node_bst* temp) {
    if(root == nullptr) {
        return nullptr;
    }
    if(temp != nullptr) {
        if(temp->ID == copy_data_id) {
            temp->COUNT = temp->COUNT + 1;

            //Decrease quantity from the file also
            ifstream innn("productdata.txt");
            ofstream outtt("productdata_temp.txt");
            int _id;
            string product_name;
            int count;
            int price;
            while(innn >> product_name >> _id >> count >> price) {
                if(_id == copy_data_id)
                    outtt << product_name << ' ' << _id << ' ' << ++count << ' ' << price << endl;
                else
                    outtt << product_name << ' ' << _id << ' ' << count << ' ' << price << endl;
            }
            innn.close();
            outtt.close();
            remove("productdata.txt");
            rename("productdata_temp.txt", "productdata.txt");
        }
        else {
            if(copy_data_id < temp->ID) {
                temp->left = return_product_and_count_increase(copy_data_id, temp->left);
            }
            else {
                temp->right = return_product_and_count_increase(copy_data_id, temp->right);
            }
        }
    }
    return temp;
}

void BST::saveinfiletemp() {
    adminfile.open("admindata.txt", ios::out);
    if(!adminfile) {
        cout << "Error\nFile not open\n";
    }
    else {
        adminfile << "Number of counts   :   ID of Product    :   Price of Product    :    Name of Product " << endl;
        saveinfile(root);
        adminfile.close();
    }
}

void BST::saveinfile(Node_bst* temp) {
    if(root == nullptr) {
        cout << "No Data is Present\n";
        return;
    }
    if(temp) {
        saveinfile(temp->left);
        if(temp->COUNT >= 1) {
            adminfile << "      ";
            adminfile << temp->COUNT << "\t\t\t  ";
            adminfile << temp->ID << "\t\t\t";
            adminfile << temp->PRICE << "\t\t\t";
            adminfile << temp->PRODUCT_NAME << "\n";
        }
        saveinfile(temp->right);
    }
}
