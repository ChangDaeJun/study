#include <iostream>
#include <vector>
using namespace std;

int number;
int histogramLine = 0;
long long bestSize = 0;
vector<int> histogram;

void inputHistogram()
{
	int x;
	for(int i = 0; i < number; i++)
	{
		cin >> x;
		if(x > histogramLine)
		{
			histogramLine = x;
		}
		histogram.push_back(x);
	}
}

void checkBestSize(const long long squareSize)
{
	if(squareSize > bestSize)
		bestSize = squareSize;
}

vector<int> mini;
int checkMin(const int start, const int end)
{

}

void divideHistogram(const int start, const int end, const int line)
{
	if(line > histogramLine)
	{
		return;
	}
	
	int Min = checkMin(start, end);
	long long squareSize = Min * (end - start + 1);
	checkBestSize(squareSize);
	
	int cnt = mini.length();
	int next = start;
	for(int i = 0; i < cnt; i++)
	{
		divideHistogram()
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> number;

	int start = 0, end = number - 1 , line = 0;
	while(number != 0)
	{
		inputHistogram();
		divideHistogram(start, end, line);
		
		cout << bestSize << '\n';
		
		histogram.clear();
		bestSize = 0;
		cin >> number;
		end = number - 1;
	}

	return 0;
}
