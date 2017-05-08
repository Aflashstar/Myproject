#include "Interface.h"

int showcList()
{
	//..
	cList LISTINT;
	SqList mList;
	ElemType e = 0;
	LISTINT.InitList(&mList);
	printf("初始化L后：mList.length=%d\n", mList.length);
	for (int j = 1; j <= 5; j++) {
		LISTINT.ListInsert(&mList, 1, j);
	}
	printf("在L的表头依次插入1～5后：mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	int isEmpty = 0;
	isEmpty = LISTINT.ListEmpty(mList);
	printf("mList是否空：isEmpty=%d(1:是 0:否)\n", isEmpty);

	LISTINT.ClearList(&mList);
	printf("清空mList后：mList.length=%d\n", mList.length);
	isEmpty = LISTINT.ListEmpty(mList);
	printf("mList是否空：isEmpty=%d(1:是 0:否)\n", isEmpty);

	for (int j = 1; j <= 10; j++) {
		LISTINT.ListInsert(&mList, j, j);
	}
	printf("在mList的表尾依次插入1～10后：mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	LISTINT.ListInsert(&mList, 1, 0);
	printf("在mList的表头插入0后：mList.data=");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);

	LISTINT.GetElem(mList, 5, &e);
	printf("第5个元素的值为：%d\n", e);

	int k;
	for (int j = 3; j <= 4; j++) {
		k = LISTINT.LocateElem(mList, j);
		if (k){
			printf("第%d个元素的值为: %d\n", k, j);
		}
		else {
			printf("没有值为%d的元素\n", j);
		}
	}


	k = LISTINT.ListLength(mList); /* k为表长 */
	for (int j = k + 1; j >= k; j--)
	{
		int ret = LISTINT.ListDelete(&mList, j, &e); /* 删除第j个数据 */
		if (ret == ERROR) {
			printf("删除第%d个数据失败\n", j);
		}
		else {
			printf("删除第%d个的元素值为：%d\n", j, e);
		}
	}
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);

	int i = 5;
	LISTINT.ListDelete(&mList, i, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", i, e);

	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);

	//构造一个有10个数的mList2
	SqList mList2;
	LISTINT.InitList(&mList2);
	for (int j = 6; j <= 15; j++)
		LISTINT.ListInsert(&mList2, 1, j);

	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	printf("mList.length=%d \n", mList.length);
	printf("依次输出mList2的元素：");
	LISTINT.OutputList(mList2);
	printf("mList2.length=%d \n", mList2.length);
	LISTINT.unionL(&mList, mList2);

	printf("依次输出合并了mList2的mList的元素：");
	LISTINT.OutputList(mList);


	return 0;
}

int shownList()
{
	//..
	nList LISTINT;
	ElemType e = 0;
	int mTemp = 0;
	LinkList mList = { 0, NULL };
	int len = 0;
	printf("初始化前单链表的内存：%d \n", sizeof(mList));
	len = LISTINT.ListLength(mList);
	printf("初始化前：mList.length=%d\n", len);
	int isEmpty;
	isEmpty = LISTINT.ListEmpty(mList);
	printf("初始化前单链表mList是否空：isEmpty=%d(1:是 0:否)\n", isEmpty);

	LISTINT.InitList(&mList);
	printf("初始化后单链表的内存：%d \n",sizeof(mList));
	len = LISTINT.ListLength(mList);
	printf("初始化后：mList.length=%d\n", len);

	isEmpty = LISTINT.ListEmpty(mList);
	printf("初始化后单链表mList是否空：isEmpty=%d(1:是 0:否)\n", isEmpty);

	printf("表头插入1~5\n");
	for (int j = 1; j <= 5; j++) {
		LISTINT.ListInsert(&mList, 1, j);
	}
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("插入后：mList.length=%d\n", len);
	printf("插入后单链表的内存: %d \n", sizeof(mList));

	LISTINT.ClearList(&mList);
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("请空表后：mList.length=%d\n", len);

	printf("表尾插入1~5\n");
	for (int j = 1; j <= 5; j++) {
		LISTINT.ListInsert(&mList, j, j);
	}
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("插入后：mList.length=%d\n", len);

	LISTINT.ListInsert(&mList, 1, 0);
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("插入后：mList.length=%d\n", len);

	LISTINT.GetElem(mList, 2, &e);
	printf("第2个元素的值为：%d\n", e);

	for (int j = 3; j <= 6; j++) {
		mTemp = LISTINT.LocateElem(mList, j);
		if (mTemp){
			printf("第%d个元素的值为: %d\n", mTemp, j);
		}
		else {
			printf("没有值为%d的元素\n", j);
		}
	}

	len = LISTINT.ListLength(mList); /* k为表长 */
	for (int j = len + 1; j >= len; j--)
	{
		int ret = LISTINT.ListDelete(&mList, j, &e); /* 删除第j个数据 */
		if (ret == ERROR) {
			printf("删除第%d个数据失败\n", j);
		}
		else {
			printf("删除第%d个的元素值为：%d\n", j, e);
		}
	}
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);

	int i = 3;
	LISTINT.ListDelete(&mList, i, &e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", i, e);

	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);

	//构造一个有10个数的mList2
	LinkList mList2 = { 0, NULL };
	LISTINT.InitList(&mList2);
	for (int j = 2; j <= 8; j++) {
		LISTINT.ListInsert(&mList2, 1, j);
	}

	printf("依次输出mList1的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("合并前：mList1.length=%d\n", len);
	printf("依次输出mList2的元素：");
	LISTINT.OutputList(mList2);
	len = LISTINT.ListLength(mList2);
	printf("合并前：mList2.length=%d\n", len);
	LISTINT.unionL(&mList, mList2);

	printf("依次输出合并了mList2的mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList2);
	printf("合并后：mList.length=%d\n", len);

	LISTINT.ClearList(&mList);
	LISTINT.ClearList(&mList2);
	len = LISTINT.ListLength(mList);
	printf("头插前：mList.length=%d\n", LISTINT.ListLength(mList));
	printf("整体创建L的元素(头插法)：\n");
	LISTINT.CreateListHead(&mList, 20);
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	len = LISTINT.ListLength(mList);
	printf("头插后：mList.length=%d\n", LISTINT.ListLength(mList));

	LISTINT.ClearList(&mList);
	printf("\n删除mList后：ListLength(L)=%d\n", LISTINT.ListLength(mList));
	printf("整体创建L的元素(尾插法)：\n");
	LISTINT.CreateListTail(&mList, 20);
	printf("依次输出mList的元素：");
	LISTINT.OutputList(mList);
	printf("尾插后：mList.length=%d\n", LISTINT.ListLength(mList));

	return 0;
}

int Idebug()
{
	//..
	nList LISTINT;
	LinkList mList = {0,NULL};
	int len = 0;
	printf("初始化前单链表的内存：%d \n", sizeof(mList));
	//len = LISTINT.ListLength(mList);
	printf("初始化前：mList.length=%d\n", len);

	return 0;

}