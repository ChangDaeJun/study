#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#define INF 1000000000

using namespace std;

int pointsCnt, linesCnt, startPoint;
unordered_map<int, vector<pair<int, int> > > weightLines;
int distances[20000];

void solution()
{
	struct compare
	{
		bool operator()(const pair<int, int> x, const pair<int, int> y)
		{
			return x.second > y.second;
		}
	};

	priority_queue<pair<int, int>, vector<pair<int, int> >, compare > Q;
	Q.push(make_pair(startPoint, 0));
	distances[startPoint] = 0;

	while(!Q.empty())
	{
		int currentPoint = Q.top().first;
		int currentDistance = Q.top().second;
		Q.pop();
		
		if(weightLines.find(currentPoint) != weightLines.end())
		{
			int cnt = weightLines[currentPoint].size();
			for(int i = 0; i < cnt; i++)
			{
				int nextPoint = weightLines[currentPoint][i].first;
				int nextDistance = weightLines[currentPoint][i].second + currentDistance;
	
				if(distances[nextPoint] > nextDistance)
				{
					distances[nextPoint] = nextDistance;
					Q.push(make_pair(nextPoint, nextDistance));
				}
			}
		}
	}
}

void input()
{
	cin >> pointsCnt >> linesCnt >> startPoint;
	for(int i = 0; i < linesCnt; i++)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		weightLines[x].push_back(make_pair(y, weight));
	}

	for(int i = 1; i <= pointsCnt; i++)
	{
		distances[i] = INF;
	}
}

void printAnswer()
{
	for(int i = 1; i <= pointsCnt; i++)
	{
		if(distances[i] == INF)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << distances[i] << '\n';
		}
	}
}

int main()
{
	input();
	solution();
	printAnswer();

	return 0;
}
