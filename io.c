#include "contact.h"

void print_con(pcon pCon)
{
	int i = 0;
	int more = 0;
	if (pCon->member == 0)
	{
		printf("�q ���������������������������������������������� �r\n");
		printf("��            ��           ��\n");
		printf("�t ���������������������������������������������� �s\n");
		return;
	}
#ifdef _SERIAL_
	//�����
	printf(FR_UP2);
	printf(FORMAT2, "���", "����", "�Ա�", "����", "�绰", "��ַ");
	printf(FR_MD2);
	for (i = 0; i < pCon->member; i++)
	{
		if (i == PRINT_MAX)
		{
			printf(FORMAT2, "...", "...", "...", "...", "...", "...");
			more = 1;
			break;
		}
		SERIAL(i + 1);
		PRINT_MEM(pCon->data[i].name, "%-12s");
		PRINT_MEM(pCon->data[i].sex, "%-6s");
		PRINT_MEM(pCon->data[i].age, "%-6s");
		PRINT_MEM(pCon->data[i].tele, "%-12s");
		PRINT_MEM(pCon->data[i].addr, "%-27s");
		printf("��\n");
	}
	printf(FR_DW2);
#else
	//�������
	printf(FR_UP);
	printf(FORMAT, "����", "����", "�Ա�", "�绰", "��ַ");
	printf(FR_MD);
	for (i = 0; i < pCon->member; i++)
	{
		if (i == PRINT_MAX)
		{
			printf(FORMAT, "...", "...", "...", "...", "...");
			more = 1;
			break;
		}
		PRINT_MEM(pCon->data[i].name, "%-12s");
		PRINT_MEM(pCon->data[i].sex, "%-6s");
		PRINT_MEM(pCon->data[i].age, "%-6s");
		PRINT_MEM(pCon->data[i].tele, "%-12s");
		PRINT_MEM(pCon->data[i].addr, "%-27s");
		printf("��\n");
	}
	printf(FR_DW);
#endif
	printf(" �� %d λ��ϵ��\n", pCon->member);
	if (more == 1)
	{
		printf("\n ��ǰ��չʾ %d λ��ϵ��\n", PRINT_MAX);
	}
} // print_con

void print_peo(info peo)
{
	printf(FR_UP);
	printf(FORMAT, "����", "�Ա�", "����", "�绰", "��ַ");
	printf(FR_MD);
	PRINT_MEM(peo.name, "%-12s");
	PRINT_MEM(peo.sex, "%-6s");
	PRINT_MEM(peo.age, "%-6s");
	PRINT_MEM(peo.tele, "%-12s");
	PRINT_MEM(peo.addr, "%-27s");
	printf("��\n");
	printf(FR_DW);
} // print_peo

int print_serial(pInfo* arr, int num)
{
	int i = 0;
	printf(FR_UP2);
	printf(FORMAT2, "���", "����", "�Ա�", "����", "�绰", "��ַ");
	printf(FR_MD2);
	for (i = 0; i < num; i++)
	{
		if (i == SEARCH_MAX)
		{
			printf(FORMAT2, "...", "...", "...", "...", "...", "...");
			printf(FR_DW2);
			return 1;
		}
		SERIAL(i + 1);
		PRINT_MEM(arr[i]->name, "%-12s");
		PRINT_MEM(arr[i]->sex, "%-6s");
		PRINT_MEM(arr[i]->age, "%-6s");
		PRINT_MEM(arr[i]->tele, "%-12s");
		PRINT_MEM(arr[i]->addr, "%-27s");
		printf("��\n");
	}
	printf(FR_DW2);
	return 0;
}

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

int add_input(pInfo pNew, const pcon pCon)
{
	char temp[64] = { 0 };
	int space = 0;
	printf("* �������⣬������������������0\n");
	//��������
	if (name_input(pNew, pCon) == 0)
		return 0;
	//�����Ա�
	sex_input(pNew);
	//��������
	age_input(pNew);
	//����绰
	tele_input(pNew);
	//�����ַ
	addr_input(pNew);

	return 1;
} // add_input

int name_input(pInfo pNew, const pcon pCon)
{
	//��������
	char temp[NAME + 16];
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
	CPY("����", pNew->name, NAME);
	return 1;
} // name_input

void sex_input(pInfo pNew)
{
	//�����Ա�
	char temp[SEX + 16];
	printf("\n�����Ա�:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("�Ա����ա�\n");
	}
	CPY("�Ա�", pNew->sex, SEX);
} // sex_input

void age_input(pInfo pNew)
{
	//��������
	char temp[SEX + 16];
	printf("\n��������:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("���佫���ա�\n");
	}
	CPY("����", pNew->age, AGE);
} // age_input

void tele_input(pInfo pNew)
{
	//����绰
	char temp[TELE + 16];
	printf("\n����绰:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("�绰�����ա�\n");
	}
	CPY("�绰", pNew->tele, TELE);
} // tele_input

void addr_input(pInfo pNew)
{
	//�����ַ
	char temp[ADDR + 16];
	printf("\n�����ַ:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("��ַ�����ա�\n");
	}
	CPY("��ַ", pNew->addr, ADDR);
} // addr_input