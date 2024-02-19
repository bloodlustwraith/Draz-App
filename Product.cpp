#include "Product.h"
#include "Store.h"

Product::Product(BST& bst) : store_data_bst(bst)
{
}

void Product::AddInitialProducts()
{
	ifstream inputData("productdata.txt");
	string _name = "";
	int _id = -1, _count = -1, _price = -1;
	while(inputData >> _name >> _id >> _count >> _price) {
		store_data_bst.root = store_data_bst.Insert(_name, _id, _count, _price, store_data_bst.Get_root());
	}
	inputData.close();
}


int Product::productcount()
{
	string a;
	int b, c, d;
	int count = 0;
	ifstream data("productdata.txt");
	while(data >> a >> b >> c >> d)
	{
		count++;
	}
	return count;
}

bool Product::searchproduct(int id) {
	string a;
	int b, c, d;
	ifstream data1("productdata.txt");
	while(data1 >> a >> b >> c >> d) {
		if(b == id) {
			return true;
		}
	}
	return false;
}

void Product::Add() {
a:
	system("cls");
	ofstream addproduct("productdata.txt", ios::app);
	string name_product;
	int id = 0, count = 0, price = 0, a;

	while(true) {
		// Input name
		cout << "Enter Product Name to Insert: ";
		cin >> name_product;
		addproduct << name_product << " ";
		// Input Unique ID
		bool data_match = false;
		Node_bst* copy_node_dataa = nullptr;
		do {
			data_match = false;
			cout << "Enter Product ID (Unique ID): ";
			cin >> id;
			store_data_bst.Search_bst(store_data_bst.Get_root(), id, data_match, copy_node_dataa);
			if(data_match) {
				cout << "This ID is Already Declared for another Product \"" << copy_node_dataa->PRODUCT_NAME << "\"" << endl;
			}
		} while(data_match);
		addproduct << " " << id << " ";

		// Input Counting of Product
		c:
		do {
			cout << "Enter Count of Product (Count >=10): ";
			cin >> count;
			if(count < 10) {
				cout << "You cannot add products less than 10" << endl;
				goto c;
			}
			
		} while(count < 1);
		addproduct << " " << count << " ";

		// Take the price of the product
		do {
			cout << "Enter the Price (1 unit) of the Product > 0: ";
			cin >> price;
		} while(price < 1);
		addproduct << " " << price << " " << endl;
		store_data_bst.root = store_data_bst.Insert(name_product, id, count, price, store_data_bst.Get_root());
		cout << endl;
		cout << name_product << " <- Product is Added in the Store Successfully!\n\n";
		Store s;
		cout << "Press 1 to add more Products\n\nPress 2 to go back to menu\n\nChoose:";
		cin >> a;
		if(a == 1) {
			goto a;
		}
		else if(a == 2) {
			return;
		}
	}
	addproduct.close();
}

void Product::Search() {
	system("cls");
	/*store_data_bst.Display_Inorder(store_data_bst.Get_root());*/
	cout << "Enter ID to Search :";
	int data_que;
	cin >> data_que;
	bool data_found = false;
	Node_bst* copy_node_data = NULL;
	store_data_bst.Search_bst(store_data_bst.Get_root(), data_que, data_found, copy_node_data);
	if(data_found == false) {
		cout << "No Data Match With this ID\n";
	}
	else {
		cout << "Data Found in Store\n";
		cout << "Name=" << copy_node_data->PRODUCT_NAME << endl;
		cout << "ID=" << copy_node_data->ID << endl;
		cout << "COUNT=" << copy_node_data->COUNT << endl;
	}
	system("pause");
}

void Product::DisplayAll() {
	system("cls");
	store_data_bst.Display_Inorder(store_data_bst.Get_root());
	system("pause");
}


