#pragma once
#include <thread>
#include <string>
#include <iostream>

using namespace std;

class ThreadCommon
{

	thread _thread;

public:
	ThreadCommon(void (*ptrFunction)());
	ThreadCommon(void (*ptrFunction)(string[]),string parametr1[] = nullptr);
	~ThreadCommon();

};

