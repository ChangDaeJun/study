#include <iostream>
#include <algorithm>

#define INF 2000000000

using namespace std;

int cityCnt, lineCnt;
int times[100][100]; // times[startCity - 1][endCity - 1] = start -> end time;

void setTimes();
void inputBusLines();
void solve();
void printAnswer();


int main()
{
	cin >> cityCnt >> lineCnt;
	setTimes();
	inputBusLines();
	solve();
	printAnswer();
	
	return 0;
}

void setTimes()
{
	for(int i = 0; i < cityCnt; i++)
	{
		for(int j = 0; j < cityCnt; j++)
		{
			if(i == j)
			{
				times[i][j] = 0;
			}
			else
			{
				times[i][j] = INF;
			}
		}
	}
}

void inputBusLines()
{	
	for(int i = 0; i < lineCnt; i++)
	{
		int startCity, endCity, time;
		cin >> startCity >> endCity >> time;

		if(times[startCity - 1][endCity - 1] > time)
		{
			times[startCity - 1][endCity - 1] = time;
		}
	}
}

void solve()
{
	for(int i = 0; i < cityCnt; i++)
	{
		int stopover = i;
		for(int j = 0; j < cityCnt; j++)
		{
			for(int k = 0; k < cityCnt; k++)
			{
				int startCity = j;
				int endCity = k;
				
				int first = times[startCity][stopover];
				int second = times[stopover][endCity];
				if(first != INF && second != INF)
				{
					times[startCity][endCity] = min(times[startCity][endCity], first + second);
				}
			}
		}
	}
}

void printAnswer()
{
	for(int i = 0; i < cityCnt; i++)
	{
		for(int j = 0; j < cityCnt; j++)
		{
			if(times[i][j] == INF)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << times[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}

