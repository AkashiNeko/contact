#include "contact.h"

FILE* file(int mode)
{
	//���ļ��������ļ�ָ��
	// new:
	// 0 - ���ļ���д
	// 1 - �½��ļ���д
	// 2 - ��ĩβ׷��
	FILE* pf = NULL;
	switch (mode)
	{
	case 0:
		pf = fopen("contact.dat", "r+");
		if (pf != NULL)
			break;
		//����ļ����������½�
	case 1:
		pf = fopen("contact.dat", "w+");
		break;
	case 2:
		pf = fopen("contact.dat", "a");
		break;
	default:
		break;
	}

	//�ļ�����ʧ��
	if (pf == NULL)
	{
		CLS;
		perror("ERROR: file \"contact.dat\"");
		exit(114514);
	}
	return pf;
} // file

void to_file(pcon pCon, pInfo except)
{
	//�����˵�ַΪexcept֮�����ϵ��д�뵽һ�����ļ���
	FILE* pf = file(1);
	int i = 0;
	for (i = 0; i < pCon->member; i++)
	{
		if (pCon->data + i == except)
			continue;
		fprintf(pf, "%s %s %s %s %s\n",
			pCon->data[i].name,
			pCon->data[i].sex,
			pCon->data[i].age,
			pCon->data[i].tele,
			pCon->data[i].addr
		);
	}
	fclose(pf);
} // to_file