#include <iostream>

using namespace std;

long long A, B, C, oneRest, totalRest = 1;
long multipleCnt = 0;

void divideMultiple(const int cnt)
{	
	if(cnt == 1)
	{
		totalRest = (totalRest * oneRest) % C;
		return;
	}

	divideMultiple(cnt / 2);
	totalRest = (totalRest * totalRest) % C;

	if(cnt % 2 == 1)
	{
		totalRest = (totalRest * oneRest) % C;
	}
}

int main()
{
	cin >> A >> B >> C;
	
	oneRest = A % C;
	if(oneRest == 1 || oneRest == 0)
	{
		cout << "ss : " << oneRest;
		return 0;
	}

	divideMultiple(B);

	cout << totalRest;
	return 0;
}
