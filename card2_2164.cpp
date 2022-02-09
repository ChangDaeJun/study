#include <iostream>
#include <string>
using namespace std;

int queueSize = 0;

typedef struct queue
{
	int number;
	struct queue *next;
}queue;

queue *head = NULL;
queue *tail = NULL;
queue *cur = NULL;
queue *newQueue = NULL;

void push(const int number)
{
	newQueue = new queue();
	newQueue -> number = number;
	newQueue -> next = NULL;

	if(queueSize == 0)
	{
		head = newQueue;
	}
	else
	{
		tail -> next = newQueue;
	}

	tail = newQueue;
	queueSize++;
}

void pop()
{
	if(queueSize == 0)
	{
		return;
	}
	else
	{
		struct queue *secondPoniter = head -> next;
		delete head;
		head = NULL;
		head = secondPoniter;
		queueSize--;
	}
}

int size()
{
	return queueSize;
}

int front()
{
	if(queueSize == 0)
	{
		return 0;
	}
	else
	{
		return head -> number;
	}
}

int back()
{
	if(queueSize == 0)
	{
		return 0;
	}
	else
	{
		return tail ->number;
	}
}

void pushNumber(const int N)
{
	for(int i = 1; i <= N; i++)
	{
		push(i);
	}
}

void moveFrontToBack()
{
	queue *Second = head -> next;
	head -> next = NULL;
	tail -> next = head;
	tail = head;
	head = Second;
}

int main()
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	
	pushNumber(N);

	while(size() != 1)
	{
		 pop();
		 if(size() == 1)
			 continue;
		 moveFrontToBack();
	}
	
	cout << front() << '\n';
	
	return 0;
}
