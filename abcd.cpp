#include <iostream>
#include <vector>
#include <queue>

#define INF 800001

using namespace std;

int pointCnt, linesCnt, firstStation, secondStation;
vector<pair<int, int> > weightLine[801];
vector<int> midNumber; // (1 - f), (1 - s), (f - s), (f - l), (s - f), (s - l)

struct compare
{
	bool operator()(const pair<int, int> x, const pair<int, int> y)
	{
		return x.second > y.second;
	}
};

void startAToBAndC(const int A, const int B, const int C)
{
	int dist[801] = {0, };
	for(int i = 1; i <= pointCnt; i++)
	{
		dist[i] = INF;
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> PQ;	
	
	PQ.push(make_pair(A, 0));
	dist[A] = 0;

	while(!PQ.empty())
	{
		int curPoint = PQ.top().first;
		int curDist = PQ.top().second;
		PQ.pop();

		int cnt = weightLine[curPoint].size();
		for(int i = 0; i < cnt; i++)
		{
			int nextPoint = weightLine[curPoint][i].first;
			int nextDist = weightLine[curPoint][i].second + curDist;

			if(dist[nextPoint] > nextDist)
			{
				dist[nextPoint] = nextDist;
				PQ.push(make_pair(nextPoint, nextDist));
			}
		}
	}
	midNumber.push_back(dist[B]);
	midNumber.push_back(dist[C]);
}

void printAnswer(const int x, const int y)
{
	if(x > y)
	{
		if(y >= INF)
		{
			cout << -1;
		}
		else
		{
			cout << y;
		}
	}
	else
	{
		if(x >= INF)
		{
			cout << -1;
		}
		else
		{
			cout << x;
		}
	}
}

void solve()
{
	startAToBAndC(1, firstStation, secondStation);
	startAToBAndC(firstStation, secondStation, pointCnt);
	startAToBAndC(secondStation, firstStation, pointCnt);

	int x = midNumber[0] + midNumber[2] + midNumber[5];
	int y = midNumber[1] + midNumber[3] + midNumber[4];

	printAnswer(x, y);
}

void input()
{
	cin >> pointCnt >> linesCnt;
	
	for(int i = 0; i < linesCnt; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		weightLine[start].push_back(make_pair(end, weight));
		weightLine[end].push_back(make_pair(start, weight));
	}

	cin >> firstStation >> secondStation;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
