#pragma once
template<class T> class Link{
public:
	T data;
	Link<T> * next;
	Link(const T info, const Link<T> * next_value = NULL){
		data = info;
		next = next_value;
	}
	Link(const Link<T> * next_value){
		next = next_value;
	}
	~Link();
};

