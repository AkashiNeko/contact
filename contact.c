#include "contact.h"

void init_con(pcon pCon)
{
	//��ʼ��ͨѶ¼
	int scf_ret;
	FILE* pf = file(0);
	//���������һ�ε�����
	if (pCon->data != NULL)
	{
		free(pCon->data);
		pCon->data = NULL;
	}
	//��ʼ����
	pCon->max = 5;
	//��ʼ��Ա��
	pCon->member = 0;
	//�����ڴ�ռ�
	pCon->data = (info*)malloc(pCon->max * sizeof(info));
	if (pCon->data == NULL)
	{
		//���ٿռ�ʧ��
		CLS;
		perror("ERROR: malloc");
		exit(114514);
	}
	//ѭ�����ļ��е�����
	do
	{
		scf_ret = fscanf(pf, "%s%s%s%s%s",
			pCon->data[pCon->member].name,
			pCon->data[pCon->member].sex,
			pCon->data[pCon->member].age,
			pCon->data[pCon->member].tele,
			pCon->data[pCon->member].addr
		);
		//��ȡ���ļ�ĩβ
		if (scf_ret != 5)
		{
			break;
		}
		//ͨѶ¼��Ա�ﵽ����������
		if (++pCon->member == pCon->max)
			check_max(pCon);
	} while (1);
	fclose(pf);
} // init_con

void add_con(pcon pCon)
{
	//�����ϵ��
	info new = { 0 };
	int ret = 0;
	int loop = 1;
	int select = 1;
	while(1)
	{
		CLS;
		printf(">> �½���ϵ��\n\n");
		//�û�������ϵ����Ϣ
		ret = add_input(&new, pCon);
		if (ret)
		{
			//�����ʽ��ȷ
			CLS;
			add_succeed(&new);
			//д���ļ���
			FILE* pf = file(2);
			fprintf(pf, "%s %s %s %s %s\n",
				new.name, new.sex, new.age, new.tele, new.addr
			);
			fclose(pf);
		}
		else
		{
			//�����ʽ����
			add_error();
		}
		//ѡ���Ƿ���������
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
		printf(">> ɾ����ϵ��\n\n");
		//ͨѶ¼Ϊ��ʱ
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* ����Ҫɾ������ϵ����Ϣ:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//��ջ�����
		while ((c = getchar()) != EOF && c != '\n');
		//����
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//ֻ�ҵ�һ����ϵ��
			if (ret == 1)
			{
				if (del_confirm(*arr[0]))
					//����д�뵽�ļ�
					to_file(pCon, arr[0]);
				break;
			}
			//�ҵ������ϵ�ˣ��û�ѡ���޸Ķ���
			print_serial(arr, ret);
			printf("\nƥ�䵽���� %d �����\n", ret);
			del_select();
			select = input_num(ret);
			if (select == 0)
				break;
			//�޸���Ϣ
			if (del_confirm(*arr[select - 1]))
				//����д�뵽�ļ�
				to_file(pCon, arr[select - 1]);
			break;
		}
		else
		{
			//�Ҳ���
			mdf_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // del_con

void serc_con(pcon pCon)
{
	//������ϵ��
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
		printf(">> ������ϵ��\n\n");
		//ͨѶ¼Ϊ��ʱ
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* ����Ҫ����������:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//��ջ�����
		while ((c = getchar()) != EOF && c != '\n');
		//����
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//�ҵ���
			print_serial(arr, ret);
			printf("\n>> �ؼ���: %s\n\n", str);
			printf("���ҵ����� %d �����\n", ret);
			serc_found();
		}
		else
		{
			//�Ҳ���
			serc_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // serc_con

void mdf_con(pcon pCon)
{
	//�޸���ϵ��
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
		printf(">> �޸���ϵ��\n\n");
		//ͨѶ¼Ϊ��ʱ
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("* ����Ҫ�޸ĵ���ϵ����Ϣ:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//��ջ�����
		while ((c = getchar()) != EOF && c != '\n');
		//����
		ret = search(pCon, str, &arr);
		if (ret)
		{
			//ֻ�ҵ�һ����ϵ��
			if (ret == 1)
			{
				modify(arr[0], pCon);
				break;
			}
			//�ҵ������ϵ�ˣ��û�ѡ���޸Ķ���
			print_serial(arr, ret);
			printf("\nƥ�䵽���� %d �����\n", ret);
			mdf_found();
			select = input_num(ret);
			if (select == 0)
				break;
			//�޸���Ϣ
			modify(arr[select - 1], pCon);
			break;
		}
		else
		{
			//�Ҳ���
			mdf_none();
		}
	} while (input_num(1));
	free(arr);
	CLS;
} // mdf_con

void sort_con(pcon pCon)
{
	//������ϵ��
	int ret;
	char c;
	int select;
	int (*pf[5])(const pInfo, const pInfo) = {
		cmp_name, cmp_sex, cmp_age, cmp_tele, cmp_addr
	};
	CLS;
	printf(">> ������ϵ��\n\n");
	//ͨѶ¼Ϊ��ʱ
	if (is_blank(pCon))
	{
		CLS;
		return;
	}
	sort_sel();
	select = input_num(5);
	if (select == 0)
		return;
	qsort(pCon->data, pCon->member, sizeof(info), pf[select - 1]);
	to_file(pCon, NULL);
	CLS;
} // sort_con