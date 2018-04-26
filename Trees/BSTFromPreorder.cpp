#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};
Node* new_node(int key)
{
	Node *newNode = new Node;
	newNode->data = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}
Node* ConstructBST(int pre[], int *prestart, int low, int high, int size)
{
	if ((*prestart >= size) || (low > high))
		return NULL;
	Node *root = new_node(pre[*prestart]);
	*prestart = *prestart + 1;
	if (low == high)
		return root;
	int i;
	for (i = low; i <= high; i++)
	{
		if (pre[i] > root->data)
			break;
	}
	root->left = ConstructBST(pre, prestart, *prestart, i - 1, size);
	root->right = ConstructBST(pre, prestart, i, high, size);
	return root;
}
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int prestart = 0;
	int size = sizeof(pre) / sizeof(pre[0]);
	Node *root = ConstructBST(pre, &prestart, 0, size - 1, size);
	inorder(root);
	getchar();
	return 0;
}