#include <iostream>
#include <vector>
#include <queue>

#define INF 90000000

using namespace std;

int cityCnt, lineCnt;
vector<vector<int> > busLines[501]; // each line = [start] =(end, time, cnt)
int times[501]; 

void input();
void timesDefault();
void solve();
void printAnswer();

int main() 
{  
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	timesDefault();
	solve();
	printAnswer();
	 
	return 0;
}

struct compare
{
	bool operator()(const pair<int, int> x, const pair<int, int> y)
	{
		return x.second > y.second;
	}
};

void input()
{
	cin >> cityCnt >> lineCnt;
    for(int i = 0; i <lineCnt; i++)
    {
		int start, end, time, cnt = 0;
        vector<int> line;
  
		cin >> start >> end >> time;
 
		line.push_back(end);
        line.push_back(time);
		line.push_back(cnt);
 
        busLines[start].push_back(line);
	}
}

void timesDefault()
{
	for(int i = 1; i <= cityCnt; i++)
	{
		times[i] = INF;
	}
}

void algori()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> PQ;
	times[1] = 0;
	PQ.push(make_pair(1, 0));
	
	while(!PQ.empty())
	{
		int curCity = PQ.top().first;
		int curTime = PQ.top().second;
		PQ.pop();

		int cnt = busLines[curCity].size();
		for(int i = 0; i < cnt; i++)
		{
			int nextCity = busLines[curCity][i][0];
			int nextTime = curTime + busLines[curCity][i][1];
			int nextLineCnt = busLines[curCity][i][2];

			if(times[nextCity] > nextTime && nextLineCnt == 0)
			{
				busLines[curCity][i][2]++;
				times[nextCity] = nextTime;
				PQ.push(make_pair(nextCity, nextTime));
			}
		}
	}
}

void searchLoop()
{
	for(int i = 1; i <= cityCnt; i++)
	{
		int startCity = i;
		int startTime = times[i];
		int cnt = busLines[startCity].size();
		for(int j = 0; j < cnt; j++)
		{
			int nextCity = busLines[startCity][j][0];
			int nextTime = startTime + busLines[startCity][j][1];
			int nextLineCnt = busLines[startCity][j][2];
			
			if(times[nextCity] > nextTime && nextLineCnt == 1)
			{
				times[0] = -1;
				return;
			}
		}
	}
}

void solve()
{
	algori();
	searchLoop();
}

void printAnswer()
{
	if(times[0] == -1 || times[1] != 0)
	{
		cout << -1;
		return;
	}

	for(int i = 2; i <= cityCnt; i++)
	{
		int number = times[i];

		if(number == INF)
		{
			cout << -1 <<'\n';
		}
		else
		{
			cout << number << '\n';
		}
	}
}

