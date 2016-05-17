#pragma once

template <class T>
class node{
	public:
		T data;			// 用于保存结点元素的内容
		node * next;	// 指向后继结点的指针
		node(const T val, node * next_node = NULL){
			data = val;
			next = next_node;
		}
		node(node * next_node = NULL){
			next = next_node;
		}
};
