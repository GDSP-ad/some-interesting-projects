/*从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。
*
* 路径上的每一步只能从一个数走到下一层和它最近的左边的那个数或者右 边的那个数。此外，向左下走的次数与向右下走的次数相差不能超过 1。
*/


#include <iostream>
#define LEN 100
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
  // 请在此输入您的代码
  int n;
    int dp[LEN][LEN][2]={0};
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            cin>>dp[i][j][0];

    if(n%2)
      dp[n-1][n/2][1]=1;
    else
      dp[n-1][n/2-1][1]=dp[n-1][n/2][1]=1;

    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
          if(dp[i+1][j][1]&&dp[i+1][j+1][1])
            dp[i][j][0]+=max(dp[i+1][j][0],dp[i+1][j+1][0]);
          else if(dp[i+1][j][1])
            dp[i][j][0]+=dp[i+1][j][0];
          else if(dp[i+1][j+1][1])
            dp[i][j][0]+=dp[i+1][j+1][0];
          else
            continue;
          dp[i][j][1]=1;
        }
    }

    cout<<dp[0][0][0];
  return 0;
}
