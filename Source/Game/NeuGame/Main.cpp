#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"

#include <iostream>
using namespace std;

int main()
{
	/*cout << lola::getFilePath() << endl;

	lola::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++) {
		cout << lola::random(10, 20) << endl;
	}*/

	lola::g_memoryTracker.DisplayInfo();
	int* p = new int;
	lola::g_memoryTracker.DisplayInfo();
	delete p;
	lola::g_memoryTracker.DisplayInfo();

	lola::Time timer;
	for (int i = 0; i < 100000; i++) {}
	cout << timer.GetElapsedSeconds() << endl;

	/* auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; i++) {}
	auto end = chrono::high_resolution_clock::now();

	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;*/

}
