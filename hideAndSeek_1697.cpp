#include <iostream>
#include <queue>

using namespace std;

int load[100500] ={0, };
int searchTime = 0;

queue<int> nextSite;
void searchHider(const int leftEnd, const int rightEnd)
{
	while(!nextSite.empty() )
	{
		int cnt = nextSite.size();
		for(int i = 0; i < cnt; i++)
		{
			int x = nextSite.front();
			nextSite.pop();
			
			if(x > leftEnd)
			{
				if(load[x - 1] == 0)
				{
					nextSite.push(x - 1);
					load[x - 1] = 1;
				}
				else
				{
					if(load[x - 1] == - 1)
					{
						return;
					}
				}
			}

			if(x < rightEnd)
			{
				if(load[x + 1] == 0)
				{
					nextSite.push(x + 1);
					load[x + 1] = 1;
				}
				else
				{
					if(load[x + 1] == - 1)
					{
						return;
					}
				}
			}

			if(2 * x < rightEnd)
			{
				if(load[2 * x] == 0)
				{
					nextSite.push(2 * x);
					load[2 * x] = 1;
				}
				else
				{
					if(load[2 * x] == - 1)
					{
						return;
					}
				}
			}
		}
		searchTime++;
	}
}

int main()
{
	int seeker, hider;
	cin >> seeker >> hider;
	
	load[seeker] = 1;
	load[hider] = -1;
	nextSite.push(seeker);
	
	searchHider(0, hider + 500);
	
	cout << searchTime + 1;
	return 0;
}
