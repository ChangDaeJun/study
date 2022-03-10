#include <iostream>

using namespace std;

int minHeap[200001] = {0, };
int arrayFloar = 1;
int numberCnt = 0;
bool err = false;


int searchZeroInFloar(const int start, const int end)
{
	for(int i = start; i < end; i++)
	{
		if(minHeap[i] == 0)
		{
			return i;
		}
	}

	return 0;
}

void sortDownPriority(const int location)
{
	int left = location * 2;
	int right = location * 2 + 1;

	minHeap[location] = 0;

	if(minHeap[left] == 0 && minHeap[right] == 0)
	{
		return;
	}

	if(minHeap[left] == 0)
	{
		minHeap[location] = minHeap[right];
		sortDownPriority(right);
	}
	else if(minHeap[right] == 0)
	{
		minHeap[location] = minHeap[left];
		sortDownPriority(left);
	}
	else if(minHeap[left] <= minHeap[right])
	{
		minHeap[location] = minHeap[left];
		sortDownPriority(left);
	}
	else
	{
		minHeap[location] = minHeap[right];
		sortDownPriority(right);
	}
}

void sortUpPriority(const int location)
{
	int upLocation = location / 2;
	if(upLocation == 0)
	{
		return;
	}

	int number = minHeap[location];
	if(minHeap[upLocation] > number || minHeap[upLocation] == 0)
	{
		minHeap[location] = minHeap[upLocation];
		minHeap[upLocation] = number;

		sortUpPriority(upLocation);
	}
}

void insertArray(const int number)
{
	int start = arrayFloar;
	int end = arrayFloar * 2;
	int location = searchZeroInFloar(start, end);
	if(location == 0)
	{
		err = true;
		return;
	}

	minHeap[location] = number;
	numberCnt++;

	if(arrayFloar * 2 - 1 == numberCnt)
	{
		arrayFloar = arrayFloar * 2;
	}

	sortUpPriority(location);
}

void popArray()
{
	if(numberCnt == 0)
	{
		cout << '0' << '\n';
		return;
	}
	
	cout << minHeap[1] << '\n';
	
	int location = 1;
	sortDownPriority(location);
}

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
			popArray();
		}
		else
		{
			insertArray(command);
		}

		if(err == true)
		{
			cout << "ERR" << endl;
			return 0;
		}
	}

	return 0;
}

