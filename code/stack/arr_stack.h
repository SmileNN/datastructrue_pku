#include <iostream>
#include ".\stack.h"

template <class T>
class arr_stack: public stack<T>{
	private:
		int size ;
		int top ;
		T * st ;
		void expand(){
			size += size ;
			T * tmp = new T[size] ;
			for(int i = 0 ; i < top ; i ++){
				tmp[i] = st[i] ;
			}
			delete st ;
			st = tmp ;
		}
		void narrow(){
			size /= 2 ;
			T * tmp = new T[size] ;
			for(int i = 0 ; i < top ; i ++){
				tmp[i] = st[i] ;
			}
			delete st ;
			st = tmp ;
		}
	public:
		arr_stack(){
			size = 1 ;
			st = new T[size] ;
			top = 0 ;
		}
		~arr_stack(){
			delete st ;
		}
		
		void clear(){
			delete st ;
			size = 1 ;
			st = new T[size] ;
			top = 0 ;
		}
		bool push(const T val){
			if(top >= size){
				expand() ;
			}
			st[top ++] = val ;
		}
		T pop(){
			T item = st[-- top] ;
			if(top * 4 < size){
				narrow() ;
			}
			return item ;
		}

		bool get_top(T & item){
			if(top > 0){
				item = st[top - 1] ;
				return true ;
			}
			return false ;
		}

		bool is_empty(){
			return top == 0 ? true : false ;
		}

		void print(){
			std::cout << "size = " << size << " top = " << top << std::endl;
			for(int i = 0 ; i < top ; i ++){
				std::cout << st[i] << " ";
			}
			std::cout << std::endl << std::endl;
		}
};

