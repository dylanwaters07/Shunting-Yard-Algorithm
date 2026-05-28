/*
Dylan Waters
3/16/26
Shunting Yard Algorithm

Description : 

    This program will also take advantage of a stack, which will be used to create the expression trees. Finally, we'll use a stack and queue for the Shunting Yard algorithm.

    The Shunting Yard algorithm is a method for parsing mathematical expressions specified in infix notation. It was invented by Edsger Dijkstra. The algorithm converts infix
    expressions (where operators are between operands) into postfix notation (where operators follow their operands), which can be easily evaluated using a stack.

    Requirements:
        BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.

        BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.

        Both of these data structures are useful for the Shunting Yard algorithm.

        You might need a similar stack for building your tree, too.

        BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. 

        (This is very similar to the Node class for linked list, except 
            it has a data value, left pointer, and right pointer. 
            If you want to combine the linked list node into the 
            binary tree node, meaning it has a left, right, AND next, you may.)
            
    Overview:
        Take a mathematical expression containing the four basic arithmetic expressions, power (represented as a carat, '^'), integer numbers (you are only required to
        parse single-digit numbers), and parentheses. Translate it into postfix notation.

        Then take in the postfix notation and create an expression tree. Allow the user to output the expression as infix, prefix, or postfix notation using the
        expression tree. (Note: You MUST output from the expression tree for infix, postfix, and prefix, rather than just printing the user input for infix, or the shunting yard output for postfix. No shortcuts!)

    Interface:  Your program should read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression.
    You should then be able to output infix, prefix, or postfix notation, which is a recursive print from the expression tree.

    References:
        https://en.wikipedia.org/wiki/Shunting_yard_algorithm
        https://en.wikipedia.org/wiki/Binary_expression_tree

        Overview of the Shunting Yard Algorithm:
            1. Read the tokens of the infix expression from left to right.
            2. If the token is an operand (number or variable), add it to the output queue.
            3. If the token is an operator, o1, then:
                a. While there is an operator, o2, at the top of the stack, and either:
                    i. o1 is left-associative and its precedence is less than or equal to that of o2, or
                    ii. o1 is right-associative and its precedence is less than that of o2
                then pop o2 off the stack and onto the output queue;
                b. Push o1 onto the stack.
            4. If the token is a left parenthesis, push it onto the stack.
            5. If the token is a right parenthesis:
                a. While the operator at the top of the stack is not a left parenthesis, pop the operator from the stack onto the output queue.
                b. Pop the left parenthesis from the stack, but not onto the output queue. If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
            6. When there are no more tokens to read:
                a. While there are still operator tokens in the stack:
                    i. If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
                    ii. Pop the operator from the stack onto the output queue.

*/

#include <iostream>
#include <cstring>

#include "node.h"
#include "queue.h"
#include "stack.h"

using namespace std;


/********************************************************************************************************** */
/* The following shunting yard implementation is from https://en.wikipedia.org/wiki/Shunting_yard_algorithm */
/********************************************************************************************************** */

