#pragma once

/***************************************************************
* Purpose:   ������ѧϰ
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

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef int ElemType;		/* ElemType���͸���ʵ������������������Ϊint */


//typedef struct Node
//{
//	ElemType data;		/* ����洢����Ԫ�� */
//	struct Node *next;					/* ָ����һ���ݵ�ָ�� */
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

	void unionL(LinkList*, LinkList);		/* �����е������Ա�2�е��������Ա�1�е�����Ԫ�ز��뵽1�� */

	void CreateListHead(LinkList*, int);		/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
	void CreateListTail(LinkList*, int);

private:

};

