//从文件abc.txt读入一些数字，并且按照每个数字各位的平方的和进行排序，要求从大到小。
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int BitSquare(int a)
{
    int t=0;
    int sum=0;
    while(a)
    {
        t=a%10;
        sum=sum+ t*t;
        a /= 10;
    }
    return sum;
}

void print(vector<int> &v)
{
    if(v.empty())
        cout<<"No Element!!"<<endl;
    for( unsigned int i = 0; i < v.size(); i++ )
        cout << v[i] << " ";

}

bool myCmp(int x, int y)//bool型的中的sort()里最后的cmp，是用于，需要让它从小往大排序的时候
{
    return x>y;
}
int main()
{
    ifstream cin("abc.txt"); //读取文件的时候，请一定一定不要忘了ifstream cin()这个整体
                            //简直是，不知道说什么了Orz
    vector<int> v;
    for(int a; cin>>a;)
        v.push_back(BitSquare(a));
    sort(v.begin(),v.end(),myCmp);
    print(v);
    return 0;
}

//abc.txt中内容：12 567 91 33 657 812	2221	3	77
//输出结果：110 110 98 82 69 18 13 9 5
