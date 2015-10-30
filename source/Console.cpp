#include "../headers/Console.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
Console* Console::instance = NULL;

Console::Console() {
}

Console::~Console() {
	delete instance;
}

Console* Console::getInstance() {
	if (instance == NULL) {
		instance = new Console();
	}
	return instance;
}

string Console::int_to_str(int num) {
	ostringstream oStream;
	oStream << num;
	return oStream.str();
}

int Console::str_to_int(string str) {
	return atoi(str.c_str());
}

void Console::put(string text) {
	cout << text << endl;
}

string Console::get() {
	string input = "";
	getline(cin, input);
	return input;
}

void Console::clear() {
	system("CLS");
}

void Console::pause() {
	system("PAUSE");
}