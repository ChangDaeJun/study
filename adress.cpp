#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int peopleNumber = 0;
int maleNumber = 0;
int femaleNumber = 0;
struct person
{
	string name;
	string phoneNumber;
	bool gender;
	int age;
};

vector<struct person> information;

void inputPerson()
{
	struct person A;

	cout << "이름을 입력해주세요 : " << '\n';
	cin >> A.name;

	cout << " - 을 포함하여 휴대폰 번호를 입력해주세요 : " << '\n';
	cin >> A.phoneNumber;

	char G;
	cout << "성별을 입력해주세요. (남성 : M, 여성 : F) " << '\n';
	cin >> G;
	if(G == 'M')
	{
		A.gender = true;
		maleNumber++;
	}
	else if(G == 'F')
	{
		A.gender = false;
		femaleNumber++;
	}
	else
	{
		cout << "잘못 입력했습니다." << '\n';
		return;
	}

	cout << "나이를 입력해주세요 : " << '\n';
	cin >> A.age;

	information.push_back(A);
	peopleNumber++;
	cout << "저장되었습니다. " << '\n';
}

bool compare(const struct person A, const struct person B)
{
	return A.age > B.age;
}

void printAllInformation()
{
	sort(information.begin(), information.end(), compare);
	cout << "       이름         연락처      성별 나이" <<'\n';
	cout << "-----------------------------------------" <<'\n';
	
	for(int i = 0; i < peopleNumber; i++)
	{
		struct person A = information[i];
		int nameSize = A.name.size();
		string gap(17 - nameSize, ' ');
		
		cout << A.name << gap << A.phoneNumber << "   ";
		if(A.gender ==true)
		{
			cout << 'M' << "    ";
		}
		else
		{
			cout << 'F' << "    ";
		}
		cout << A.age << '\n';
		cout << '\n';
	}

	cout << "총" << peopleNumber << "명(남자 : " << maleNumber << "명, 여자 : " << femaleNumber << "명)" <<'\n';
	cout << "최고령 : " << information.front().age << "세, 최저령 : " << information.back().age << "세" << '\n';
	cout << '\n';
}

void searchPerson()
{
	string name;
	cout << "조회할 이름을 입력하세요 : " << '\n';
	cin >> name;
	cout << '\n';
	
	cout << "       이름         연락처      성별 나이" <<'\n';
	cout << "-----------------------------------------" <<'\n';

	for(int i = 0; i < peopleNumber; i++)
	{
		struct person A = information[i];
		if(A.name == name)
		{
			int nameSize = A.name.size();
			string gap(17 - nameSize, ' ');
		
			cout << A.name << gap << A.phoneNumber << "   ";
			if(A.gender ==true)
			{
				cout << 'M' << "    ";
			}
			else
			{
				cout << 'F' << "    ";
			}
			cout << A.age << '\n';
			cout << '\n';
		}
	}
}

void deletePerson()
{	
	string name;
	cout << "삭제할 이름을 입력하세요 : " << '\n';
	cin >> name;
	cout << '\n';

	for(int i = 0; i < peopleNumber; i++)
	{
		struct person A = information[i];
		if(A.name == name)
		{
			cout << '['<< name << ']';
			cout << " 학생의 정보를 삭제했습니다." << '\n';
			peopleNumber--;
			if(A.gender == true)
			{
				maleNumber--;
			}
			else
			{
				femaleNumber--;
			}
			information.erase(information.begin() + i);
		}
	}
}

void playCommand(const int command)
{
	if(command == 1)
	{
		inputPerson();
	}
	
	if(command == 2)
	{
		printAllInformation();
	}
	
	if(command == 3)
	{
		searchPerson();
	}
	
	if(command == 4)
	{
		deletePerson();
	}
}

int main()
{
	int command; // 0-종료, 1-입력, 2-출력, 3-조회, 4-삭제
	
	cout << "command를 입력해주세요 : " << '\n';
	cin >> command;
	
	while(command != 0)
	{
		if(0 <= command && command < 5)
		{
			playCommand(command);
		}
		else
		{
			cout << "잘못된 조작입니다." << '\n';
		}
		
		cout << "command를 입력해주세요 : " << '\n';
		cin >> command;
	}

	return 0;
}
