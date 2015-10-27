#include "../headers/MemoryTracker.h"
#include <time.h>
PROCESS_MEMORY_COUNTERS MemoryTracker::memStruct;
int MemoryTracker::loggedMemory = 0;

void MemoryTracker::save_memory() {
	GetProcessMemoryInfo(GetCurrentProcess(), &memStruct, sizeof(memStruct));
	loggedMemory = memStruct.QuotaNonPagedPoolUsage;
}

int MemoryTracker::get_saved_memory() {
	return loggedMemory;
}

int MemoryTracker::get_current_memory() {
	GetProcessMemoryInfo(GetCurrentProcess(), &memStruct, sizeof(memStruct));
	return memStruct.QuotaNonPagedPoolUsage;
}

