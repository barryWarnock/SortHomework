#pragma once
#ifndef MEMORYTRACKER_H
#define MEMORYTRACKER_H
#include <windows.h>
#include <psapi.h>

class MemoryTracker {
protected:
	static PROCESS_MEMORY_COUNTERS memStruct;
	static int loggedMemory;

public:
	//saves how much memory is being used at the time this is called
	static void save_memory();
	//returns the last saved memory usage
	static int get_saved_memory();
	//returns the current amount of memory being used by this program in bytes
	static int get_current_memory();
};
#endif