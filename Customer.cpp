#include "customer.h"
#include "Store.h"
Customer::Customer(BST& bst) : store_data_bst(bst)
{
	customer_bucket = new Stack;
	Customer_queue = new Queue;
}

void Customer::BuyProduct(std::string& name_custmr)
{
	a:
	system("cls");
	int id,b;
	store_data_bst.Display_Inorder(store_data_bst.Get_root());
	cout << "Enter ID to Buy a Product From Store: ";
	cin >> id;
	bool data_match = false;
	Node_bst* copy_node_dataa = NULL;
	store_data_bst.root = store_data_bst.Search_and_decrease_count(store_data_bst.Get_root(), id, data_match, copy_node_dataa);

	if(data_match == false)
	{
		cout << "No Data is Present with this ID (or May be OUT of Stock)\n";
	}
	else
	{
		customer_bucket->Push(copy_node_dataa->PRODUCT_NAME, copy_node_dataa->ID, false, copy_node_dataa->PRICE, name_custmr);
		cout << endl;
		cout << "Product is Added in the Bucket Successfully\n\n";
		b:
		cout << "Press 1 to buy product again\n\nPress 2 to go back\n\nChoose: ";
		cin >> b;
		if(b == 1)
		{
			goto a;
		}
		else if(b == 2)
		{
			return;
		}
		else
		{
			cout << "Wrong input try again" << endl;
			goto b;
		}
	}
	system("pause");
}

void Customer::ShowComplains()

{
	system("cls");
	std::string line = "N/A";
	int complain_number = 1;
	int useless1 = 0;
	std::string useless3;
	bool useless2 = false;
	while(complains_obj.Pop(line, useless1, useless2, useless1, useless3) == true)
	{
		cout << "\nComplain No." << complain_number << " : ";
		cout << line;
		complain_number++;
	}
	cout << endl;
	system("pause");
}

void Customer::Complain(std::string& name_custmr)
{
	system("cls");
	string complain;
	string useless3;
	cout << "\tPLEASE WRITE YOUR COMPLAINS\n";
	getline(std::cin, complain);
	getline(std::cin, complain);

	complain = name_custmr + " -> " + complain;
	complains_obj.Push(complain, -1, false, -1, useless3);
	cout << "Your Complain is Recorded\n";
	system("pause");
}

void Customer::Display()
{
	system("cls");
	Customer_queue->Display();
	system("pause");
}

void Customer::Dequeue()
{
	system("cls");
	Customer_queue->Dequeue();
}

void Customer::FavouriteProducts()
{
	system("cls");
	customer_bucket->show_favorit_products(customer_bucket->Stack_TOP);
	system("pause");
}

void Customer::ReturnProduct()
{
	system("cls");
	int id;
	bool is_present = false;
	Stack_NODE* copy_data;
	customer_bucket->Display(customer_bucket->Stack_TOP);
	cout << "Enter the ID of the Product which You want to Return: ";
	cin >> id;
	customer_bucket->Search_value(id, is_present, copy_data, customer_bucket->Stack_TOP);
	if(is_present) {
		int to_be_delete_id = copy_data->ID;
		store_data_bst.root = store_data_bst.return_product_and_count_increase(copy_data->ID, store_data_bst.root);
		customer_bucket->Stack_TOP = customer_bucket->Delete_this_data(to_be_delete_id);
	}
	else {
		cout << "No Data Present with this ID\n";
	}
}

void Customer::BuyingHistory()
{
	system("cls");
	
	cout << "The Customer Buying History is as:\n";
	customer_bucket->Display(customer_bucket->Stack_TOP);
	system("pause");
}

void Customer::GoToQueue()
{
	system("cls");
	customer_bucket->saveinfilecustomerhelp();

	if(customer_bucket->IsEmpty() == false)
	{
		string name_product = "", custmr_name2 = "";
		int id = 0, price = 0;
		bool fav = false;
		while(customer_bucket->Pop(name_product, id, fav, price, custmr_name2) == true)
		{
			Customer_queue->Enqueue(name_product, id, fav, price, custmr_name2);
		}

		Customer_queue->Enqueue(name_product, id, fav, -5, custmr_name2);

		while(customer_bucket->Pop(name_product, id, fav, price, custmr_name2))
		{
			// Making empty the Bucket for the next customer
		}
	}
}

void Customer::ExitShopping()
{
	system("cls");
	customer_bucket->saveinfilecustomerhelp();
}
