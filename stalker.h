#include <bits/stdc++.h>
using namespace std;

class Noder
{
public:
    string data;
    Noder *next;
};

class Stack
{
public:
    Noder *top = NULL;
    bool empty();
    void push(string);
    void pop();
};

bool Stack ::empty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Stack ::push(string new_data)
{
    Noder *new_node = new Noder();
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}
void Stack ::pop()
{
    if (empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        Noder *temp = top;
        top = top->next;
        delete (temp);
    }
}

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
 
// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{
 
    Stack s;
    // length of expression
    int length = pre_exp.size();
 
    // reading from right to left
    for (int i = length - 1; i >= 0; i--)
    {
        // check if symbol is operator
        if (isOperator(pre_exp[i]))
        {
            // pop two operands from stack
            string op1 = s.top->data;
            s.pop();
            string op2 = s.top->data;
            s.pop();
 
            // concat the operands and operator
            string temp = op1 + op2 + pre_exp[i];
 
            // Push string temp back to stack
            s.push(temp);
        }
 
        // if symbol is an operand
        else {
 
            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }
 
    // stack contains only the Postfix expression
    return s.top->data;
}
