#include <bits/stdc++.h>
#define LEN 2000
using namespace std;

int main()
{
    int T, M;
    int a[LEN][2] = {0}; //[i][0]时间,[i][1]价值
    int value[2][LEN] = {0};
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
                value[1][j] = max(value[0][j], value[0][j - a[i][0]] + a[i][1]);
            }
        }
        for (int j = 1; j <= T; j++)
        {
            value[0][j] = value[1][j];
        }
    }

    cout << value[1][T];
}