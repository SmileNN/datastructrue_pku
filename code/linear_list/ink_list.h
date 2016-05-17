#include <iostream>
#include ".\list.h"

template <class T>
class node{
	public:
		T data;			// 用于保存结点元素的内容
		node * next;	// 指向后继结点的指针
		node(const T val, node * next_node = NULL){
			data = val;
			next = next_node;
		}
		node(node * next_node = NULL){
			next = next_node;
		}
};

template <class T>
class ink_list:public list<T>{
	protected:
		node<T>* head;
		node<T>* tail;			// 单链表的头、尾指针
		int len ;
		
		node<T>* get_point(int p){
			node<T> * res = head ;
			for(int i = 0 ; i < p && res != NULL ; i ++){
				res = res -> next ;
			}
			return res ;
		}
	public:
		ink_list(){
			head = tail = new node<T>(9527) ;	// head 和 tail 是一个节点。
			len = 0 ;
		}
		~ink_list(){
			clear();
			delete head ;
		}
		
		void clear(){					// 将链表存储的内容清除，成为空表
			node<T> * temp;
			while(head != NULL){
				temp = head ;
				head = head -> next ;
				delete temp ;
			}
			head = tail = new node<T>(9527) ;	// head 和 tail 是一个节点。
			len = 0 ;
		}
		
		int length(){
			return len ;
		}
		
		bool is_empty(){
			return len == 0 ? true : false ;
		}
		
		bool append(T val){				// 在表尾添加一个元素value，表的长度增1
			tail -> next = new node<T>(val) ;		// ????????????????????????????????????
			tail = tail -> next ;
			len ++ ;
		}
		
		bool insert(int p, T val){
			if( p < 0 || p > len){					// 插入的时候是闭区间
				std::cerr << "ERROR: " << p << " isn't in [0," << len << "]." << std::endl;
				return false ;
			}
			node<T> * ind = get_point(p) ;
			node<T> *  temp = new node<T>(val, ind -> next) ;
			ind -> next = temp ;
			if(ind == tail){
				tail = temp ;
			}
			len ++ ;
			return true ;
		}
		
		bool remove(int p){
			if( p < 0 || p >= len){
				std::cerr << "ERROR: " << p << " isn't in [0," << len << ")." << std::endl;
				return false ;
			}
			node<T> * temp = get_point(p) ;
			node<T> * point = temp -> next ;
			temp -> next = point -> next ;
			delete point ;
			if(p == len - 1){
				tail = temp ;	
			}

			len -- ;
			return true ;
		}
			
		T get_value(int p){
			if( p < 0 || p >= len){
				std::cerr << "ERROR: " << p << " isn't in [0," << len << ")." << std::endl;
				return false ;
			}
			node<T> * temp = get_point(p) ;
			return temp -> next -> data ;
		}
		
		bool set_value(int p, T value){ // 用value修改位置p的元素值
			if( p < 0 || p >= len){
				std::cerr << "ERROR: " << p << " isn't in [0," << len << ")." << std::endl;
				return false ;
			}
			node<T> * temp = get_point(p) ;
			temp -> next -> data = value;
			return true ;
		}
		
		int get_position(const T val){
			int cnt = -1 ;
			for(node<T> * temp = head ; temp != tail -> next ; temp = temp -> next){
				if(temp -> data == val){
					return cnt ;
				}
				cnt ++ ;
			}
			return -1 ;
		}
		
		void print(){
			std::cout << "len = " << len << " , head = " << head -> data << " , tail = " << tail -> data << std::endl;
			for(node<T> * i = head ; i != tail -> next ; i = i -> next){
				std::cout << i -> data << " ";
			}
			std::cout << std::endl << std::endl;
		}
};
