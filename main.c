#include "contact.h"

int main()
{
	option select;
	contact con;
	TITLE;
	//用户选择
	do
	{
		//初始化通讯录
		init_con(&con);
		//打印所有联系人
		print_con(&con);
		//打印菜单选项
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