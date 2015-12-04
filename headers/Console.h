#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H
#include <string>
using namespace std;

class Console {
protected:
	Console();
	~Console();
	static Console* instance;
public:
	//returns the instance of Console, or creates it if there is no instance yet
	static Console* getInstance();
	//a utility function that turns an int into a string
	string int_to_str(int num);
	//a utility function that turns a string into a int
	int str_to_int(string str);
	//prints the given string as a line on the console
	void put(string text);
	//gets a line of input from the user
	string get();
	//clears the console
	void clear();
	//pauses the console until the user presses any key
	void pause();
};
#endif