//X = A*N + B*LOC(N)+C*N*N*N
// GIVEN A,B,C,X   FIND N

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX1 100000000000001
#define MAX2 100001
ll a,b,c,x,ans;
int logg(ll n){
    double d = n;
    int cnt = 0;
    while(d>= 2.71878){
        cnt++;
        d /= 2.71878;
    }
    return cnt;
}


void solve(){
    ll l=0,mid;
    ll h = MAX2;
    if(c == 0 ) h = MAX1;

    while(l <= h){
        mid = (h+l)/2;
        ll tmp = a*mid + b*logg(mid) + c*mid*mid*mid;

        if(tmp == x){
            ans = mid;
            return;
        }
        if(tmp>x)
            h = mid-1;
        else
            l = mid+1;

    }

}

int main(){
    int test;
    freopen("/home/rifat/Desktop/Samsung/ADVANCED (1)/Equation/Equation_input.txt", "r", stdin);
    cin>>test;

    for(int t=1;t<=test;t++){
        cin>>a>>b>>c>>x;
        solve();
        cout<<t<<" "<<ans<<endl;

    }


}
