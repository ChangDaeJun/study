#include <iostream>
#include <string>
#include <queue>

using namespace std;

int map[1000][1000] = {0, };

void settingMap(const int column, const int row)
{
	for(int i = 0; i < column; i++)
	{
		string line;
		cin >> line;

		for(int j = 0; j < row; j++)
		{
			map[i][j] = line[j] - 48;
		}
	}
}

queue<pair<int, int> > nextPoint;
queue<pair<int, int> > BreakedWall;

void nextStapA(const int x, const int y, const int column, const int row)
{
	if(x > 0)
	{
		if(map[x - 1][y] == 0)
		{
			map[x - 1][y] = map[x][y] + 1;
			nextPoint.push(make_pair(x - 1, y) );
		}

		if(map[x - 1][y] == 1)
		{
			map[x - 1][y] = map[x][y] + 1;
			BreakedWall.push(make_pair(x - 1, y) );
		}	
	}

	if(x < column - 1)
	{
		if(map[x + 1][y] == 0)
		{
			map[x + 1][y] = map[x][y] + 1;
			nextPoint.push(make_pair(x + 1, y) );
		}
		
		if(map[x + 1][y] == 1)
		{
			map[x + 1][y] = map[x][y] + 1;
			BreakedWall.push(make_pair(x + 1, y) );
		}
	}
	
	if(y > 0)
	{
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = map[x][y] + 1;
			nextPoint.push(make_pair(x, y - 1) );
		}

		if(map[x][y - 1] == 1)
		{
			map[x][y - 1] = map[x][y] + 1;
			BreakedWall.push(make_pair(x, y - 1) );
		}
	}

	if(y < row - 1)
	{
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = map[x][y] + 1;
			nextPoint.push(make_pair(x, y + 1) );
		}

		if(map[x][y + 1] == 1)
		{
			map[x][y + 1] = map[x][y] + 1;
			BreakedWall.push(make_pair(x, y + 1) );
		}
	}	
}

void nextStapB(const int x, const int y, const int column, const int row)
{
	if(x > 0)
	{
		if(map[x - 1][y] == 0)
		{
			map[x - 1][y] = map[x][y] + 1;
			BreakedWall.push(make_pair(x - 1, y) );
		}
	}

	if(x < column - 1)
	{
		if(map[x + 1][y] == 0)
		{
			map[x + 1][y] = map[x][y] + 1;
			BreakedWall.push(make_pair(x + 1, y) );
		}
	}
	
	if(y > 0)
	{
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = map[x][y] + 1;
			BreakedWall.push(make_pair(x, y - 1) );
		}
	}

	if(y < row - 1)
	{
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = map[x][y] + 1;
			BreakedWall.push(make_pair(x, y + 1) );
		}
	}
}

void escapeMap(const int column, const int row)
{
	while(map[column][row] == 0 && (!nextPoint.empty() || !BreakedWall.empty() ) )
	{
		int Acnt = nextPoint.size();
		int Bcnt = BreakedWall.size();

			for(int i = 0; i < Acnt; i++)
			{
				int x = nextPoint.front().first;
				int y = nextPoint.front().second;
				cout << "not" << x << ' ' << y <<endl;
				nextPoint.pop();
				nextStapA(x, y, column, row);
			}

			for(int i = 0; i < Bcnt; i++)
			{
				int x = BreakedWall.front().first;
				int y = BreakedWall.front().second;
				cout << "break" << x << ' ' << y <<endl;
				BreakedWall.pop();
				nextStapB(x, y, column, row);
			}
	}
}

int main()
{
	int column, row;
	cin >> column >> row;

	settingMap(column, row);
	
	if(column == 1 && row == 1)
	{
		cout << 0;
		return 0;
	}
	nextPoint.push(make_pair(0, 0) );
	map[0][0] = 2;
	escapeMap(column, row);

	cout << map[column - 1][row - 1] - 1;
	cout << '\n';
	for(int i = 0; i < column; i++)
	{
		for(int j = 0; j < row; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
