#include <iostream>

const int max_N = 301 ;
bool exi[max_N]; 
int n , m ;

int find(int begin){
	int res = begin ;
	for(int i = 0 ; i < m ;){
		if(exi[res] == true) i ++ ;
		res = (res + 1) % n ;
	}
	//std::cerr << (res - 1 + n ) % n << std::endl;
	return (res - 1 + n ) % n ;
}

int main(){
	while(std::cin >> n >> m){
		for(int i = 0 ; i < max_N ; i ++) exi[i] = true ;
		int ind = 0 ;
		for(int i = 0 ; i < n - 1 ; i ++){
			ind = find(ind) ;
			exi[ind] = false ;
		}
		for(int i = 0 ; i < n ; i ++){
			if(exi[i] == true){ 
				std::cout << i + 1 << std::endl; 
				break ;
			}
		}
	}
	return 0;
}
