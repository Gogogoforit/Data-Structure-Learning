//Linkage:https://pta.patest.cn/pta/test/3512/exam/4/question/58272
/*
The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer KK (\le 10000≤10000). The second line contains KK numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices ii and jj (as shown by the sample case). If all the KK numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4
*/

#include<iostream>
using namespace std;
int main()
{
    int N;
    int *input;
    int i;
    int begin=0, end=0, sum=0;  //最终所求的子序列的起始位置，终止位置，以及子序列和。
    int tempSum=0, tempBegin=0, tempEnd=0;  //目前正在考察的子序列的起始位置，终止位置，以及子序列的和。

    cin>>N;
    input = new int[N];
    for(i=0; i<N; i++)
        cin>>input[i];

    end = N-1;
    for(i=0; i<N; i++)
    {
        if(tempSum >= 0)
        {
            tempSum += input[i];
            tempEnd = i;
        }
        else {
            //如果tempSum<0,那么tempSum+input[i]<input[i]
            //所以此时我们要开始考察新的子序列
            tempSum = 0;
            tempSum += input[i];
            tempBegin = i;
            tempEnd = i;
        }

        //if(tempSum > sum) 这样写不能AC，应改为如下：
        if(tempSum > sum || (tempSum == 0 && end == N-1))
        {
            sum = tempSum;
            begin = tempBegin;
            end = tempEnd;
        }
    }
    cout<<sum<<" "<<input[begin]<<" "<<input[end]<<endl;
    return 0;
}
