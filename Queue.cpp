#include "Queue.h"
#include <iostream>

Queue::Queue()
{
    Front = nullptr;
    Rear = nullptr;
}

Queue::~Queue()
{
    delete Front;
    delete Rear;
}

bool Queue::Is_empty()
{
    return Front == nullptr;
}

void Queue::Enqueue(std::string name, int id, bool favorite, int price, std::string name_custmr)
{
    Node_Queue* newObject = new Node_Queue;
    newObject->next = nullptr;
    newObject->data_part->PRODUCT_NAME = name;
    newObject->data_part->ID = id;
    newObject->data_part->is_Faviorite = favorite;
    newObject->data_part->PRICE = price;
    newObject->data_part->CUSTOMER_NAME = name_custmr;

    if(Rear == nullptr || Front == nullptr)
    {
        Rear = newObject;
        Front = newObject;
    }
    else
    {
        Rear->next = newObject;
        Rear = newObject;
    }
}

void Queue::Dequeue()
{
    bool flag = true;
    float total_price = 0;

    if(Front == nullptr)
    {
        std::cout << "CUSTOMER QUEUE IS EMPTY\n";
        system("pause");
    }
    else
    {
        while(Front != nullptr && flag == true)
        {
            std::cout << "\n      >>>>>>>>> Customer Name  \"" << Front->data_part->CUSTOMER_NAME << "\"  <<<<<<<<<\n";

            while(Front != nullptr && flag == true)
            {
                if(Front->data_part->PRICE == -5)
                {
                    flag = false;
                }
                else
                {
                    std::cout << "      PRODUCT NAME = " << Front->data_part->PRODUCT_NAME << " : " << "    PRODUCT PRICE = " << Front->data_part->PRICE << std::endl;
                    total_price = total_price + Front->data_part->PRICE;
                }
                Front = Front->next;
            }
        }

        if(flag == false)
        {
            cout << "   --> 0 % DISCOUNT ON SHOPPING OF 1-100 Rs.\n";
            cout << "   --> 5 % DISCOUNT ON SHOPPING OF 101-500 Rs.\n";
            cout << "   --> 7 % DISCOUNT ON SHOPPING OF 501-1,000 Rs.\n";
            cout << "   --> 12 % DISCOUNT ON SHOPPING OF 1001-2,000 Rs.\n";
            cout << "   --> 20 % DISCOUNT ON SHOPPING  Above 2000 Rs.\n\n";

            std::cout << "   Total Price of Products is " << total_price << std::endl;
            if(total_price <= 100)
            {
                total_price = total_price - (total_price / 100) * 0;
                cout << "  No Discount %\n";
            }
            else if(total_price <= 500)
            {
                total_price = total_price - (total_price / 100) * 5;
                cout << "   Discount is 5 %\n";
            }
            else if(total_price <= 1000)
            {
                total_price = total_price - (total_price / 100) * 7;
                cout << "   Discount is 7 %\n";
            }
            else if(total_price <= 2000)
            {
                total_price = total_price - (total_price / 100) * 12;
                cout << "   Discount is 12 %\n";
            }
            else if(total_price > 2000)
            {
                total_price = total_price - (total_price / 100) * 20;
                cout << "   Discount is 20 %\n";
            }
            cout << "   Price After Discount is " << total_price << std::endl;
            system("pause");
            cout << "\n\n================================================================\n";
            cout << "================ THANK YOU FOR SHOPPING ===============\n";
            cout << "================================================================\n";
            system("pause");
        }
    }
}

void Queue::Display()
{
    if(Front == nullptr && Rear == nullptr)
    {
        cout << "Queue is Empty\n";
        return;
    }
    Node_Queue* front = Front;
    Node_Queue* rear = Rear;
    bool flag = false;

    while(front != nullptr)
    {
        cout << "\n      >>>>>>>>> Customer Name : \"" << front->data_part->CUSTOMER_NAME << "\"  <<<<<<<<<\n";
        flag = true;
        while(front != nullptr && flag == true)
        {
            if(front->data_part->PRICE == -5)
            {
                flag = false;
            }
            else
            {
                cout << "      PRODUCT NAME = " << front->data_part->PRODUCT_NAME << " : " << "    PRODUCT PRICE = " << front->data_part->PRICE << std::endl;
            }
            front = front->next;
        }
    }
}
