#include "contact.h"

void check_max(pcon pCon)
{
	//����
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
} // check_max

void init_con(pcon pCon)
{
	//��ʼ��ͨѶ¼
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
		ret = user_input(&new, pCon);
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

int is_name_repetition(const char* name, const pcon pCon)
{
	//�ж�����������Ƿ��Ѵ���
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		//���������Ƿ��Ѵ���
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
	//ɾ����ϵ��
	int select = -1;
	CLS;
	printf(">> ɾ����ϵ��\n\n");
	//ͨѶ¼Ϊ��ʱ
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
	//ȷ��ɾ��
	if (del_confirm(pCon->data[select - 1]))
		//����д�뵽�ļ�
		to_file(pCon, select - 1);
	CLS;
} // del_con

void serc_con(pcon pCon)
{
	//������ϵ��
	int i, count;
	char str[32];
	char c;
	do
	{
		int exist = 0;
		CLS;
		printf(">> ������ϵ��\n\n");
		//ͨѶ¼Ϊ��ʱ
		if (is_blank(pCon))
		{
			CLS;
			return;
		}
		printf("����Ҫ����������:> ");
		scanf("%s", str);
		str[ADDR - 1] = '\0';
		//��ջ�����
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
				//�ҵ���
				if (exist == 0)
				{
					printf(FR_UP);
					printf(FORMAT, "����", "����", "�Ա�", "�绰", "��ַ");
					printf(FR_MD);
				}
				exist++;
				PRINT_MEM(pCon->data[i].name, "%-12s");
				PRINT_MEM(pCon->data[i].sex, "%-6s");
				PRINT_MEM(pCon->data[i].age, "%-6s");
				PRINT_MEM(pCon->data[i].tele, "%-12s");
				PRINT_MEM(pCon->data[i].addr, "%-27s");
				printf("��\n");
			}
		}
		if (exist)
		{
			printf(FR_DW);
			printf("\n>> �ؼ���: %s\n\n", str);
			printf("���ҵ����� %d �����\n", exist);
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