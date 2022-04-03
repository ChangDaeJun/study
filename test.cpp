#include <iostream>
#include <queue>

using namespace std;

int main()
{
	struct compare
	{
		bool operator()(const int x, const int y)
		{
			return x > y;
		}
	};

	priority_queue<int, vector<int>, compare> q;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}

	for(int i = 0; i < n; i++)
	{
		int x;
		x = q.top();
		cout << x;
		q.pop();
	}
	return 0;
}
