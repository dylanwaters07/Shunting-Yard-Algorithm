/*
Dylan Waters
4/13/26

Queue class for managing a queue of nodes. This will be used for the Shunting Yard algorithm. It has an enqueue
function for adding to the back of the queue, and a dequeue function for removing from the front of the queue.
You can implement this using a linked list, with a front and back pointer.

*/

#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

/* Node class for linked list or binary tree */
class Queue{
    public:
        Queue(){
            front = nullptr;
            back = nullptr;
        }

        void enqueue(char c);

        void dequeue();

        char frontData();

        bool empty() {
            return front == nullptr;
        }

    private:
        Node* front;
        Node* back;
};

#endif