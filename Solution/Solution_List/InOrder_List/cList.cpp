#pragma once

/***************************************************************
* Purpose:   ˳���ѧϰ
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

/* ��ʼ��˳�����Ա� */
Status cList::InitList(SqList *L)
{
	L->length = 0;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status cList::ListEmpty(SqList L)
{
	if (L.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status cList::ClearList(SqList *L)
{
	L->length = 0;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ,ע��s��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status cList::GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i<1 ||  i>L.length) {
		return ERROR;
	}

	*e = L.data[i - 1];
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
Status cList::LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
		}
	}

	return 0;
}


/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status cList::ListInsert(SqList *L, int i, ElemType e)
{
	/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
	if (i<1 || i>L->length+1) {
		return ERROR;
	}
	/* ˳�����Ա��Ѿ��� */
	if (L->length >= MAXSIZE) {
		return ERROR;
	}

	/* ����������λ�ò��ڱ�β */
	if (i<=L->length) {
		/* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
		for (int k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];		
		}
	}
	L->data[i - 1] = e;		/* ����Ԫ�ز��� */
	L->length++;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status cList::ListDelete(SqList *L, int i, ElemType *e)
{
	/* ���Ա�Ϊ�ջ�ɾ��λ�ò����� */
	if (L->length == 0 || i<1 || i>L->length) {
		return ERROR;
	}

	*e = L->data[i - 1];
	/* ���ɾ���������λ�� */
	if (i<L->length) {
		/* ��ɾ��λ�ú��Ԫ��ǰ�� */
		for (int k = i - 1; k < L->length - 1; k++) {
			L->data[k] = L->data[k + 1];
		}
	}
	L->length--;

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
Status cList::ListLength(SqList L)
{
	return L.length;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status cList::OutputList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		visit(L.data[i]);
	}
	printf("\n");

	return OK;
}

/* �����е������Ա�Lb�е��������Ա�1�е�����Ԫ�ز��뵽La�� */
void cList::unionL(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	/* ������La��Lb��ͬ������Ԫ��e */
	ElemType e;		
	/* �����Ա�ĳ���*/
	La_len = ListLength(*La);		
	Lb_len = ListLength(Lb);

	for (int i = 1; i <= Lb_len; i++) {
		/* ȡLb�е�i������Ԫ�ظ���e */
		GetElem(Lb, i, &e);		
		/* La�в����ں�e��ͬ����Ԫ�� */
		if (!LocateElem(*La, e)) {
			/* ���� */
			ListInsert(La, ++La_len, e);		
		}
	}
}


