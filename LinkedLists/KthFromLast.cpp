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
void reverse_display(node *head)
{
    if(NULL == head)
        return;
    reverse_display(head->next);
    cout<<head->data<< " ";
}
void KthFromLastRecursive(node *head,int k)
{
    static int i = 0;
    if(NULL == head)
        return;
    KthFromLastRecursive(head->next,k);
    i++;
    if(k == i)
        cout<<endl<<head->data<<endl;
}
void KthFromLastReference(node *head,int k,int &i)
{
    if(head == NULL)
        return;
    KthFromLastReference(head->next,k,i);
    i++;
    if(k == i)
        cout<<endl<<head->data<<endl;
}
void Kth2Pointers(node *head,int k)
{
    node *p1=head , *p2=head;
    int count = 0;
    while(count != k)
    {
        p1 = p1->next;
        count++;
    }
    while(p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    cout<<endl<<p2->data<<endl;
}
void KthFromLastReferenceCaller(node *head,int k)
{
    int i = 0;
    KthFromLastReference(head,k,i);

}
int main()
{
    node *head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    display(head);
    //display(RemoveDup(head));
    KthFromLastReferenceCaller(head,2);
    KthFromLastRecursive(head,4);
    //reverse_display(head);
    Kth2Pointers(head,1);
    getchar();
    return 0;
}