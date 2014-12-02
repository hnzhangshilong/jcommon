/*
 * =====================================================================================
 *
 *       Filename:  SqBiTree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2014 09:35:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#include "Public.h"
#include "SqBiTree.h"

void InitTree(SqBiTree tree)
{
	for(int i=0;i<MAXTREESIZE;++i)
		tree[i] = Nil;
}

void CreateTree(SqBiTree tree)
{
	int i=0;
	while(i<10)
	{
		tree[i]=i+1;
		
		if(i!=0&&tree[(i+1)/2-1]==Nil&&tree[i]!=Nil) /* 此结点(不空)无双亲且不是根 */
		{
			printf("出现无双亲的非根结点%d\n",tree[i]);
			exit(ERROR);
		}
		i++;
	}
	while(i<MAXTREESIZE)
	{
		tree[i]=Nil; /* 将空赋值给T的后面的结点 */
		i++;
	}
}

void DestoryTree(SqBiTree tree)
{
	InitTree(tree);
}

void ClearTree(SqBiTree tree)
{
	InitTree(tree);
}

int TreeEmpty(SqBiTree tree)
{
	return tree[0] == Nil;
}

//完全二叉树的特性4
int TreeDepth(SqBiTree tree)
{
	int i;
	if(TreeEmpty(tree))
		return 0;
	for(i=MAXTREESIZE-1;i>=0;--i){
		if(tree[i] != Nil)
			break;
	}
	return (int)log2(i+1)+1;
}

void Root(SqBiTree tree,ElemType *e)
{
	assert(e);
	*e = tree[0];
}

//第i层，第一个结点的坐标是2的i-1次方减去1
ElemType Value(SqBiTree tree,Position e)
{
	return tree[(int)powl(2,e.level-1)-1 + e.order-1];
}

int Assign(SqBiTree T,Position e,ElemType value)
{
	int i=(int)powl(2,e.level-1)+e.order-2; /* 将层、本层序号转为矩阵的序号 */
	if(value!=Nil&&T[(i+1)/2-1]==Nil) /* 给叶子赋非空值但双亲为空 */
		return ERROR;
	else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil)) /*  给双亲赋空值但有叶子（不空） */
		return ERROR;
	T[i]=value;
	return SUCCESS;
}
ElemType Parent(SqBiTree T,ElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return Nil;
	for(i=1;i<=MAXTREESIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[(i+1)/2-1];
	return Nil; /* 没找到e */
}

ElemType LeftChild(SqBiTree T,ElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return Nil;
	for(i=0;i<=MAXTREESIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+1];
	return Nil; /* 没找到e */
}

ElemType RightChild(SqBiTree T,ElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return Nil;
	for(i=0;i<=MAXTREESIZE-1;i++)
		if(T[i]==e) /* 找到e */
			return T[i*2+2];
	return Nil; /* 没找到e */
}

ElemType LeftSibling(SqBiTree T,ElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return Nil;
	for(i=1;i<=MAXTREESIZE-1;i++)
		if(T[i]==e&&i%2==0) /* 找到e且其序号为偶数(是右孩子) */
			return T[i-1];
	return Nil; /* 没找到e */
}

ElemType RightSibling(SqBiTree T,ElemType e)
{
	int i;
	if(T[0]==Nil) /* 空树 */
		return Nil;
	for(i=1;i<=MAXTREESIZE-1;i++)
		if(T[i]==e&&i%2) /* 找到e且其序号为奇数(是左孩子) */
			return T[i+1];
	return Nil; /* 没找到e */
}

/* PreOrderTraverse()调用 */
void PreTraverse(SqBiTree T,int e)
{ 
	printf("%d ",T[e]);
	if(T[2*e+1]!=Nil) /* 左子树不空 */
		PreTraverse(T,2*e+1);
	else
		printf("# ");
	if(T[2*e+2]!=Nil) /* 右子树不空 */
		PreTraverse(T,2*e+2);
	else
		printf("# ");
}

/* 初始条件: 二叉树存在 */
/* 操作结果: 先序遍历T。 */
void PreOrderTraverse(SqBiTree T)
{ 
	if(!TreeEmpty(T)) /* 树不空 */
	 PreTraverse(T,0);
	printf("\n");
}

/* 层序遍历二叉树 */
void LevelOrderTraverse(SqBiTree T)
{ 
	int i=MAXTREESIZE-1,j;
	while(T[i]==Nil)
		i--; /* 找到最后一个非空结点的序号 */
	for(j=0;j<=i;j++)  /* 从根结点起,按层序遍历二叉树 */
		if(T[j]!=Nil)
			printf("%d ",T[j]); /* 只遍历非空的结点 */
		else
			printf("# ");
	printf("\n");
}