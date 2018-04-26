#include <iostream>
using namespace std;
/* structure for a node in circular
  linked list */
struct Node
{
   int data;
   struct Node *next;
};

// To create a new node of circular
// linked list
Node *newNode(int data)
{
  Node *temp = new Node;
  temp->next = temp;
  temp->data = data;
  return temp;
}
void Josephine(int n , int m)
{
    Node *ptr1  ,*ptr2;
    Node *head = newNode(1);
    Node *prev = head;
    for(int i = 2;i <=n;i ++)
    {
        prev->next = newNode(i);
        prev = prev->next;
    }
    prev->next = head;
    ptr1 = head , ptr2 = head;
    while(ptr1->next != ptr1)
    {
        int count = 1;
        while(count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next;
        Node *temp = ptr1;
        ptr1 = ptr1->next;
        delete temp;
    }
    cout<<"Remaining = "<<ptr1->data<<endl;
}
int main()
{
    Josephine(14,4);
    getchar();
    return 0;
}