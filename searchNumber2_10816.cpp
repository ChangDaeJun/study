#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int ,int> numbers;

void inputNumber(const int n)
{
	for(int i = 0; i < n; i++)
	{
		int number;
		cin >> number;

		if(numbers.find(number) == numbers.end())
		{
			numbers[number] = 1;
		}
		else
		{
			numbers[number]++;
		}
	}
}

int search(const int m)
{
	if(numbers.find(m) == numbers.end())
	{
		return 0;
	}
	else
	{
		return numbers[m];
	}
}

int main()
{
	int n;
	cin >> n;
	inputNumber(n);

	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		int numberCnt = search(number);
		cout << numberCnt << ' ';
	}
	
	return 0;
}
