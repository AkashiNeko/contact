#include "contact.h"

int main()
{
	option select;
	contact con;
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
			return 0;
		case ADD:
			add_con(&con);
			break;
		case DELETE:
			del_con(&con);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		default:
			printf("select error!\n\nre");
			break;
		}
	} while (1);
	return 0;
}