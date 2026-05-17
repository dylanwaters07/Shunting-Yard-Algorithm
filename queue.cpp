/*
Dylan Waters
4/13/26

    Queue class for managing a queue of nodes. This will be used for the Shunting Yard algorithm. It has an enqueue
    function for adding to the back of the queue, and a dequeue function for removing from the front of the queue.
    You can implement this using a linked list, with a front and back pointer.

*/

#include "queue.h"
#include "node.h"

using namespace std;

// enqueue adds a new node with the given character to the back of the queue
void Queue::enqueue(char c) {
    Node* newNode = new Node(c);
    if (back == nullptr) {
        front = back = newNode;
    } else {
        back->setNext(newNode);
        back = newNode;
    }
}

// dequeue removes the node at the front of the queue and deletes it
void Queue::dequeue() {
    if (front != nullptr) {
        Node* temp = front;
        front = front->getNext();
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }
}

// front returns the character at the front of the queue without removing it
char Queue::front() {
    if (front != nullptr) {
        return front->getData();
    }
    return '\0'; // Return null character if queue is empty
}
