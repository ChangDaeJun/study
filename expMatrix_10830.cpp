#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > matrixFrist;
vector<vector<int> > matrixA;
vector<vector<int> > matrixB;
vector<vector<int> > solvedMatrix;

void inputMatrix()
{
	for(int i = 0; i < n; i++)
	{
		vector<int> line;
		int number;
		for(int j = 0; j < n; j++)
		{
			cin >> number;
			number = number % 1000;
			line.push_back(number);
		}
			matrixFrist.push_back(line);
	}
}

void printSolvedMatrix()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << solvedMatrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

void expMatrix()
{	
	for(int i = 0; i < n; i++)
	{
		vector<int> line;
		for(int j = 0; j < n; j++)
		{
			int number = 0;
			
			for(int l = 0; l < n; l++)
			{
				number = number + matrixA[i][l] * matrixB[l][j];
			}
			number = number % 1000;
			line.push_back(number);
		}
		
		solvedMatrix.push_back(line);
	}

}

void divideMultiple(const long long b)
{
	if(b == 1)
	{
		solvedMatrix = matrixFrist;
		return;
	}

	divideMultiple(b / 2);

	matrixA = solvedMatrix;
	matrixB = solvedMatrix;
	solvedMatrix.clear();
	expMatrix();
	
	if(b % 2 == 1)
	{
		matrixA = solvedMatrix;
		matrixB = matrixFrist;
		solvedMatrix.clear();
		expMatrix();
	}
}

int main()
{
	long long b;
	cin >> n >> b;
	
	inputMatrix();
	
	divideMultiple(b);

	printSolvedMatrix();

	return 0;
}
