#include <iostream>
#include <cstring>

const int max_N = 10000 ;

int main(){
	int N ; std::cin >> N ;
	char ch[max_N] ;
	std::cin.get();
	for(int _t = 0 ; _t < N ; _t ++){
		std::cin.getline(ch, max_N, '\n') ;
		int len = strlen(ch) ;
		for(int i = 0 ; i < len ; i ++){
			if( ch[i] <= 'z' && ch[i] >= 'a' ){
				ch[i] = 'a' + (ch[i] - 'a' + 1) % 26 ;
			}
			if( ch[i] <= 'Z' && ch[i] >= 'A' ){
				ch[i] = 'A' + (ch[i] - 'A' + 1) % 26 ;
			}
		}
		std::cout << ch << std::endl;
	}
}
