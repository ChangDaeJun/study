#include <iostream>
#include <queue>

using namespace std;

queue<int> printList;
int list[10] = {0, };

void pushQueue(const int number)
{
	int listKey;

	for(int i = 0; i <number; i++)
	{
		cin >> listKey;
		printList.push(listKey);
		list[listKey]++;
	}
}

void printerQueue(const int memory)
{
	int point = memory;
	for(int i = 9; i > 0; i--)
	{	
		while(list[i] != 0)
		{
			if(printList.front() == i)
			{
				printList.pop();
				list[i] --;
				
				if(point == 0)
					return;
				else
					point--;
			}
			else
			{
				int first = printList.front();
				printList.pop();
				printList.push(first);

				if(point == 0)
					point = printList.size() - 1;
				else
					point--;
			}
		}
	}
}

void clearData()
{
	while(printList.empty()== false)
		printList.pop();
	for(int i = 0; i < 10; i++)
	{
		list[i] = 0;
	}
}

int main()
{
	int testCase, number, memory;
	
	cin >> testCase;
	
	for (int i = 0; i < testCase; i++)
	{
		cin >> number >> memory;
		pushQueue(number);
		printerQueue(memory);
		int count = number - printList.size();
		cout << count <<endl;
		clearData();
	}
	return 0;
}
