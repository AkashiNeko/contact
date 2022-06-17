#include "contact.h"

void print_con(pcon pCon)
{
	int i = 0;
	if (pCon->member == 0)
	{
		printf("╭ ─────────────────────── ╮\n");
		printf("│            空           │\n");
		printf("╰ ─────────────────────── ╯\n");
	}
	else
	{
		printf(FR_UP);
		printf(FORMAT, "姓名", "年龄", "性别", "电话", "地址");
		printf(FR_MD);
		for (i = 0; i < pCon->member; i++)
		{
			PRINT_MEM(pCon->data[i].name, "%-12s");
			PRINT_MEM(pCon->data[i].sex, "%-6s");
			PRINT_MEM(pCon->data[i].age, "%-6s");
			PRINT_MEM(pCon->data[i].tele, "%-12s");
			PRINT_MEM(pCon->data[i].addr, "%-27s");
			printf("│\n");
		}
		printf(FR_DW);

	}
} // print_con

void print_name(pcon pCon)
{
	assert(pCon->member);
	int i = 0;
	printf("┌─────┬───────┐\n");
	printf("│ %-4s│ %-6s│\n", "序号", "姓名");
	printf("├─────┼───────┤\n");
	for (i = 0; i < pCon->member; i++)
	{
		printf("│ %-4d│ %-6s│\n", i + 1, pCon->data[i].name);
	}
	printf("└─────┴───────┘\n");
} // print_name

void print_peo(info peo)
{
	printf(FR_UP);
	printf(FORMAT, "姓名", "年龄", "性别", "电话", "地址");
	printf(FR_MD);
	PRINT_MEM(peo.name, "%-12s");
	PRINT_MEM(peo.sex, "%-6s");
	PRINT_MEM(peo.age, "%-6s");
	PRINT_MEM(peo.tele, "%-12s");
	PRINT_MEM(peo.addr, "%-27s");
	printf("│\n");
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

int user_input(pInfo pNew, const pcon pCon)
{
	char temp[64] = { 0 };
	int space = 0;
	printf("* 除姓名外，其他内容留空请输入0\n");

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
	CPY("姓名", name, NAME)

	printf("\n输入性别:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("性别将留空。\n");
	}
	CPY("性别", sex, SEX)

	printf("\n输入年龄:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("年龄将留空。\n");
	}
	CPY("年龄", age, AGE)

	printf("\n输入电话:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("电话将留空。\n");
	}
	CPY("电话", tele, TELE)

	printf("\n输入地址:> ");
	scanf("%s", temp);
	if (is_zero(temp))
	{
		printf("地址将留空。\n");
	}
	CPY("地址", addr, ADDR)

	return 1;
} // user_input

