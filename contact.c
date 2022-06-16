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
		//�����ļ�ʧ��
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
		//����ʧ��
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

void add_con(contact* pCon)
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
		ret = user_input(&new);
		if (ret)
		{
			FILE* pf = file();
			//�����ʽ��ȷ
			fseek(pf, 0, SEEK_END);
			//д���ļ���
			fprintf(pf, "%s %s %s %s %s\n",
				new.name, new.sex, new.age, new.tele, new.addr
			);
			fclose(pf);
			//��ʾ
			add_succeed();
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

void del_con(contact* pCon)
{
	int select = -1;
	CLS;
	printf(">> ɾ����ϵ��\n\n");
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