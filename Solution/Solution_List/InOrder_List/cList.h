#pragma once

/***************************************************************
* Purpose:   ˳���ѧϰ
* Author:    JsonLin
* Created:   2017-05-05
**************************************************************/


#include <cstdio>



#define MAXSIZE 20		/* �洢�ռ��ʼ������ */

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef int ElemType;		/* ElemType���͸���ʵ������������������Ϊint */

typedef struct
{
	ElemType data[MAXSIZE];		/* ����洢����Ԫ�أ����ֵΪMAXSIZE */
	int length;					/* ���Ա�ǰ���� */
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
		
	void unionL(SqList*, SqList);		/* �����е������Ա�2�е��������Ա�1�е�����Ԫ�ز��뵽1�� */

private:
	
	
};

