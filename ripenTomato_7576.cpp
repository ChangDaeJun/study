#include <iostream>
#include <queue>

using namespace std;

int box[1000][1000] = {0, };
int ripenDay = -1;

queue<pair<int, int> > nextTomato;

void putTomato(const int length, const int width)
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < length; j++)
		{
			cin >> box[i][j];
			
			if(box[i][j] == 1)
			{
				nextTomato.push(make_pair(i, j) );
			}
		}
	}
}

void ripenTomato(const int length, const int width)
{
	while(!nextTomato.empty() )
	{
		int number = nextTomato.size();
		for(int i = 0; i < number; i++)
		{
			int x = nextTomato.front().first;
			int y = nextTomato.front().second;
			nextTomato.pop();

			if(x > 0)
			{
				if(box[x - 1][y] == 0)
				{
					nextTomato.push(make_pair(x - 1, y) );
					box[x - 1][y] = 1;
				}
			}
			
			if(x < width - 1)
			{
				if(box[x + 1][y] == 0)
				{
					nextTomato.push(make_pair(x + 1, y) );
					box[x + 1][y] = 1;
				}
			}

			if(y > 0)
			{
				if(box[x][y - 1] == 0)
				{
					nextTomato.push(make_pair(x, y - 1) );
					box[x][y - 1] = 1;
				}
			}

			if(y < length - 1)
			{
				if(box[x][y + 1] == 0)
				{
					nextTomato.push(make_pair(x, y + 1) );
					box[x][y + 1] = 1;
				}
			}
		}
		ripenDay++;
	}
}

bool unripenedTomato(const int length, const int width)
{
	for(int i = 0; i < width; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if(box[i][j] == 0)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int boxLength, boxWidth;
	cin >> boxLength >> boxWidth;
	
	putTomato(boxLength, boxWidth);
	ripenTomato(boxLength, boxWidth);
	
	if(unripenedTomato(boxLength, boxWidth) == true)
	{
		cout << "-1";
	}
	else
	{
		cout << ripenDay;
	}

	return 0;
}
