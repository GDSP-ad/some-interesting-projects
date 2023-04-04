#include <iostream>
using namespace std;

string s1="123";

void f(string s,int index=0)
{
    if(index==s.length())
    {
        cout<<s<<endl;
        return;
    }

    string _s=s;
    _s[index]="";
    f(_s,index);
    f(s,index+1);
}

int main()
{
    f("123");
}