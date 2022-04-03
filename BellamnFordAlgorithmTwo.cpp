#include <iostream>
#include <vector>

#define INF 60000000

using namespace std;

int	cityCnt, lineCnt;
vector<pair<int, int> > busLines[501];
long long shortTime[501];

void input()
{
	cin >> cityCnt >> lineCnt;
	for(int i = 0; i< lineCnt; i++)
	{
		int start, end, time;
		cin >>start >> end >> time;
		busLines[start].push_back(make_pair(end, time));
	}
}

void settingDefault()
{
	for(int i = 1; i <= cityCnt; i++)
	{
		shortTime[i] = INF;
	}
}
int main()
{
	input();
	settingDefault();

	return 0;
}
