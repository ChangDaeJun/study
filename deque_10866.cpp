#include <iostream>
#include <string>

using namespace std;

typedef struct deque
{
	struct deque * previous;
	int number;
	struct deque * next;
}deque;

deque *head = NULL;
deque *tail = NULL;
deque *cur = NULL;
deque *newDeque = NULL;
int dequeSize = 0;

void push_front(const int number)
{
	newDeque = new deque();
	newDeque -> number = number;	
	newDeque -> previous = NULL;

	if(dequeSize == 0)
	{
		newDeque -> next = NULL;
		tail = newDeque;
		head = newDeque;
	}
	else
	{
		newDeque -> next = head;
		head -> previous = newDeque;
	}
		head = newDeque;
		dequeSize++;
}

void push_back(const int number)
{
	newDeque = new deque();
	newDeque -> number = number;
	newDeque -> next = NULL;

	if(dequeSize == 0)
	{
		newDeque -> previous = NULL;
		head = newDeque;
		tail = newDeque;
	}
	else
	{
		newDeque -> previous = tail;
		tail -> next = newDeque;
	}
	tail = newDeque;
	dequeSize++;
}

void pop_front()
{
	if(dequeSize == 0)
	{
		cout << -1 << '\n';
	}
	else
	{	
		int firstNumber = head -> number;
		struct deque *secondDeque = NULL;
		
		if(dequeSize != 1)
		{
			secondDeque = head -> next;
		}

		delete head;
		head = NULL;
		head = secondDeque;

		dequeSize--;
		cout << firstNumber << '\n';
	}
}

void pop_back()
{
	if(dequeSize == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		int lastNumber = tail -> number;
		struct deque *backSeoncdDeque = NULL;
		
		if(dequeSize != 1)
		{
			backSeoncdDeque = tail -> previous;
		}
		
		delete tail;
		tail = NULL;
		tail = backSeoncdDeque;

		dequeSize--;
		cout << lastNumber << '\n';
	}
}

void size()
{
	cout << dequeSize << '\n';
}

void empty()
{
	if(dequeSize == 0)
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}

void front()
{
	if(dequeSize == 0)
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
	if(dequeSize == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << tail -> number << '\n';
	}
}

int checkCommand(const string command)
{
	if(command == "push_front")
		return 0;
	if(command == "push_back")
		return 1;
	if(command == "pop_front")
		return 2;
	if(command == "pop_back")
		return 3;
	if(command == "size")
		return 4;
	if(command == "empty")
		return 5;
	if(command == "front")
		return 6;
	if(command == "back")
		return 7;

	return -1;
}

void implementCommand(const int check)
{
	if(check == 0)
	{
		int number;
		cin >> number;
		push_front(number);
		return;
	}
	if(check == 1)
	{
		int number;
		cin >> number;
		push_back(number);
		return;
	}
	if(check == 2)
	{
		pop_front();
		return;
	}
	if(check == 3)
	{
		pop_back();
		return;
	}
	if(check == 4)
	{
		size();
		return;
	}
	if(check == 5)
	{
		empty();
		return;
	}
	if(check == 6)
	{
		front();
		return;
	}
	if(check == 7)
	{
		back();
		return;
	}
	return;
}

int main ()
{
	int caseNumber;
	int check;
	string command;
	
	cin >> caseNumber;

	for(int i = 0; i< caseNumber; i++)
	{
		cin >> command;
		check = checkCommand(command);
		implementCommand(check);
		command.clear();
	}
	return 0;
}
