#include "contact.h"

void pmenu()
{
	printf("  1.添加   2.删除   3.搜索\n");
	printf("  4.修改   5.排序   0.退出\n");
	printf("----------------------------\n");
} // pmenu

void add_error()
{
	printf("\n添加联系人失败。\n");
	printf("* 是否重新添加？\n");
	printf("------------------\n");
	printf(" 1.确定   0.取消\n\n");
} // add_error

void add_succeed(const pInfo pNew)
{
	printf("新建联系人成功。\n");
	PRINT_NEW(name, "%-12s", "姓名")
	PRINT_NEW(sex, "%-6s", "性别")
	PRINT_NEW(age, "%-6s", "年龄")
	PRINT_NEW(tele, "%-12s", "电话")
	PRINT_NEW(addr, "%-27s", "地址")
	printf("\n* 是否继续添加？\n");
	printf("-----------------\n");
	printf(" 1.确定   0.返回\n\n");
} // add_succeed

void blank()
{
	printf("当前通讯录为空。\n\n");
	printf("* 是否添加新的联系人？\n");
	printf("-----------------------\n");
	printf(" 1.添加   0.取消\n\n");
} // del_blank

void del_select()
{
	printf("\n选择要删除的联系人\n\n");
	printf("* 输入联系人的序号（0.取消）\n");
	printf("----------------------------\n");
} // del_select

int del_confirm(const info peo)
{
	CLS;
	print_peo(peo);
	printf("\n* 确定要删除该联系人吗？\n");
	printf("------------------------\n");
	printf(" 1.确定   0.取消\n\n");
	return input_num(1);
} // del_confirm

void serc_none()
{
	printf("\n未搜索到任何结果。\n\n");
	printf("* 是否重新搜索？\n");
	printf("-------------------\n");
	printf(" 1.确定   0.取消\n\n");
} // serc_none

void serc_found()
{
	printf("\n* 是否继续搜索？\n");
	printf("-------------------\n");
	printf(" 1.继续   0.返回\n\n");
}