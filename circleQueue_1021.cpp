#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

void makeQueue(const int size)
{
	for(int i = 1; i <= size; i++)
	{
		q.push(i);
	}
}

int caseN[50] = {0, };
void saveCaseN(const int number)
{
	for(int i = 0; i < number; i++)
	{
		cin >> caseN[i];
	}
}

void spin()
{
	int frontNumber = q.front();
	
	q.pop();
	q.push(frontNumber);
}

int spinCnt = 0;
void repeatSpin(const int checkNumber)
{
	int rightCnt = 0, size = q.size();

	while(q.front() != checkNumber && rightCnt <= size)
	{
		spin();
		rightCnt++;
	}

	if(rightCnt > size)
	{
		cout << "err" << endl;
	}

	if(rightCnt <= size / 2)
	{
		spinCnt = rightCnt;
		return;
	}else
	{
		spinCnt = size - rightCnt;
		return;
	}
}

int main()
{
	int size, number;

	cin >> size >> number;
	makeQueue(size);
	saveCaseN(number);

	int cnt = 0;
	bool spinDirection;
	for(int i = 0; i < number; i++)
	{
		repeatSpin(caseN[i]);
		q.pop();
		cnt = cnt + spinCnt;
		spinCnt = 0;
	}

	cout << cnt;
	return 0;
}
