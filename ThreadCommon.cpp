#include "ThreadCommon.h"

ThreadCommon::ThreadCommon(void (*ptrFunction)())
{
	_thread = thread(ptrFunction);
}

ThreadCommon::ThreadCommon(void (*ptrFunction)(string[]), string parametr1[])
{
	_thread = thread(ptrFunction, parametr1);
}	

ThreadCommon::~ThreadCommon()
{
	_thread.join();
}
