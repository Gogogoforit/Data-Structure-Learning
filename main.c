/*������к�����
��Ŀ���ӣ�https://pta.patest.cn/pta/test/3512/exam/4/question/58271
������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ������������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20����Ҫ�����д���򣬼�������������е�������к͡�

����ּ�ڲ��Ը��ֲ�ͬ���㷨�ڸ�����������µı��֡�������������ص����£�

�����ʽ:

�����1�и���������KK (\le 100000��100000)����2�и���KK������������Կո�ָ���

�����ʽ:

��һ�������������к͡��������������������Ϊ�����������0��

��������:

6
-2 11 -4 13 -5 -2
�������:

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

        /* ����������кͱȽϣ�������������к� */
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        /* ��̬�滮���֣�������ǰ��Ϊ���������� */
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

//�����2017-03-01 21:47	����ȷ	20	01-���Ӷ�1	gcc	20	1	����38324
