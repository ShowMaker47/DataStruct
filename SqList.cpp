﻿
// 线性表的顺序存储结构

#include <iostream>
#define MAXSIZE 20
typedef int ElemType;

struct LNode
{
    ElemType Data[MAXSIZE];
    int Last;
}; 
typedef struct LNode* List;

//初始化线性表 
List initList() {
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));//分配空间
    if (Ptrl) {
        Ptrl->Last = -1;//指向当前元素的指针
    }
    return Ptrl;
}
//根据元素查找，返回顺序
int findIdByElem(ElemType X, List Ptrl) {
    int i = 0;
    while (i <= Ptrl->Last && Ptrl->Data[i] != X)
        i++;
    if (i > Ptrl->Last) return -1;
    else {
        return i+1;
    }
}
//根据顺序查找，返回元素
ElemType findElemById(int i, List Ptrl) {
    if (Ptrl->Last == -1) {
        printf("empty");
        return NULL;
    }
    if (i<1 || i>Ptrl->Last + 1) {
        printf("位置不合法");
        return NULL;
    }
    return Ptrl->Data[i - 1];
}
//插入元素
void insertElem(ElemType X, int i, List Ptrl) {
    int j;
    if (Ptrl->Last == MAXSIZE - 1) {
        printf("full\n");
        return;
    }
    if (i<1 || i>Ptrl->Last + 2) {
        printf("位置不合法\n");
        return;
    }
    for (j = Ptrl->Last + 1; j >= i - 1; j--) {
        Ptrl->Data[j + 1] = Ptrl->Data[j];
    }
        Ptrl->Data[i - 1] = X;
        Ptrl->Last++;
        return;
    
}
//删除元素
void deleteElem(int i, List Ptrl) {
    int j;
    if (Ptrl->Last == - 1) {
        printf("empty");
        return;
    }
    if (i<1 || i>Ptrl->Last + 1) {
        printf("位置不合法");
        return;
    }
    for (j = i-1; j < Ptrl->Last; j++) 
        Ptrl->Data[j] = Ptrl->Data[j + 1];
        Ptrl->Last--;
        return;
    
}
//输出线性表序列
void printList(List Ptrl) {
    printf("线性表共有%d个元素\n", Ptrl->Last+1);
    for (int i = 0; i < Ptrl->Last+1; i++) {
        printf("第%d个元素的值为%d\n", i, Ptrl->Data[i]);
    }
}
int main()
{
    List p = initList();
    insertElem(1, 1, p);
    insertElem(2, 2, p);
    insertElem(3, 3, p);
    int k = findIdByElem(2, p);
    printf("%d\n",k);
    insertElem(4, 4, p);
    printList(p);
    deleteElem(2, p);
    printList(p);
    int m = findElemById(4, p);
    printf("%d",m);
}

