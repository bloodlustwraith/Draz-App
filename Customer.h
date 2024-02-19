#pragma once

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "bst.h"

class Customer
{
public:
	Stack* customer_bucket;
	Queue* Customer_queue;
	Stack complains_obj;
	BST& store_data_bst;
	
	Customer(BST& bst);

	void BuyProduct(std::string& name_custmr);
	void ShowComplains();
	void Complain(std::string& name_custmr);
	void Display();
	void Dequeue();
	void FavouriteProducts();
	void ReturnProduct();
	void BuyingHistory();
	void GoToQueue();
	void ExitShopping();
	
	
};
