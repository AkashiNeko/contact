#include "contact.h"

void check_max(pcon pCon)
{
	//扩容
	pCon->max += 3;
	pInfo ptr = (pInfo)realloc(pCon->data, pCon->max * sizeof(info));
	if (ptr == NULL)
	{
		//扩容失败
		CLS;
		perror("ERROR: realloc");
		exit(114514);
	}
	pCon->data = ptr;
} // check_max

void init_con(pcon pCon)
{
	//初始化通讯录
	int scf_ret;
	FILE* pf = file(0);
	//初始容量
	pCon->max = 5;
	//初始成员数
	pCon->member = 0;
	//开辟内存空间
	pCon->data = (info*)malloc(pCon->max * sizeof(info));
	if (pCon->data == NULL)
	{
		//开辟空间失败
		CLS;
		perror("ERROR: malloc");
		exit(114514);
	}
	//循环读文件中的内容
	do
	{
		scf_ret = fscanf(pf, "%s%s%s%s%s",
			pCon->data[pCon->member].name,
			pCon->data[pCon->member].sex,
			pCon->data[pCon->member].age,
			pCon->data[pCon->member].tele,
			pCon->data[pCon->member].addr
		);
		//读取到文件末尾
		if (scf_ret != 5)
		{
			break;
		}
		//通讯录成员达到上限则扩容
		if (++pCon->member == pCon->max)
			check_max(pCon);
	} while (1);
	fclose(pf);
} // init_con

void add_con(pcon pCon)
{
	//添加联系人
	info new = { 0 };
	int ret = 0;
	int loop = 1;
	int select = 1;
	while(1)
	{
		CLS;
		printf(">> 新建联系人\n\n");
		//用户输入联系人信息
		ret = user_input(&new, pCon);
		if (ret)
		{
			//输入格式正确
			CLS;
			add_succeed(&new);
			//写入文件中
			FILE* pf = file(2);
			fprintf(pf, "%s %s %s %s %s\n",
				new.name, new.sex, new.age, new.tele, new.addr
			);
			fclose(pf);
		}
		else
		{
			//输入格式错误
			add_error();
		}
		//选择是否重新输入
		select = input_num(1);
		switch (select)
		{
		case 1:
			continue;
		case 0:
			CLS;
			return;
		default:
			break;
		}
	}
} // add_con

int is_name_repetition(const char* name, const pcon pCon)
{
	//判断输入的姓名是否已存在
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		//查找姓名是否已存在
		if (strcmp(name, pCon->data[i].name) == 0)
			return 1;
	}
	return 0;
} // is_name_repetition

int is_blank(pcon pCon)
{
	if (pCon->member == 0)
	{
		blank();
		if (input_num(1))
			add_con(pCon);
		return 1;
	}	
	return 0;
}

void del_con(pcon pCon)
{
	//删除联系人
	int select = -1;
	CLS;
	printf(">> 删除联系人\n\n");
	//通讯录为空时
	if (is_blank(pCon))
	{
		CLS;
		return;
	}
	print_name(pCon);
	del_select();
	select = input_num(pCon->member);
	if (select == 0)
	{
		CLS;
		return;
	}
	//确认删除
	if (del_confirm(pCon->data[select - 1]))
		//重新写入到文件
		to_file(pCon, select - 1);
	CLS;
} // del_con

void serc_con(pcon pCon)
{
	//搜索联系人
	int i, count;
	char str[32];
	char c;
	do
	{
		int exist = 0;
		CLS;
		printf(">> 搜索联系人\n\n");
		//通讯录为空时
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("输入要搜索的内容:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//清空缓冲区
		while ((c = getchar()) != EOF && c != '\n');

		for (i = 0; i < pCon->member; i++)
		{
			if (
				strstr(pCon->data[i].name, str) != NULL ||
				strstr(pCon->data[i].sex, str) != NULL ||
				strstr(pCon->data[i].age, str) != NULL ||
				strstr(pCon->data[i].tele, str) != NULL ||
				strstr(pCon->data[i].addr, str) != NULL)
			{
				//找到了
				if (exist == 0)
				{
					printf(FR_UP);
					printf(FORMAT, "姓名", "年龄", "性别", "电话", "地址");
					printf(FR_MD);
				}
				exist++;
				PRINT_MEM(pCon->data[i].name, "%-12s");
				PRINT_MEM(pCon->data[i].sex, "%-6s");
				PRINT_MEM(pCon->data[i].age, "%-6s");
				PRINT_MEM(pCon->data[i].tele, "%-12s");
				PRINT_MEM(pCon->data[i].addr, "%-27s");
				printf("│\n");
			}
		}
		if (exist)
		{
			printf(FR_DW);
			printf("\n>> 关键词: %s\n\n", str);
			printf("共找到以上 %d 个结果\n", exist);
			serc_found();
		}
		else
		{
			serc_none();
		}
	} while (input_num(1));
	CLS;
}

void mdf_con(pcon pCon)
{

}