#include <iostream>

using namespace std;

typedef struct queue
{
	int number;
	struct queue *next;
}queue;

queue *head = NULL;
queue *tail = NULL;
queue *now = NULL;
queue *cur = NULL;

int size = 0;

void push(const int number)
{
	now = new queue();
	now -> number = number;
	now -> next = NULL;
	
	if(size == 0)
		head = now;
	else
		tail ->next = now;
	tail = now;
	size++;
}

void printQueue()
{
	cur = head;
	while(cur -> next != NULL)
	{
		cout << cur -> number << ' ';
		cur = cur->next;
	}
	cout << cur -> number;
}

int main()
{
	int N;
	int x;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		push(x);
	}

	printQueue();

	return 0;
}
