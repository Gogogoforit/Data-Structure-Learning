/*最大子列和问题
题目链接：https://pta.patest.cn/pta/test/3512/exam/4/question/58271
最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

输入格式:

输入第1行给出正整数KK (\le 100000≤100000)；第2行给出KK个整数，其间以空格分隔。

输出格式:

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

输入样例:

6
-2 11 -4 13 -5 -2
输出样例:

20

*/
#include <stdio.h>
#include <stdlib.h>

int MaxSubsequent(int a[], int n)
{
    int i, ThisSum, MaxSum;
    ThisSum = MaxSum =0;

    for (i = 0; i < n; i++)
    {
        ThisSum += a[i];

        /* 与最大子序列和比较，更新最大子序列和 */
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        /* 动态规划部分，舍弃当前和为负的子序列 */
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    int i ,N,result;
    i = N =result=0;
    scanf("%d", &N);
    int a[N];
    for (i=0;i<N;i++)
        scanf("%d",&a[i]);
    result=MaxSubsequent(a,N);
    printf("%d",result);
    return 0;
}

//结果：2017-03-01 21:47	答案正确	20	01-复杂度1	gcc	20	1	蓁蓁38324
