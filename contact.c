#include "contact.h"

FILE* file()
{
	FILE* pf = fopen("contact.dat", "r+");
	if (pf == NULL)
	{
		pf = fopen("contact.dat", "w+");
	}
	if (pf == NULL)
	{
		//创建文件失败
		CLS;
		perror("ERROR: open file \"contact.dat\"");
		exit(114514);
	}
	return pf;
}

void add(contact* con)
{
}

void check_max(contact* pCon)
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

void init_con(contact* pCon)
{
	int scf_ret;
	FILE* pf = file();
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

void add_con(contact* pCon)
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
		ret = user_input(&new);
		if (ret)
		{
			FILE* pf = file();
			//输入格式正确
			fseek(pf, 0, SEEK_END);
			//写入文件中
			fprintf(pf, "%s %s %s %s %s\n",
				new.name, new.sex, new.age, new.tele, new.addr
			);
			fclose(pf);
			//提示
			add_succeed();
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

void del_con(contact* pCon)
{
	int select = -1;
	CLS;
	printf(">> 删除联系人\n\n");
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
}