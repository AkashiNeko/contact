#include "contact.h"

FILE* file(int mode)
{
	//读文件，返回文件指针
	// new:
	// 0 - 打开文件读写
	// 1 - 新建文件读写
	// 2 - 在末尾追加
	FILE* pf = NULL;
	switch (mode)
	{
	case 0:
		pf = fopen("contact.dat", "r+");
		if (pf != NULL)
			break;
		//如果文件不存在则新建
	case 1:
		pf = fopen("contact.dat", "w+");
		break;
	case 2:
		pf = fopen("contact.dat", "a");
		break;
	default:
		break;
	}

	//文件操作失败
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
	//将除了地址为except之外的联系人写入到一个新文件中
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