#include "store.h"
#include "Drawer.h"
#include<windows.h>
Drawer drawer;

Store::Store() : product(store_data_bst), customer(store_data_bst)
{
	product.AddInitialProducts();
	main_choice = 0;
	main_flag = true;
}

void Store::LoadingScreen()
{
	drawer.CordXY(30, 12);
	system("color F4");
	cout << "Loading:";
	char x = 219;
	for(int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(30);
		if(i == 5)
		{
			Sleep(500);
		}
		if(i == 20)
		{
			Sleep(200);
		}
	}

}

void Store::Start()
{
	LoadingScreen();

	system("color F0");
	

	//this is the main loop
	while(main_flag)
	{
	b:
		system("cls");
		drawer.DesignFirst(32, 77, 5, 7);
		drawer.CordXY(37, 6);
		cout << "  W E L C O M E   T O    D A R A Z" << endl;


		drawer.CordXY(35, 10);
		cout << "Press 1 to open admin portal";

		drawer.CordXY(35, 11);
		drawer.Line(30);

		drawer.CordXY(35, 12);
		cout << "Press 2 to open Customer Portal";

		drawer.CordXY(35, 13);
		drawer.Line(30);

		drawer.CordXY(35, 14);
		cout << "Press 3 to Exit " << endl;

		drawer.CordXY(35, 15);
		drawer.Line(25);

		cout << endl;

		drawer.DesignFirst(35, 46, 16, 18);
		drawer.CordXY(36, 17);
		cout << "Choose: ";


		std::cin >> main_choice;
		if(main_choice == 1)
		{
			AdminMode("admin", 1234);
		}
		else if(main_choice == 2)
		{
		a:
			system("cls");
			int a;
			drawer.DesignFirst(20, 100, 5, 12);
			drawer.CordXY(25, 7);
			cout << "\t   W E L C O M E  T O  C U S T O M E R   P O R T A L\n";

			drawer.CordXY(21, 9);
			drawer.Line(79);

			drawer.DesignFirst(40, 77, 13, 15);
			drawer.CordXY(38, 14);
			cout << "\t\t  Press 1 to Login";

			drawer.DesignFirst(40, 77, 16, 18);
			drawer.CordXY(38, 17);
			cout << "\t\t Press 2 to Register";

			drawer.DesignFirst(38, 79, 19, 21);
			drawer.CordXY(40, 20);
			cout << "      Press 3 to forget password" << endl;

			drawer.DesignFirst(38, 79, 22, 24);
			drawer.CordXY(40, 23);
			cout << "   Press 4 to back to DARAZ Portal";

			drawer.DesignFirst(48, 60, 25, 27);
			drawer.CordXY(49, 26);

			cout << "Choose: ";
			cin >> a;
			if(a == 1)
			{
				Login();
			}
			else if(a == 2)
			{
				Register();
			}
			else if(a == 3)
			{
				ForgotPassword();
				goto a;
			}
			else if(a == 4)
			{
				goto b;
			}
		}
		else if(main_choice == 3)
		{
			main_flag = false;
		}
		else
		{
			system("cls");
			cout << "INVALID CHOICE\n";
			cout << "PLEASE SELECT BETWEEN 1 AND 3\n";
			system("pause");
		}
	}
	system("cls");
	drawer.DesignFirst(32, 86, 5, 7);
	drawer.CordXY(37, 6);
	cout << "T H A N K  Y O U  F O R  U S I N G  D A R A Z" << endl << endl;
	system("pause");
}


bool Store::CheckRegistration(string registerID)
{
	string a;
	string b;
	ifstream data5("Customeracc.txt");

	while(data5 >> a >> b)
	{
		if(a == registerID)
		{
			return true;
		}
	}

	return false;
}

void Store::Register()
{

	string registerID, id, pass, registerpassword;

	while(true)
	{
		system("cls");
		drawer.DesignFirst(34, 81, 4, 6);
		drawer.CordXY(36, 5);
		cout << "Enter Username and Password for Registration";

		drawer.DesignFirst(38, 66, 9, 11);
		drawer.CordXY(39, 10);

		cout << "Enter Username: ";
		cin >> registerID;

		drawer.DesignFirst(38, 66, 9, 13);
		drawer.CordXY(39, 12);
		cout << "Enter Password: ";
		cin >> registerpassword;

		if(CheckRegistration(registerID) == false)
		{
			break;
		}

		drawer.CordXY(37, 15);
		cout << "This username exist!" << endl;

		system("pause");
	}

	ofstream regist("Customeracc.txt", ios::app);
	regist << registerID << ' ' << registerpassword << endl;

	drawer.CordXY(37, 15);
	cout << "Registration is successful!";

	drawer.CordXY(32, 18);
	cout << "Press 1 to got back to Daraz portal: ";

	drawer.CordXY(71, 18);

	string s;
	cin >> s;

	return;
}

