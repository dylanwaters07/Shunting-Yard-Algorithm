/*
Dylan Waters
4/13/26

*/

#ifndef STACK_H
#define STACK_H

#include "node.h"

/* Stack class for managing a stack of nodes */
class Stack{
    public:
    Stack(){
        top = nullptr;
    }

    void push(Node* node){
        node->setNext(top);
        top = node;
    }

    void push(char c){
        Node* newNode = new Node(c);
        newNode->setNext(top);
        top = newNode;
    }

    Node* topNode(){
        return top;
    }

    char pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->getNext();
            char data = temp->getData();
            //delete temp;
            return data;
        }
        return '\0';
    }

    char peek() {
        if (top != nullptr) {
            return top->getData();
        }
        return '\0'; // Return null character if stack is empty
    }

    bool empty() {
        return top == nullptr;
    }

    private:
        Node* top;
};

#endif // STACK_H