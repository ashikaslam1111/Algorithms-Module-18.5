#include <bits/stdc++.h>
using namespace std;
sumOfnum(string s,int index)
{
    if(index ==0)return s[index] - 48;
    return  s[index] - 48 + sumOfnum(s, index - 1);
}
int main()
{
    string theNum;
    cin>>theNum;
    int len = theNum.length();
    cout<<sumOfnum(theNum,len - 1);
    return 0;
}
