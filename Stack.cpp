#include "Stack.h"

Stack::Stack()
{
    Stack_TOP = NULL;
}

Stack::~Stack()
{
    delete Stack_TOP;
}

bool Stack::IsEmpty()
{
    return (Stack_TOP == NULL);
}

void Stack::Push(string name, int id, bool favorite, int price, string name_custmr)
{
    Stack_NODE* newPtr = new Stack_NODE;
    newPtr->PRODUCT_NAME = name;
    newPtr->CUSTOMER_NAME = name_custmr;
    newPtr->ID = id;
    newPtr->is_Faviorite = favorite;
    newPtr->PRICE = price;
    newPtr->next = Stack_TOP;
    Stack_TOP = newPtr;
}

bool Stack::Pop(string& name, int& id, bool& is_fav, int& price, string& name_custmr)
{
    if(IsEmpty())
    {
        return false;
    }
    Stack_NODE* tempPtr = Stack_TOP;
    name = Stack_TOP->PRODUCT_NAME;
    name_custmr = Stack_TOP->CUSTOMER_NAME;
    id = Stack_TOP->ID;
    is_fav = Stack_TOP->is_Faviorite;
    price = Stack_TOP->PRICE;
    Stack_TOP = Stack_TOP->next;
    delete tempPtr;
    return true;
}

void Stack::show_favorit_products(Stack_NODE* temp)
{
    cout << "\nThe Favorite Products are:\n";
    while(temp != NULL)
    {
        if(temp->is_Faviorite == true)
        {
            cout << " -> " << temp->PRODUCT_NAME << endl;
        }
        temp = temp->next;
    }
}

void Stack::Display(Stack_NODE* temp)
{
    if(Stack_TOP == NULL)
    {
        cout << "It is Empty\n";
    }
    if(temp == NULL)
    {
        return;
    }
    else
    {
        if(temp == Stack_TOP)
        { // used for making a title line
            cout << "\nID of Product    :   Price of Product    :     Name of Product " << endl;
        }
        cout << temp->ID << "\t\t\t";
        cout << temp->PRICE << "\t\t\t";
        cout << temp->PRODUCT_NAME << "\n";
        Display(temp->next);
    }
}

void Stack::Search_value(int id, bool& is_present, Stack_NODE*& copy_data, Stack_NODE* temp)
{
    if(temp == NULL)
    {
        return;
    }
    else
    {
        if(temp->ID == id)
        {
            is_present = true;
            copy_data = temp;
        }
        Search_value(id, is_present, copy_data, temp->next);
    }
}

Stack_NODE* Stack::Delete_this_data(int deletion_id)
{
    string name, custmr_name;
    int id = 0, price = 0;
    bool is_Faviorite = false;
    Stack secondary_stack;
    bool once = false;
    while(Pop(name, id, is_Faviorite, price, custmr_name) == true)
    {
        if(id != deletion_id || once)
        {
            secondary_stack.Push(name, id, is_Faviorite, price, custmr_name);
        }
        else
        {
            cout << endl << name << " is Removed From the Bucket!\n";
            system("pause");
            once = true;
        }
    }

    while(secondary_stack.Pop(name, id, is_Faviorite, price, custmr_name) == true)
    {
        this->Push(name, id, is_Faviorite, price, custmr_name);
    }

    secondary_stack.Stack_TOP = nullptr;

    return this->Stack_TOP;
}

void Stack::saveinfilecustomer(Stack_NODE* temp)
{
    if(Stack_TOP == NULL)
    {
        cout << "It is Empty\n";
    }
    if(temp == NULL)
    {
        return;
    }
    else
    {
        if(temp == Stack_TOP)
        {
            Stack_NODE* newPtr = new Stack_NODE;
            customerfile << "Name :" << temp->CUSTOMER_NAME << "\n";
            customerfile << "\nID of Product:\t\t\tPrice of Product:\t\t\tName of Product:   " << endl;
        }
        customerfile << temp->ID << "\t\t\t\t\t";
        customerfile << temp->PRICE << "\t\t\t\t\t";
        customerfile << temp->PRODUCT_NAME << "\t\t\t\t\t";
        saveinfilecustomer(temp->next);
    }
}

void Stack::saveinfilecustomerhelp()
{
    customerfile.open("customerdata.txt", ios::app);
    if(!customerfile)
    {
        cout << "error\nFile not open\n";
    }
    else
    {
        saveinfilecustomer(Stack_TOP);
        customerfile.close();
    }
}
