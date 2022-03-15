#include <iostream>

using namespace std;

int filed[50][50] = {0, };
int filedLength, filedWidth;

void plantCabbages(const int cabbagesCnt)
{
	for(int i = 0; i < cabbagesCnt; i++)
	{
		int x, y;
		cin >> x >> y;

		filed[y][x] = 1;
	}
}

void changeZero(const int x, const int y)
{
	if(x > 0)
	{
		if(filed[x - 1][y] == 1)
		{
			filed[x - 1][y] = 0;
			changeZero(x - 1, y);
		}
	}

	if(x < filedWidth - 1)
	{
		if(filed[x + 1][y] == 1)
		{
			filed[x + 1][y] = 0;
			changeZero(x + 1, y);
		}
	}

	if(y > 0)
	{
		if(filed[x][y - 1] == 1)
		{
			filed[x][y - 1] = 0;
			changeZero(x, y - 1);
		}
	}

	if(y < filedLength - 1)
	{
		if(filed[x][y + 1] == 1)
		{
			filed[x][y + 1] = 0;
			changeZero(x, y + 1);
		}
	}

}

int cabbagesGroup = 0;
void searchCabbagesGroup()
{
	for(int i = 0; i < filedWidth; i++)
	{
		for(int j = 0; j < filedLength; j++)
		{
			if(filed[i][j] == 1)
			{
				cabbagesGroup++;
				filed[i][j] = 0;
				changeZero(i, j);
			}
		}
	}
}

int main()
{
	int number;
	cin >> number;

	for(int i = 0; i < number; i++)
	{
		int cabbagesCnt;
		cin >> filedLength >> filedWidth >> cabbagesCnt;
		
		plantCabbages(cabbagesCnt);
		searchCabbagesGroup();

		cout << cabbagesGroup << '\n';
		
		cabbagesGroup = 0;
	}

	return 0;
}
