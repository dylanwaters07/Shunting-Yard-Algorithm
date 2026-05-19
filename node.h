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
        left = nullptr;
        right = nullptr;
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

    void setLeft(Node* leftNode){
        left = leftNode;
    }

    void setRight(Node* rightNode){
        right = rightNode;
    }

    Node* getNext(){
        return next;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return right;
    }

    private:
        // if used for stack or queue
        Node* next;

        // If used for tree
        Node* left;
        Node* right;

        char data;
};

#endif // NODE_H