#pragma once

/***************************************************************
* Purpose:   ������ѧϰ
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


/* ��ʼ��˳������ */
Status nList::InitList(LinkList *L)
{
	//*L = (LinkList)malloc(1024);
	L = new (std::nothrow) LinkList(); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!L) {/* �洢����ʧ�� */
		return ERROR;
	}

	L->next = NULL; /* ָ����Ϊ�� */

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status nList::ListEmpty(LinkList L)
{
	if (L.next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status nList::ClearList(LinkList *L)
{
	LinkList *p, *q;
	p = L->next;           /*  pָ���һ����� */
	while (p)                /*  û����β */
	{
		q = p->next;
		delete(p);
		p = q;
	}

	L->next = NULL;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
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

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status nList::ListInsert(LinkList *L, int i, ElemType e)
{
	/* ��i�ȵ�һλ��С */
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
		return ERROR;   /* ��i��Ԫ�ز����� */
	}
	s = new LinkList();
	s->next = q->next;
	s->data = e;
	q->next = s;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status nList::ListDelete(LinkList *L, int i, ElemType *e)
{
	/* ���Ա�Ϊ�ջ�ɾ��λ�ò����� */
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

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
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

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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

/* �����е������Ա�Lb�е��������Ա�1�е�����Ԫ�ز��뵽La�� */
void nList::unionL(LinkList *La, LinkList Lb)
{
	int La_len, Lb_len;
	/* ������La��Lb��ͬ������Ԫ��e */
	ElemType e;
	/* �����Ա�ĳ���*/
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

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void nList::CreateListHead(LinkList *L, int n)
{
	LinkList *p;
	srand(time(0));                         /* ��ʼ����������� */
	InitList(L);
	for (int i = 0; i<n; i++)
	{
		p = new LinkList();
		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
		p->next = L->next;
		L->next = p;						/*  ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void nList::CreateListTail(LinkList *L, int n)
{
	LinkList *p, *r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	InitList(L);
	r = L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i<n; i++)
	{
		p = new LinkList(); /*  �����½�� */
		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}
