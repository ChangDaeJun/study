#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100] = {0, };
int ripenDay = -1;

queue<vector<int> > nextTomato;

void putTomato(const int x, const int y, const int z)
{

	for(int i = 0; i < z; i++)
	{
		for(int j = 0; j < y; j++)
		{
			for(int k = 0; k < x; k++)
			{
				cin >> box[i][j][k];
				
				if(box[i][j][k] == 1)
				{
					vector<int> T;
					T.push_back(i);
					T.push_back(j);
					T.push_back(k);
					nextTomato.push(T);
				}
			}
		}
	}
}

void ripenTomato(const int x, const int y, const int z)
{
	while(!nextTomato.empty() )
	{
		int number = nextTomato.size();
		for(int i = 0; i < number; i++)
		{
			int X = nextTomato.front()[2];
			int Y = nextTomato.front()[1];
			int Z = nextTomato.front()[0];
			nextTomato.pop();

			if(X > 0)
			{
				if(box[Z][Y][X - 1] == 0)
				{
					vector<int> T;
					T.push_back(Z);
					T.push_back(Y);
					T.push_back(X - 1);
					nextTomato.push(T);
					box[Z][Y][X - 1] = 1;
				}
			}
			
			if(X < x - 1)
			{
				if(box[Z][Y][X + 1] == 0)
				{
					vector<int> T;
					T.push_back(Z);
					T.push_back(Y);
					T.push_back(X + 1);
					nextTomato.push(T);
					box[Z][Y][X + 1] = 1;
				}
			}

			if(Y > 0)
			{
				if(box[Z][Y - 1][X] == 0)
				{
					vector<int> T;
					T.push_back(Z);
					T.push_back(Y - 1);
					T.push_back(X);
					nextTomato.push(T);
					box[Z][Y - 1][X] = 1;
				}
			}

			if(Y < y - 1)
			{
				if(box[Z][Y + 1][X] == 0)
				{
					vector<int> T;
					T.push_back(Z);
					T.push_back(Y + 1);
					T.push_back(X);
					nextTomato.push(T);
					box[Z][Y + 1][X] = 1;
				}
			}
			
			if(Z > 0)
			{
				if(box[Z - 1][Y][X] == 0)
				{
					vector<int> T;
					T.push_back(Z - 1);
					T.push_back(Y);
					T.push_back(X);
					nextTomato.push(T);
					box[Z - 1][Y][X] = 1;
				}
			}
			
			if(Z < z - 1)
			{
				if(box[Z + 1][Y][X] == 0)
				{
					vector<int> T;
					T.push_back(Z + 1);
					T.push_back(Y);
					T.push_back(X);
					nextTomato.push(T);
					box[Z + 1][Y][X] = 1;
				}
			}
		}
		ripenDay++;
	}
}

bool unripenedTomato(const int x, const int y, const int z)
{
	for(int i = 0; i < z; i++)
	{
		for(int j = 0; j < y; j++)
		{
			for(int k = 0; k < x; k++)
			{	
				if(box[i][j][k] == 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	int boxX, boxY, boxZ;
	cin >> boxX >> boxY >> boxZ;
	
	putTomato(boxX, boxY, boxZ);
	ripenTomato(boxX, boxY, boxZ);
	
	if(unripenedTomato(boxX, boxY, boxZ) == true)
	{
		cout << "-1";
	}
	else
	{
		cout << ripenDay;
	}

	return 0;
}

