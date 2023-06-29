#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include <iostream>
using namespace std;

int main()
{
	cout << lola::getFilePath() << endl;

	lola::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++) {
		cout << lola::random(10, 20) << endl;
	}
}
