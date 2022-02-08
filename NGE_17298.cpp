#include <iostream>
#include <vector>

using namespace std;

int N;

void saveN()
{
	cin >> N;
}

vector<int> sequence;

void inputSequence()
{
	for(int i = 0; i < N; i++)
	{
		int S;
		cin >> S;
		sequence.push_back(S);
	}
}

int NGE[1000001] = {0, };
vector<int> stack;
vector<int> sequencei;
int stackSize = 0;

bool checkPop(const int i)
{
	if(stackSize == 0)
		return false;
	if(stack.back() < sequence[i])
		return true;
	else
		return false;
}

void pop()
{
	stack.pop_back();
	stackSize --;
}

void push(const int x)
{
	stack.push_back(x);
	stackSize++;
}

void saveNGE(const int N, const int i)
{
	int pushNumber = sequence[i];
	NGE[N] = pushNumber;
}

void checkDefalt()
{
	int sequenceLength = sequence.size();
	for(int i = 0; i < sequenceLength; i++)
	{
		if(NGE[i] == 0)
			NGE[i] = -1;
	}
}

void calculateNGE()
{
	int sequenceLength = sequence.size();
	for(int i = 0; i < sequenceLength; i++)
	{
		bool check = checkPop(i);

		while(check == true)
		{	
			int lastNumber = sequencei.back();
			pop();
			saveNGE(lastNumber, i);
			sequencei.pop_back();
			check = checkPop(i);
		}

		push(sequence[i]);
		sequencei.push_back(i);
	}
	checkDefalt();
}

void printNGE()
{
	int sequenceLength = sequence.size();
	for(int i = 0; i < sequenceLength; i++)
	{
		cout << NGE[i] << ' ';
	}
}

int main()
{
	saveN();
	inputSequence();
	calculateNGE();
	printNGE();

	return 0;
}
