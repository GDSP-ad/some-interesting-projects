#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,w;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>w;
    sort(a,a+n);
    int max=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<=w)
        {
            max=a[i];
            break;
        }
    }
    
    int ans=0;
    int total=0;
    
    for(int i=0;i<n;i++)
    {
        total+=a[i];
        if(total>max)
        {
            cout<<ans;
            return 0;
        }
        ans++;
    }
}