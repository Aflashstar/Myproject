#pragma once

/***************************************************************
* Purpose:   单链表学习
* Author:    JsonLin
* Created:   2017-05-06
**************************************************************/


#include "nList.h"



nList::nList()
{
}


nList::~nList()
{
}

Status nList::visit(ElemType e)
{
	printf("%d  ", e);

	return OK;
}


/* 初始化顺序单链表 */
Status nList::InitList(LinkList *L)
{
	//*L = (LinkList)malloc(1024);
	L = new (std::nothrow) LinkList(); /* 产生头结点,并使L指向此头结点 */
	if (!L) {/* 存储分配失败 */
		return ERROR;
	}

	L->next = NULL; /* 指针域为空 */

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status nList::ListEmpty(LinkList L)
{
	if (L.next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status nList::ClearList(LinkList *L)
{
	LinkList *p, *q;
	p = L->next;           /*  p指向第一个结点 */
	while (p)                /*  没到表尾 */
	{
		q = p->next;
		delete(p);
		p = q;
	}

	L->next = NULL;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status nList::GetElem(LinkList L, int i, ElemType *e)
{
	LinkList *p;	
	p = L.next;
	if (!p || i<1) {
		return ERROR;
	}

	int j = 1;
	while (p && j<i)
	{
		p = p->next;
		++j;
	}

	*e = p->data;

	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
Status nList::LocateElem(LinkList L, ElemType e)
{
	LinkList *p;
	p = L.next;
	int i = 1;
	while (p)
	{
		if (p->data == e) {
			return i;
		}
		p = p->next;
		++i;
	}

	return 0;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status nList::ListInsert(LinkList *L, int i, ElemType e)
{
	/* 当i比第一位置小 */
	if (i<1) {
		return ERROR;
	}
	LinkList *p,*q,*s;
	p = L->next;
	q = L;
	int j = 1;
	while (p && j<i)
	{
		q = p;
		p = p->next;
		++j;
	} 
	if (!q) {
		return ERROR;   /* 第i个元素不存在 */
	}
	s = new LinkList();
	s->next = q->next;
	s->data = e;
	q->next = s;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status nList::ListDelete(LinkList *L, int i, ElemType *e)
{
	/* 线性表为空或删除位置不合理 */
	if (i<1) {
		return ERROR;
	}

	LinkList *p,*q;
	p = L->next;
	q = L;
	int j = 1;
	while (p && j < i)
	{
		//..
		q = p;
		p = p->next;
		++j;
	}
	if (!p) {
		return ERROR;
	}
	q->next = p->next;
	*e = p->data;

	delete(p);

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
Status nList::ListLength(LinkList L)
{
	LinkList *p;
	if (!L.next) {
		return ERROR;
	}
	p = L.next;
	int i = 0;
	while (p)
	{
		p = p->next;
		++i;
	}
	
	return i;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status nList::OutputList(LinkList L)
{
	LinkList *p;
	p = L.next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");

	return OK;
}

/* 将所有的在线性表Lb中但不在线性表1中的数据元素插入到La中 */
void nList::unionL(LinkList *La, LinkList Lb)
{
	int La_len, Lb_len;
	/* 声明与La和Lb相同的数据元素e */
	ElemType e;
	/* 求线性表的长度*/
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);

	LinkList *pa, *pb;
	pa = La->next;
	pb = Lb.next;
	int i = 1;
	while (i<=Lb_len)
	{
		GetElem(Lb, i, &e);
		++i;
		if (!LocateElem(*La, e)) {
			ListInsert(La, ++La_len, e);
		}
	}

}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void nList::CreateListHead(LinkList *L, int n)
{
	LinkList *p;
	srand(time(0));                         /* 初始化随机数种子 */
	InitList(L);
	for (int i = 0; i<n; i++)
	{
		p = new LinkList();
		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
		p->next = L->next;
		L->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void nList::CreateListTail(LinkList *L, int n)
{
	LinkList *p, *r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	InitList(L);
	r = L;                                /* r为指向尾部的结点 */
	for (i = 0; i<n; i++)
	{
		p = new LinkList(); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}
