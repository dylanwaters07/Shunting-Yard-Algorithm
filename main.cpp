#include <iostream>
#include <string>
using namespace std;

/*
BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.

BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.

Both of these data structures are useful for the Shunting Yard algorithm.

You might need a similar stack for building your tree, too.

BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. 

(This is very similar to the Node class for linked list, except 
it has a data value, left pointer, and right pointer. 
If you want to combine the linked list node into the 
binary tree node, meaning it has a left, right, AND next, you may.)

*/

int main()
{
    
    /* NOTE TO SELF:
        "Infix Notation (Normal numbers before operators)";
        "Prefix Notation (Operator before number)";
        "Postfix Notation (Operators all at the end)";
    */
    
    cout << "==================" << endl;
    cout << "Instructions: Enter a mathematical expression using four\nbasic arithmetic expressions." << endl;
    cout << "==================" << endl;
    
    bool running = true;
    while (running){
        cout << "Enter an expression: ";
        string expression;
        cin >> expression;
        
        
    }
    return 0;
}
