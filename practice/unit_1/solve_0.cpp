#include <iostream>

int f(int n , int m){
	int num[] = new int[n + 1] ;
	int liv[] = new int[n + 1] ;
	for(int i = 0 ; i < n + 1 ; i ++){
		num[i] = i ;
		liv[i] = 1 ;
	}
	int cnt = 0 ;
	int ind = 1 ;
	while(cnt != n - 1){
		
	}
}

int main(){
	int n , m ; 
	while(std::cin >> n >> m){
		std::cout << f(n , m) << std::endl;
	}
	return 0 ;
}
