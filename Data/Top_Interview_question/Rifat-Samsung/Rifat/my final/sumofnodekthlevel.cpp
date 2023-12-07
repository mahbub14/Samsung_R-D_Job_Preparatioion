#include<bits/stdc++.h>
using namespace std;

int main(){
    int test=1,k;
    //cin>>test;
    while(test--){
        string str;
        cin>>k;
        cin>>str;
        int ans = 0;
        int n = str.size(),lvl=-1;
        for(int i=0;i<n;i++){
            if(str[i] == '(')
                lvl++;
            else if(str[i] == ')')
                lvl--;
            else if(k == lvl){
                string tmp = "";
                while(isdigit(str[i])){
                    tmp += str[i++];
                }
                i--;
                ans += stoi(tmp);
            }

        }
        cout<<ans<<endl;

    }


}
