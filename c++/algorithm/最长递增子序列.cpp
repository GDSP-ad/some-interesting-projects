#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define LEN 1000
using namespace std;


int main()
{
    int a[LEN]={1,2,3,1,2,3,4};
    int dp[LEN]={1};
    int ans=1;
    for(int i=1;i<LEN;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=dp[j]+1>dp[i]?dp[j]+1:dp[i];
            }
        }
        ans=dp[i]>ans?dp[i]:ans;
    }
    cout<<ans;
    return 0;
}