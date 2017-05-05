#pragma once

/***************************************************************
* Purpose:   顺序表学习
* Author:    JsonLin
* Created:   2017-05-05
**************************************************************/


#include "cList.h"




cList::cList()
{
	
}

cList::~cList()
{
}

Status cList::visit(ElemType e)
{
	printf("%d  ", e);

	return OK;
}

/* 初始化顺序线性表 */
Status cList::InitList(SqList *L)
{
	L->length = 0;

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status cList::ListEmpty(SqList L)
{
	if (L.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status cList::ClearList(SqList *L)
{
	L->length = 0;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意s是指位置，第1个位置的数组是从0开始 */
Status cList::GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 ||  i>L.length) {
		return ERROR;
	}

	*e = L.data[i - 1];
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
Status cList::LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
		}
	}

	return 0;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status cList::ListInsert(SqList *L, int i, ElemType e)
{
	/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
	if (i<1 || i>L->length+1) {
		return ERROR;
	}
	/* 顺序线性表已经满 */
	if (L->length >= MAXSIZE) {
		return ERROR;
	}

	/* 若插入数据位置不在表尾 */
	if (i<=L->length) {
		/* 将要插入位置之后的数据元素向后移动一位 */
		for (int k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];		
		}
	}
	L->data[i - 1] = e;		/* 将新元素插入 */
	L->length++;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status cList::ListDelete(SqList *L, int i, ElemType *e)
{
	/* 线性表为空或删除位置不合理 */
	if (L->length == 0 || i<1 || i>L->length) {
		return ERROR;
	}

	*e = L->data[i - 1];
	/* 如果删除不是最后位置 */
	if (i<L->length) {
		/* 将删除位置后继元素前移 */
		for (int k = i - 1; k < L->length - 1; k++) {
			L->data[k] = L->data[k + 1];
		}
	}
	L->length--;

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
Status cList::ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status cList::OutputList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");

	return OK;
}

/* 将所有的在线性表Lb中但不在线性表1中的数据元素插入到La中 */
void cList::unionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	/* 声明与La和Lb相同的数据元素e */
	ElemType e;		
	/* 求线性表的长度*/
	La_len = ListLength(*La);		
	Lb_len = ListLength(Lb);

	for (int i = 1; i <= Lb_len; i++) {
		/* 取Lb中第i个数据元素赋给e */
		GetElem(Lb, i, &e);		
		/* La中不存在和e相同数据元素 */
		if (!LocateElem(*La, e)) {
			/* 插入 */
			ListInsert(La, ++La_len, e);		
		}
	}
}


