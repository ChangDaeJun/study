#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int> > cityMap;
vector<int> complexCnt;

void saveMap(const int number)
{
	for(int i = 0; i < number; i++)
	{
		string Sline;
		cin >> Sline;
		
		vector<int> line;
		for(int j = 0; j < number; j++)
		{
			int x = Sline[j] - 48;
			line.push_back(x);
		}
		cityMap.push_back(line);
	}
}

vector<pair<int, int> > oneComplex;
void BFS(const int number)
{	
	int start = oneComplex.size() - number;
	int end = oneComplex.size();
	for(int i = start; i < end; i++)
	{
		int x = oneComplex[i].first;
		int y = oneComplex[i].second;
		if(x > 0)
		{
			if(cityMap[x - 1][y] == 1)
			{
				oneComplex.push_back(make_pair(x-1, y) );
				cityMap[x-1][y] = 0;
			}
		}

		if(y > 0)
		{
			if(cityMap[x][y - 1] == 1)
			{
				oneComplex.push_back(make_pair(x, y-1) );
				cityMap[x][y-1] = 0;
			}
		}	
		
		if(x < cityMap.size() - 1)
		{
			if(cityMap[x + 1][y] == 1)
			{
				oneComplex.push_back(make_pair(x+1, y) );
				cityMap[x+1][y] = 0;
			}
		}
		
		if(y < cityMap.size() - 1)
		{
			if(cityMap[x][y+1] == 1)
			{
				oneComplex.push_back(make_pair(x, y+1) );
				cityMap[x][y+1] = 0;
			}
		}
	}
	int nextNumber = oneComplex.size() - end;
	if(nextNumber == 0)
	{
		return;
	}
	else
	{
		BFS(nextNumber);
	}
}

int main()
{
	int number;
	cin >> number;

	saveMap(number);

	for(int i = 0; i < number; i++)
	{
		for(int j = 0; j < number; j++)
		{
			if(cityMap[i][j] == 1)
			{
				oneComplex.push_back(make_pair(i,j) );
				cityMap[i][j] = 0;
				BFS(1);
				complexCnt.push_back(oneComplex.size() );
				oneComplex.clear();
			}
		}
	}
	
	sort(complexCnt.begin(), complexCnt.end());
	int cnt = complexCnt.size();
	
	cout << cnt <<'\n';
	for(int i = 0; i < cnt; i++)
	{
		cout << complexCnt[i] <<'\n';
	}

	return 0;
}
