//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-16
//    author: Akashi (����)
//    github: https://github.com/AkashiNeko/contact
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "contact.h"

int main()
{
	option select;
	contact con;
	con.data = NULL;
	TITLE;
	//�û�ѡ��
	do
	{
		//��ʼ��ͨѶ¼
		init_con(&con);
		//��ӡ������ϵ��
		print_con(&con);
		//��ӡ�˵�ѡ��
		pmenu();
#ifdef _DEBUG_
		printf("\nmember: %d   max: %d\n\n", con.member, con.max);
#endif
		select = input_num(5);
		switch (select)
		{
		case EXIT:
			CLS;
			free(con.data);
			return 0;
		case ADD:
			add_con(&con);
			break;
		case DELETE:
			del_con(&con);
			break;
		case SEARCH:
			serc_con(&con);
			break;
		case MODIFY:
			mdf_con(&con);
			break;
		case SORT:
			sort_con(&con);
			break;
		default:
			break;
		}
	} while (1);
	return 0;
}