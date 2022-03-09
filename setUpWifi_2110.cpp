#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int houseCnt, wifiCnt;
vector<int> houses;

void inputHouseAddress()
{
	for(int i = 0; i < houseCnt; i++)
	{
		int address;
		cin >> address;
		houses.push_back(address);
	}
}

bool checking(const int wifiLength)
{
	int frontAddress = houses.front();
	int restWifiCnt = wifiCnt - 1;
	for(int i = 1; i < houseCnt; i++)
	{
		int d = frontAddress + wifiLength;
		if(houses[i] >= d)
		{
			frontAddress = houses[i];
			restWifiCnt--;
		}
		if(restWifiCnt <= 0)
		{
			return true;
		}
	}
	if(restWifiCnt <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int setUpWifi(const int minNumber, const int maxNumber )
{
	int midNumber = (maxNumber + minNumber) / 2;
	bool min = checking(minNumber);
	bool mid = checking(midNumber);
	bool max = checking(maxNumber);
	
	if(max == true)
	{
		return maxNumber;
	}
	else if(minNumber == midNumber || midNumber == maxNumber)
	{
		return midNumber;
	}
	else if(min && mid == true)
	{
		return setUpWifi(midNumber, maxNumber);
	}
	else
	{
		return setUpWifi(minNumber, midNumber);
	}
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin >> houseCnt >> wifiCnt;

	inputHouseAddress();
	sort(houses.begin(), houses.end());
	
	int maxHouseLength = houses.back() - houses.front();
	int maxWifiLength = maxHouseLength / (wifiCnt - 1);
	int minWifiLength = setUpWifi(1, maxWifiLength);

	cout << minWifiLength;
	return 0;
}
