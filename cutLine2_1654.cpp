#include <iostream>
#include <vector>

using namespace std;

vector<int> lines;
int n, m;

void inputLines()
{
	for(int i = 0; i < n; i++)
	{
		int line;
		cin >> line;
		lines.push_back(line);
	}
}

long long linesAverage()
{
	long long sum = 0;
	long long rest = 0;

	for(int i = 0; i < n; i++)
	{
		sum = sum + lines[i] / m;
		rest = rest + lines[i] % m;
		if(rest / m >= 1)
		{
			sum = sum + rest / m;
			rest = rest - m * (rest / m);
		}
	}
	
	return sum;
}

bool checking(const long long number)
{
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + lines[i] / number;
	}

	if(sum >= m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

long long cutLine(const long long start, const long long end)
{
	long long midNumber = (start + end) / 2;
	bool front = checking(start);
	bool mid = checking(midNumber);
	bool back = checking(end);
	
	if(back == true)
	{
		return end;
	}
	else if(start == midNumber || end == midNumber)
	{
		return midNumber;
	}
	else if(mid && front == true)
	{
		return cutLine(midNumber, end);
	}
	else
	{
		return cutLine(start, midNumber);
	}
}

int main()
{
	cin >> n >> m;

	inputLines();

	long long average = linesAverage();
	cout << cutLine(1, average);
	return 0;
}
