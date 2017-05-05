#include "cList.h"

int main()
{
	cList LISTINT;
	SqList mList;
	ElemType e = 0;
	LISTINT.InitList(&mList);
	printf("��ʼ��L��mList.length=%d\n", mList.length);
	for (int j = 1; j <= 5; j++) {
		LISTINT.ListInsert(&mList, 1, j);
	}
	printf("��L�ı�ͷ���β���1��5��mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	int isEmpty = 0;
	isEmpty = LISTINT.ListEmpty(mList);
	printf("mList�Ƿ�գ�isEmpty=%d(1:�� 0:��)\n", isEmpty);

	LISTINT.ClearList(&mList);
	printf("���mList��mList.length=%d\n", mList.length);
	isEmpty = LISTINT.ListEmpty(mList);
	printf("mList�Ƿ�գ�isEmpty=%d(1:�� 0:��)\n", isEmpty);

	for (int j = 1; j <= 10; j++) {
		LISTINT.ListInsert(&mList, j, j);
	}
	printf("��mList�ı�β���β���1��10��mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	LISTINT.ListInsert(&mList, 1, 0);
	printf("��mList�ı�ͷ����0��mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	LISTINT.GetElem(mList, 5, &e);
	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);

	int k;
	for (int j = 3; j <= 4; j++) {
		k = LISTINT.LocateElem(mList, j);
		if (k){
			printf("��%d��Ԫ�ص�ֵΪ: %d\n", k, j);
		}
		else {
			printf("û��ֵΪ%d��Ԫ��\n", j);
		}
	}


	k = LISTINT.ListLength(mList); /* kΪ�� */
	for (int j = k + 1; j >= k; j--)
	{
		int ret = LISTINT.ListDelete(&mList, j, &e); /* ɾ����j������ */
		if (ret == ERROR) {
			printf("ɾ����%d������ʧ��\n", j);
		}
		else {
			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
		}
	}
	printf("�������mList��Ԫ�أ�");
	LISTINT.OutputList(mList);

	int i = 5;
	LISTINT.ListDelete(&mList, i, &e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", i, e);

	printf("�������mList��Ԫ�أ�");
	LISTINT.OutputList(mList);

	//����һ����10������mList2
	SqList mList2;
	LISTINT.InitList(&mList2);
	for (int j = 6; j <= 15; j++)
		LISTINT.ListInsert(&mList2, 1, j);

	printf("�������mList��Ԫ�أ�");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);
	printf("�������mList2��Ԫ�أ�");
	LISTINT.OutputList(mList2);
	printf("mList2.length=%d \n", mList2.length);
	LISTINT.unionL(&mList, mList2);

	printf("��������ϲ���mList2��mList��Ԫ�أ�");
	LISTINT.OutputList(mList);

	getchar();
	return 0;
}