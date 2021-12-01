#include <iostream>
#include "stacker.h"   // Including this header file for prefix to postfix conversion using stack
using namespace std;
class Node
{
public:
    char data;
    Node *left, *right;
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void inorder_recursive(Node *);
    void preorder_recursive(Node *);
    void postorder_recursive(Node *);
    void inorder_nonrecursive(Node *);
    void preorder_nonrecursive(Node *);
    void postorder_nonrecursive(Node *);
    Node *expression();
};
Node *Tree::expression()
{
    Node *temp;
    int i, top = -1;
    char exp[20];
    Node *stack[10];
    int flag[10];
    int n;

    cout<<"1. PREFIX EXPRESSION : "<<endl;
    cout<<"2. POSTFIX EXPRESSION : "<<endl;
    cout << "Enter the type of expression : ";
    cin>>n;
    cout << "Enter the expression : ";
    cin >> exp;
    if(n == 1)
    {
        string t = preToPost(exp);  // use of the stacker.h headerfile.
        for(int i = 0; i < t.length() ; i++)
        {
            exp[i] = t[i];
        }
    }
    for (i = 0; exp[i] != '\0'; i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            temp = new Node;
            temp->data = exp[i];
            temp->left = temp->right = NULL;
            stack[++top] = temp;
        }
        else
        {
            root = new Node;
            root->data = exp[i];
            root->left = root->right = NULL; // root creation for operator
            root->right = stack[top--];
            root->left = stack[top--];
            stack[++top] = root;
        }
    }
    root = stack[top--];
    return root;
}
void Tree::inorder_recursive(Node *root)
{
    if (root != NULL)
    {
        inorder_recursive(root->left);
        cout << root->data;
        inorder_recursive(root->right);
    }
}
void Tree::preorder_recursive(Node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}
void Tree::postorder_recursive(Node *root)
{
    if (root != NULL)
    {
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        cout << root->data;
    }
}
void Tree::inorder_nonrecursive(Node *root)
{
    Node *stack[20];
    int top = -1;
    while (root != NULL || top != -1)
    {
        if (root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }
        else
        {
            root = stack[top--];
            cout << root->data;
            root = root->right;
        }
    }
}
void Tree::preorder_nonrecursive(Node *root)
{
    Node *stack[20];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        root = stack[top--];
        if (root != NULL)
        {
            cout << root->data;
            stack[++top] = root->right;
            stack[++top] = root->left;
        }
    }
}
void Tree::postorder_nonrecursive(Node *root)
{
    Node *stack[20];
    int top = -1;
    int flag[10];
    while (top != -1 || root != NULL)
    {
        if (root != NULL)
        {
            stack[++top] = root;
            flag[top] = 0;
            root = root->left;
        }
        else
        {
            root = stack[top];
            if (flag[top] == 1)
            {
                cout << root->data;
                top--;
                root = NULL;
            }
            else
            {
                flag[top] = 1;
                root = root->right;
            }
        }
    }
}
int main()
{
    Tree s;
    s.root = s.expression();
    int ch, ans;
    cout << "\n-----------------------MENU--------------------------";
    cout << "\n1.Recursive function for inorder";
    cout << "\n2.Recursive function for preorder";
    cout << "\n3.Recursive function for postorder";
    cout << "\n4.Nonrecursive function for inorder";
    cout << "\n5.Nonrecursive function for preorder";
    cout << "\n6.Nonrecursive function forpostorder";
    cout << "\n-----------------------------------------------------";

    do
    {
        cout << "\nENTER YOUR CHOICE : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nInorder Exp with Recursive => ";
            s.inorder_recursive(s.root);
            break;
        case 2:
            cout << "\nPreorder Exp with Recursive => ";
            s.preorder_recursive(s.root);
            break;
        case 3:
            cout << "\nPostorder Exp with Recursive => ";
            s.postorder_recursive(s.root);
            break;
        case 4:
            cout << "\nInorder Exp with Non_Recursive => ";
            s.inorder_nonrecursive(s.root);
            break;
        case 5:
            cout << "\nPreorder Exp with Non_Recursive => ";
            s.preorder_nonrecursive(s.root);
            break;
        case 6:
            cout << "\nPostorder Exp with Non_Recursive => ";
            s.postorder_nonrecursive(s.root);
            break;
        }
        char h;
        cout << "\nDo you want to continue (y/n) : ";
        cin>>h;
        if(h == 'y')
        {
            ans = 1;
        }
        else
        {
            ans = -1;
        }
    } while (ans == 1);
    return 0;
}
