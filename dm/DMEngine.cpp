#include "stdafx.h"
#include "DMEngine.h"


DMEngine::DMEngine(void)
{
}


DMEngine::~DMEngine(void)
{
}

void DMEngine::run() {
	while(1) {
		vector<DMEvent>::iterator iter = mEvents.begin();
		vector<vector<DMEvent>::iterator> iterForRemove;
		while(iter != mEvents.end()) {
			if(!iter->Update())
				iterForRemove.push_back(iter);
			
			iter++;
		}
		vector<vector<DMEvent>::iterator>::iterator removeIter = iterForRemove.begin();
		while(removeIter != iterForRemove.end()) {
			mEvents.erase(*removeIter);
			removeIter++;
		}

	}
}