#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

using namespace std;

void Swap(int A, int B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void Swap(int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

void Swap2(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void PrintShape(int Card, int Score, int Var)
{
	string CardType[4] = {"♠","♡" ,"♣","◇"};
	string CardNumber[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	cout << CardType[Card % 4] << CardNumber[Score - 1];
	if(Var == 0)
	{
		cout << "\t";
	}
	else
	{
		cout << "\n";
	}
	 
}

int Process(int Score, int PlayerScore, bool bIsAce, bool bHasAce)
{
	if (Score > 10 && !bIsAce)
	{
		PlayerScore += 10;
	}
	else
	{
		PlayerScore += Score;
	}

	if (PlayerScore > 21 && bHasAce)
	{
		PlayerScore -= 10;
	}

	return PlayerScore;
}

#define MAX_SIZE 52
#define SFAE_DELETE
int main()
{
	srand((unsigned int)time(nullptr));

	int Count;
	cout << "공의 갯수를 입력해 주세요 : ";
	cin >> Count;

	int Ball;
	bool bIsClear = true;
	int *Pocket = new int[Count];

	//공을 넣는다
	for (int i = 0; i < Count; i++)
	{
		Pocket[i] = i + 1;
	}

	//랜덤이나 자료구조를 만들라고 안함
	random_shuffle(&Pocket[0], &Pocket[Count]);

	//임의의 수를 만든다
	//공을 섞는다
	/*for (int i = 0; i < Count; i++)
	{
		int First = rand() % Count;
		int Second = rand() % Count;
		int Temp = 0;

		Temp = Pocket[First];
		Pocket[First] = Pocket[Second];
		Pocket[Second] = Temp;
	}*/

	//공을 꺼낸다
	for (int i = 0; i < Count; i++)
	{
		cout << Pocket[i] << "\n";
	}

	char Trash = _getch();
	system("cls");

	int Deck[MAX_SIZE] = { 0, };

	//카드를 만든다.
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Deck[i] = i;
	}

	//카드를 섞는다.
	random_shuffle(&Deck[0], &Deck[51]);

	//카드를 뽑는다.
	int Dealer[3] = { 0, };
	int Player[3] = { 0, };
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
		{
			Dealer[i / 2] = Deck[i];
		}
		else
		{
			Player[i / 2] = Deck[i];
		}
	}

	//점수 계산
	int DealerScore = 0;
	int PlayerScore = 0;
	bool bDealerHasAce = false;
	bool bPlayerHasAce = false;
	cout << "Dealer" << "\tPlayer\n--------------------------------------\n";
	for (int i = 0; i < 3; i++)
	{
		int Score = Dealer[i] / 4 + 1;
		bool bIsAce = false;

		PrintShape(Dealer[i], Score, 0);

		if (Score == 1)
		{
			bIsAce = true;
			bDealerHasAce = true;
			Score = 11;
		}
		DealerScore = Process(Score, DealerScore, bIsAce, bDealerHasAce);
		

		Score = Player[i] / 4 + 1;
		bIsAce = false;

		PrintShape(Player[i], Score, 1);

		if (Score == 1)
		{
			bIsAce = true;
			bPlayerHasAce = true;
			Score = 11;
		}
		PlayerScore = Process(Score, PlayerScore, bIsAce, bPlayerHasAce);
	}

	cout << "--------------------------------------\n" << DealerScore << "\t" << PlayerScore << "\n\n";

	if (DealerScore > 21)
	{
		cout << "PlayerWin\n";
	}
	else if (PlayerScore > 21)
	{
		cout << "DealerWin\n";
	}
	else if (DealerScore > PlayerScore)
	{
		cout << "DealerWin\n";
	}
	else
	{
		cout << "PlayerWin\n";
	}
	Trash = _getch();
	system("cls");


	
	//메모리 주소 출력
	cout << new int << endl;

	//int형 메모리 주소를 저장하는 자료형
	int* P = new int;
	*P = 100;

	int A = 10;
	int B = 20;

	Swap(A, B);

	cout << A << "\n" << B << "\n";

	Swap(&A, &B);

	cout << A << "\n" << B << "\n";

	Swap2(A, B);

	cout << A << "\n" << B << "\n";

	Trash = _getch();
	system("cls");

	int Size = 10;
	//new int[Size]을 print하면 주소값을 출력. 즉 저 값은 주소값(포인터)임
	int* Arr = new int[Size]; 

	*Arr = 1;			// exam) 0x200 
	*(Arr + 1) = 2;		// exam) 0x204
	*(Arr + 2) = 3;		// exam) 0x208
	*(Arr + 3) = 4;		// exam) 0x212
	//int는 4byte 크기의 자료형
	//char은 1byte 크기라 주소값이 200 201 202 203이었을 것이다

	cout << *Arr << *(Arr + 1) << *(Arr + 2) << *(Arr + 3) << endl;

	//메모리를 삭제할 때도 배열임을 명시해야 함. 그러지 않을 경우 첫 값만 삭제하고 나머지 값을 삭제할 방법을 잃게됨
	delete[] Arr;
	Arr = nullptr;

	Trash = _getch();
	system("cls");

	int Number[10] = { 0,1,2,3,4,5,6,7,8,9 };

	int* Prt = Number;

	cout << Prt << "\n" << (Prt + 1) << endl;
	cout << Number << "\n" << (Number + 1) << endl;
	cout << *(Prt + 1) << "\n" << Prt[1] << endl;

	Trash = _getch();
	system("cls");

	//문법상 틀리지 않으나 논리적으론 메모리를 삭제한 곳에 값을 저장하려 한 거라 오류가 생김
	//이 오류를 댕글링포인터라고 부름
	int* DanglingPnt = new int;

	delete DanglingPnt;

	*DanglingPnt = 10;

	return 0;
}