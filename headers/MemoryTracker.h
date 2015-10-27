#pragma once
#include <windows.h>
#include <psapi.h>

class MemoryTracker {
protected:
	static PROCESS_MEMORY_COUNTERS memStruct;
	static int loggedMemory;

public:
	static void save_memory();
	static int get_saved_memory();
	static int get_current_memory();
};