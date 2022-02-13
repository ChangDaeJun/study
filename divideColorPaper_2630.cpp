#include <iostream>
#include <vector>

using namespace std;

int paperSize = 0, whiteCnt = 0, blueCnt = 0;
vector<int> paper;

void inputPaper()
{
	int x;
	for(int i = 0; i < paperSize * paperSize; i++)
	{
		cin >> x;
		paper.push_back(x);
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
		whiteCnt ++;
		return;
	}
	if(paperCnt == curPaperSize * curPaperSize)
	{
		blueCnt ++;
		return;
	}

	int secondPoint = startPoint + curPaperSize / 2;
	int thirdPoint = startPoint + paperSize * curPaperSize / 2 ;
	int fourthPoint = thirdPoint + curPaperSize / 2;
	
	dividePaper(startPoint, divideCnt + 1);
	dividePaper(secondPoint, divideCnt + 1);
	dividePaper(thirdPoint, divideCnt + 1);
	dividePaper(fourthPoint, divideCnt + 1);
}

int main()
{
	cin >> paperSize;
	inputPaper();
	dividePaper(0, 0);

	cout << whiteCnt << '\n';
	cout << blueCnt;
	return 0;
}
