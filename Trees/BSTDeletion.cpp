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
void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void preorder(Node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
Node * minValueNode(Node *root)
{
    if(NULL == root)
        return root;
    Node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node * deleteNode(Node *root,int key)
{
    if(NULL == root)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left,key);
    else if(key > root->data)
        root->right = deleteNode(root->right,key);
    else
    {
        if(root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root  = insert(root,50);
    insert(root,40);
    insert(root,30);
    insert(root,20);
    insert(root,10);
    insert(root,60);
    insert(root,70);
    insert(root,80);
    preorder(root);
    cout<<endl;
    root = deleteNode(root,50);
    preorder(root);
    getchar();
    return 0;
}