/*
 * =====================================================================================
 *
 *       Filename:  SqBiTree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2014 09:35:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#ifndef GIT_JCOMMON_STACK_H
#define GIT_JCOMMON_STACK_H

#define MAXTREESIZE 100
#define Nil '#'

typedef int ElemType;

typedef ElemType SqBiTree[MAXTREESIZE];

typedef struct
{
	int level,order; /* 结点的层,本层序号(按满二叉树计算) */
}Position;


void InitTree(SqBiTree tree);
void CreateTree(SqBiTree tree);
void DestoryTree(SqBiTree tree);
void ClearTree(SqBiTree tree);
int TreeEmpty(SqBiTree tree);
int TreeDepth(SqBiTree tree);
void Root(SqBiTree tree,ElemType *e);
ElemType Value(SqBiTree tree,Position e);
int Assign(SqBiTree tree,Position e,ElemType value);
ElemType Parent(SqBiTree tree,ElemType e);
ElemType LeftChild(SqBiTree tree,ElemType e);
ElemType RightChild(SqBiTree tree,ElemType e);
ElemType LeftSibling(SqBiTree tree,ElemType e);
ElemType RightSibling(SqBiTree tree,ElemType e);

void PreTraverse(SqBiTree T,int e);
void PreOrderTraverse(SqBiTree tree);
void LevelOrderTraverse(SqBiTree tree);


#endif
