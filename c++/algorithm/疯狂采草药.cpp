#include <bits/stdc++.h>
#define NUM 10000
#define SIZE 100002
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, M; //时间 数量
    int a[NUM][2] = {0};
    long long value[SIZE] = {0};
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            if (j >= a[i][0])
            {
                    value[j] = max(value[j], value[j - a[i][0]] + a[i][1]);
            }
        }
    }
    cout << value[T];
}