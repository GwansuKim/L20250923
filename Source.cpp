#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int BallCount;
	cout << "공의 갯수를 입력해 주세요 : ";
	cin >> BallCount;

	int Ball;
	bool bIsClear = true;
	bool *Pocket = new bool[BallCount];
	int Count = 0;

	for (int i = 0; i < BallCount; i++)
	{
		Pocket[i] = false;
	}

	while(bIsClear)
	{
		Ball = rand() % BallCount;

		if (Pocket[Ball])
		{
			continue;
		}

		Pocket[Ball] = true;
		Count++;

		if (Count == BallCount)
		{
			bIsClear = false;
		}

		cout << (Ball + 1) << "\n";
	}
}