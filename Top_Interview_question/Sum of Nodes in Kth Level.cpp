#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k,arr[150]={0},lvl=-1,sum=0;
    string s;
    cin>>k>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            arr[lvl]+=sum;
            lvl++;
            sum=0;
        }
        else if(s[i]==')')
        {
            arr[lvl]+=sum;
            lvl--;
            sum=0;
        }
        else{
            sum=sum*10+s[i]-'0';
        }
    }

    cout<<arr[k]<<endl;

    return 0;
}
