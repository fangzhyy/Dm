#ifndef __DMGLOBAL_H__
#define __DMGLOBAL_H__


#define CREATE(__TYPE__, __PARAM__)\
	__TYPE__* pRet = new __TYPE__(__PARAM__); \
	if (pRet && pRet->init())\
		return pRet; \
	delete pRet; \
	return nullptr;

#define CREAET_FUNC(__TYPE__)\
	static __TYPE__* create()\
	{\
		__TYPE__* pRet = new __TYPE__(); \
		if (pRet && pRet->init())\
			return pRet; \
		delete pRet; \
		return nullptr;\
	}

#endif
