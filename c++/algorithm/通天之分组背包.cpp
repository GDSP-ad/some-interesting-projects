#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int main()
{
    int m, n;
    int weight, value, group;
    int a[MAX][MAX][2] = {0};
    int ans[2][MAX] = {0};
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight >> value >> group;
        int j = 0;
        for (; a[group-1][j][0]; j++);
        a[group-1][j][0] = weight;
        a[group-1][j][1] = value;
    }


    int num=0;
    for(;a[num][0][0];num++);
    for (int i = 0; i<num; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for(int k=0;a[i][k][0];k++)
            {
                if(j>=a[i][k][0])
                {
                    ans[1][j]=ans[1][j]>max(ans[0][j],ans[0][j-a[i][k][0]]+a[i][k][1])?
                    ans[1][j]:max(ans[0][j],ans[0][j-a[i][k][0]]+a[i][k][1]);
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            ans[0][j]=ans[1][j];
        }
    }

    cout<<ans[1][m];
}