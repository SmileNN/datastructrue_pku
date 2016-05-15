#include <iostream>

int main(){
	long long N ;
	while(std::cin >> N){
		long long ans = 1 ;
		long long a = 2 * N ;
		long long b = N + 1 ;
		long long c = N ;
		for(int i = a ; i >= 2 ; i --){
			ans *= i ;
			while( ans % b == 0 && b >= 2 ){
				ans /= b ; b -- ;
			}
			while( ans % c == 0 && c >= 2 ){
				ans /= c ; c -- ;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0 ;
}
