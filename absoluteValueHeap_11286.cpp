#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(const int a, const int b)
	{
		int x = a;
		int y = b;

		if(x < 0)
		{
			x = (-1) * x;
		}
		if(y < 0)
		{
			y = (-1) * y;
		}
		
		if(x == y)
		{
			return b < a;
		}
		else
		{
			return y < x;
		}
	}
};

priority_queue<int, vector<int>, compare> absolute; 

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int number;
	cin >> number;
	for(int i = 0; i < number; i++)
	{
		int command;
		cin >> command;

		if(command == 0)
		{
			if(absolute.size() == 0)
			{
				cout << '0' << '\n';
			}
			else
			{
				cout << absolute.top() << '\n';
				absolute.pop();
			}
		}
		else
		{
			absolute.push(command);
		}
	}
	return 0;
}
