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

	//�����ļ�ʧ��
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
		//����ʧ��
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
		printf(">> �½���ϵ��\n\n");
		//�û�������ϵ����Ϣ
		ret = user_input(&new, pCon);
		if (ret)
		{
			//�����ʽ��ȷ
			CLS;
			add_succeed(&new);
			//д���ļ���
			FILE* pf = file(0);
			fseek(pf, 0, SEEK_END);
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
}

int is_name_repetition(const char* name, const pcon pCon)
{
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		//���������Ƿ��Ѵ���
		if (strcmp(name, pCon->data[i].name) == 0)
			return 1;
	}
	return 0;
}

void del_con(pcon pCon)
{
	int select = -1;
	CLS;
	printf(">> ɾ����ϵ��\n\n");
	//ͨѶ¼Ϊ��ʱ
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
	//����д�뵽�ļ�
	to_file(pCon, select - 1);
	CLS;
}

void to_file(pcon pCon, int except)
{
	//�������±�Ϊexcept֮�����ϵ��д�뵽һ�����ļ���
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