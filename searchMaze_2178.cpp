#include <iostream>
#include <string>
#include <queue>

using namespace std;

int maze[100][100] = {0, };
// (0,0) 에서(i,j)까지 도달할 수 있는 최소 거리를 [i][j]에 저장

void inputMaze(const int width, const int length)
{
	for(int i = 0; i < width; i++)
	{
		string line;
		cin >> line;
		for(int j = 0; j <length; j++)
		{
			maze[i][j] = line[j] - 48;
		}
	}
}

queue<pair<int, int> > nextSpace;
void searchMaze(const int width, const int length)
{
	while(!nextSpace.empty())
	{
		int cnt = nextSpace.size();
		for(int i = 0; i < cnt; i++)
		{
			int x = nextSpace.front().first;
			int y = nextSpace.front().second;
			nextSpace.pop();

			if(x > 0)
			{
				if(maze[x - 1][y] == 1)
				{
					maze[x - 1][y] = maze[x][y] + 1;
					nextSpace.push(make_pair(x - 1, y) );
				}
			}

			if(x < width - 1)
			{
				if(maze[x + 1][y] == 1)
				{
					maze[x + 1][y] = maze[x][y] + 1;
					nextSpace.push(make_pair(x + 1, y) );
				}
			}

			if(y > 0)
			{
				if(maze[x][y - 1] == 1)
				{
					maze[x][y - 1] = maze[x][y] + 1;
					nextSpace.push(make_pair(x, y - 1) );
				}
			}

			if(y < length - 1)
			{
				if(maze[x][y + 1] == 1)
				{
					maze[x][y + 1] = maze[x][y] + 1;
					nextSpace.push(make_pair(x, y + 1) );
				}
			}
		}
	}
}

int main()
{
	int mazeWidth, mazeLength;
	cin >> mazeWidth >> mazeLength;
	inputMaze(mazeWidth, mazeLength);
	
	nextSpace.push(make_pair(0,0) );
	maze[0][0] = 2;
	searchMaze(mazeWidth, mazeLength);

	cout << maze[mazeWidth - 1][mazeLength - 1] - 1;
	return 0;
}
