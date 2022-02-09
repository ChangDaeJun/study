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
		cout << -1 <<'\n';
		return;
	}
	else
	{
		int firstNumber = head -> number;
		struct queue *secondPoniter = head -> next;
		delete head;
		head = NULL;
		head = secondPoniter;
		queueSize--;
		cout << firstNumber << '\n';
	}
}

void size()
{
	cout << queueSize << '\n';
}

void empty()
{
	if(queueSize == 0)
	{
		cout << 1 <<'\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}

void front()
{
	if(queueSize == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << head -> number << '\n';
	}
}

void back()
{
	if(queueSize == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << tail ->number << '\n';
	}
}

int checkCommand(const string command)
{
	if(command == "push")
		return 0;
	if(command == "pop")
		return 1;
	if(command == "size")
		return 2;
	if(command == "empty")
		return 3;
	if(command == "front")
		return 4;
	if(command == "back")
		return 5;

	return -1;
}

void implementCommand(const int check)
{
	if(check == 0)
	{
		int number;
		cin >> number;
		push(number);
		return;
	}
	if(check == 1)
	{
		pop();
		return;
	}
	if(check == 2)
	{	
		size();
		return;
	}
	if(check == 3)
	{	
		empty();
		return;
	}
	if(check == 4)
	{	
		front();
		return;
	}
	if(check == 5)
	{
		back();
		return;
	}
	return;
}

int main()
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N;
	int check;
	string command;

	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> command;
		check = checkCommand(command);
		implementCommand(check);
		command.clear();
	}
	return 0;
}
