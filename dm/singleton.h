#pragma once

template<typename  T>
class Singleton {

private:
	static T obj;
	//typedef T obj_type;
	static double i;
public:
	static T& instance() {
		return obj;
	}
};

template<typename T> T Singleton<T>::obj;