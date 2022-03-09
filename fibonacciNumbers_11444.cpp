#include <iostream>

using namespace std;
long long first = 0, second = 0;

void fibonacciNumber(const long long n)
{
	
	if(n == 1)
	{
		first = 1;
		second = 1;
		return;
	}

	fibonacciNumber(n / 2);

	long long first2 = first * first % 1000000007;
	long long second2 = second * second % 1000000007;
	long long firstSeoncd = first * second % 1000000007;

	
	if(n % 2 == 1)
	{
		first = (first2 + second2) % 1000000007;
		second = (second2 + 2 * firstSeoncd) % 1000000007;
	}
	else
	{
		first = (2 * firstSeoncd - first2) % 1000000007;	
		second = (first2 + second2) % 1000000007;
	}
}
void controlValue()
{
	while(first < 0)
	{
		first = first + 1000000007;
	}
}

int main()
{
	long long n;
	cin >> n;

	fibonacciNumber(n);

	controlValue();
	cout << first;
	return 0;
}
