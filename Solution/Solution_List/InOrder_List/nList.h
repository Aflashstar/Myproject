#pragma once

/***************************************************************
* Purpose:   单链表学习
* Author:    JsonLin
* Created:   2017-05-06
**************************************************************/


#include <cstdio>
#include <new>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef int ElemType;		/* ElemType类型根据实际情况而定，这里假设为int */


//typedef struct Node
//{
//	ElemType data;		/* 数组存储数据元素 */
//	struct Node *next;					/* 指向下一数据的指针 */
//}Node;
//
//typedef struct Node *LinkList;

class LinkList
{
public:
	ElemType data;
	class LinkList *next;
};

class nList
{
public:
	nList();
	~nList();

	Status visit(ElemType);

	Status InitList(LinkList*);
	Status ListEmpty(LinkList);
	Status ClearList(LinkList*);
	Status GetElem(LinkList, int, ElemType*);
	Status LocateElem(LinkList, int);
	Status ListInsert(LinkList*, int, ElemType);
	Status ListDelete(LinkList*, int, ElemType*);
	Status ListLength(LinkList);

	Status OutputList(LinkList);

	void unionL(LinkList*, LinkList);		/* 将所有的在线性表2中但不在线性表1中的数据元素插入到1中 */

	void CreateListHead(LinkList*, int);		/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
	void CreateListTail(LinkList*, int);

private:

};

