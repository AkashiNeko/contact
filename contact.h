#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define _DEBUG_

//清屏
#define CLS system("cls")

//标题
#define TITLE system("title 通讯录  -  By AkashiNeko")

//打印联系人信息
#define PRINT_MEM(m, f) \
if(is_zero(pCon->data[i].m))\
	printf("│ "f, " ");\
else\
	printf("│ "f, pCon->data[i].m);

//成员信息输入过长
#define CPY(text, m, len) \
strncpy(pNew->m, temp, len - 1);\
if (strlen(temp) > strlen(pNew->m))\
	printf("\n"text"过长 (长度＞%d)\n* 将被保存为 %s\n", len - 1, pNew->m);

#define FORMAT "│ %-12s│ %-6s│ %-6s│ %-12s│ %-27s│\n"

//表格边框
#define FR_UP "┌─────────────┬───────┬───────┬─────────────┬────────────────────────────┐\n"
#define FR_MD "├─────────────┼───────┼───────┼─────────────┼────────────────────────────┤\n"
#define FR_DW "└─────────────┴───────┴───────┴─────────────┴────────────────────────────┘\n"

enum max
{
	NAME = 13,
	SEX = 7,
	AGE = 7,
	TELE = 13,
	ADDR = 28,
};
    
typedef enum options
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SORT,
}option;

typedef struct Info
{
	char name[NAME];
	char sex[SEX];
	char age[AGE];
	char tele[TELE];
	char addr[ADDR];
} info, * pInfo;

typedef struct con
{
	pInfo data;
	int member;
	int max;
}contact;

/********************* io.c 函数定义 *********************/

//打印菜单
void pmenu();

//打印所有联系人
void print_con(contact* pCon);

//判断字符串是否为"0"
int is_zero(const char* str);

//输入一个数字
int input_num(int max);

//用户输入联系人信息
int user_input(pInfo pNew);

//添加失败
void add_error();

//添加成功
void add_succeed();

//删除空白通讯录
void del_blank();

/****************** contact.c 函数定义 *******************/

//读文件
FILE* file();

//扩容
void check_max(contact* pCon);

//初始化通讯录
void init_con(contact* pCon);

//添加联系人
void add_con(contact* pCon);

//删除联系人
void del_con(contact* pCon);

#endif