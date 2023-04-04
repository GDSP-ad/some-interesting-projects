#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, m, t;
    vector<long long> a;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }

    if(a.size()==1)
    {
        cout<<1;
        return 0;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        int minNum=a.front();
        int maxNum=a.back();
        double avg=accumulate (a.begin(), a.end(), 0)/n;
        if (avg-a.front()>a.back()-avg)
        {
            a.pop_back();
            a.insert(a.begin(), minNum);
        }
        else if(avg-a.front()<a.back()-avg)
        {
            a.erase(a.begin());
            a.push_back(maxNum);
        }
        else
        {
            int minNumCount=0,maxNumCount=0;
            for(auto i: a)
            {
                if(i==minNum)
                    minNumCount++;
                else
                    break;
            }

            for(auto i=a.size()-1;i>=0;i--)
            {
                if(a[i]==maxNum)
                    maxNumCount++;
                else
                    break;
            }

            if(minNumCount>maxNumCount)
            {
                a.pop_back();
                a.insert(a.begin(), minNum);
            }
            else
            {
                a.erase(a.begin());
                a.push_back(maxNum);
            }
        }
    }


    cout << a.back()-a.front();
}