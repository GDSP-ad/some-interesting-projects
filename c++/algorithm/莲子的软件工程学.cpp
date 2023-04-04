#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    if(b>0)
    {
        cout<<abs(a);
    }
    else
    {
        cout<<-abs(a);
    }
    return 0;
}