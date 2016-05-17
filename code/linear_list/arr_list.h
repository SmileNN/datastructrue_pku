#include <iostream>

template <class T>
class arr_list{
	private:    					// 线性表的取值类型和取值空间
		int  max_size;            	// 私有变量，顺序表实例的最大长度
		int  cur_len; 		    	// 私有变量，顺序表实例的当前长度
		int  position;				// 私有变量，当前处理位置
		T	 *a_list ;            	// 私有变量，存储顺序表的实例	
	public:
		arr_list(const int size){		// 创建一个新的顺序表，参数为表实例的最大长度
			max_size = size;
			a_list = new T[max_size];
			cur_len = position = 0;
		}
		
		~arr_list(){					// 析构函数，用于消除该表实例
			std::cerr << "list is delete" << std::endl;
			delete [] a_list;
		}
		
		void clear(){      			// 将顺序表存储的内容清除，成为空表
			delete [] a_list;
			cur_len = position = 0;
			a_list = new T[max_size];
		}

		int length(){
			return cur_len;	
		}
		
		bool append(const T val){			// 在表尾添加一个元素val，表的长度增1
			if(cur_len >= max_size){
				std::cerr << "ERROR: cur_len = " << cur_len << " >= max_size =" << max_size << "." << std::endl;
				return false;
			}
			a_list[cur_len ++] = val;
			return true;
		}

		bool insert(int p, T val){
			if(cur_len >= max_size){
				std::cerr << "ERROR: cur_len = " << cur_len << " >= max_size = " << max_size << "." << std::endl;
				return false;
			}
			for(int i = cur_len ; i > p ; i --){
				a_list[i] = a_list[i - 1];
			}
			cur_len ++;					// 特别注意：这里的cur_len是最后一个元素的下一个。
			a_list[p] = val ;
			return true;
		}

		bool remove(int p){				// 删除位置p上的元素，表的长度减 1
			if(p < 0 || p >= cur_len){
				std::cerr << "ERROR: remove position " << p << " is not in [0, " << cur_len << ")." << std::endl;
				return false;
			}
			cur_len --;					// 特别注意：这里的cur_len是之向最后一个元素的。
			for(int i = p ; i < cur_len ; i ++){
				a_list[i] = a_list[i + 1];
			}
			return true;
		}

		int get_position(const T val){	// 在线性表中查找值为val的元素，并返回第1次出现的位置
			for(int i = 0 ; i < cur_len ; i ++){
				if(a_list[i] == val) return i;
			}
			return -1;					// -1 是一个不存在的下标，所以找不到的时候就返回 -1
		}

		void print(){
			std::cout << "len = " << cur_len << std::endl;
			for(int i = 0 ; i < cur_len ; i ++){
				if(i > 0) std::cout << " " ;
				std::cout << "[" << i << "," << a_list[i] << "]" ;
			}
			std::cout << std::endl;
		}
};
