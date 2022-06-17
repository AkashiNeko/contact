#include "contact.h"

void pmenu()
{
	printf("  1.���   2.ɾ��   3.����\n");
	printf("  4.�޸�   5.����   0.�˳�\n");
	printf("----------------------------\n");
}

void print_con(pcon pCon)
{
	int i = 0;
	if (pCon->member == 0)
	{
		printf("�q ���������������������������������������������� �r\n");
		printf("��            ��           ��\n");
		printf("�t ���������������������������������������������� �s\n");
	}
	else
	{
		printf(FR_UP);
		printf(FORMAT, "����", "����", "�Ա�", "�绰", "��ַ");
		printf(FR_MD);
		for (i = 0; i < pCon->member; i++)
		{
			PRINT_MEM(name, "%-12s");
			PRINT_MEM(sex, "%-6s");
			PRINT_MEM(age, "%-6s");
			PRINT_MEM(tele, "%-12s");
			PRINT_MEM(addr, "%-27s");
			printf("��\n");
		}
		printf(FR_DW);

	}
}

void print_name(pcon pCon)
{
	assert(pCon->member);
	int i = 0;
	printf("�������������Щ���������������\n");
	printf("�� %-4s�� %-6s��\n", "���", "����");
	printf("�������������੤��������������\n");
	for (i = 0; i < pCon->member; i++)
	{
		printf("�� %-4d�� %-6s��\n", i + 1, pCon->data[i].name);
	}
	printf("�������������ة���������������\n");

}

int is_zero(const char* str)
{
	if (str[0] == '0' && str[1] == '\0')
		return 1;
	else
		return 0;
}

int input_num(int max)
{
	int select = -1;
	char c;
	printf(" select:> ");
	while (1)
	{
		if (scanf("%d", &select) == 0)
		{
			//��ջ�����
			while ((c = getchar()) != EOF && c != '\n');
			printf("   select error!\n\n reselect:> ");
			continue;
		}
		if (select >= 0 && select <= max)
			return select;
		printf("   select error!\n\n reselect:> ");
	}
}

int user_input(pInfo pNew, const pcon pCon)
{
	char temp[64] = { 0 };
	int space = 0;
	printf("* �������⣬������������������0\n");

	printf("\n��������:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("\n�����������գ�\n");
		return 0;
	}
	//�����������ݽض�
	temp[NAME] = '\0';
	if (is_name_repetition(temp, pCon))
	{
		printf("\n��ϵ�� %s �Ѵ��ڣ�\n", temp);
		return 0;
	}
	CPY("����", name, NAME)


	printf("\n�����Ա�:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("�Ա����ա�\n");
	}
	CPY("�Ա�", sex, SEX)

	printf("\n��������:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("���佫���ա�\n");
	}
	CPY("����", age, AGE)

	printf("\n����绰:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("�绰�����ա�\n");
	}
	CPY("�绰", tele, TELE)

	printf("\n�����ַ:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("��ַ�����ա�\n");
	}
	CPY("��ַ", addr, ADDR)

	return 1;
}

void add_error()
{
	printf("\n�����ϵ��ʧ�ܡ�\n");
	printf("* �Ƿ�������ӣ�\n");
	printf("------------------\n");
	printf(" 1.ȷ��   0.ȡ��\n\n");
}

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
}

void del_blank()
{
	printf("��ǰͨѶ¼Ϊ�ա�\n\n");
	printf("* �Ƿ�����µ���ϵ�ˣ�\n");
	printf("-----------------------\n");
	printf(" 1.���   0.ȡ��\n\n");
}

void del_select()
{
	printf("\nѡ��Ҫɾ������ϵ��\n\n");
	printf("* ������ϵ�˵���ţ�0.ȡ����\n");
	printf("----------------------------\n");
}