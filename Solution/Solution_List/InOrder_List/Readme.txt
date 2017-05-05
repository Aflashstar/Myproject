
ADT 线性表（LIST）

Data
	线性表的数据对象集合为{a1,a2,...,an},每个元素的类型均为DataType. 其中，除第一个元素a1外，每一个元素有且只有一个直接前驱元素，
除了最后一个元素外，每一个元素有且只有一个后继元素。数据元素之间的关系是一对一的关系。

Operation
	InitList(*L):			初始化操作,建立一个空的线性表L.
	ListEmpty(L):			若线性表为空,则返回true,否则返回false.
	ClearList(*L):			将线性表清空.
	GetElem(L,i,*e):		将线性表中的第i个元素返回给e.
	LocateElem(L,e):		在线性表中查找与给定值e相等的元素,如果查找成功，返回该元素在表中序号表示成功;否则,返回0表示失败.
	ListInsert(*L,i,e):		在线性表L中的第i个位置插入新元素e.
	ListDelete(*L,i,*e):	删除线性表中的第i个元素,并用e返回其值.
	ListLength(L):			返回线性表L的元素个数.

function
	unionL(*L,L);			将所有的在线性表2中但不在线性表1中的数据元素插入到1中.
endADT