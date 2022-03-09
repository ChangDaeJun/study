#include <iostream>
#include <vector>
using namespace std;

vector<int> lines;
vector<int> revisedLines;

void inputLine(const int n)
{
	for(int i = 0; i < n ; i++)
	{
		int line;
		cin >> line;

		lines.push_back(line);
	}
}

int checkLine(const int i, const int lineLength)
{
	int x = lines[i] / lineLength;

	return x;
}

int dmddo = 0;
int cutLine()
{
	int lineLength = revisedLines.back() / 2;
	revisedLines.pop_back();
	revisedLines.push_back(lineLength);

	dmddo = lineLength;

	int cnt = lines.size();
	int sum = 0;
	for(int i = 0; i < cnt; i++)
	{
		sum = sum + checkLine(i, lineLength);
	}
	cout << lineLength << ' ' << sum << endl;
	return sum;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	inputLine(n);
	sort(lines.begin(), lines.end());
	
	revisedLines = lines;
	int sum = 0;
	while(sum < m)
	{
		sum = cutLine();
	}
	cout << dmddo;

	return 0;
}
