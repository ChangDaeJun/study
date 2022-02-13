#include <iostream>
#include <vector>
#include <string>

using namespace std;

int paperSize = 0;
vector<int> paper;

void inputPaper()
{
	string numberLine;
	int x;

	for(int i = 0; i < paperSize; i++)
	{
		cin >> numberLine;

		for(int j = 0; j < paperSize; j++)
		{
			x = numberLine[j] - 48;
			paper.push_back(x);
		}
		numberLine.clear();
	}
}

int checkPaperSize(const int divideCnt)
{
	int curPaperSize = paperSize;

	for(int i = 0; i < divideCnt; i++)
	{
		curPaperSize = curPaperSize / 2;
	}
	return curPaperSize;
}

int countPaper(const int startPoint, const int curPaperSize)
{
	int sum = 0;
	for(int i = 0; i < curPaperSize; i++)
	{
		for(int j = 0; j < curPaperSize; j++)
		{
			sum = sum + paper[startPoint + i * paperSize + j];
		}
	}
	return sum;
}

void dividePaper(const int startPoint, const int divideCnt)
{
	int curPaperSize = checkPaperSize(divideCnt);
	int paperCnt = countPaper(startPoint, curPaperSize);
	if(paperCnt == 0)
	{
		cout << 0;
		return;
	}
	if(paperCnt == curPaperSize * curPaperSize)
	{
		cout << 1;
		return;
	}
	
	int secondPoint = startPoint + curPaperSize / 2;
	int thirdPoint = startPoint + paperSize * curPaperSize / 2 ;
	int fourthPoint = thirdPoint + curPaperSize / 2;
	
	cout << '(';
	dividePaper(startPoint, divideCnt + 1);
	dividePaper(secondPoint, divideCnt + 1);
	dividePaper(thirdPoint, divideCnt + 1);
	dividePaper(fourthPoint, divideCnt + 1);
	cout << ')';
}

int main()
{
	cin >> paperSize;
	inputPaper();
	dividePaper(0, 0);
	return 0;
}
