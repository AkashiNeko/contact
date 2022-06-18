#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//测试
//#define _DEBUG_

//主菜单表格带序号
//#define _SERIAL_

//清屏
#define CLS system("cls")

//标题
#define TITLE system("title 通讯录  -  By AkashiNeko")

//主菜单表格联系人数上限
#define PRINT_MAX 1000

//搜索联系人人数上限
#define SEARCH_MAX 9999

//打印联系人信息
#define PRINT_MEM(m, f) \
if(is_zero(m))\
	printf("│ "f, " ");\
else\
	printf("│ "f, m)

//序号
#define SERIAL(num) printf("│ %-4d", num)

//打印新建的联系人信息
#define PRINT_NEW(m, f, text) \
if(is_zero(pNew->m))\
	printf("\n"text": "f"\n", " ");\
else\
	printf("\n"text": "f"\n", pNew->m)

//成员信息输入过长
#define CPY(text, m, len) \
strncpy(m, temp, len - 1);\
if (strlen(temp) > strlen(m))\
	printf("\n"text"过长 (长度＞%d)\n* 将被保存为 %s\n", len - 1, m)

//格式
#define FORMAT "│ %-12s│ %-6s│ %-6s│ %-12s│ %-27s│\n"
//表格边框
#define FR_UP "┌─────────────┬───────┬───────┬─────────────┬────────────────────────────┐\n"
#define FR_MD "├─────────────┼───────┼───────┼─────────────┼────────────────────────────┤\n"
#define FR_DW "└─────────────┴───────┴───────┴─────────────┴────────────────────────────┘\n"

//格式（带序号）
#define FORMAT2 "│ %-4s│ %-12s│ %-6s│ %-6s│ %-12s│ %-27s│\n"
//表格边框（带序号）
#define FR_UP2 "┌─────┬─────────────┬───────┬───────┬─────────────┬────────────────────────────┐\n"
#define FR_MD2 "├─────┼─────────────┼───────┼───────┼─────────────┼────────────────────────────┤\n"
#define FR_DW2 "└─────┴─────────────┴───────┴───────┴─────────────┴────────────────────────────┘\n"

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

//重新写入到文件（除去 pInfo except）
void to_file(pcon pCon, pInfo except);

/********************* io.c 函数定义 *********************/

//打印所有联系人
void print_con(pcon pCon);

//打印单个成员表格
void print_peo(info peo);

//打印带序号的联系人列表
int print_serial(pInfo* arr, int num);

//判断字符串是否为"0"
int is_zero(const char* str);

//输入一个数字
int input_num(int max);

//用户输入联系人信息
int add_input(pInfo pNew, const pcon pCon);

//输入姓名
int name_input(pInfo pNew, const pcon pCon);

//输入性别
void sex_input(pInfo pNew);

//输入年龄
void age_input(pInfo pNew);

//输入电话
void tele_input(pInfo pNew);

//输入地址
void addr_input(pInfo pNew);

/******************** tips.c 函数定义 ********************/

//打印菜单
void pmenu();

//添加失败
void add_error();

//添加成功
void add_succeed(const pInfo pNew);

//空白通讯录
void blank();

//选择删除对象
void del_select();

//确认删除
int del_confirm(const info peo);

//搜索不到结果
void serc_none();

//找到了
void serc_found();

//修改联系人 - 搜索不到结果
void mdf_none();

//修改联系人 - 找到了
void mdf_found();

//修改联系人 - 选择要修改的信息
void mdf_sel();

/****************** contact.c 函数定义 *******************/

//初始化通讯录
void init_con(pcon pCon);

//添加联系人
void add_con(pcon pCon);

//删除联系人
void del_con(pcon pCon);

//搜索联系人
void serc_con(pcon pCon);

//修改联系人
void mdf_con(pcon pCon);

//排序联系人
void sort_con(pcon pCon);

/******************* subpro.c 函数定义 *******************/

//扩容
void check_max(pcon pCon);

//判断要添加的联系人是否已存在
int is_name_repetition(const char* name, const pcon pCon);

//通讯录为空
int is_blank(pcon pCon);

//通过关键词搜索
int search(pcon pCon, char* str, pInfo** pArr);

//修改信息
void modify(pInfo peo, const pcon pCon);

//排序 - 用于函数指针
int cmp_name(const pInfo a, const pInfo b);
int cmp_sex(const pInfo a, const pInfo b);
int cmp_age(const pInfo a, const pInfo b);
int cmp_tele(const pInfo a, const pInfo b);
int cmp_addr(const pInfo a, const pInfo b);

#endif