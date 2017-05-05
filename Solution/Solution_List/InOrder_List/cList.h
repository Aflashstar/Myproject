#pragma once

/***************************************************************
* Purpose:   顺序表学习
* Author:    JsonLin
* Created:   2017-05-05
**************************************************************/


#include <cstdio>



#define MAXSIZE 20		/* 存储空间初始分配量 */

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef int ElemType;		/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct
{
	ElemType data[MAXSIZE];		/* 数组存储数据元素，最大值为MAXSIZE */
	int length;					/* 线性表当前长度 */
}SqList;


class cList
{
public:
	cList();
	~cList();

	Status visit(ElemType);

	Status InitList(SqList*);
	Status ListEmpty(SqList);
	Status ClearList(SqList*);
	Status GetElem(SqList, int, ElemType*);
	Status LocateElem(SqList, int);
	Status ListInsert(SqList*, int, ElemType);
	Status ListDelete(SqList*, int, ElemType*);
	Status ListLength(SqList);

	Status OutputList(SqList);
		
	void unionL(SqList*, SqList);		/* 将所有的在线性表2中但不在线性表1中的数据元素插入到1中 */

private:
	
	
};

