/*
 * =====================================================================================
 *
 *       Filename:  SqString_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 01:48:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#include "Public.h"
#include "SqString.h"

int main()
{
	String str1;
	StrAssign(str1,"zhangshilong");
	printString(str1);

	String str2;
	StrCopy(str2,str1);
	printString(str2);

	ClearString(str2);
	printString(str2);

	StrCopy(str2,str1);
	printString(str2);
	printf("%d\n",StrCompare(str1,str2));

	String str3;
	StrAssign(str3,"is");
	StrInsert(str2,str2[0]+1,str3);
	printString(str2);

	printf("%d\n",StrCompare(str1,str2));
	
	String str4;
	Concat(str4,str1,str3);
	printString(str4);

	String str5;
	SubString(str5,str4,11,4);
	printString(str5);

	String str6;
	StrAssign(str6,"shi");
	printf("%d\n",Index(str1,str6,1));

	StrDelete(str1,1,5);
	printString(str1);

	String str7;
	StrAssign(str7,"haha");
	Replace(str1,str6,str7);
	printString(str1);

	return 0;
}