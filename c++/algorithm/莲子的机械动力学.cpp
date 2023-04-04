#include <bits/stdc++.h>
using namespace std;

long long a[200000], b[200000];

int main()
{
    int n, m;

    cin >> n >> m;

    if (n < m)
    {
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < m; i++)
            cin >> a[i];
        n ^= m ^= n ^= m;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
    }

    int index;
    int jinzhi = 2;
    index = n - 1;
    for (int i = m - 1; i >= 0; i--)
    {
        a[index] += b[i];
        if (a[index] >= jinzhi && index)
        {
            int t=jinzhi;
            for(int j=index;a[j]>=t&&j-1>=0;j--)
            {
                a[j-1] += a[j] / t;
                a[j] %= t;
                t++;
            }
        }
        jinzhi++;
        index--;
    }


    if (a[0] >= n + 1)
    {
        cout << a[0] / (n + 1) << ' ';
        cout << a[0] % (n + 1) << ' ';
        for (int i = 1; i < n; i++)
        {
            cout << a[i] << ' ';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
    }
}