#include <iostream>
#include <string>
#include <deque>

using namespace std;

string command;
deque<int> sequence;
int Size = 0;

void inputSequence()
{
	string sequences;
	cin >> sequences;
	
	int number = 0, pointer = 1;
	for(int i = 0; i < Size; i++)
	{
		while(sequences[pointer] != ',' && sequences[pointer] != ']')
		{
			number = number * 10;
			number = number + sequences[pointer] - 48;
			pointer++;
		}
		sequence.push_back(number);
		pointer++;
		number = 0;
	}
}

bool Forward = true;
void changeDirect()
{
	if(Forward == true)
		Forward = false;
	else
		Forward = true;
}

void popFront()
{
	if(Forward == true)
	{
		sequence.pop_front();
	}
	else
	{
		sequence.pop_back();
	}
}

bool err = false;
void implementeCommand()
{
	int commandLength = command.length();
	for(int i = 0; i < commandLength; i++)
	{
		if(command[i] == 'R')
		{
			changeDirect();
		}
		else
		{
			if(sequence.size() == 0)
			{
				err = true;
				return;
			}
			popFront();
			Size --;
		}
	}
}

void clearData()
{
	command.clear();
	sequence.clear();
	Forward = true;
	err = false;
	Size = 0;
}

void printSequence()
{
	cout << '[';
	
	if(Forward == true)
	{
		for(int i = 0; i < Size - 1; i++)
		{
			cout << sequence.front() << ',';
			sequence.pop_front();
		}
	}
	else
	{
		for(int i = 0; i < Size - 1; i++)
		{
			cout << sequence.back() << ',';
			sequence.pop_back();
		}
	}
	if(sequence.empty() == false)
		cout << sequence.front() << ']' << '\n';
	else
		cout << ']' <<'\n';
}

int main()
{
	int testCase;
	cin >> testCase;

	for(int i = 0; i < testCase; i++)
	{
		cin >> command;
		cin >> Size;
		
		inputSequence();
		implementeCommand();

		if(err == false)
			printSequence();
		else
			cout << "error" << '\n';

		clearData();
	}

	return 0;
}
