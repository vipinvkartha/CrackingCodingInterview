#include <iostream>
#include <unordered_map>
#include <stack>

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
void Paliendrome(node *head)
{
    node *slow = head, *fast = head;
    int temp;
    bool flag = true;
    stack<int> s;
    while(fast && fast->next)
    {
        s.push(slow->data);
        slow=slow->next;
        fast = fast->next->next;
    }
    if(fast)
        slow = slow->next;
    while(slow!= NULL)
    {
        temp = s.top();
        s.pop();
        if(temp != slow->data)
        {
            flag = false;
            break;
        }
        slow = slow->next;
    }
    if(flag)
        cout<<"Paliendrome\n";
    else
        cout<<"Not paliendrome\n";
}
bool isPaliendromeRecursion(node *&left,node *right)
{
    if(NULL == right)
        return true;
    bool isPaliendrome = isPaliendromeRecursion(left,right->next);
    if(!isPaliendrome)
        return false;
    isPaliendrome = (left->data == right->data);
    left = left->next;
    return isPaliendrome;
}
int main()
{
    node *head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    display(head);
    //Paliendrome(head);
    if(isPaliendromeRecursion(head,head))
        cout<<"Paliendrome\n";
    else
        cout<<"Not Paliendrome\n";
    getchar();
    return 0;
}