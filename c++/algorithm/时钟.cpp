#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int day = x / (60 * 24);

    int oneDayGoodTimeTotal = 39;
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<10;j++)
    //     {
    //         if(i==2&&j==4)
    //             goto L1;
    //         for(int k=0;k<6;k++)
    //         {
    //             for(int l=0;l<10;l++)
    //             {
    //                 if ((i == 0 && l - k == k - j) || (i > 0 && (l - k == k - j) && (l - k == j - i)))
    //                     oneDayGoodTimeTotal++;
    //             }
    //         }
    //     }
    // }

    x = x % (60 * 24);
    int goodTime = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    if ((i == 0 && l - k == k - j) || (i > 0 && (l - k == k - j) && (l - k == j - i)))
                        goodTime++;
                    if ((i * 10 + j) * 60 + k * 10 + l == x)
                        goto L2;
                }
            }
        }
    }
L2:
    cout << day * oneDayGoodTimeTotal + goodTime;
}