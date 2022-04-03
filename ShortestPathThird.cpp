#include <iostream>
#include <queue>
#include <vector>

#define INF 4000000

using namespace std;

int pointCnt, lineCnt, startPoint;
int dist[20001] = {0, };
vector<pair<int, int> > weightLines[20001];

void input()
{
	cin >> pointCnt >> lineCnt >> startPoint;
	for(int i = 1; i <= pointCnt; i++)
	{
		dist[i] = INF;
	}

	for(int i = 0; i < lineCnt; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		weightLines[start].push_back(make_pair(end, weight));
	}
}

struct compare
{
	bool operator()(const pair<int, int> x, const pair<int, int> y)
	{
		return x.second > y.second;
	}
};

void solve()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare > PQ;
	PQ.push(make_pair(startPoint, 0));
	dist[startPoint] = 0;

	while(!PQ.empty())
	{
		int curPoint = PQ.top().first;
		int curDist = PQ.top().second;
		PQ.pop();

		cout << curPoint << ' ' << curDist <<'\n';
		int cnt = weightLines[curPoint].size();
		for(int i = 0; i < cnt; i++)
		{
			int nextPoint = weightLines[curPoint][i].first;
			int nextDist = curDist + weightLines[curPoint][i].second;

			if(dist[nextPoint] > nextDist)
			{
				dist[nextPoint] = nextDist;
				PQ.push(make_pair(nextPoint, nextDist));
			}
		}
	}
}

void printfAnswer()
{
	for(int i = 1; i <= pointCnt; i++)
	{
		if(dist[i] == INF)
		{
			cout << "INF" <<'\n';
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	input();
	solve();
	printfAnswer();

	return 0;
}
