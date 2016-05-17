#pragma once

template <class T>
class node{
	public:
		T data;			// ���ڱ�����Ԫ�ص�����
		node * next;	// ָ���̽���ָ��
		node(const T val, node * next_node = NULL){
			data = val;
			next = next_node;
		}
		node(node * next_node = NULL){
			next = next_node;
		}
};
