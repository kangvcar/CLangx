#include <stdio.h>

int main(void)
{
    // 定义变量
    double num1, num2, result;
    char op;

    printf("请输入一个数字：");
    scanf("%lf", &num1); // 读取用户输入的第一个数字

    printf("请输入运算符(+ - * /)：");
    // 注意前面的空格，用于跳过之前输入结束后留下的换行符
    scanf(" %c", &op); // 读取用户输入的运算符

    printf("请输入第二个数字：");
    scanf("%lf", &num2); // 读取用户输入的第二个数字

    // 根据运算符计算结果
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("除数不能为0\n");
            return 1; // 当程序异常结束时，main函数应该返回1
        }
        result = num1 / num2;
        break;
    default:
        printf("运算符输入错误\n");
        break;
    }

    printf("结果是：%lf\n", result);
    printf("结果：%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
    return 0; // 当程序正常结束时，main函数应该返回0
}


