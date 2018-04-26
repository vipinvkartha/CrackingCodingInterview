#include <iostream>
#include <unordered_map>

using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node **head,int val)
{
    node *new_node = new node;
    new_node->data = val;
    new_node->next = (*head);
    (*head) = new_node;
}
void display(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
node * RemoveDup(node *head)
{
    node *prev = head;
    node *curr = head;
    node *temp = NULL;
    unordered_map<int,int> dup;
    while(curr != NULL)
    {
        if(dup.find(curr->data) != dup.end())
        {
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            dup[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    node *head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,1);
    insert(&head,2);
    insert(&head,1);
    display(head);
    display(RemoveDup(head));
    getchar();
    return 0;
}