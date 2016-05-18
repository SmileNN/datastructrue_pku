#pragma once

template <class T> class queue{
	public:
		virtual void clear() = 0 ;
		virtual bool push(const T value) = 0 ;
		virtual T pop() = 0 ;
		virtual T top() = 0 ;
		virtual bool is_empty() = 0 ;
		virtual int get_size() = 0 ;
		virtual void print() = 0 ;
};
