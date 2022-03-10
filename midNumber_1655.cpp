#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator() (const int a, const int b)
	{
		return a > b;
	}
};

priority_queue<int, vector<int> > low;
priority_queue<int, vector<int>, compare> high;
int mid;

void pushNumber(const int interger)
{
	if(low.size() == high.size())
	{
		if(mid <= interger)
		{
			high.push(interger);
		}
		else
		{
			low.push(interger);
			high.push(mid);
			mid = low.top();
			low.pop();
		}
	}
	else
	{
		if(mid <= interger)
		{
			high.push(interger);
			low.push(mid);
			mid = high.top();
			high.pop();
		}
		else
		{
			low.push(interger);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int number;
	cin >> number;

	cin >> mid;
	cout << mid << '\n';

	for(int i = 0; i < number - 1; i++)
	{
		int interger;
		cin >> interger;
		
		pushNumber(interger);

		cout << mid << '\n';
	}
	return 0;
}
