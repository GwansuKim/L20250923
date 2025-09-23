#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int Ball;
	bool bIsClear = true;
	bool Pocket[52] = { false, };
	int Count = 0;

	/*for (int i = 0; i < 52; i++)
	{
		cout << Pocket[i] << "\n";
	}*/

	while(bIsClear)
	{
		Ball = rand() % 52;

		if (Pocket[Ball])
		{
			continue;
		}

		Pocket[Ball] = true;
		Count++;

		if (Count == 52)
		{
			bIsClear = false;
		}

		cout << (Ball + 1) << "\n";
	}
}