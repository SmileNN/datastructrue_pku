#include <iostream>

#include "./linear_list/arr_list.h"
#include "./linear_list/ink_list.h"

#include "./stack/stack.h"
#include "./stack/arr_stack.h"
#include "./stack/ink_stack.h"

#include "./queue/queue.h"
#include "./queue/ink_queue.h"

void ink_list_test();
void arr_list_test();
void arr_stack_test();
void ink_stack_test();
void ink_queue_test();

int main(){
	//arr_list_test();
	//k_list_test();
	//arr_stack_test();
	//ink_stack_test();
	ink_queue_test();	
	return 0 ;
}

void ink_queue_test(){
	ink_queue<int> aqueue ;
	for(int i = 0 ; i < 14 ; i ++){
		aqueue.push(i) ;
	}
	aqueue.print();

	for(int i = 0 ; i < 3 ; i ++){
		aqueue.pop() ;
		aqueue.print();
	}
	
	std::cout << aqueue.top() << std::endl;

}

void ink_stack_test(){
	ink_stack<int> astack ;
	for(int i = 0 ; i < 1000 ; i ++){
		astack.push(i) ;
	}
	astack.print();
	
	int item ;
	astack.get_top(item) ;
	std::cout << "top : " << item << std::endl;
	
	for(int i = 0 ; i < 100 ; i ++){
		std::cout << "pop : " << astack.pop() << std::endl;
	}
	astack.print();

	astack.clear();
	astack.print();
}

void arr_stack_test(){
	arr_stack<int> astack ;
	for(int i = 0 ; i < 17 ; i ++){
		astack.push(i) ;
	}
	astack.print();
	
	int item ;
	astack.get_top(item) ;
	std::cout << "top : " << item << std::endl;
	
	for(int i = 0 ; i < 10 ; i ++){
		std::cout << "pop : " << astack.pop() << std::endl;
		astack.print();
	}

	astack.clear();
	astack.print();
}

void ink_list_test(){
	ink_list<int> alist ;
	for(int i = 0 ; i < 10 ; i ++){
		alist.append(i) ;
	}
	for(int i = 10 ; i < 14 ; i ++){
		alist.insert(i , 11 * (i + 1)) ;
		alist.print();
	}
	alist.print();
	for(int i = 14 ; i > 10 ; i --){
		alist.remove(i) ;
		alist.print();
	}
	
	alist.reverse();
	alist.print();

	for(int i = 0 ; i < 10 ; i ++){
		std::cout << i << " in " << alist.get_position(i) << std::endl;
	}
	alist.clear();
	alist.print();
}

void arr_list_test(){
	arr_list<int> alist(100);
	for(int i = 0 ; i < 100 ; i ++){
		alist.append(i);
	}
	alist.print();
	
	for(int i = 10 ; i < 100 ; i ++){
		alist.remove(10) ;
	}
	alist.print();
	
	for(int i = 5 ; i < 15 ; i ++){
		int t(alist.get_position(i));
		std::cout << i << " in " << t << std::endl;
	}

	for(int i = 0 ; i < 10 ; i ++){
		alist.insert(5,7);
	}
	alist.print();

	alist.~arr_list();
}

