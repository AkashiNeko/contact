#include "contact.h"

void pmenu()
{
	printf("  1.���   2.ɾ��   3.����\n");
	printf("  4.�޸�   5.����   0.�˳�\n");
	printf("----------------------------\n");
} // pmenu

void add_error()
{
	printf("\n�����ϵ��ʧ�ܡ�\n");
	printf("* �Ƿ�������ӣ�\n");
	printf("------------------\n");
	printf(" 1.ȷ��   0.ȡ��\n\n");
} // add_error

void add_succeed(const pInfo pNew)
{
	printf("�½���ϵ�˳ɹ���\n");
	PRINT_NEW(name, "%-12s", "����")
	PRINT_NEW(sex, "%-6s", "�Ա�")
	PRINT_NEW(age, "%-6s", "����")
	PRINT_NEW(tele, "%-12s", "�绰")
	PRINT_NEW(addr, "%-27s", "��ַ")
	printf("\n* �Ƿ������ӣ�\n");
	printf("-----------------\n");
	printf(" 1.ȷ��   0.����\n\n");
} // add_succeed

void blank()
{
	printf("��ǰͨѶ¼Ϊ�ա�\n\n");
	printf("* �Ƿ�����µ���ϵ�ˣ�\n");
	printf("-----------------------\n");
	printf(" 1.���   0.ȡ��\n\n");
} // del_blank

void del_select()
{
	printf("\nѡ��Ҫɾ������ϵ��\n\n");
	printf("* ������ϵ�˵���ţ�0.ȡ����\n");
	printf("----------------------------\n");
} // del_select

int del_confirm(const info peo)
{
	CLS;
	print_peo(peo);
	printf("\n* ȷ��Ҫɾ������ϵ����\n");
	printf("------------------------\n");
	printf(" 1.ȷ��   0.ȡ��\n\n");
	return input_num(1);
} // del_confirm

void serc_none()
{
	printf("\nδ�������κν����\n\n");
	printf("* �Ƿ�����������\n");
	printf("-------------------\n");
	printf(" 1.ȷ��   0.ȡ��\n\n");
} // serc_none

void serc_found()
{
	printf("\n* �Ƿ����������\n");
	printf("-------------------\n");
	printf(" 1.����   0.����\n\n");
}