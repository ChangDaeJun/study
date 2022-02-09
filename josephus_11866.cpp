#include <iostream>
#include <queue>

using namespace std;

queue<int> table;

void seatTable(const int number)
{
	for(int i = 1; i <= number; i++)
	{
		table.push(i);
	}
}

void popAndPush(const int M)
{
	int front;

	for(int i = 0; i < M; i++)
	{
		front = table.front();

		table.pop();
		table.push(front);
	}
}

int main()
{
	int N, M;
	
	cin >> N >> M;
	seatTable(N);

	cout << '<';
	while(table.size() != 1)
	{
		popAndPush(M - 1);
		cout << table.front() << ", ";
		table.pop();
	}
	popAndPush(M - 1);
	cout << table.front() << '>';

	return 0;
}
