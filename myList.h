#pragma once
#include<iostream>
#include"library.h"
//����ڵ���
typedef Book ElemType;
template<class T>
class Node
{
public:
	Node(Node<T>* p = NULL, Node<T>* n = NULL) :prev(p), next(n) {}
	ElemType data;//�������
	Node<T>* prev;//ǰһ���ڵ�
	Node<T>* next;//��һ���ڵ�
};
//�����б�
template<class T>
class myList
{
public:
	myList(int s = 0);
	void push_back(ElemType d);
	void insert(int n, ElemType d);
	Node<T>* operator[](int n);
	void erase(int n);
	void change(int n, ElemType d);
	int size();
	void clear();
	bool empty();
private:
	Node<T>* head;//ͷ���
	int sz;//�б���
};
