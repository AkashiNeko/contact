#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _DEBUG_

//清屏
#define CLS system("cls")

//标题
#define TITLE system("title 通讯录  -  By AkashiNeko")

//打印联系人信息
#define PRINT_MEM(m, f) \
if(is_zero(m))\
	printf("│ "f, " ");\
else\
	printf("│ "f, m);

#define PRINT_NEW(m, f, text) \
if(is_zero(pNew->m))\
	printf("\n"text": "f"\n", " ");\
else\
	printf("\n"text": "f"\n", pNew->m);

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
}contact, * pcon;

/******************** file.c 函数定义 ********************/

//读文件
FILE* file(int mode);

//重新写入到文件
void to_file(pcon pCon, int except);

/********************* io.c 函数定义 *********************/

//打印所有联系人
void print_con(pcon pCon);

//打印所有联系人的名字（带序号）
void print_name(pcon pCon);

//打印单个成员表格
void print_peo(info peo);

//判断字符串是否为"0"
int is_zero(const char* str);

//输入一个数字
int input_num(int max);

//用户输入联系人信息
int user_input(pInfo pNew, const pcon pCon);

/******************** tips.c 函数定义 ********************/

//打印菜单
void pmenu();

//添加失败
void add_error();

//添加成功
void add_succeed(const pInfo pNew);

//删除空白通讯录
void blank();

//选择删除对象
void del_select();

//确认删除
int del_confirm(const info peo);

//搜索不到结果
void serc_none();

//找到了
void serc_found();

/****************** contact.c 函数定义 *******************/

//扩容
void check_max(pcon pCon);

//初始化通讯录
void init_con(pcon pCon);

//添加联系人
void add_con(pcon pCon);

//判断要添加的联系人是否已存在
int is_name_repetition(const char* name, const pcon pCon);

//通讯录为空
int is_blank(pcon pCon);

//删除联系人
void del_con(pcon pCon);

//搜索联系人
void serc_con(pcon pCon);

//修改联系人
void mdf_con(pcon pCon);

#endif