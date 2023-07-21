// 引入所需的头文件。stdio.h用于输入/输出功能，string.h用于字符串操作。
#include <stdio.h>
#include <string.h>

// 定义一个宏，表示最大的联系人数量为100。
#define MAX_CONTACTS 100

// 使用typedef和struct定义一个名为Contact的结构体，表示一个联系人。
// 这个结构体包含了联系人的姓名、邮箱和电话。
typedef struct
{
    char name[50];
    char email[50];
    char phone[15];
} Contact;

// 定义一个包含MAX_CONTACTS个元素的Contact类型的数组contacts，用于存储所有的联系人。
Contact contacts[MAX_CONTACTS];

// 定义一个整数变量num_contacts，表示当前已有的联系人数量。初始化为0。
int num_contacts = 0;

// 主函数，程序的入口点。
int main(void){
    // 使用一个无限循环，使得用户可以不断地进行操作。
    while (1)
    {
        // 打印出用户可以进行的操作。
        printf("请输入操作：\n");
        printf("1. 添加联系人\n");
        printf("2. 显示所有联系人\n");
        printf("3. 查找联系人\n");
        printf("4. 退出\n");

        // 读取用户的选择。
        int choice;
        scanf("%d", &choice);

        // 如果用户选择添加联系人（choice等于1）。
        if (choice == 1)
        {
            // 如果当前联系人数量还未达到最大值。
            if (num_contacts < MAX_CONTACTS)
            {
                // 让用户输入新联系人的信息，并存储到contacts数组的下一个空位。
                printf("请输入联系人姓名：");
                scanf("%s", contacts[num_contacts].name);
                printf("请输入联系人邮箱：");
                scanf("%s", contacts[num_contacts].email);
                printf("请输入联系人电话：");
                scanf("%s", contacts[num_contacts].phone);

                // 联系人数量增加1。
                num_contacts++;
                printf("联系人添加成功\n");
            } else // 如果当前联系人数量已经达到最大值。
            {
                printf("地址簿已满，无法添加\n");
            }
        }
        // 如果用户选择显示所有联系人（choice等于2）。
        else if (choice == 2)
        {
            // 遍历contacts数组，打印出每一个联系人的信息。
            for (int i = 0; i < num_contacts; i++)
            {
                printf("姓名：%s\n", contacts[i].name);
                printf("邮箱：%s\n", contacts[i].email);
                printf("电话：%s\n", contacts[i].phone);
                printf("=======================\n");
            }
        }
        // 如果用户选择查找联系人（choice等于3）。
        else if (choice == 3)
        {
            // 让用户输入要查找的联系人的姓名。
            printf("请输入要查找的联系人姓名：\n");
            char name[50];
            scanf("%s", name);

            // 遍历contacts数组，找到与用户输入的姓名相同的联系人，并打印其信息。
            for (int i = 0; i < num_contacts; i++)
            {
                if (strcmp(contacts[i].name, name) == 0)
                {
                    printf("姓名：%s\n", contacts[i].name);
                    printf("邮箱：%s\n", contacts[i].email);
                    printf("电话：%s\n", contacts[i].phone);
                    break;
                }
            }
        }
        // 如果用户选择退出（choice等于4）。
        else if (choice == 4)
        {
            // 结束无限循环，退出程序。
            break;
        } else // 如果用户输入了非法的选择。
        {
            printf("输入错误，请重新输入\n");
        }
    }
    // 主函数返回0，表示程序正常结束。
    return 0;
}
