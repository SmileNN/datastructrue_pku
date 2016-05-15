#include <iostream>
#include <algorithm>

const int max_N = 10000 ;
struct aa{
	int a ;
	int b ;
};
aa arr[max_N] ;

bool cmp(aa x , aa y){
	if(x.b < y.b) return false ;
	return true ;
}

void gao(){
	int a , b ;
	int ind = 0 ;
	for(int _c = 0 ; _c < 2 ;){
		std::cin >> a >> b ;
		if(b < 0) {
			_c ++ ;
			continue ;
		}
		bool find = false ;
		for(int j = 0 ; j < ind ; j ++){
			if(arr[j].b == b){
				arr[j].a += a ;
				find = true ;
				break ;
			}
		}
		if(find == false){
			arr[ind].a = a ;
			arr[ind].b = b ;
			ind ++ ;
		}
	}

	std::sort(arr , arr + ind , cmp) ;
	for(int i = 0 ; i < ind ; i ++){
		if(arr[i].a == 0) continue ;
		std::cout << "[ " << arr[i].a << " " << arr[i].b << " ] " ;
	}
	std::cout << std::endl;
}
int main(){
	int N ; std::cin >> N ;
	for(int _t = 0 ; _t < N ; _t ++){
		gao() ;
	}
	return 0 ;
}
