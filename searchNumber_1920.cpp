#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> numberList;

void inputNumbers(const int n)
{
	for(int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		numberList.push_back(number);
	}
}

void sortNumbers()
{
	sort(numberList.begin(), numberList.end());
}

bool search(const int start, const int end, const int number)
{
	if(number > numberList[end] || number < numberList[start])
	{	
		return false;
	}

	int mid = (end + start) / 2;
	int midNumber = numberList[mid];

	if(number == midNumber)
	{
		return true;

	}
	else
	{
		if(number > midNumber)
		{
			return search(mid + 1, end, number);
		}
		if(number < midNumber)
		{
			return search(start, mid - 1, number);
		}
	}
	return false;
}

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base :: sync_with_stdio(false);

	int n;
	cin >> n;
	inputNumbers(n);
	sortNumbers();
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		
		int start = 0, end = n - 1;
		bool exist = search(start, end, number);
		if(exist == true)
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}

	return 0;
}
