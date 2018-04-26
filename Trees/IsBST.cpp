#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left , *right;
};
Node* new_node(int key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isBST(Node *root,int min,int max)
{
    if(NULL == root)
        return 1;
    if(min > root->data || max < root->data)
        return 0;
    return(isBST(root->left,min,root->data-1)&&(isBST(root->right,root->data+1,max)));
}
int main()
{
    Node *root = new_node(6);
    root->left = new_node(4);
    root->left->left = new_node(3);
    root->left->right = new_node(5);
    root->right = new_node(8);
    root->right->left = new_node(1);
    root->right->right = new_node(9);
    if(isBST(root,INT_MIN,INT_MAX))
        cout<<"BST";
    else
        cout<<"Not BST";
    getchar();
    return 0;
}