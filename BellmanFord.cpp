#include <iostream>
#include <vector>

#define MAXCITY 501
#define INF 800000000

using namespace std;

void input();
void setTimes();
void solve();
void checkOneTime(const bool); // all buslines check one time;
void printAnswer();

int main()
{
	input();
	setTimes();
	solve();
	printAnswer();
}

int cityCnt, linesCnt;
long long times[MAXCITY];
vector<pair<int, int> >busLines[MAXCITY]; // BusLines[startCity] = {endCity, time}
bool cycle = false;

void input()
{
	cin >> cityCnt >> linesCnt;
	for(int i = 0; i < linesCnt; i++)
	{
		int startCity, endCity, time;
		cin >> startCity >> endCity >> time;
		busLines[startCity].push_back(make_pair(endCity, time));
	}
}

void setTimes()
{
	for(int i = 1; i <= cityCnt; i++)
	{
		times[i] = INF;
	}
}

void solve()
{
	bool first = true;
	times[1] = 0;
	for(int i = 0; i < cityCnt - 1; i++)
	{
		checkOneTime(first);
	}

	first = false;
	checkOneTime(first);
}

void checkOneTime(const bool first)
{
	for(int i = 1; i <=cityCnt; i++)
	{
		int startCity = i;
		long long startTime = times[startCity];
		
		if(startTime == INF)
		{
			continue;
		}

		int cnt = busLines[startCity].size();
		for(int j = 0; j < cnt; j++)
		{
			int endCity = busLines[startCity][j].first;
			long long endTime = startTime + busLines[startCity][j].second;
			
			if(times[endCity] > endTime)
			{
				if(first)
				{
					times[endCity] = endTime;
				}
				else
				{
					cycle = true;
					return;
				}
			}
		}
	}
}

void printAnswer()
{
	if(cycle)
	{
		cout << -1;
		return;
	}

	for(int i = 2; i <= cityCnt; i++)
	{
		if(times[i] == INF)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << times[i] << '\n';
		}
	}
}
