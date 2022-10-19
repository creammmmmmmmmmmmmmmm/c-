#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 50


//定义操作符栈，存放操作符用
typedef struct s
{
    char* s_data;
    int top;
}Stack_s;

//初始化操作符栈
Stack_s* InitStack_s()
{
    Stack_s* s = (Stack_s*)malloc(sizeof(Stack_s));
    s->s_data = (char*)malloc(sizeof(char) * MAX);
    s->top = -1;
    return s;
}

//操作符入栈
void push_ops(Stack_s* ops, char x)
{
    if (ops->top == MAX - 1)
    {
        printf("运算符栈满\n");
        //这里标着是为了调试的时候知道哪里出错了，下面同理
        exit(0);
    }
    else
    {
        ops->s_data[++(ops->top)] = x;
        //把新元素添加到栈顶，也就是加到s_data中已有数据的后面，也就是第top+1项，下标top
    }
}

//操作符出栈
char pop_ops(Stack_s* ops)
{
    char arr;
    if (ops->top == -1)
    {
        printf("2输入有误\n");
        exit(0);
    }
    else
    {
        arr = ops->s_data[ops->top--];
        //把栈顶存入arr，并且top-1
    }
    return arr;
}

//获取操作符栈的栈顶元素，这个跟出栈的区别在于，这个不删除栈顶元素
char gettop_ops(Stack_s* ops)
{
    if (ops->top != -1)
    {
        return ops->s_data[ops->top];
    }
    else
    {
        printf("输入有误opsget\n");
        exit(0);
    }
}
//定义操作数栈，这下面的几个函数跟上面是基本一致的，就是存的data是double类型
typedef struct n
{
    double* s_data;
    int top;
}Stack_n;

//初始化操作数栈
Stack_n* InitStack_n()
{
    Stack_n* s = (Stack_n*)malloc(sizeof(Stack_n));
    s->s_data = (double*)malloc(sizeof(double) * MAX);
    s->top = -1;
    return s;
}

//操作数入栈
void push_ovs(Stack_n* ovs, double x)
{
    if (ovs->top == MAX - 1)
    {
        printf("运算数栈满\n");
        exit(0);
    }
    else
    {
        ovs->s_data[++ovs->top] = x;
    }
}

//操作数出栈
double pop_ovs(Stack_n* ovs)
{
    double num;
    if (ovs->top == -1)
    {
        printf("1输入有误\n");
        exit(0);
    }
    else
    {
        num = ovs->s_data[ovs->top--];
    }
    return num;
}

//获取操作数栈的栈顶元素
double gettop_ovs(Stack_n* ovs)
{
    if (ovs->top != -1)
    {
        return ovs->s_data[ovs->top];
    }
    else
    {
        printf("输入有误ovsget\n");
        exit(0);
    }
}
//与上面相同的内容到此为止

//这个函数判断操作符的优先级
//如果优先级相同或t1>t2，输出1，否则输出0
//如果t1是括号则输出0
int Judge_ops(char t1, char t2)
{
    switch (t1)
    {
    case '+':
    case '-':
        if (t2 == '+' || t2 == '-')
            return 1;
        else
            return 0;
    case '*':
    case '/': return 1;
    case '(':return 0;
    }
    return 1;
}

//判断是否是操作符并分类
int Is_ops(char e)
{
    switch (e)
    {
    case '+':
    case '-':
    case '*':
    case '/':return 1;//+-*/输出1
    case '(':return 2;//前括号输出2
    case ')':return -1;//后括号输出-1
    default:return 0;//数字（包括'.'）输出0
    }
}

