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
	string CardType[4] = {"��","��" ,"��","��"};
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
	cout << "���� ������ �Է��� �ּ��� : ";
	cin >> Count;

	int Ball;
	bool bIsClear = true;
	int *Pocket = new int[Count];

	//���� �ִ´�
	for (int i = 0; i < Count; i++)
	{
		Pocket[i] = i + 1;
	}

	//�����̳� �ڷᱸ���� ������ ����
	random_shuffle(&Pocket[0], &Pocket[Count]);

	//������ ���� �����
	//���� ���´�
	/*for (int i = 0; i < Count; i++)
	{
		int First = rand() % Count;
		int Second = rand() % Count;
		int Temp = 0;

		Temp = Pocket[First];
		Pocket[First] = Pocket[Second];
		Pocket[Second] = Temp;
	}*/

	//���� ������
	for (int i = 0; i < Count; i++)
	{
		cout << Pocket[i] << "\n";
	}

	char Trash = _getch();
	system("cls");

	int Deck[MAX_SIZE] = { 0, };

	//ī�带 �����.
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Deck[i] = i;
	}

	//ī�带 ���´�.
	random_shuffle(&Deck[0], &Deck[51]);

	//ī�带 �̴´�.
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

	//���� ���
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


	
	//�޸� �ּ� ���
	cout << new int << endl;

	//int�� �޸� �ּҸ� �����ϴ� �ڷ���
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
	//new int[Size]�� print�ϸ� �ּҰ��� ���. �� �� ���� �ּҰ�(������)��
	int* Arr = new int[Size]; 

	*Arr = 1;			// exam) 0x200 
	*(Arr + 1) = 2;		// exam) 0x204
	*(Arr + 2) = 3;		// exam) 0x208
	*(Arr + 3) = 4;		// exam) 0x212
	//int�� 4byte ũ���� �ڷ���
	//char�� 1byte ũ��� �ּҰ��� 200 201 202 203�̾��� ���̴�

	cout << *Arr << *(Arr + 1) << *(Arr + 2) << *(Arr + 3) << endl;

	//�޸𸮸� ������ ���� �迭���� ����ؾ� ��. �׷��� ���� ��� ù ���� �����ϰ� ������ ���� ������ ����� �ҰԵ�
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

	//������ Ʋ���� ������ �������� �޸𸮸� ������ ���� ���� �����Ϸ� �� �Ŷ� ������ ����
	//�� ������ ��۸������Ͷ�� �θ�
	int* DanglingPnt = new int;

	delete DanglingPnt;

	*DanglingPnt = 10;

	return 0;
}