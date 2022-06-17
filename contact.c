#include "contact.h"

FILE* file(int new)
{
	FILE* pf = NULL;
	if (new)
	{
		pf = fopen("contact.dat", "w+");
	}
	else
	{
		pf = fopen("contact.dat", "r+");
		if (pf == NULL)
		{
			pf = fopen("contact.dat", "w+");
		}
	}

	//创建文件失败
	if (pf == NULL)
	{
		CLS;
		perror("ERROR: file \"contact.dat\"");
		exit(114514);
	}
	return pf;
}

void add(pcon con)
{
}

void check_max(pcon pCon)
{
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
}

void init_con(pcon pCon)
{
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
}

void add_con(pcon pCon)
{
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
			FILE* pf = file(0);
			fseek(pf, 0, SEEK_END);
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
}

int is_name_repetition(const char* name, const pcon pCon)
{
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		//查找姓名是否已存在
		if (strcmp(name, pCon->data[i].name) == 0)
			return 1;
	}
	return 0;
}

void del_con(pcon pCon)
{
	int select = -1;
	CLS;
	printf(">> 删除联系人\n\n");
	//通讯录为空时
	if (pCon->member == 0)
	{
		del_blank();
		select = input_num(1);
		switch (select)
		{
		case 1:
			add_con(pCon);
			return;
		case 0:
			CLS;
			return;
		default:
			break;
		}
	}
	print_name(pCon);
	del_select();
	select = input_num(pCon->member);
	if (select == 0)
	{
		CLS;
		return;
	}
	//重新写入到文件
	to_file(pCon, select - 1);
	CLS;
}

void to_file(pcon pCon, int except)
{
	//将除了下标为except之外的联系人写入到一个新文件中
	FILE* pf = file(1);
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		if (i == except)
			continue;
		fprintf(pf, "%s %s %s %s %s\n",
			pCon->data[i].name,
			pCon->data[i].sex,
			pCon->data[i].age,
			pCon->data[i].tele,
			pCon->data[i].addr
		);
	}
}