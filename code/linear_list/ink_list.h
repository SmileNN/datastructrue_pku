#include <iostream>

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
class ink_list{
	protected:
		node<T>* head;
		node<T>* tail;			// 单链表的头、尾指针
		int length ;
	public:
		ink_list(){
			tail = new node<T> ;	// head 和 tail 是一个节点。
			head = tail ;
			head -> data = 9527 ;	// 9527 做标记。
			length = 0 ;
		}
		~ink_list(){
			clear();
			delete head ;
		}
		void print(){
			std::cout << "length = " << length << " : ";
			for(node<T> * i = head ; i != tail -> next ; i = i -> next){
				std::cout << i -> data << " ";
			}
			std::cout << std::endl;
		}

		bool is_empty(){
			return length == 0 ? true : false ;
		}

		void clear(){					// 将链表存储的内容清除，成为空表
			node<T> * temp;
			while(head != NULL){
				temp = head ;
				head = head -> next ;
				delete temp ;
			}
			head = tail = new node<T> ;
			length = 0 ;
		}

		bool append(T val){				// 在表尾添加一个元素value，表的长度增1
			tail -> next = new node<T>(val) ;		// ????????????????????????????????????
			tail = tail -> next ;
			length ++ ;
		}

		bool insert(int p, T val){
			if( p < 0 || p > length){
				std::cerr << "ERROR: " << p << " isn't in [0," << length << "]." << std::endl;
				return false ;
			}
			node<T> * ind = head ;
			for(int i = 0 ; i < p ; i ++){
				ind = ind -> next ;
			}
			node<T> *  temp = new node<T>(val, ind -> next) ;
			ind -> next = temp ;
			length ++ ;
			return true ;
		}

		bool remove(int p){
			if( p < 0 || p > length){
				std::cerr << "ERROR: " << p << " isn't in [0," << length << "]." << std::endl;
				return false ;
			}
			node<T> * temp = head ;
			for(int i = 0 ; i < p ; i ++){
				temp = temp -> next ;
			}
			node<T> * point = temp -> next ;
			temp -> next = point -> next ;
			delete point ;
			length -- ;
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
};
