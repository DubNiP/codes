#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,r=10;
    cin>>a;
    while(a){
        r=min(r,a%10);
        a/=10;
    }
    cout<<r<<"\n";
}



int main()
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}