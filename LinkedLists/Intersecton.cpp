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
int getCount(node *head)
{
    node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void intersection(node *head1,node *head2)
{
    int count1 = getCount(head1);
    int count2 = getCount(head2);
    cout<<count1 << " "<<count2;
    int counter = 0;
    node *temp1,*temp2;
    int d = 0;
    if(count1 >= count2)
    {
        d = count1 - count2;
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        d = count2 - count1;
        temp1 = head2;
        temp2 = head2;
    }
    while(counter < d)
    {
        temp1 = temp1->next;
        counter++;
    }
    while(temp1 && temp2)
    {
        if(temp1 == temp2)
        {
            cout<<"Intersection = "<<temp1->data<<endl;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}
void intersection_map(node *head1,node *head2)
{
    unordered_map<node*,int> m;
    while(head1 != NULL)
    {
        m[head1] = 1;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        if(m.find(head2) != m.end())
        {
            cout<<"Intersection = "<<head2->data<<endl;
            return;
        }
        head2 = head2->next;
    }
}
int main()
{
    node *head = NULL,*temp = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,1);
    insert(&head,1);
    insert(&head,5);
    insert(&head,6);
    insert(&head,9);
    insert(&head,10);
    insert(&head,11);
    insert(&head,7);
    insert(&temp,3);
    insert(&temp,4);
    insert(&temp,9);
    temp->next->next->next = head->next->next->next->next->next;
    display(head);
    display(temp);
    //intersection(head,temp);
    intersection_map(head,temp);

    getchar();
    return 0;
}