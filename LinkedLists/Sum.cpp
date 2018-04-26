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
node * Sum(node *num1,node *num2)
{
    node *res = NULL , *temp = NULL;
    node *prev = NULL;
    int carry = 0, sum = 0;
    while((num1 != NULL) || (num2 != NULL))
    {
        sum = carry + (num1?num1->data:0) + (num2?num2->data:0);
        carry = (sum>=10)?1:0;
        sum = sum % 10;
        temp = new node;
        temp->data = sum;
        temp->next = NULL;
        if(NULL == res)
            res = temp;
        else
        {
            prev->next = temp;

        }
        prev = temp;
        if(num1)
            num1 = num1->next;
        if(num2)
            num2 = num2->next;
    }
    if(carry > 0)
    {
        temp = new node;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
    return res;
}
int main()
{
    node *head1 = NULL,*head2 = NULL,*sum1 = NULL;
    insert(&head1,6);
    insert(&head1,4);
    insert(&head1,9);
    insert(&head1,5);
    insert(&head1,7);
    insert(&head2,4);
    insert(&head2,8);
    sum1 = Sum(head1,head2);
    display(head1);
    display(head2);
    display(sum1);
    getchar();
    return 0;
}