#include <iostream>
#include <vector>

using namespace std;
int paperSize;
vector<vector<int> > paper;
void inputNumber()
{
	for(int i = 0; i < paperSize; i++)
	{
		vector<int> line;
		for(int i = 0; i < paperSize; i++)
		{
			int x;
			cin >> x;
			line.push_back(x);
		}
		paper.push_back(line);
	}
}

int checkPaper(const int x, const int y, const int curPaperSize)
{
	bool perfact = false;
	int firstNumber = paper[x][y];
	for(int i = 0; i < curPaperSize; i++)
	{
		for(int j = 0; j < curPaperSize; j++)
		{
			if(firstNumber != paper[x + i][y + j])
			{
				perfact = false;
				return 3;
			}
		}
	}
	return firstNumber;
}

int zero = 0, plusOne = 0, minusOne = 0;
bool countCases(const int check)
{
	if(check == 0)
	{
		zero++;
		return true;
	}
	if(check == -1)
	{	
		minusOne++;
		return true;
	}
	if(check == 1)
	{
		plusOne++;
		return true;
	}

	return false;
}

int calculatePaperSize(const int cnt)
{
	int curPaperSize = paperSize;
	for(int i = 0 ; i < cnt; i++)
	{
		curPaperSize = curPaperSize / 3;
	}
	return curPaperSize;
}

void solvePaper(const int x, const int y, const int cnt)
{
	int curPaperSize = calculatePaperSize(cnt);
	int check = checkPaper(x, y, curPaperSize);
	if(countCases(check) == true)
		return;

	int first = 0;
	int second = curPaperSize / 3;
	int third = 2 * curPaperSize /3;
	solvePaper(x + first, y + first, cnt + 1);
	solvePaper(x + first, y + second, cnt + 1);
	solvePaper(x + first, y + third, cnt + 1);
	solvePaper(x + second, y + first, cnt + 1);
	solvePaper(x + second, y + second, cnt + 1);
	solvePaper(x + second, y + third, cnt + 1);
	solvePaper(x + third, y + first, cnt + 1);
	solvePaper(x + third, y + second, cnt + 1);
	solvePaper(x + third, y + third, cnt + 1);
}

int main()
{
	cin >> paperSize;
	
	inputNumber();
	solvePaper(0, 0, 0);

	cout << minusOne << '\n';
	cout << zero << '\n';
	cout << plusOne << '\n';

	return 0;
}
