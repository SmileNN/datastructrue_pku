#pragma once

template <class T> 
class list{
	virtual void clear() = 0 ;						// 置空线性表
	virtual int length() = 0 ;						// 返回线性表的长度
	virtual bool is_empty() = 0 ;					// 线性表为空时，返回True
	virtual bool append(T value) = 0 ;				// 在表尾添加一个元素value，表的长度增1
	virtual bool insert(int p, T value) = 0 ;		// 在位置p上插入一个元素value，表的长度增1
	virtual bool remove(int p) = 0 ; 				// 删除位置p上的元素，表的长度减 1
	virtual T get_value(int p) = 0 ;				// 返回位置p的元素值 
	virtual bool set_value(int p, T value) = 0 ;	// 用value修改位置p的元素值
	virtual int get_position(const T val) = 0 ;		// 在线性表中查找值为val的元素，并返回第1次出现的位置
	virtual void print() = 0 ;						// 打印线性表
};