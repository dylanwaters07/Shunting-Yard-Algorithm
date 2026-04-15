/*
Dylan Waters
4/13/26

*/

#include "node.h"
using namespace std;

Node::Node(){

}

Node::Node(char value){

}

Node::~Node(){ // Destructor

} 

Node* Node::getNext(){
    return next;
}

char Node::getData(){
    return data;
}

void Node::setNext(){

}