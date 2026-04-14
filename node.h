/*
Dylan Waters
3/16/26

*/

#ifndef NODE_H
#define NODE_H

/* Node class for linked list or binary tree */
class Node{
    public:
     //
     Node* next;
     char data;
     
     Node(char value){
         data = value;
         next = nullptr;
     }
};

#endif