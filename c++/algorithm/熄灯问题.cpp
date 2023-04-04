#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5][6];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            cin >> a[i][j];

    for (int i = 0; i < 64; i++)
    {

        int _a[5][6], ans[5][6] = {0};
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 6; k++)
                _a[j][k] = a[j][k];

        int t = i;
        for (int j = 0; j < 6; j++)
        {
            ans[0][j] = t % 2;

            _a[0][j] ^= ans[0][j];
            j == 0 ? 0 : _a[0][j - 1] ^= ans[0][j];
            j == 5 ? 0 : _a[0][j + 1] ^= ans[0][j];
            _a[1][j] ^= ans[0][j];
            t >>= 1;
        }

        for (int j = 1; j < 5; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (_a[j - 1][k])
                {
                    ans[j][k] = 1;
                    _a[j][k] ^= 1;
                    j == 4 ? 0 : _a[j + 1][k] ^= 1;
                    k == 0 ? 0 : _a[j][k - 1] ^= 1;
                    k == 5 ? 0 : _a[j][k + 1] ^= 1;
                }
            }
        }

        if (!(_a[4][0] || _a[4][1] || _a[4][2] || _a[4][3] || _a[4][4] || _a[4][5]))
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    cout << ans[j][k] << ' ';
                }
                cout << endl;
            }
            return 0;
        }
    }
}