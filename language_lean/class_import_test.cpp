#include <iostream>

class A{
	public:
		void a();
		virtual void b() = 0 ;
};
class B: public A{
	public:
		void a(){
			std::cout << "a" << std::endl;
		}
};
class C: public B{
	public:
		void b(){
			std::cout << "b" << std::endl;
		}
};
int main(){
	C c ;
	c.a();
	c.b();
}
