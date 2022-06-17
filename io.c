#include "contact.h"

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
			PRINT_MEM(pCon->data[i].name, "%-12s");
			PRINT_MEM(pCon->data[i].sex, "%-6s");
			PRINT_MEM(pCon->data[i].age, "%-6s");
			PRINT_MEM(pCon->data[i].tele, "%-12s");
			PRINT_MEM(pCon->data[i].addr, "%-27s");
			printf("��\n");
		}
		printf(FR_DW);

	}
} // print_con

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
} // print_name

void print_peo(info peo)
{
	printf(FR_UP);
	printf(FORMAT, "����", "����", "�Ա�", "�绰", "��ַ");
	printf(FR_MD);
	PRINT_MEM(peo.name, "%-12s");
	PRINT_MEM(peo.sex, "%-6s");
	PRINT_MEM(peo.age, "%-6s");
	PRINT_MEM(peo.tele, "%-12s");
	PRINT_MEM(peo.addr, "%-27s");
	printf("��\n");
	printf(FR_DW);
} // print_peo

int is_zero(const char* str)
{
	if (str[0] == '0' && str[1] == '\0')
		return 1;
	else
		return 0;
} // is_zero

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
} // input_num

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
} // user_input

