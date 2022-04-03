#include <iostream>
#include <vector>

#define INF 6000000
using namespace std;

int cityCnt, lineCnt;
long long shortTime[501] = {0, };
long long  shortestTime[501] = {0, };
vector<pair<int, int> > busLines[501];

void printAnswer()
{
	if(shortestTime[1] == INF)
	{
		cout << -1;
		return;
	}
	for(int i = 2; i <= cityCnt; i++)
	{
		if(shortestTime[i] == INF)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << shortestTime[i] << '\n';
		}
	}
}

void inputBusLines()
{
	for(int i = 0; i < lineCnt; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;
		busLines[start].push_back(make_pair(end, time));
	}
}

void input()
{
	cin >> cityCnt >> lineCnt;
	inputBusLines();
}

void shortTimeDefalut()
{
	for(int i = 0; i <= cityCnt; i++)
	{
		shortTime[i] = INF;
	}
}

void nextCity(const int startCity, const int N)
{
	int cnt = busLines[startCity].size();
	long long curTime = shortTime[startCity];
	for(int i = 0; i < cnt; i++)
	{
		int city = busLines[startCity][i].first;
		long long time = busLines[startCity][i].second + curTime;
		if(shortTime[city] > time)
		{
			if(N == 1)
			{
				shortTime[city] = time;
			}
			else
			{
				shortTime[city] = time;
				shortestTime[city] = INF;
			}
		}
	}
}

void searchTime(const int number)
{
	for(int i = 0; i < number; i++)
	{
		for(int j = 1; j <= cityCnt; j++)
		{
			if(shortTime[j] != INF)
			{
				nextCity(j, 1);
			}
		}
	}

	for(int i = 1; i <= cityCnt; i++)
	{
		if(shortTime[i] != INF)
		{
			if(shortestTime[i] != INF)
			{
				shortestTime[i] = shortTime[i];
				nextCity(i, 2);
			}
			nextCity(i, 2);
		}
		else
		{
			shortestTime[i] = INF;
		}
	}

}

void solve()
{
	shortTimeDefalut();
	shortTime[1] = 0;
	searchTime(cityCnt);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	solve();
	printAnswer();

	return 0;
}
