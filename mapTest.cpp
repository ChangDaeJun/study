#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, int> mapTest;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		mapTest[name] = 0;
	}

	for(int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		if(mapTest.find(name) == mapTest.end())
			cout << "aaaa" << endl;
		else
			cout << "bbb" << endl;
		cout << mapTest.size() << endl;
	}


	return 0;
}
