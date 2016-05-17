#include <iostream>

#include "./linear_list/arr_list.h"
#include "./linear_list/ink_list.h"

void ink_list_test();
void arr_list_test();

int main(){
	//arr_list_test();
	ink_list_test();
	return 0 ;
}

void ink_list_test(){
	ink_list<int> alist ;
	for(int i = 0 ; i < 10 ; i ++){
		alist.append(i) ;
	}
	for(int i = 0 ; i < 4 ; i ++){
		alist.insert(i , 11 * (i + 1)) ;
		alist.print();
	}
	alist.print();
	for(int i = 0 ; i < 5 ; i ++){
		alist.remove(i) ;
		alist.print();
	}

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