void Store::Login()
{
	system("color F0");
	system("cls");

	string  id, pass;
	int count = 0,  a;
b:
	drawer.DesignFirst(34, 72, 4, 6);
	drawer.CordXY(36, 5);
	cout << "Please Enter Username and Password " << endl;

	drawer.DesignFirst(38, 66, 9, 11);
	drawer.CordXY(39, 10);
	cout << "USERNAME: ";
	cin >> userID;

	drawer.DesignFirst(38, 66, 9, 13);
	drawer.CordXY(39, 12);
	cout << "PASSWORD: ";
	cin >> password;

	ifstream data("Customeracc.txt");
	while(data >> id >> pass)
	{
		if(id == userID && pass == password)
		{
			count = 1;
			system("cls");
		}
	}

	if(count == 1)
	{
		CustomerMode();
	}
	else
	{
		system("cls");
		system("color 4");
		cout << "\n Error! you have entered wrong username or password please try again :( \n";
		goto b;
	}
}

void Store::ForgotPassword()
{

	system("cls");

	
	drawer.DesignFirst(33, 72, 3, 5);
	drawer.CordXY(34, 4);
	cout << "Press 1 to search your ID by username " << endl;

	drawer.DesignFirst(33, 72, 6, 8);
	drawer.CordXY(34, 7);
	cout << "Press 2 to go back to Customer Portal " << endl;

	drawer.DesignFirst(45, 60, 9, 11);
	drawer.CordXY(46, 10);
	cout << "Choose: ";
	int option;
	cin >> option;

	switch(option)
	{
	case 1:
	{
	c:
		system("cls");

		int count = 0, d, v;
		string searchid, sID, searchpassword;

		drawer.DesignFirst(29, 90, 9, 11);
		drawer.CordXY(30, 10);
		cout << "Enter the username which you remembered: ";
		cin >> searchid;

		ifstream search("Customeracc.txt");

		while(search >> sID >> searchpassword)
		{
			if(sID == searchid)
			{
				count = 1;
				break;
			}
		}
		search.close();
		if(count == 1)
		{

			drawer.CordXY(35, 14);
			cout << "Your account has been found!";
			drawer.CordXY(38, 17);
			cout << "Your password is: " << searchpassword << endl;
			drawer.CordXY(38, 18);
			drawer.Line(20);
			cout << endl;
			drawer.DesignFirst(34, 80, 19, 21);
			drawer.CordXY(35, 20);
			cout << "Press 1 to back to Customer Portal: ";
			cin >> d;
			if(d == 1)
			{
				return;
			}
		}
		else
		{
			drawer.CordXY(39, 13);
			cout << "Sorry your account is not found! " << endl;
			drawer.CordXY(39, 14);
			drawer.Line(33);
			drawer.DesignFirst(34, 80, 16, 18);
			drawer.CordXY(35, 17);
			cout << "Press 1 to again check your password: ";
			cin >> v;
			if(v == 1)
			{
				goto c;
			}
		}
		break;
	}
	case 2:
	{
		return;
	}
	default:
		cout << "\t\t\t Wrong choice! Please try again";

		break;
	}
}



void Store::AdminMode(string AU, int AP)
{
	system("cls");
  a:

	// Welcome to Admin Mode
	int admin_choice = 0;
	bool admin_flag = true;
	string au;
	int ap;
	drawer.DesignFirst(34, 72, 4, 6);
	drawer.CordXY(36, 5);
	cout << "Please Enter Username and Password " << endl;

	drawer.DesignFirst(38, 66, 9, 11);
	drawer.CordXY(39, 10);
	cout << "USERNAME: ";
	cin >> au;

	drawer.DesignFirst(38, 66, 9, 13);
	drawer.CordXY(39, 12);
	cout << "PASSWORD: ";
	cin >> ap;

	if(au != AU || ap != AP)
	{
		system("cls");
		cout << "\nWrong password or user name\n";
		goto a;
	}
	else
	{
		system("cls");
		// this is the admin loop
		while(admin_flag)
		{
			AdminMenu(admin_choice);

			if(admin_choice == 1)
			{
				product.Add();
			}
			else if(admin_choice == 2)
			{
				product.DisplayAll();
			}
			else if(admin_choice == 3)
			{
				product.Modify();
			}
			else if(admin_choice == 4)
			{
				product.Delete();
			}
			else if(admin_choice == 5)
			{
				customer.Display();
			}
			else if(admin_choice == 6)
			{
				customer.Dequeue();
			}
			else if(admin_choice == 7)
			{
				product.Search();
			}
			else if(admin_choice == 8)
			{
				product.Total();
			}
			else if(admin_choice == 9)
			{
				customer.ShowComplains();
			}
			else if(admin_choice == 10)
			{// MAIN MENU
				store_data_bst.saveinfiletemp();
				admin_flag = false;
			}
			else if(admin_choice == 11)
			{// END PROGRAM

				store_data_bst.saveinfiletemp();
				admin_flag = false;

				main_flag = false;
			}
			else
			{
				std::cout << "INVALID CHOICE\n";
				system("pause");
			}
		} // END OF ADMIN WHILE LOOP
	}

}

