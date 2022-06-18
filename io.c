#include "contact.h"

void print_con(pcon pCon)
{
	int i = 0;
	int more = 0;
	if (pCon->member == 0)
	{
		printf("╭ ─────────────────────── ╮\n");
		printf("│            空           │\n");
		printf("╰ ─────────────────────── ╯\n");
		return;
	}
#ifdef _SERIAL_
	//带序号
	printf(FR_UP2);
	printf(FORMAT2, "序号", "姓名", "性别", "年龄", "电话", "地址");
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
		printf("│\n");
	}
	printf(FR_DW2);
#else
	//不带序号
	printf(FR_UP);
	printf(FORMAT, "姓名", "年龄", "性别", "电话", "地址");
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
		printf("│\n");
	}
	printf(FR_DW);
#endif
	printf(" 共 %d 位联系人\n", pCon->member);
	if (more == 1)
	{
		printf("\n 当前仅展示 %d 位联系人\n", PRINT_MAX);
	}
} // print_con

void print_peo(info peo)
{
	printf(FR_UP);
	printf(FORMAT, "姓名", "性别", "年龄", "电话", "地址");
	printf(FR_MD);
	PRINT_MEM(peo.name, "%-12s");
	PRINT_MEM(peo.sex, "%-6s");
	PRINT_MEM(peo.age, "%-6s");
	PRINT_MEM(peo.tele, "%-12s");
	PRINT_MEM(peo.addr, "%-27s");
	printf("│\n");
	printf(FR_DW);
} // print_peo

int print_serial(pInfo* arr, int num)
{
	int i = 0;
	printf(FR_UP2);
	printf(FORMAT2, "序号", "姓名", "性别", "年龄", "电话", "地址");
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
		printf("│\n");
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
			//清空缓冲区
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
	printf("* 除姓名外，其他内容留空请输入0\n");
	//输入姓名
	if (name_input(pNew, pCon) == 0)
		return 0;
	//输入性别
	sex_input(pNew);
	//输入年龄
	age_input(pNew);
	//输入电话
	tele_input(pNew);
	//输入地址
	addr_input(pNew);

	return 1;
} // add_input

int name_input(pInfo pNew, const pcon pCon)
{
	//输入姓名
	char temp[NAME + 16];
	printf("\n输入姓名:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("\n姓名不能留空！\n");
		return 0;
	}
	//将超长的内容截断
	temp[NAME] = '\0';
	if (is_name_repetition(temp, pCon))
	{
		printf("\n联系人 %s 已存在！\n", temp);
		return 0;
	}
	CPY("姓名", pNew->name, NAME);
	return 1;
} // name_input

void sex_input(pInfo pNew)
{
	//输入性别
	char temp[SEX + 16];
	printf("\n输入性别:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("性别将留空。\n");
	}
	CPY("性别", pNew->sex, SEX);
} // sex_input

void age_input(pInfo pNew)
{
	//输入年龄
	char temp[SEX + 16];
	printf("\n输入年龄:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("年龄将留空。\n");
	}
	CPY("年龄", pNew->age, AGE);
} // age_input

void tele_input(pInfo pNew)
{
	//输入电话
	char temp[TELE + 16];
	printf("\n输入电话:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("电话将留空。\n");
	}
	CPY("电话", pNew->tele, TELE);
} // tele_input

void addr_input(pInfo pNew)
{
	//输入地址
	char temp[ADDR + 16];
	printf("\n输入地址:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("地址将留空。\n");
	}
	CPY("地址", pNew->addr, ADDR);
} // addr_input