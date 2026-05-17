/*
Dylan Waters
4/13/26

    Node class for linked list or binary tree that accepts characters as data. This
    will be used for the stack, queue, and expression tree. It has a next pointer
    for the stack and queue, and left and right pointers for the expression tree.
    You can combine these into one class if you want, but it might be easier to
    just have a separate class for the expression tree node that has left and right
    pointers, and a separate class for the stack and queue node that has a next pointer.
*/

#ifndef NODE_H
#define NODE_H

/* Node class for linked list or binary tree */
class Node{
    public:

    Node(char value){
        data = value;
        next = nullptr;
    }

    char getData(){
        return data;
    }

    void setData(char value){
        data = value;
    }

    void setNext(Node* nextNode){
        next = nextNode;
    }

    Node* getNext(){
        return next;
    }

    private:
        Node* next;
        char data;
};

#endif // NODE_H