void Store::CustomerMode()
{
	system("cls");
	int customer_choice = 0;
	bool customer_loop_flag = true;
	

	// this is the customer loop
	while(customer_loop_flag)
	{
		CustomerMenu(customer_choice);

		if(customer_choice == 1)
		{
			customer.BuyProduct(userID);
		}
	/*	else if(customer_choice == 100)
		{
			customer.FavouriteProducts();
		}*/
		else if(customer_choice == 2)
		{
			customer.Complain(userID);
		}
		else if(customer_choice == 3)
		{
			customer.ReturnProduct();
		}
	/*	else if(customer_choice == 101)
		{
			Show_Discounts_Details();
		}*/
		else if(customer_choice == 4)
		{
			customer.BuyingHistory();
		}
		else if(customer_choice == 5)
		{
			customer.GoToQueue();

			customer_loop_flag = false;
		}
		else if(customer_choice == 6)
		{
			customer.ExitShopping();

			customer_loop_flag = false;
			main_choice = false;
		}
		else
		{
			std::cout << "INVALID CHOICE\n";
			system("pause");
		}
	}
}

void Store::AdminMenu(int& admin_choice)
{
	system("color F0");
	system("cls");
	drawer.DesignFirst(40, 67, 0, 2);
	drawer.CordXY(45, 1);
	cout << "A D M I N  M E N U ";
	drawer.CordXY(44, 3);
	drawer.Line(20);
	drawer.DesignFirst(40, 70, 4, 29);
	drawer.CordXY(42, 5);
	cout << "1.ADD NEW PRODUCT";
	drawer.CordXY(42, 7);
	cout << "2.DISPLAY ALL PRODUCTS" ;
	drawer.CordXY(42, 9);
	cout << "3.MODIFY EXISTING PRODUCT";
	drawer.CordXY(42, 11);
	cout << "4.DELETE A PRODUCT";
	drawer.CordXY(42, 13);
	cout << "5.CUSTOMER LIST";
	drawer.CordXY(42, 15);
	cout << "6.DEQUEUE CUSTOMER";
	drawer.CordXY(42, 17);
	cout << "7.SEARCH PRODUCT";
	drawer.CordXY(42, 19);
	cout << "8.COUNT PRODUCTS IN STORE";
	drawer.CordXY(42, 21);
	cout << "9.SHOW CUSTOMER COMPLAINS";
	drawer.CordXY(42, 23);
	cout << "10.MAIN MENU";
	drawer.CordXY(42, 25);
	cout << "11.QUIT PROGRAM";
	drawer.CordXY(42, 27);
	cout << "Choose: ";
	cin >> admin_choice;
}

void Store::CustomerMenu(int& customer_choice)
{
	system("color F0");
	system("cls");
	drawer.DesignFirst(43, 72, 0, 3);
	drawer.CordXY(46, 1);
	cout << "C U S T O M E R  M E N U ";
	drawer.CordXY(45, 2);
	drawer.Line(26);
	drawer.DesignFirst(40, 77, 4, 19);
	drawer.CordXY(42, 5);
	cout << "1.ADD TO CART";
	drawer.CordXY(42, 7);
	cout << "2.COMPLAINS";
	drawer.CordXY(42, 9);
	cout << "3.RETURN OPTION";
	drawer.CordXY(42, 11);
	cout << "4.BUYING HISTORY";
	drawer.CordXY(42, 13);
	cout << "5.MAIN MENU (GO TO CUSTOMER QUEUE )";
	drawer.CordXY(42, 15);
	cout << "6.GO BACK";
	drawer.CordXY(42, 17);
	cout << "Choose: ";
	cin >> customer_choice;
}