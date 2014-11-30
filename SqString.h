/*
 * =====================================================================================
 *
 *       Filename:  SqString.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 01:48:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#ifndef GIT_JCOMMON_SQSTRING_H
#define GIT_JCOMMON_SQSTRING_H

#define MAXSIZE 200

typedef char String[MAXSIZE+1];//第0个位置存放串的长度

int StrAssign(String t,char *chars);
void StrCopy(String t,String s);
void ClearString(String t);
void StringEmpty(String t);
int StrLength(String t);
int StrCompare(String t,String s);
int Concat(String t,String s1,String s2);
int SubString(String sub,String t,int pos,int len);
int Index(String t,String sub,int pos);
void Replace(String t,String s,String v);
int StrInsert(String t,int pos,String s);
int StrDelete(String t,int pos,int len);

void printString(String str);



#endif