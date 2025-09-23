#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

using namespace std;

void PrintShape(int Card)
{
	switch (Card % 4)
	{
	case 0:
		cout << "♠";
		break;
	case 1:
		cout << "♡";
		break;
	case 2:
		cout << "♣";
		break;
	case 3:
		cout << "◇";
		break;
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
int main()
{
	srand((unsigned int)time(nullptr));

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
	for (int i = 0; i < 3; i++)
	{
		int Score = Dealer[i] / 4 + 1;
		bool bIsAce = false;

		cout << "Dealer" << " : " << Dealer[i] << " // " ;
		PrintShape(Dealer[i]);
		cout << Score << "\n";

		//Ace카드
		if (Score == 1)
		{
			bIsAce = true;
			bDealerHasAce = true;
			Score = 11;
		}
		DealerScore = Process(Score, DealerScore, bIsAce, bDealerHasAce);
		

		Score = Player[i] / 4 + 1;
		bIsAce = false;

		cout << "Player" << " : " << Player[i] << " // ";
		PrintShape(Player[i]);
		cout << Score << "\n";

		//Ace카드
		if (Score == 1)
		{
			bIsAce = true;
			bPlayerHasAce = true;
			Score = 11;
		}
		PlayerScore = Process(Score, PlayerScore, bIsAce, bPlayerHasAce);
	}

	cout << "Dealer : " << DealerScore << "\nPlayer : " << PlayerScore << "\n";

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

}