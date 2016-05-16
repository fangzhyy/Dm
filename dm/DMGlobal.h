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
#define PROPERTY(__TYPE__, __NAME__)\
	__TYPE__ m##__NAME__;\
	inline __TYPE__ get##__NAME__(){\
		return m##__NAME__;\
	}\
	inline void set##__NAME__(__TYPE__ value){\
	m##__NAME__ = value; \
	}

#define MinZero(__T__)\
__T__ = __T__ > 0 ? __T__ : 0;


#endif
