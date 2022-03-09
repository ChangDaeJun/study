#include <iostream>

using namespace std;

int search(const int start, const int mid, const int end, const int number)
{
	int squareOfStart = start * start;
	int squareOfMid = mid * mid;
	int squareOfEnd = end * end;
	
	bool first = (squareOfStart < number);
	bool second = (squareOfMid < number);
	bool third = (squareOfEnd < number);

	if(start == mid)
	{
		return mid;
	}

	if(second == false)
	{
		int nextMid = (start + mid) / 2;
		return search(start, nextMid, mid, number);
	}
	else
	{
		if(third == true)
		{
			return end;
		}
		else
		{
			int nextMid = (mid + end) / 2;
			return search(mid, nextMid, end, number);
		}
	}
}

int main()
{
	int arraySize, number;
	cin >> arraySize >> number;

	int reverseOrder = arraySize * arraySize - number + 1;
	int mid = (arraySize + 1) / 2;
	
	int minSquareOfNumber = search(0, mid ,arraySize, reverseOrder);
	int cnt = (minSquareOfNumber+1) * (minSquareOfNumber + 1) - reverseOrder + 1;
	int sol = (arraySize - minSquareOfNumber)*(arraySize - minSquareOfNumber + cnt / 2);
	cout << sol;
	return 0;
}
