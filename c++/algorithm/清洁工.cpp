#include <bits/stdc++.h>
#define MAX 100
using namespace std;

void move(int &x,int &y,char d)
{
    switch(d)
    {
        case 'N':y++;break;
        case 'S':y--;break;
        case 'W':x--;break;
        case 'E':x++;break;
    }
}

int main()
{
    int a[MAX][MAX][2]={0};
    int n,m,x,y;
    string s;
    cin>>n>>m>>x>>y;
    cin>>s;

    for(int index=0;index<m;index++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(y==i&&x==j)
                    continue;
                a[i][j][0]+=++a[i][j][1];
            }
        }
        move(x,y,s[index]);
        a[y][x][1]=0;
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j][0]<<' ';
        }
        cout<<endl;
    }
    return 0;
}