//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-16
//    author: Akashi (氟氟)
//    github: https://github.com/AkashiNeko/contact
//    Mail:   akashineko@qq.com / akashinekof@gmail.com
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "contact.h"

int main() {
    option select;
    contact con;
    con.data = NULL;
    // 用户选择
    do {
        // 初始化通讯录
        init_con(&con);
        // 打印所有联系人
        print_con(&con);
        // 打印菜单选项
        pmenu();
#ifdef _DEBUG_
        printf("\nmember: %d   max: %d\n\n", con.member, con.max);
#endif
        select = input_num(5);
        switch (select) {
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