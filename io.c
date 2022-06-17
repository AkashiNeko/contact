#include "contact.h"

void pmenu()
{
	printf("  1.添加   2.删除   3.搜索\n");
	printf("  4.修改   5.排序   0.退出\n");
	printf("----------------------------\n");
}

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
			PRINT_MEM(name, "%-12s");
			PRINT_MEM(sex, "%-6s");
			PRINT_MEM(age, "%-6s");
			PRINT_MEM(tele, "%-12s");
			PRINT_MEM(addr, "%-27s");
			printf("│\n");
		}
		printf(FR_DW);

	}
}

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
			//清空缓冲区
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
}

void add_error()
{
	printf("\n添加联系人失败。\n");
	printf("* 是否重新添加？\n");
	printf("------------------\n");
	printf(" 1.确定   0.取消\n\n");
}

void add_succeed(const pInfo pNew)
{
	printf("新建联系人成功。\n");
	PRINT_NEW(name, "%-12s", "姓名")
	PRINT_NEW(sex, "%-6s", "性别")
	PRINT_NEW(age, "%-6s", "年龄")
	PRINT_NEW(tele, "%-12s", "电话")
	PRINT_NEW(addr, "%-27s", "地址")
	printf("\n* 是否继续添加？\n");
	printf("-----------------\n");
	printf(" 1.确定   0.返回\n\n");
}

void del_blank()
{
	printf("当前通讯录为空。\n\n");
	printf("* 是否添加新的联系人？\n");
	printf("-----------------------\n");
	printf(" 1.添加   0.取消\n\n");
}

void del_select()
{
	printf("\n选择要删除的联系人\n\n");
	printf("* 输入联系人的序号（0.取消）\n");
	printf("----------------------------\n");
}