#include <iostream>
#define LEN 100
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int n;
    int dp[LEN][LEN]={0};
    cout<<"输入三角形的高度:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>dp[i][j];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
        }
    }

    cout<<"最长路径:"<<dp[0][0];
    return 0;
}