void Product::Modify() {
	system("cls");
	store_data_bst.Display_Inorder(store_data_bst.Get_root());
	cout << "Enter Existing ID to Modify Product: ";
	int id_modify;
	cin >> id_modify;
	bool data_found = false;
	Node_bst* copy_node_dataa = nullptr;
	store_data_bst.Search_bst(store_data_bst.Get_root(), id_modify, data_found, copy_node_dataa);
	if(data_found == false) {
		cout << "No Data Match With this ID\n";
	}
	else {
		string name;
		int id = 0, count = 0, price = 0;

		// Input name
		cout << "Enter New Name of Product: ";
		cin >> name;

		// Input Unique ID
		bool data_match = false;
		Node_bst* copy_node = nullptr;
		bool does_id_match_bool = false;

		// Loop for unique ID
		do {
			data_match = false;
			cout << "Enter New ID of Product (Unique ID): ";
			cin >> id;
			store_data_bst.Search_bst(store_data_bst.Get_root(), id, data_match, copy_node);
			if(copy_node == nullptr)
			{
				does_id_match_bool = true;
			}
			else if(id_modify == copy_node->ID)
			{
				does_id_match_bool = true;
			}
			else if(data_match == true)
			{
				cout << "This ID is Already Declared for another Product \"" << copy_node->PRODUCT_NAME << "\"" << endl;
			}
		} while(does_id_match_bool == false);

		// Input Counting of Product
		do {
			cout << "Enter New Count of Product (Count > 0): ";
			cin >> count;
		} while(count < 1);

		// Take the price of the product
		do {
			cout << "Enter the Price (1 unit) of the Product > 0: ";
			cin >> price;
		} while(price < 1);

		store_data_bst.root = store_data_bst.Modify_Product(name, id, count, price, copy_node_dataa, store_data_bst.root);

		//Modification in the file:
		ifstream OldFile("productdata.txt");
		ofstream newFile("temp_productdata.txt");
		string _name = "";
		int _id = -1, _count = -1, _price = -1;
		while(OldFile >> _name >> _id >> _count >> _price) {
			if(_id != id_modify) {
				newFile << _name << " " << _id << " " << _count << " " << _price << endl;
			}
			else {
				newFile << name << " " << id << " " << count << " " << price << endl;
			}
		}
		OldFile.close();
		newFile.close();
		remove("productdata.txt");
		rename("temp_productdata.txt", "productdata.txt");


		cout << "Product is Modified Successfully\n";
	}
	system("pause");
}


void Product::Total()
{
	system("cls");
	int total_product = 0;
	total_product = store_data_bst.Total_nodes(store_data_bst.Get_root());
	cout << "Total Products in The Store is/are = " << total_product << endl;
	system("pause");
}



void Product::Delete()
{
	system("cls");
	store_data_bst.Display_Inorder(store_data_bst.Get_root());
	cout << "Enter ID to Delete Product: ";
	int id;
	cin >> id;
	bool data_found = false;
	Node_bst* copy_node_data = nullptr;

	// Function will find the node in the store if present or not,
	// If present, it will copy the node data for usage
	store_data_bst.Search_bst(store_data_bst.Get_root(), id, data_found, copy_node_data);

	if(data_found == false)
	{
		cout << "No Data Match With this ID\n";
	}
	else
	{
		store_data_bst.root = store_data_bst.Delete_Node_BST(store_data_bst.Get_root(), id);

		//Deletion From File:
		ifstream OldFile("productdata.txt");
		ofstream newFile("temp_productdata.txt");
		string _name = "";
		int _id = -1, _count = -1, _price = -1;
		while(OldFile >> _name >> _id >> _count >> _price) {
			if(_id != id) {
				newFile << _name << " " << _id << " " << _count << " " << _price << endl;
			}
			else {
				continue;
			}
		}
		OldFile.close();
		newFile.close();
		remove("productdata.txt");
		rename("temp_productdata.txt", "productdata.txt");


		cout << "Product is Deleted from the Store Successfully\n";
	}
	system("pause");
}
