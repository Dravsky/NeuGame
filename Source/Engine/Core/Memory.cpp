#include "Memory.h"

using namespace std;
lola::MemoryTracker lola::g_memoryTracker;

void* operator new (size_t size) {

	void* p = malloc(size);

	lola::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* address, size_t size) {
	
	lola::g_memoryTracker.Remove(address, size);

	free(address);
}


namespace lola {
	void MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}
	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}
	void MemoryTracker::DisplayInfo()
	{
		cout << "Current bytes allocated: " << m_bytesAllocated << endl;
		cout << "Current number allocations: " << m_numAllocations << endl;
	}
}