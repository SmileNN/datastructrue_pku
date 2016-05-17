#include <iostream>

#include ".\stack.h"
#include "..\node.h"

template <class T>
class ink_stack:public stack<T>{
	private:
		int size ;
		node<T> * top ;
	public:
		ink_stack(){
			size = 0 ;
			top = NULL ;
		}
		~ink_stack(){
			clear() ;	
		}
		void clear(){
			while( top != NULL){
				node<T> * p = top ;
				top = p -> next ;
				delete p ;
			}
			size = 0 ;
		}
		bool push(const T val){
			node<T> * temp = new node<T>(val, top) ;
			top = temp ;
			size ++ ;
			return true ;
		}
		T pop(){
			node<T> * temp = top ;
			top = top -> next ;
			T res = temp -> data ;
			delete temp ;
			size -- ;
			return res ;
		}
		bool get_top(T & item){
			if( top == NULL ){
				return false ;
			}
			item = top -> data ;
			return true ;
		}
		bool is_empty(){
			return top == NULL ? true : false ;
		}
		void print(){
			std::cout << "size = " << size << std::endl;
			node<T> * temp = top ;
			while(temp != NULL){
				std::cout << temp -> data << " " ;
				temp = temp -> next ;
			}
			std::cout << std::endl << std::endl ;
		}
};
