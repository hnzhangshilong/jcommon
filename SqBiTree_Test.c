/*
 * =====================================================================================
 *
 *       Filename:  SqBiTree_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2014 09:35:56 PM
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

int main()
{
	SqBiTree tree;
	InitTree(tree);
	CreateTree(tree);
	PreOrderTraverse(tree);
	printf("depth:%d\n",TreeDepth(tree));
	
	ElemType rootData;
	Root(tree,&rootData);
	printf("Root:%d\n",rootData);
	
	Position pos;
	pos.level = 3;
	pos.order = 2;
	printf("Value(3,2):%d\n",Value(tree,pos));
	
	ElemType tmpData = 37;
	pos.level = 5;
	pos.order = 1;
	Assign(tree,pos,tmpData);
	PreOrderTraverse(tree);
	printf("depth:%d\n",TreeDepth(tree));

	printf("parent:%d\n",Parent(tree,37));

	printf("leftChild:%d\n",LeftChild(tree,8));

	printf("leftChild:%d\n",RightChild(tree,8));

	printf("LeftSibling:%d\n",LeftSibling(tree,9));
	printf("LeftSibling:%d\n",RightSibling(tree,8));

	LevelOrderTraverse(tree);
	return 0;
}