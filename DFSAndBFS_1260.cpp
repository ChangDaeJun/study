#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int> > graph;
vector<int> DFS;
vector<int> BFS;
unordered_map<int, int> DFSPoint;	
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

void setDFSBFS(const int pointCnt)
{
	for(int i = 1; i <= pointCnt; i++)
	{
		if(graph[i].back() != 0)
		{	
			DFSPoint[i] = 1;
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

void searchDFS(const int startPoint)
{
	DFS.push_back(startPoint);
	DFSPoint.erase(startPoint);

	int cnt = graph[startPoint].size();
	for(int i = 1; i < cnt; i++)
	{
		int number = graph[startPoint][i];
		if(DFSPoint.find(number) != DFSPoint.end())
		{
			searchDFS(number);
		}
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

void printDFS()
{
	int cnt = DFS.size();

	for(int i = 0; i < cnt; i++)
	{
		cout << DFS[i] << ' ';
	}
	cout << '\n';
}

void printBFS()
{
	int cnt = BFS.size();

	for(int i = 0; i < cnt; i++)
	{
		cout << BFS[i] << ' ';
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int pointCnt, lineCnt, startPoint;
	cin >> pointCnt >> lineCnt >> startPoint;

	pushLines(pointCnt, lineCnt);
	setDFSBFS(pointCnt);

	sortGraph(pointCnt);
	
	searchDFS(startPoint);
	searchBFS(startPoint);

	printDFS();
	printBFS();

	return 0;
}
