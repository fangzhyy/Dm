#include "stdafx.h"
#include "DMEngine.h"
#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

DMEngine::DMEngine(void)
{
}


DMEngine::~DMEngine(void)
{
}

void DMEngine::wait(int s) {
#ifdef WIN32
	Sleep(s);
#else
	sleep(s);
#endif

}

void DMEngine::run() {
	while(1) {
		auto iter = mEvents.begin();
		while(iter != mEvents.end()) {
			if ((*iter)->Update()){
				delete *iter;
				iter = mEvents.erase(iter);
			}
			iter++;
		}
		wait(1);
	}
}