#include <iostream>
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
Node* search(Node *root,int key)
{
    if(root == NULL || root->data == key)
        return root;
    if(root->data > key)
        return search(root->left,key);
    else
        return search(root->right,key);
}
Node* insert(Node *root,int key)
{
    if(NULL == root)
        return new_node(key);
    if(key < root->data)
        root->left = insert(root->left,key);
    else
        root->right = insert(root->right,key);
    return root;
}
void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    Node *root = NULL;
    root  = insert(root,50);
    insert(root,40);
    insert(root,30);
    insert(root,20);
    insert(root,10);
    inorder(root);
    cout<<endl;
    if(search(root,60) != NULL) 
        cout<<"found";
    else
        cout<<"Not found";
    getchar();
    return 0;
}