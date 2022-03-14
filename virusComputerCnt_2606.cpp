#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int> > graph;
vector<int> BFS;
unordered_map<int, int> BFSPoint;

void pushLines(const int pointCnt, const int lineCnt)
{
	for(int i = 0; i <= pointCnt; i++)
	{
		vector<int> x;
		x.push_back(0);
		graph.push_back(x);
	}

	for(int i = 0; i < lineCnt; i++)
	{
		int x, y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

void setBFS(const int pointCnt)
{
	for(int i = 1; i <= pointCnt; i++)
	{
		if(graph[i].back() != 0)
		{	
			BFSPoint[i] = 1;	
		}
	}
}

void sortGraph(const int pointCnt)
{
	for(int i = 1; i <= pointCnt; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
}

void searchBFS(const int startPoint)
{
	BFS.push_back(startPoint);
	BFSPoint.erase(startPoint);
	
	int number = 1;
	while(number != 0)
	{
		int start = BFS.size() - number;
		int end = BFS.size();
		number = 0;
		for(int i = start; i < end; i++)
		{
			int m = graph[BFS[i]].size();
			for(int j = 1; j < m; j++)
			{
				int x = graph[BFS[i]][j];
				if(BFSPoint.find(x) != BFSPoint.end())
				{
					BFS.push_back(x);
					BFSPoint.erase(x);
					number++;
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int pointCnt, lineCnt, startPoint = 1;
	cin >> pointCnt >> lineCnt;

	pushLines(pointCnt, lineCnt);
	setBFS(pointCnt);

	sortGraph(pointCnt);
	
	searchBFS(startPoint);

	cout << BFS.size() - 1;

	return 0;
}

