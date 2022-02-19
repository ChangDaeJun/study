#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > matrixA;
vector<vector<int> > matrixB;
vector<vector<int> > solvedMatrix;

bool A = true;
void inputMatrix(const int n , const int m)
{
	for(int i = 0; i < n; i++)
	{
		vector<int> line;
		int number;
		for(int j = 0; j < m; j++)
		{
			cin >> number;
			line.push_back(number);
		}
		if(A == true)
			matrixA.push_back(line);
		else
			matrixB.push_back(line);
	}
	A = false;
}

void multipleMatrix(const int n, const int m, const int k)
{	
	for(int i = 0; i < n; i++)
	{
		vector<int> line;
		for(int j = 0; j < k; j++)
		{
			int number = 0;
			
			for(int l = 0; l < m; l++)
			{
				number = number + matrixA[i][l] * matrixB[l][j];
			}
			
			line.push_back(number);
		}
		
		solvedMatrix.push_back(line);
	}

}

void printSolvedMatrix(const int n, const int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << solvedMatrix[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m;
	inputMatrix(n, m);

	cin >> m >> k;
	inputMatrix(m, k);

	multipleMatrix(n, m, k);
	printSolvedMatrix(n, k);

	return 0;
}
