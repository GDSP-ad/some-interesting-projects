#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s[600];

    for(int i=0;;i++)
    {
        cin>>s[i];
        if(s[i]=="0")
            break;
    }

    for(int i=0;s[i]!="0";i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j)
                cout<<s[i];
            if(s[i]==s[j])
                break;
        }
    }
    return 0;
}