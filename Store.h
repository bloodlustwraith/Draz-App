#pragma once
#include <iostream>
#include "bst.h"
#include "product.h"
#include "customer.h"


class Store
{
protected:
	bool CheckRegistration(string registerID);

private:
	bool main_flag;
	int main_choice, AP;
	BST store_data_bst;
	Product product;
	Customer customer;
	string userID, password,AU;



public:
	
	Store();
	void LoadingScreen();
	void AdminMode(string AU,int AP);
	void CustomerMode();
	void AdminMenu(int& admin_choice);
	void CustomerMenu(int& customer_choice);
	void Start();

	void Register();
	void Login();
	void ForgotPassword();
	void Loading_Screen();
	
};
