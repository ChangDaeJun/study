#include <iostream>
using namespace std;

long long A, B, C, number = 0, firstNumber = 0;
bool circle = false;
long long circleSize = 0;

void checkZeroOne()
{
	number = A % C;
	firstNumber = number;
	if(number == 0 || number == 1)
	{
		circle = true;
	}
}

void checkCircle()
{
	for(int i = 0; circle == false && i < B - 1; i++)
	{
		number = (number * A) % C;
		circleSize ++;
		if(number == 0 || number == firstNumber)
		{
			circle = true;
			return;
		}
	}
}

void printRest()
{
	if(circle == true && firstNumber == number)
	{
		int b = (B - 1) % circleSize;
		for(int i = 0; i < b; i++)
		{
			number = (number * A) % C;
		}
		cout << number;
	}
	else
	{
		cout << number;
	}
}

int main()
{
	cin >> A >> B >> C;

	checkZeroOne();
	checkCircle();
	printRest();

	return 0;
}
