#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

unoreded_map<int, vector<pair<int, int> > > weightLine;
vector<int> distance; // is distance between startPoint and i;

void defaultDistance(const int pointCnt)
{
	for(int i = 0; i <= pointCnt; i++)
	{
		distance.push_back(0);
	}
}

void inputWeightLines(const int lineCnt)
{
	for(int i = 0; i < lineCnt; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		if(weightLine.find(start) != weightLine.end() )
		{
			weightLine[start].push_back(make_pair(end, weight) );
		}
		else
		{
			vector<int> newVector;
			newVector.push_back(make_pair(end, weight) );
			weightLine[start] = newVector;
		}
	}
}

int getStartPoint(const int pointCnt)
{
	int startPoint;
	cin >> startPoint;
	
	while(startPoint > pointCnt)
	{
		cout << startPoint << "cannot be the startPoint " <<'\n';
		cout << "please input the number again" <<'\n';
		cin >> startPoint;
	}
}


struct compare
{
	bool operator()(const pair x, const pair y)
	{
		return x.second > y.second;
	}
};

priority queue<pair<int, int>, vector<pair<int, int> >, compare> nextPoints;

void getCurrentPoint()
{
	int number = nextPoints.front().first;
	
	while(weightLine.find(number) == weightLine.end() )
	{
		nextPoints.pop();
		number = nextPoints.front().first;
	}

	return number;
}

void searchShortestPath(const int startPoint)
{
	nextPoints.push(make_pair(startPoint, 0) );
	
	int currentPoint, length = 0;
	while(!nextPoints.empty() )
	{
		currentPoint = getCurrentPoint();
		

	}
}

int main()
{
	int pointCnt, lineCnt, startPoint;
	cin >> pointCnt >> lineCnt;
	startPoint = getStartPoint(pointCnt);
	
	inputWeightLines(lineCnt);
	defaultDistance(pointCnt);
	
	searchShortestPath(startPoint);
	
	printDistance();
	return 0;
}
