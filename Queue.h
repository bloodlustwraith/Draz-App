#pragma once

#include "Node_Queue.h"
#include <string>

class Queue
{
public:
    Node_Queue* Front;
    Node_Queue* Rear;

    Queue();
    ~Queue();

    bool Is_empty();
    void Enqueue(std::string name, int id, bool favorite, int price, std::string name_custmr);
    void Dequeue();
    void Display();
};
