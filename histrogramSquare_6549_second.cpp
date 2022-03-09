#include <iostream>
#include <vector>

using namespace std;
int number, hight = 0;
long long bestSize = 0;
vector<int> histogram;

void inputHistogram()
{
	for(int i = 0; i < number; i++)
	{
		int n;
		cin >> n;
		histogram.push_back(n);
		if(n > hight)
		{
			hight = n;
		}
	}
}
void divideHistogram(const int start, const int end)
{	
	if(start > end)
		return;

	divide.push_back(start);
	divide.push_back(start);
	bool circle = false;
	for(int i = start; i <= end; i++)
	{
		if(histogram[i] < min)
		{
			min = histogram[i];
			divide.clear();
			divide.push_back(start);
			divide.push_back(i);
			divide.push_back(i);
			divide.push_back(i);
			circle = false;
		}
		else if(histogram[i] == min)
		{	
			if(circle == false)
			{
				divide.pop_back();
				divide.pop_back();	
				divide.push_back(i);
				divide.push_back(i);
			}
			else
			{
				divide.pop_back();
				divide.push_back(i);
				divide.push_back(i);
				divide.push_back(i);
				circle = false;
			}
		}
		else
		{
			divide.pop_back();
			divide.push_back(i);
			circle = true;
		}
	}
	
	long long squareSize = (end - start + 1) * min;
	if(bestSize < squareSize)
		bestSize = squareSize;
	
	if(start == end)
		return;

	divideHistogram(divide[0], divide[1] - 1);
	
	for(int i = 2; i < divide.size() - 2; i = i + 2)
	{
		divideHistogram(divide[i] + 1, divide[i + 1] - 1);
	}

	divideHistogram(divide[divide.size()- 2] + 1 , divide[divide.size() - 1]);
}

int main()
{
	cin >> number;
	int start = 0, end = number - 1;
	while(number != 0)
	{
		inputHistogram();

		divideHistogram(start, end);

		cout << bestSize << '\n';
		
		histogram.clear();
		bestSize = 0;
		hight = 0;

		cin >> number;

		start = 0;
		end = number - 1;
	}

	return 0;
}
