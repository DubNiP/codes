#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

int n, l;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n; n++;
    int l = 0;
    for(int i = 0; i < n; i++){
        l <<= 1;
        int u;
        cin >> u;
        l += u;
    }
    int op = 0;
    while(l!=1){
        if((l&1) == 1) l = (l ^(l << 1))^1;
        else l >>= 1;
        op++;
    }
    cout << op << '\n';
    return 0;
}