#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x = 0;
	
	if(x)
	{
		cout << "false" << endl;
	}

	x = 1;

	if(x)
	{
		cout << "true" << endl;
	}

	vector<int> a;
	a.push_back(1);

	if(a)
	{
		cout << "true" << endl;
	}

	return 0;
}