// Is token an operator? Note: The only operators in this project are +, -, *, /, and ^.
bool isOperator(char token){
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

// Is token left-associative? Note: The only left-associative operators in this project are +, -, *, and /.
bool isLeftAssociative(char token){
    return token == '+' || token == '-' || token == '*' || token == '/';
}

// Is token right-associative? Note: The only right-associative operator in this project is the power operator, '^'.
bool isRightAssociative(char token){
    return token == '^';
}

// What is the precedence of the operator? Higher number means higher precedence.
int precedence(char token){
    if (token == '+' || token == '-'){
        return 1;
    } else if (token == '*' || token == '/'){
        return 2;
    } else if (token == '^'){
        return 3;
    }
    return 0; // For non-operators
}

// Take in an infix expression and output the postfix expression using the Shunting Yard algorithm. You will need to use a stack and a queue for this.  
void shuntingYard(char* expression, Queue& outputQueue){

    Stack stk; // Stack for operators

    if (expression == nullptr){
        cout << "Error: Null expression." << endl;
        return;
    }

// Add a bunch of debug statements to see what's going on with the shunting yard algorithm. Print the current token, the contents of the stack, and the contents of the output queue at each step.


    int length = strlen(expression);

    // 1. Read the tokens of the infix expression from left to right.
    for (int i = 0; i < length; i++){

        char token = expression[i]; // Assuming tokens are single characters and separated by spaces

        // 2. If the token is an number, add it to the output queue.
        if (isdigit(token)){
            //cout << "Token is an operand: " << token << endl;
            outputQueue.enqueue(token); // Add operand to output queue

        // 3. If the token is an operator, o1, then:
        } else if (isOperator(token)){
            // a. While there is an operator, o2, at the top of the stack, and either:
            //    i. o1 is left-associative and its precedence is less than or equal to that of o2, or
            //    ii. o1 is right-associative and its precedence is less than that of o2
            while (!stk.empty() && isOperator(stk.peek()) &&
                   ((isLeftAssociative(token) && precedence(token) <= precedence(stk.peek())) ||
                    (isRightAssociative(token) && precedence(token) < precedence(stk.peek())))) {
                        // then pop o2 off the stack and onto the output queue;
                        //cout << "Token is an operator: " << token << endl;
                        outputQueue.enqueue(stk.pop()); // Pop operator from stack to output queue
            }
            // b. Push o1 onto the stack.
            //cout << "Pushing operator onto stack: " << token << endl;
            stk.push(token); // Push current operator onto stack
        // 4. If the token is a left parenthesis, push it onto the stack.
        } else if (token == '('){
            //cout << "Token is a left parenthesis: " << token << endl;
            stk.push(token); // Push left parenthesis onto stack
        // 5. If the token is a right parenthesis:
        } else if (token == ')'){
            //cout << "Token is a right parenthesis: " << token << endl;
            // a. While the operator at the top of the stack is not a left parenthesis, pop the operator from the stack onto the output queue.
            while (!stk.empty() && stk.peek() != '('){
                //cout << "Popping operator from stack to output queue: " << stk.peek() << endl;
                outputQueue.enqueue(stk.pop()); // Pop operators from stack to output queue until left parenthesis is found
            }
            // b. Pop the left parenthesis from the stack, but not onto the output queue. If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
            if (!stk.empty() && stk.peek() == '('){
                //cout << "Popping left parenthesis from stack." << endl;
                stk.pop(); // Pop left parenthesis from stack
            } else {
                cout << "Error: Mismatched parentheses." << endl;
                return;
            }
        }
    }

    // 6. When there are no more tokens to read:
    // a. While there are still operator tokens in the stack:
    while (!stk.empty()){
        // i. If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
        if (stk.peek() == '(' || stk.peek() == ')'){
            cout << "Error: Mismatched parentheses." << endl;
            return;
        }
        // ii. Pop the operator from the stack onto the output queue.
        //cout << "Popping remaining operator from stack to output queue: " << stk.peek() << endl;
        outputQueue.enqueue(stk.pop()); // Pop remaining operators from stack to output queue 
    }
}

Node* buildExpressionTree(Queue& outputQueue) {
    Stack treeStack; // Stack for building expression tree

    while (!outputQueue.empty()) {

        char token = outputQueue.frontData(); // Get front token from output queue

        //cout << "Processing token: " << token << endl;

        outputQueue.dequeue(); // Remove token from output queue

        if (isdigit(token)){

            //cout << "Pushing operand onto tree stack: " << token << endl;
            // If token is an operand, create a tree node and push it onto the stack
            Node* newNode = new Node(token);
            treeStack.push(newNode); // Push pointer to tree node as char

        } else { //} if (isOperator(token)){

            // If token is an operator, pop two nodes from the stack, create a new tree node with the operator, and push it back onto the stack
            Node* rightNode = treeStack.topNode(); // Pop right operand
            //cout << "Popping right operand from tree stack: " << rightNode->getData() << endl;
            treeStack.pop(); // Remove right operand from stack
            Node* leftNode = treeStack.topNode(); // Pop left operand
            //cout << "Popping left operand from tree stack: " << leftNode->getData() << endl;
            treeStack.pop(); // Remove left operand from stack

            //cout << "Creating new tree node with operator: " << token << endl;
            Node* newNode = new Node(token); // Create new tree node with operator
            newNode->setLeft(leftNode); // Set left child
            newNode->setRight(rightNode); // Set right child
            treeStack.push(newNode); // Push pointer to new tree node as char
        }
    }

    // The remaining node on the stack is the root of the expression tree
    return treeStack.topNode(); // Return pointer to root of expression tree
}

// Function to print the expression tree in infix notation
void infix(Node* node){
    if (node != nullptr && node->getLeft() && node->getRight()){
        infix(node->getLeft()); // Recursively print left subtree
        cout << node->getData() << " "; // Print root data
        infix(node->getRight()); // Recursively print right subtree
    } else {
        cout << node->getData() << " "; // Print leaf node data
    }
}

// Function to print the expression tree in prefix notation
void prefix(Node* node){
    if (node != nullptr){
        cout << node->getData() << " "; // Print root data
        prefix(node->getLeft()); // Recursively print left subtree
        prefix(node->getRight()); // Recursively print right subtree
    }
}

// Function to print the expression tree in postfix notation
void postfix(Node* node){
    if (node != nullptr){
        postfix(node->getLeft()); // Recursively print left subtree
        postfix(node->getRight()); // Recursively print right subtree
        cout << node->getData() << " "; // Print root data
    }
}

// Main function to run the program.
int main(){
    
    /* NOTE TO SELF:
        "Infix Notation (Normal numbers before operators)";
        "Prefix Notation (Operator before number)";
        "Postfix Notation (Operators all at the end)";
    */
    
    cout << "==================" << endl;
    cout << "Instructions: Enter an infix expression for the Shunting Yard Algorithm." << endl;
    cout << "==================" << endl;
    
    bool running = true;
    while (running){
        char expression[100];
        cout << "Enter infix expression: ";
        cin.getline(expression, 100);

        Queue outputQueue; // Queue for output of Shunting Yard algorithm

        //cout << "Converting infix to postfix using Shunting Yard algorithm..." << endl;
        shuntingYard(expression, outputQueue); // Convert infix to postfix using Shunting Yard algorithm

        //cout << "Printing output queue (postfix expression)..." << endl;
        //outputQueue.printQueue(); // Print the contents of the output queue (postfix expression)

        //cout << "Building expression tree from postfix notation..." << endl;
        Node* root = buildExpressionTree(outputQueue); // Build expression tree from postfix notation
        
        if (root == nullptr){
            cout << "Error: Failed to build expression tree." << endl;
            continue;
        }

        cout << "Infix:" << endl;
        infix(root);
        cout << endl << endl;
        
        cout << "Prefix:\n";
        prefix(root);
        cout << "\n" << endl;
        
        cout << "Postfix:\n";
        postfix(root);
        cout << "\n" << endl;
    }
    return 0;
}