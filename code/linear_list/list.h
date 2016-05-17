template <class T> 
class list{
	void clear();					// 置空线性表
	bool is_empty();				// 线性表为空时，返回True
	bool append(T value);			// 在表尾添加一个元素value，表的长度增1
	bool insert(int p, T value);	// 在位置p上插入一个元素value，表的长度增1
	bool remove(int p); 			 	// 删除位置p上的元素，表的长度减 1
	T get_value(int p);			 	// 返回位置p的元素值 
	T set_value(int p, T value);	 	// 用value修改位置p的元素值
}; 

