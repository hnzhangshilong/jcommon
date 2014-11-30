/*
 * =====================================================================================
 *
 *       Filename:  SqString.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 01:48:46 PM
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

int StrAssign(String t,char *chars)
{
	assert(chars);
	size_t inputLen = strlen(chars);
	if(inputLen > MAXSIZE)
		return ERROR;
	t[0] = inputLen;
	memcpy(t+1,chars,inputLen);
	return SUCCESS;
}

void StrCopy(String t,String s)
{
	t[0] = s[0];
	memcpy(t+1,s+1,s[0]);
}

void ClearString(String t)
{
	t[0] = 0;
}

void StringEmpty(String t)
{
	t[0] = 0;
}

int StrLength(String t)
{
	return t[0];
}

int StrCompare(String t,String s)
{
	int minLen = min(t[0],s[0]);
	for(int i=0;i<minLen;++i){
		if(t[i] != s[i])
			return t[i]-s[i]>0?1:-1;
	}
	return t[0]-s[0]!=0?(t[0]-s[0]>0?1:-1):0;
}

int Concat(String t,String s1,String s2)
{
	if(s1[0] + s2[0] > MAXSIZE)
		return ERROR;
	t[0] = s1[0] + s2[0];
	memcpy(t+1,s1+1,s1[0]);
	memcpy(t+1+s1[0],s2+1,s2[0]);
	return SUCCESS;
}

int SubString(String sub,String t,int pos,int len)
{
	if(pos-1+len>t[0] || pos<1)
		return ERROR;
	sub[0] = len;
	for(int i=0;i<len;++i)
		sub[i+1] = t[pos++];
	return SUCCESS;
}

int Index(String t,String sub,int pos)
{
	if(sub[0]+pos > t[0]+1)
		return -1;
	String tmpStr;
	for(int i=pos;i<=t[0]-sub[0]+1;++i){
		SubString(tmpStr,t,i,sub[0]);
		if(StrCompare(sub,tmpStr)==0)
			return i;
	}
	return -1;
}

void Replace(String t,String s,String v)
{
	int pos = 1;
	while((pos=Index(t,s,pos))!=-1){
		StrDelete(t,pos,s[0]);
		StrInsert(t,pos,v);
		pos += v[0]; 
	}
}

int StrInsert(String t,int pos,String s)
{
	if(pos<1 || pos>t[0]+1 || t[0]+s[0]>MAXSIZE)
		return ERROR;
	memmove(t+pos+s[0],t+pos,t[0]-pos+1);
	memcpy(t+pos,s+1,s[0]);
	t[0] += s[0];
	return SUCCESS;
}

int StrDelete(String t,int pos,int len)
{
	if(pos<1 || pos+len>t[0])
		return ERROR;
	memmove(t+pos,t+pos+len,t[0]-pos-len+1);
	t[0] -= len;
	return SUCCESS;
}

void printString(String str)
{
	printf("len:%d,data:",str[0]);
	for(int i=1;i<=str[0];++i)
		printf("%c",str[i]);
	printf("\n");
}