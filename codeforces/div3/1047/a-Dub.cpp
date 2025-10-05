#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

void solve(){
    ll x,k;
    cin>>k>>x;
    while(k--){
        x*=2;
    }
    cout<<x<<"\n";
}

int main(){ _
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}