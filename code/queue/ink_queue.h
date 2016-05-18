#pragma once

#include <iostream>

#include "..\node.h"

template <class T> 
class ink_queue:public queue<T>{
	private:
		node<T>	* head; //链表实现队列，head处弹出。
		node<T> * tail; //			    tail处压入。
		int size ;
	public:
		ink_queue(){
			head = tail = NULL ;
			size = 0 ;
		}
		~ink_queue(){
			clear() ;
		}
	
		// 清空当前栈
		void clear(){
			while(head != NULL){
				tail = head ;
				head = head -> next ;
				delete tail;
			}
			tail = NULL ;
			size = 0 ;
		}
		
		// 把元素压入栈尾。
		bool push(const T value){
			if(head == NULL){
				head = tail = new node<T>(value, NULL);
			}else{
				node<T> * p = new node<T>(value, NULL);
				tail -> next = p ;
				tail = p ;
			}
			size ++ ;
		}

		// 把元素从栈头弹出来。
		T pop(){
			if(head == NULL){
				std::cerr << "ERROR: stack is empty." << std::endl;
				//return NULL ;
			}else{
				node<T> * p = head ;
				T res = p -> data ;
				head = head -> next ;
				delete p ;
				size -- ;
				return res ;
			}
		}

		T top(){
			if(head == NULL){
				std::cerr << "ERROR: stack is empty." << std::endl;
				//return NULL ;
			}else{
				return head -> data ;
			}
		}

		bool is_empty(){
			return head == NULL ? true : false;
		}
		
		int get_size(){
			return size;
		}

		void print(){
			std::cout << "size = " << size ;
			if(size > 0){
				std::cout << " , head = " << head -> data << " , tail = " << tail -> data << std:: endl;
			}else{
				std::cout << " , head = NULL , tail = NULL" << std:: endl;
			}
			for(node<T> * i = head ; i != NULL ; i = i -> next){
				std::cout << i -> data << " " ;
			}
			std::cout << std::endl << std::endl; 
		}
};
