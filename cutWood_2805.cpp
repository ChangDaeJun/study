#include <iostream>
#include <vector>

using namespace std;

long long number, wantWoods, maxWood = 0;
vector<int> woods;


void inputWoods()
{
	for(int i = 0; i < number; i++)
	{
		int wood;
		cin >> wood;
		woods.push_back(wood);
		if(wood > maxWood)
			maxWood = wood;
	}
}

long long averageWoods()
{
	long long sum = 0, rest = 0;
	for(int i = 0; i < number; i++)
	{
		sum = sum + woods[i] / number;
		rest = rest + woods[i] % number;
		if(rest / number >= 1)
		{
			sum = sum + rest / number;
			rest = rest - number * (rest / number);
		}
	}
	return sum;
}
bool checking(const long long length)
{
	long long sum = 0;
	for(int i = 0; i < number; i++)
	{
		long long wood = woods[i] - length;
		if(wood >= 0)
		{
			sum = sum + wood;
		}
	}

	if(sum >= wantWoods)
	{
		return true;
	}
	else
	{
		return false;
	}
}

long long cutWoods(const long long start, const long long end)
{
	long long midNumber = (start + end) / 2;
	bool front = checking(start);
	bool mid = checking(midNumber);
	bool back = checking(end);
	if(back == true)
	{
		return end;
	}
	else if(start == midNumber || midNumber == end)
	{
		return midNumber;
	}
	else if(front && mid == true)
	{
		return cutWoods(midNumber, end);
	}
	else
	{
		return cutWoods(start, midNumber);
	}
}

int main()
{
	cin >> number >> wantWoods;
	
	inputWoods();
	
	long long average = averageWoods();
	long long start = average - (wantWoods / number) - 1;
	long long gainedWoods = cutWoods(start, maxWood);

	cout << gainedWoods;
	return 0;
}