//判断算数表达式是否正确
void judge(char e[MAX])
{
    int i = 1;
    while (e[i] != '\0')
    {//如果连续两个操作符或者数字后面直接跟着括号就算错
        if ((Is_ops(e[i - 1]) == 1 && Is_ops(e[i]) == 1) ||
            (Is_ops(e[i - 1]) == 0 && Is_ops(e[i]) == 2))
        {//判断条件太长放不下，给隔断了
            printf("%c %c\n", e[i - 1], e[i]);
            printf("输入表达式有误\n");
            exit(0);
        }
        i++;
    }
}
//对两个数和一个运算符进行计算
double getNum(double b, double a, char c)
{
    switch (c)
    {
    case '+':return a + b; break;
    case '-':return a - b; break;
    case '*':return a * b; break;
    case '/':return a / b; break;//很直观，不备注了
    }
    return 1;
}
//这个是取数字栈栈顶的两个数字和符号栈栈顶进行计算
void count(Stack_s* s, Stack_n* n)
{
    double a, b, nums;
    char c;
    a = pop_ovs(n);
    b = pop_ovs(n);
    c = pop_ops(s);
    nums = getNum(a, b, c);//计算完把数字压回数字栈
    push_ovs(n, nums);
}
//计算主体
double val(Stack_s* s, Stack_n* n, char e[MAX])
{
    int i = 0, j = 0;
    double a, b, transformNUM, nums;
    char c;
    char buff[MAX] = { '0' };
    judge(e);
    while (e[i])//开始遍历输入的字符串
    {
        if (e[i] >= '0' && e[i] <= '9')
        {
            while ((e[i] >= '0' && e[i] <= '9') || e[i] == '.')
                //进行处理多位数，遍历输入的字符串，遇到数字或者小数点就继续，直到读入符号
            {
                buff[j++] = e[i++];//把读入的存在buff里面
            }
            transformNUM = (double)atof(buff);
            //atof函数可以把字符串转化为浮点型，有兴趣自行百度
            push_ovs(n, transformNUM);//把得到的浮点型压入数据栈
            for (int i = 0; i < j; i++)
            {
                buff[i] = '\0';//把buff初始化，下次还要用呢
            }
            j = 0;
        }
        else if (e[i] == '+' || e[i] == '-')
        {//这里比较复杂，因为-可能代表负号或者减法。太长了，我写在思路里面了
            if (i != 0 && e[i - 1] != '(' || e[i] == '+')
            {//这种是不是负号的情况
                if (s->top == -1)
                {//符号栈是空栈，直接压入
                    push_ops(s, e[i++]);
                }
                else if (Judge_ops(gettop_ops(s), e[i]) && n->top >= 1)
                {//栈顶运算符也是加或者减，并且数字栈有两个以上的数
                    count(s, n);//弹出栈顶进行运算
                }
                else if (gettop_ops(s) != '(')
                {//不是括号的情况就是乘除了，那就弹出栈顶计算，把新新数字和新符号压入栈
                    count(s, n);
                    push_ops(s, e[i++]);
                }
                else
                    push_ops(s, e[i++]);
            }
            else
            {//是负号的情况
                i += 1;
                j = 1;
                buff[0] = '-';//先给buff数组上个负号
                while ((e[i] >= '0' && e[i] <= '9') || e[i] == '.')
                    //多位数进行处理，因为负号后面是数字嘛，跟前面读入数字那个一样
                {
                    buff[j++] = e[i++];
                }
                transformNUM = (double)atof(buff);
                push_ovs(n, transformNUM);
                for (int i = 0; i < j; i++)
                {
                    buff[i] = '\0';
                }
                j = 0;
            }
        }
        else if (e[i] == '*' || e[i] == '/')
        {//乘除简单很多
            if (s->top == -1)
            {//是空操作符栈就压入
                push_ops(s, e[i++]);
            }
            else
            {//栈顶优先级>=新操作符则弹出进行计算
                if (Judge_ops(gettop_ops(s), e[i]) && n->top >= 1)
                {
                    count(s, n);
                }//算完压入栈
                push_ops(s, e[i++]);
            }
        }
        else if (e[i] == '(')
        {//遇到（直接压入栈
            push_ops(s, e[i++]);
        }
        else if (e[i++] == ')')
        {//遇到），把（后面的符号全部弹出进行计算
            while (gettop_ops(s) != '(')
            {
                count(s, n);
            }
            pop_ops(s);//记得删掉（哦
        }
    }
    if (e[i] == '\0')
    {//如果读完了，就依次弹出计算
        while (s->top != -1)
            count(s, n);
    }
    return gettop_ovs(n);
}


int main()
{
    Stack_s* s = InitStack_s();
    Stack_n* n = InitStack_n();
    printf("请输入一个算术表达式\n");
    char e[MAX];
    fgets(e, sizeof e, stdin);

    //char x[MAX] = { '\0' };
    //int m = 0;
    //for (int i = 0; i < strlen(e) - 1; i++)
    //{
    //    if (e[i] == ' ')
    //    {
    //        ;
    //    }
    //    else
    //    {
    //        x[m] = e[i];
    //        m++; //指向数组的指针往后移动
    //    }
    //}

    printf("%lf\n", val(s, n, e));
    return 0;
}