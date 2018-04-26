#include <iostream>
using namespace std;

struct stack
{
	int data;
	stack *next;
};
struct queue
{
	stack *s1, *s2;
};

void push(stack **top, int val)
{
	stack *new_node = new stack;
	new_node->data = val;
	new_node->next = *top;
	*top = new_node;
}
int pop(stack **top)
{
	if (*top == NULL)
	{
		cout << "Stack Overflow";
		getchar();
		exit(0);
	}
	int x = (*top)->data;
	stack *temp = *top;
	(*top) = (*top)->next;
	delete temp;
	temp = NULL;
	return x;
}
void enQueue(queue *q, int val)
{
	push(&q->s1, val);
}
int deQueue(queue *q)
{
	int x;
	if ((q->s1 == NULL) && (q->s2 == NULL))
	{
		cout << "Empty\n";
		getchar();
		exit(0);
	}
	if (q->s2 == NULL)
	{
		while (q->s1 != NULL)
		{
			x = pop(&q->s1);
			push(&q->s2, x);
		}
	}
	x = pop(&q->s2);
	return x;
}
int main()
{
	queue *q = new queue;
	q->s1 = NULL;
	q->s2 = NULL;
	enQueue(q, 5);
	enQueue(q, 4);
	enQueue(q, 3);
	enQueue(q, 2);
	enQueue(q, 1);
	cout << deQueue(q) << " ";
	cout << deQueue(q) << " ";
	cout << deQueue(q) << " ";
	cout << deQueue(q) << " ";
	cout << deQueue(q) << " ";
	getchar();
	return 0;
}