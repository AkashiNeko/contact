#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define _DEBUG_

//����
#define CLS system("cls")

//����
#define TITLE system("title ͨѶ¼  -  By AkashiNeko")

//��ӡ��ϵ����Ϣ
#define PRINT_MEM(m, f) \
if(is_zero(pCon->data[i].m))\
	printf("�� "f, " ");\
else\
	printf("�� "f, pCon->data[i].m);

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
}contact;

/********************* io.c �������� *********************/

//��ӡ�˵�
void pmenu();

//��ӡ������ϵ��
void print_con(contact* pCon);

//�ж��ַ����Ƿ�Ϊ"0"
int is_zero(const char* str);

//����һ������
int input_num(int max);

//�û�������ϵ����Ϣ
int user_input(pInfo pNew);

//���ʧ��
void add_error();

//��ӳɹ�
void add_succeed();

//ɾ���հ�ͨѶ¼
void del_blank();

/****************** contact.c �������� *******************/

//���ļ�
FILE* file();

//����
void check_max(contact* pCon);

//��ʼ��ͨѶ¼
void init_con(contact* pCon);

//�����ϵ��
void add_con(contact* pCon);

//ɾ����ϵ��
void del_con(contact* pCon);

#endif