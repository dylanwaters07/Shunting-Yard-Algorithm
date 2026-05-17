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
#include <string>

using namespace std;


void infix(string expression){
    
}

void prefix(string expression){
    
}

void postfix(string expression){
    
}

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
        string expression;
        cout << "Enter infix expression: ";
        getline(cin, expression);
        
        cout << "Infix:\n";
        infix(expression);
        cout << "\n" << endl;
        
        cout << "Prefix:\n";
        prefix(expression);
        cout << "\n" << endl;
        
        cout << "Postfix:\n";
        postfix(expression);
        cout << "\n" << endl;
    }
    return 0;
}