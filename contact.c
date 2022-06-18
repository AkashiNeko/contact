#include "contact.h"

void init_con(pcon pCon)
{
	//初始化通讯录
	int scf_ret;
	FILE* pf = file(0);
	printf("读取联系人信息中...\n");
	//如果存有上一次的数据
	if (pCon->data != NULL)
	{
		free(pCon->data);
		pCon->data = NULL;
	}
	//初始容量
	pCon->max = 4;
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
			break;
		//通讯录成员达到上限则扩容
		if (++pCon->member == pCon->max)
			check_max(pCon);
	} while (1);
	fclose(pf);
	CLS;
} // init_con

void add_con(pcon pCon)
{
	//添加联系人
	info new = { 0 };
	int ret = 0;
	int loop = 1;
	int select = 1;
	do
	{
		CLS;
		printf(">> 新建联系人\n\n");
		//用户输入联系人信息
		ret = add_input(&new, pCon);
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
	} while (input_num(1));
	CLS;
} // add_con

void del_con(pcon pCon)
{
	int select = -1;
	int ret;
	char str[32];
	char c;
	pInfo* arr = NULL;
	do
	{
		CLS;
		if (arr != NULL)
		{
			free(arr);
			arr = NULL;
		}
		printf(">> 删除联系人\n\n");
		//通讯录为空时
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* 输入要删除的联系人信息:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//清空缓冲区
		while ((c = getchar()) != EOF && c != '\n');
		//查找
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//只找到一个联系人
			if (ret == 1)
			{
				if (del_confirm(*arr[0]))
					//重新写入到文件
					to_file(pCon, arr[0]);
				break;
			}
			//找到多个联系人，用户选择修改对象
			int more = print_serial(arr, ret);
			printf("\n 匹配到 %d 个结果\n", ret);
			if (more)
				printf("\n 结果过多，仅展示以上 %d 位\n", SEARCH_MAX);
			del_select();
			select = input_num(ret);
			if (select == 0)
				break;
			//修改信息
			if (del_confirm(*arr[select - 1]))
				//重新写入到文件
				to_file(pCon, arr[select - 1]);
			break;
		}
		else
		{
			//找不到
			mdf_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // del_con

void serc_con(pcon pCon)
{
	//搜索联系人
	int ret;
	char str[32];
	char c;
	pInfo* arr = NULL;
	do
	{
		CLS;
		if (arr != NULL)
		{
			free(arr);
			arr = NULL;
		}
		printf(">> 搜索联系人\n\n");
		//通讯录为空时
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* 输入要搜索的内容:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//清空缓冲区
		while ((c = getchar()) != EOF && c != '\n');
		//查找
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//找到了
			int more = print_serial(arr, ret);
			printf("\n>> 关键词: %s\n\n", str);
			printf(" 共找到 %d 个结果\n", ret);
			if (more)
				printf("\n 结果过多，仅展示以上 %d 位\n", SEARCH_MAX);
			serc_found();
		}
		else
		{
			//找不到
			serc_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // serc_con

void mdf_con(pcon pCon)
{
	//修改联系人
	int ret;
	char str[32];
	char c;
	pInfo* arr = NULL;
	do
	{
		if (arr != NULL)
		{
			free(arr);
			arr = NULL;
		}
		int select;
		CLS;
		printf(">> 修改联系人\n\n");
		//通讯录为空时
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* 输入要修改的联系人信息:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//清空缓冲区
		while ((c = getchar()) != EOF && c != '\n');
		//查找
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//只找到一个联系人
			if (ret == 1)
			{
				modify(arr[0], pCon);
				break;
			}
			//找到多个联系人，用户选择修改对象
			int more = print_serial(arr, ret);
			printf("\n 匹配到 %d 个结果\n", ret);
			if(more)
				printf("\n 结果过多，仅展示以上 %d 位\n", SEARCH_MAX);
			mdf_found();
			select = input_num(ret);
			if (select == 0)
				break;
			//修改信息
			modify(arr[select - 1], pCon);
			break;
		}
		else
		{
			//找不到
			mdf_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // mdf_con

void sort_con(pcon pCon)
{
	//排序联系人
	int ret;
	char c;
	int select;
	int (*pf[5])(const pInfo, const pInfo) = {
		cmp_name, cmp_sex, cmp_age, cmp_tele, cmp_addr
	};
	CLS;
	printf(">> 排序联系人\n\n");
	//通讯录为空时
	if (is_blank(pCon))
	{
		CLS;
		return;
	}
	sort_sel();
	select = input_num(5);
	if (select == 0)
		return;
	printf("\n正在排序中...");
	qsort(pCon->data, pCon->member, sizeof(info), pf[select - 1]);
	to_file(pCon, NULL);
	CLS;
} // sort_con