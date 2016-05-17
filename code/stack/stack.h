#pragma once

template <class T>
class stack{
	public:
		virtual void clear() = 0 ;
		virtual bool push(const T val) = 0 ;
		virtual T pop() = 0 ;
		virtual bool get_top(T & item) = 0 ;
		virtual bool is_empty() = 0 ;
		virtual void print() = 0 ;
};
