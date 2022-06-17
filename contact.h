#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _DEBUG_

//����
#define CLS system("cls")

//����
#define TITLE system("title ͨѶ¼  -  By AkashiNeko")

//��ӡ��ϵ����Ϣ
#define PRINT_MEM(m, f) \
if(is_zero(m))\
	printf("�� "f, " ");\
else\
	printf("�� "f, m);

#define PRINT_NEW(m, f, text) \
if(is_zero(pNew->m))\
	printf("\n"text": "f"\n", " ");\
else\
	printf("\n"text": "f"\n", pNew->m);

//��Ա��Ϣ�������
#define CPY(text, m, len) \
strncpy(pNew->m, temp, len - 1);\
if (strlen(temp) > strlen(pNew->m))\
	printf("\n"text"���� (���ȣ�%d)\n* ��������Ϊ %s\n", len - 1, pNew->m);

#define FORMAT "�� %-12s�� %-6s�� %-6s�� %-12s�� %-27s��\n"

//���߿�
#define FR_UP "�����������������������������Щ��������������Щ��������������Щ��������������������������Щ���������������������������������������������������������\n"
#define FR_MD "�����������������������������੤�������������੤�������������੤�������������������������੤��������������������������������������������������������\n"
#define FR_DW "�����������������������������ة��������������ة��������������ة��������������������������ة���������������������������������������������������������\n"

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

/******************** file.c �������� ********************/

//���ļ�
FILE* file(int mode);

//����д�뵽�ļ�
void to_file(pcon pCon, int except);

/********************* io.c �������� *********************/

//��ӡ������ϵ��
void print_con(pcon pCon);

//��ӡ������ϵ�˵����֣�����ţ�
void print_name(pcon pCon);

//��ӡ������Ա���
void print_peo(info peo);

//�ж��ַ����Ƿ�Ϊ"0"
int is_zero(const char* str);

//����һ������
int input_num(int max);

//�û�������ϵ����Ϣ
int user_input(pInfo pNew, const pcon pCon);

/******************** tips.c �������� ********************/

//��ӡ�˵�
void pmenu();

//���ʧ��
void add_error();

//��ӳɹ�
void add_succeed(const pInfo pNew);

//ɾ���հ�ͨѶ¼
void blank();

//ѡ��ɾ������
void del_select();

//ȷ��ɾ��
int del_confirm(const info peo);

//�����������
void serc_none();

//�ҵ���
void serc_found();

/****************** contact.c �������� *******************/

//����
void check_max(pcon pCon);

//��ʼ��ͨѶ¼
void init_con(pcon pCon);

//�����ϵ��
void add_con(pcon pCon);

//�ж�Ҫ��ӵ���ϵ���Ƿ��Ѵ���
int is_name_repetition(const char* name, const pcon pCon);

//ͨѶ¼Ϊ��
int is_blank(pcon pCon);

//ɾ����ϵ��
void del_con(pcon pCon);

//������ϵ��
void serc_con(pcon pCon);

//�޸���ϵ��
void mdf_con(pcon pCon);

#endif