#include "contact.h"

void check_max(pcon pCon)
{
	//扩容
	pCon->max *= 2;
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
} // is_blank

int search(pcon pCon, char* str, pInfo** pArr)
{
	int i;
	int index = 0;
	int arr_max = 4;
	int exist = 0;
	*pArr = (pInfo*)malloc(arr_max * sizeof(pInfo*));
	if (*pArr == NULL)
	{
		CLS;
		perror("search: malloc");
		exit(114514);
	}
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
			exist++;
			(*pArr)[index] = &(pCon->data[i]);
			if (++index == arr_max)
			{
				arr_max *= 2;
				pInfo* temp = (pInfo*)realloc(*pArr, arr_max * sizeof(pInfo*));
				if (temp == NULL)
				{
					CLS;
					perror("search: realloc");
					exit(114514);
				}
				*pArr = temp;
			}
		}
	}
	return exist;
} // search

void modify(pInfo peo, const pcon pCon)
{
	void (*pf[4])(pInfo) = {
		sex_input,
		age_input,
		tele_input,
		addr_input
	};
	int ret;
	int nam_ret = 1;
	do
	{
		CLS;
		print_peo(*peo);
		mdf_sel();
		if (nam_ret == 0)
		{
			printf("姓名修改失败。\n");
			printf("请检查输入是否已经存在或留空\n\n");
		}
		nam_ret = 1;
		ret = input_num(5);
		if (ret == 0)
			//写入到文件
			to_file(pCon, NULL);
		else if (ret == 1)
			nam_ret = name_input(peo, pCon);
		else
			pf[ret - 2](peo);
	} while (ret);
} // modify

int cmp_name(const pInfo a, const pInfo b)
{
	return strcmp(a->name, b->name);
} // cmp_name

int cmp_sex(const pInfo a, const pInfo b)
{
	return strcmp(a->sex, b->sex);
} // cmp_sex

int cmp_age(const pInfo a, const pInfo b)
{
	return strcmp(a->age, b->age);
} // cmp_age

int cmp_tele(const pInfo a, const pInfo b)
{
	return strcmp(a->tele, b->tele);
} // cmp_tele

int cmp_addr(const pInfo a, const pInfo b)
{
	return strcmp(a->addr, b->addr);
} // cmp_addr
