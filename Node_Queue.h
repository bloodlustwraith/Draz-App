#pragma once

#include "Stack_NODE.h"

class Node_Queue
{
public:
    Stack_NODE* data_part;
    Node_Queue* next;

    Node_Queue();
};
