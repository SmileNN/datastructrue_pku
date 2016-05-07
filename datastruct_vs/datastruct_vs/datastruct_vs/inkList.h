#pragma once
#include "List.h"

template<class T> class inkList : public List<T>{
private:
	Link<T> *head;
	Link<T> *tail;
	Link<T> *set_pos(const int p);
public:
	inkList(int s);
	~inkList();
	bool is_empty();
	void clear();
	int length();
	bool append(const int p, const T value);
	bool insert(const int p, const T value);
	bool delete(const int p);
	bool get_value(const int p, T & value);
	bool get_pos(int & p, const T value);
};

// find the i-th node in the list.
template<class T> Link<T>* inkList<T>::set_pos(int i){
	int count = 0;
	if (i == -1) return head;
	Link<T> * p = head->next;

}
